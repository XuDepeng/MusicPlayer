#pragma once
#include <QDialog>
#include "ui_SoundEffectDialog.h"

class SouncEffectDialog:public QDialog{
	Q_OBJECT
public:
	static SouncEffectDialog* CreateSoundEffect();
	static void DestroySoundEffect(SouncEffectDialog*);
private:
	void initFont(); // reset to MS Yahei

	void createSliders();
	void createRadioBtns();

	Ui::SoundEffectDialogClass ui;
	static SouncEffectDialog *m_instance;

	SouncEffectDialog(QWidget* parent = 0);
	SouncEffectDialog(const SouncEffectDialog&);
	SouncEffectDialog operator =(const SouncEffectDialog&);
public slots:
	void setLowFreq(int freq);
	void setMidFreq(int freq);
	void setHighFreq(int freq);
	void setLowmidFreq(int freq);
	void setMidhighFreq(int freq);
	void setExtremhighFreq(int freq);
	void setReverb(int reverb);

	void setEcho(bool isEnabled);
	void setRotate(bool isEnabled);
	void setFlanger(bool isEnabled);

	void reset();
signals:
	void lowFreqChanged(int freq);
	void midFreqChanged(int freq);
	void highFreqChanged(int freq);
	void lowmidFreqChanged(int freq);
	void midhighFreqChanged(int freq);
	void extremhighFreqChanged(int freq);
	void reverbChanged(int reverb);

	void rotateChanged(bool isEnabled);
	void echoChanged(bool isEnabled);
	void flangerChanged(bool isEnabled);
};
