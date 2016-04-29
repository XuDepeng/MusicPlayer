#pragma once

#include <QThread>
#include <QPointer>

class QTimer;

class MusicPlayer :public QThread{
	Q_OBJECT
public:
	explicit MusicPlayer(QObject *parent = 0);
	~MusicPlayer();
	double getTotalPosByte();

	bool m_isPlaying;
	static QString s_curName;
private:
	unsigned long m_chan;
	QPointer<QTimer> m_timer;

	int m_lowFreq;
	int m_lowmidFreq;
	int m_midFreq;
	int m_midhighFreq;
	int m_highFreq;
	int m_extremhighFreq;
	int m_reverb;

	bool m_rotate;
	bool m_echo;
	bool m_flanger;
signals:
	void songFinished();
	void positionChanged(int Position);

public slots:
	void play(QString songName);
	void pause();
	void resume();
	void stop();

	void setVolume(int vol);
	void setPosition(int position);

	void setLowFreq(int freq);
	void setLowmidFreq(int freq);
	void setMidFreq(int freq);
	void setMidhighFreq(int freq);
	void setHighFreq(int freq);
	void setExtremhighFreq(int freq);
	void setReverb(int reverb);

	void setEcho(bool isEnabled);
	void setRotate(bool isEnabled);
	void setFlanger(bool isEnaled);
	
	void update();	
};