#include <QTimer>
#include <QDebug>
#include <QMessageBox>

#include <bass.h>
#include "MusicPlayer.h"

namespace{
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

	FILE *file = nullptr;
	// "eq"
	HFX fx[7];			// 6 eq bands + reverb
	bool endOfMusic;

	// "rotate"
	HDSP rotdsp = 0;	// DSP handle
	float rotpos;	// cur.pos

	// "echo"
	HDSP echdsp = 0;	// DSP handle
#define ECHBUFLEN 1200	// buffer length
	float echbuf[ECHBUFLEN][2];	// buffer
	int echpos;	// cur.pos

	// "flanger"
	HDSP fladsp = 0;	// DSP handle
#define FLABUFLEN 350	// buffer length
	float flabuf[FLABUFLEN][2];	// buffer
	int flapos;	// cur.pos
	float flas, flasinc;	// sweep pos/increment
}

void initialFX(int b);

void CALLBACK syncFunc(HSYNC handle, DWORD channel, DWORD data, void *user);

void CALLBACK rotate(HDSP handle, DWORD channel, void *buffer, DWORD length, void *user);
void CALLBACK echo(HDSP handle, DWORD channel, void *buffer, DWORD length, void *user);
void CALLBACK flange(HDSP handle, DWORD channel, void *buffer, DWORD length, void *user);

void CALLBACK downloadProc(const void *buffer, DWORD length, void *user);

QString MusicPlayer::s_curName = QString::null;

MusicPlayer::MusicPlayer(QObject *parent):
QThread(parent){
	BASS_SetConfig(BASS_CONFIG_FLOATDSP, TRUE);

	if (!BASS_Init(-1, 44100, 0, NULL, NULL))
		QMessageBox::information(0, 
		QStringLiteral("警告"), 
		QStringLiteral("设备初始化失败！"));
	BASS_SetVolume(0.06); // default

	m_lowFreq=10;
	m_lowmidFreq = 10;
	m_midFreq = 10;
	m_midhighFreq = 10;
	m_highFreq = 10;
	m_extremhighFreq = 10;
	m_reverb = 0;

	m_echo = false;
	m_rotate = false;
	m_flanger = false;

	m_timer = new QTimer(this);	

	connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
	connect(this, SIGNAL(songFinished()), this, SLOT(pause()));
	
	endOfMusic = true;
}

MusicPlayer::~MusicPlayer(){
	BASS_ChannelStop(m_chan);
	BASS_MusicFree(m_chan);
	BASS_StreamFree(m_chan);
	BASS_Stop();
	BASS_Free();
}

void MusicPlayer::play(QString songName){
	BASS_ChannelStop(m_chan);
	BASS_MusicFree(m_chan);
	BASS_StreamFree(m_chan);

	if (!(m_chan = BASS_StreamCreateFile(false, songName.toLocal8Bit(), 0, 0, BASS_SAMPLE_LOOP | BASS_SAMPLE_FX))
		&& !(m_chan = BASS_MusicLoad(false, songName.toLocal8Bit(), 0, 0, BASS_MUSIC_RAMP | BASS_SAMPLE_LOOP | BASS_SAMPLE_FX, 1))
		&& !(m_chan = BASS_StreamCreateURL(songName.toLocal8Bit().constData(), 0, BASS_SAMPLE_LOOP | BASS_SAMPLE_FX, 0, 0)))
		return;
	else{
		endOfMusic = false;
		BASS_DX8_PARAMEQ p;
		fx[0] = BASS_ChannelSetFX(m_chan, BASS_FX_DX8_PARAMEQ, 0);
		fx[1] = BASS_ChannelSetFX(m_chan, BASS_FX_DX8_PARAMEQ, 0);
		fx[2] = BASS_ChannelSetFX(m_chan, BASS_FX_DX8_PARAMEQ, 0);
		fx[3] = BASS_ChannelSetFX(m_chan, BASS_FX_DX8_PARAMEQ, 0);
		fx[4] = BASS_ChannelSetFX(m_chan, BASS_FX_DX8_PARAMEQ, 0);
		fx[5] = BASS_ChannelSetFX(m_chan, BASS_FX_DX8_PARAMEQ, 0);
		fx[6] = BASS_ChannelSetFX(m_chan, BASS_FX_DX8_REVERB, 0);
		p.fGain = 0;
		p.fBandwidth = 18;
		p.fCenter = 125;
		BASS_FXSetParameters(fx[0], &p);
		p.fCenter = 400;
		BASS_FXSetParameters(fx[1], &p);
		p.fCenter = 1000;
		BASS_FXSetParameters(fx[2], &p);
		p.fCenter = 3000;
		BASS_FXSetParameters(fx[3], &p);
		p.fCenter = 8000;
		BASS_FXSetParameters(fx[4], &p);
		p.fCenter = 12000;
		BASS_FXSetParameters(fx[5], &p);

		initialFX(0);
		initialFX(1);
		initialFX(2);
		initialFX(3);
		initialFX(4);
		initialFX(5);
		initialFX(6);

		BASS_ChannelPlay(m_chan, true);

		m_timer->start(100);
		BASS_ChannelSetSync(m_chan, BASS_SYNC_POS, 0, &syncFunc, 0);

		setLowFreq(m_lowFreq);
		setLowmidFreq(m_lowmidFreq);
		setMidFreq(m_midFreq);
		setMidhighFreq(m_midhighFreq);
		setHighFreq(m_highFreq);
		setExtremhighFreq(m_extremhighFreq);
		setReverb(m_reverb);

		setEcho(m_echo);
		setRotate(m_rotate);
		setFlanger(m_flanger);

		m_isPlaying = true;
		int index = songName.lastIndexOf("=");
		s_curName = "../data/" + songName.mid(index + 1);
	}
}

