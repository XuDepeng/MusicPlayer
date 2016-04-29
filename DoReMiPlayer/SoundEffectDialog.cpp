#include "SoundEffectDialog.h"

#include <QFile>
#include <QTextStream>
#include <QSlider>
#include <QHBoxLayout>

SouncEffectDialog* SouncEffectDialog::m_instance = nullptr;

SouncEffectDialog* SouncEffectDialog::CreateSoundEffect(){
	if (!m_instance){
		m_instance = new SouncEffectDialog;
	}
	return m_instance;
}
void SouncEffectDialog::DestroySoundEffect(SouncEffectDialog* instance){
	if (instance){
		delete m_instance;
		m_instance = nullptr;
	}
}

SouncEffectDialog::SouncEffectDialog(QWidget* parent):
QDialog(parent){
	ui.setupUi(this);
	QFile f("../qdarkstyle/style.qss");
	if (!f.exists()){
		return;
	}
	else{
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		setStyleSheet(ts.readAll());
	}

	createSliders();
	createRadioBtns();
	initFont();

	connect(ui.lowFreqSlider, SIGNAL(valueChanged(int)), this, SLOT(setLowFreq(int)));
	connect(ui.midFreqSlider, SIGNAL(valueChanged(int)), this, SLOT(setMidFreq(int)));
	connect(ui.highFreqSlider, SIGNAL(valueChanged(int)), this, SLOT(setHighFreq(int)));
	connect(ui.lowmidFreqSlider, SIGNAL(valueChanged(int)), this, SLOT(setLowmidFreq(int)));
	connect(ui.midhighFreqSlider, SIGNAL(valueChanged(int)), this, SLOT(setMidhighFreq(int)));
	connect(ui.extremhighFreqSlider, SIGNAL(valueChanged(int)), this, SLOT(setExtremhighFreq(int)));
	connect(ui.reverbSlider, SIGNAL(valueChanged(int)), this, SLOT(setReverb(int)));

	connect(ui.rotateRadioButton, SIGNAL(toggled(bool)), this, SLOT(setRotate(bool)));
	connect(ui.echoRadioButton, SIGNAL(toggled(bool)), this, SLOT(setEcho(bool)));
	connect(ui.flangerRadioButton, SIGNAL(toggled(bool)), this, SLOT(setFlanger(bool)));

	connect(ui.confirmPushBtn, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.cancelPushBtn, SIGNAL(clicked()), this, SLOT(reset()));
}

void SouncEffectDialog::createSliders(){
	ui.lowFreqSlider->setRange(0, 20);
	ui.lowFreqSlider->setValue(10);
	ui.midFreqSlider->setRange(0, 20);
	ui.midFreqSlider->setValue(10);
	ui.highFreqSlider->setRange(0, 20);
	ui.highFreqSlider->setValue(10);

	ui.lowmidFreqSlider->setRange(0, 20);
	ui.lowmidFreqSlider->setValue(10);
	ui.midhighFreqSlider->setRange(0, 20);
	ui.midhighFreqSlider->setValue(10);
	ui.extremhighFreqSlider->setRange(0, 20);
	ui.extremhighFreqSlider->setValue(10);

	ui.reverbSlider->setRange(0, 20);
	ui.reverbSlider->setValue(0);
}

void SouncEffectDialog::createRadioBtns(){
	ui.rotateRadioButton->setChecked(false);
	ui.echoRadioButton->setChecked(false);
	ui.flangerRadioButton->setChecked(false);
}

void SouncEffectDialog::setLowFreq(int freq){
	emit lowFreqChanged(freq);
}

void SouncEffectDialog::setMidFreq(int freq){
	emit midFreqChanged(freq);
}

void SouncEffectDialog::setHighFreq(int freq){
	emit highFreqChanged(freq);
}

void SouncEffectDialog::setReverb(int reverb){
	emit reverbChanged(reverb);
}

void SouncEffectDialog::setLowmidFreq(int freq){
	emit lowmidFreqChanged(freq);
}

void SouncEffectDialog::setMidhighFreq(int freq){
	emit midhighFreqChanged(freq);
}

void SouncEffectDialog::setExtremhighFreq(int freq){
	emit extremhighFreqChanged(freq);
}

void SouncEffectDialog::setEcho(bool isEnabled){
	emit echoChanged(isEnabled);
}
void SouncEffectDialog::setRotate(bool isEnabled){
	emit rotateChanged(isEnabled);
}
void SouncEffectDialog::setFlanger(bool isEnabled){
	emit flangerChanged(isEnabled);
}

void SouncEffectDialog::reset(){
	ui.lowFreqSlider->setValue(10);
	ui.midFreqSlider->setValue(10);
	ui.highFreqSlider->setValue(10);

	ui.lowmidFreqSlider->setValue(10);
	ui.midhighFreqSlider->setValue(10);
	ui.extremhighFreqSlider->setValue(10);

	ui.reverbSlider->setValue(0);

	ui.echoRadioButton->toggled(false);
	ui.rotateRadioButton->toggled(false);
	ui.flangerRadioButton->toggled(false);
}

void SouncEffectDialog::initFont(){
	QFont font;
	font.setFamily(QStringLiteral("Î¢ÈíÑÅºÚ"));
	ui.sqGroupBox->setFont(font);
	ui.eqBox->setFont(font);

	ui.lowLabel->setFont(font);
	ui.lowmidLabel->setFont(font);
	ui.midLabel->setFont(font);
	ui.midhighLabel->setFont(font);
	ui.highLabel->setFont(font);
	ui.extremhighLabel->setFont(font);

	ui.reverbLabel->setFont(font);

	ui.rotateRadioButton->setFont(font);
	ui.echoRadioButton->setFont(font);
	ui.flangerRadioButton->setFont(font);

	ui.confirmPushBtn->setFont(font);
	ui.cancelPushBtn->setFont(font);
}