void MusicPlayer::pause(){
	BASS_ChannelPause(m_chan);
	m_timer->stop();
	m_isPlaying = false;
}

void MusicPlayer::resume(){
	if (!BASS_ChannelPlay(m_chan, false))
		qDebug() << "Error resuming";
	else{
		m_timer->start(98);
		m_isPlaying = true;
	}
}

void MusicPlayer::stop(){
	BASS_ChannelStop(m_chan);
	m_timer->stop();
	m_isPlaying = false;
}

void MusicPlayer::update(){
	if (endOfMusic == false){
		emit positionChanged(BASS_ChannelBytes2Seconds(m_chan, BASS_ChannelGetPosition(m_chan, BASS_POS_BYTE)));
	}
	else{
		emit songFinished();
		m_isPlaying = false;
	}
}

void MusicPlayer::setPosition(int position){
	BASS_ChannelSetPosition(m_chan, BASS_ChannelSeconds2Bytes(m_chan, position), BASS_POS_BYTE);
}

void MusicPlayer::setVolume(int vol){
	float bassvol = (float)vol/400.0f;
	BASS_SetVolume(bassvol);
}

double MusicPlayer::getTotalPosByte(){
	return BASS_ChannelBytes2Seconds(m_chan, BASS_ChannelGetLength(m_chan, BASS_POS_BYTE));
}

void MusicPlayer::setLowFreq(int freq){
	m_lowFreq = freq;
	int v = freq;
	BASS_DX8_PARAMEQ p;
	BASS_FXGetParameters(fx[0], &p);
	p.fGain = 10.0 - v;
	BASS_FXSetParameters(fx[0], &p);
}

void MusicPlayer::setLowmidFreq(int freq){
	m_lowmidFreq = freq;
	int v = freq;
	BASS_DX8_PARAMEQ p;
	BASS_FXGetParameters(fx[1], &p);
	p.fGain = 10.0 - v;
	BASS_FXSetParameters(fx[1], &p);
}

void MusicPlayer::setMidFreq(int freq){
	m_midFreq = freq;
	int v = freq;
	BASS_DX8_PARAMEQ p;
	BASS_FXGetParameters(fx[2], &p);
	p.fGain = 10.0 - v;
	BASS_FXSetParameters(fx[2], &p);

}

void MusicPlayer::setMidhighFreq(int freq){
	m_midhighFreq = freq;
	int v = freq;
	BASS_DX8_PARAMEQ p;
	BASS_FXGetParameters(fx[3], &p);
	p.fGain = 10.0 - v;
	BASS_FXSetParameters(fx[3], &p);
}

void MusicPlayer::setHighFreq(int freq){
	m_highFreq = freq;
	int v = freq;
	BASS_DX8_PARAMEQ p;
	BASS_FXGetParameters(fx[4], &p);
	p.fGain = 10.0 - v;
	BASS_FXSetParameters(fx[4], &p);
}

void MusicPlayer::setExtremhighFreq(int freq){
	m_extremhighFreq = freq;
	int v = freq;
	BASS_DX8_PARAMEQ p;
	BASS_FXGetParameters(fx[5], &p);
	p.fGain = 10.0 - v;
	BASS_FXSetParameters(fx[5], &p);

}

void MusicPlayer::setReverb(int reverb){
	m_reverb = reverb;
	int v = 20-reverb;
	BASS_DX8_REVERB p;
	BASS_FXGetParameters(fx[6], &p);
	p.fReverbMix = (v < 20 ? log(1 - v / 20.0) * 20 : -96);
	BASS_FXSetParameters(fx[6], &p);
}

void MusicPlayer::setEcho(bool isEnabled){
	m_echo = isEnabled;
	if (m_echo){
		memset(echbuf, 0, sizeof(echbuf));
		echpos = 0;
		echdsp = BASS_ChannelSetDSP(m_chan, &echo, 0, 1);
	}
	else
		BASS_ChannelRemoveDSP(m_chan, echdsp);
}

void MusicPlayer::setRotate(bool isEnabled){
	m_rotate = isEnabled;
	if (m_rotate){
		rotpos = M_PI / 4;
		rotdsp = BASS_ChannelSetDSP(m_chan, &rotate, 0, 2);
	}
	else
		BASS_ChannelRemoveDSP(m_chan, rotdsp);

}

void MusicPlayer::setFlanger(bool isEnaled){
	m_flanger = isEnaled;
	if (m_flanger){
		memset(flabuf, 0, sizeof(flabuf));
		flapos = 0;
		flas = FLABUFLEN / 2;
		flasinc = 0.002f;
		fladsp = BASS_ChannelSetDSP(m_chan, &flange, 0, 0);
	}
	else
		BASS_ChannelRemoveDSP(m_chan, fladsp);
}

void initialFX(int b){
	if (b < 6) {
		int v = 10;
		BASS_DX8_PARAMEQ p;
		BASS_FXGetParameters(fx[b], &p);
		p.fGain = 10.0 - v;
		BASS_FXSetParameters(fx[b], &p);
	}
	else {
		int v = 20;
		BASS_DX8_REVERB p;
		BASS_FXGetParameters(fx[6], &p);
		p.fReverbMix = (v < 20 ? log(1 - v / 20.0) * 20 : -96);
		BASS_FXSetParameters(fx[6], &p);
	}
}

void CALLBACK syncFunc(HSYNC handle, DWORD channel, DWORD data, void *user){
	BASS_ChannelRemoveSync(channel, handle);
	BASS_ChannelStop(channel);
	endOfMusic = true;
}

void CALLBACK rotate(HDSP handle, DWORD channel, void *buffer, DWORD length, void *user){
	float *d = (float*)buffer;
	DWORD a;

	for (a = 0; a < length / 4; a += 2) {
		d[a] *= fabs(sin(rotpos));
		d[a + 1] *= fabs(cos(rotpos));
		rotpos += 0.00003;
	}
	rotpos = fmod(rotpos, 2 * M_PI);
}

void CALLBACK echo(HDSP handle, DWORD channel, void *buffer, DWORD length, void *user){
	float *d = (float*)buffer;
	DWORD a;

	for (a = 0; a < length / 4; a += 2) {
		float l = d[a] + (echbuf[echpos][1] / 2);
		float r = d[a + 1] + (echbuf[echpos][0] / 2);
#if 1 // 0=echo, 1=basic "bathroom" reverb
		echbuf[echpos][0] = d[a] = l;
		echbuf[echpos][1] = d[a + 1] = r;
#else
		echbuf[echpos][0] = d[a];
		echbuf[echpos][1] = d[a + 1];
		d[a] = l;
		d[a + 1] = r;
#endif
		echpos++;
		if (echpos == ECHBUFLEN) echpos = 0;
	}
}

void CALLBACK flange(HDSP handle, DWORD channel, void *buffer, DWORD length, void *user){
	float *d = (float*)buffer;
	DWORD a;

	for (a = 0; a < length / 4; a += 2) {
		int p1 = (flapos + (int)flas) % FLABUFLEN;
		int p2 = (p1 + 1) % FLABUFLEN;
		float f = flas - (int)flas;
		float s;

		s = (d[a] + ((flabuf[p1][0] * (1 - f)) + (flabuf[p2][0] * f)))*0.7;
		flabuf[flapos][0] = d[a];
		d[a] = s;

		s = (d[a + 1] + ((flabuf[p1][1] * (1 - f)) + (flabuf[p2][1] * f)))*0.7;
		flabuf[flapos][1] = d[a + 1];
		d[a + 1] = s;

		flapos++;
		if (flapos == FLABUFLEN) flapos = 0;
		flas += flasinc;
		if (flas<0 || flas>FLABUFLEN - 1) {
			flasinc = -flasinc;
			flas += flasinc;
		}
	}
}

void CALLBACK downloadProc(const void *buffer, DWORD length, void *user){
	if (!file) file = fopen(MusicPlayer::s_curName.toLocal8Bit().constData(), "wb"); // create the file
	if (!buffer) fclose(file); // finished downloading
	else fwrite(buffer, 1, length, file);
}