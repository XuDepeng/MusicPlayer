/********************************************************************************
** Form generated from reading UI file 'SoundEffectDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOUNDEFFECTDIALOG_H
#define UI_SOUNDEFFECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_SoundEffectDialogClass
{
public:
    QGroupBox *eqBox;
    QGridLayout *gridLayout;
    QLabel *lowLabel;
    QSlider *midFreqSlider;
    QSlider *reverbSlider;
    QSlider *highFreqSlider;
    QLabel *midLabel;
    QLabel *reverbLabel;
    QLabel *highLabel;
    QSlider *lowFreqSlider;
    QSlider *midhighFreqSlider;
    QSlider *lowmidFreqSlider;
    QSlider *extremhighFreqSlider;
    QLabel *lowmidLabel;
    QLabel *midhighLabel;
    QLabel *extremhighLabel;
    QGroupBox *sqGroupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *rotateRadioButton;
    QRadioButton *echoRadioButton;
    QRadioButton *flangerRadioButton;
    QPushButton *confirmPushBtn;
    QPushButton *cancelPushBtn;

    void setupUi(QDialog *SoundEffectDialogClass)
    {
        if (SoundEffectDialogClass->objectName().isEmpty())
            SoundEffectDialogClass->setObjectName(QStringLiteral("SoundEffectDialogClass"));
        SoundEffectDialogClass->resize(453, 189);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SoundEffectDialogClass->sizePolicy().hasHeightForWidth());
        SoundEffectDialogClass->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setKerning(false);
        SoundEffectDialogClass->setFont(font);
        SoundEffectDialogClass->setStyleSheet(QStringLiteral(""));
        SoundEffectDialogClass->setSizeGripEnabled(false);
        SoundEffectDialogClass->setModal(true);
        eqBox = new QGroupBox(SoundEffectDialogClass);
        eqBox->setObjectName(QStringLiteral("eqBox"));
        eqBox->setGeometry(QRect(10, 0, 281, 181));
        gridLayout = new QGridLayout(eqBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lowLabel = new QLabel(eqBox);
        lowLabel->setObjectName(QStringLiteral("lowLabel"));

        gridLayout->addWidget(lowLabel, 1, 0, 1, 1);

        midFreqSlider = new QSlider(eqBox);
        midFreqSlider->setObjectName(QStringLiteral("midFreqSlider"));
        midFreqSlider->setStyleSheet(QLatin1String("QSlider::groove:vertical {                                \n"
"     border: 1px solid #999999;                  \n"
"     height: 105px;                                           \n"
"     margin: 1px;                                         \n"
"     left: 8px; right:8px;\n"
"     bottom: 30px; top:30 px;\n"
" }                                                          \n"
"QSlider::handle:vertical {                                                \n"
"     border: 1px solid #5c5c5c;                \n"
"     border-image:url(../Resources/slider.png);\n"
"     width:20px;                                             \n"
"     margin: -10px -10px;                           \n"
" }\n"
"QSlider::add-page:vertical {\n"
"        background-color: rgb(37, 168, 198);\n"
"        width:4px;\n"
"}\n"
"QSlider::sub-page:vertical {\n"
"        background-color: rgb(87, 97, 106);\n"
"        width:4px;\n"
"}"));
        midFreqSlider->setOrientation(Qt::Vertical);
        midFreqSlider->setInvertedAppearance(true);
        midFreqSlider->setInvertedControls(false);

        gridLayout->addWidget(midFreqSlider, 0, 2, 1, 1);

        reverbSlider = new QSlider(eqBox);
        reverbSlider->setObjectName(QStringLiteral("reverbSlider"));
        reverbSlider->setStyleSheet(QLatin1String("QSlider::groove:vertical {                                \n"
"     border: 1px solid #999999;                  \n"
"     height: 105px;                                           \n"
"     margin: 1px;                                         \n"
"     left: 8px; right:8px;\n"
"     bottom: 25px; top:25 px;\n"
" }                                                          \n"
"QSlider::handle:vertical {                                                \n"
"     border: 1px solid #5c5c5c;                \n"
"     border-image:url(../Resources/slider.png);\n"
"     width:10px;                                             \n"
"     margin:-10px -10px;                           \n"
" }\n"
"QSlider::add-page:vertical {\n"
"        background-color: rgb(37, 168, 198);\n"
"        width:4px;\n"
"}\n"
"QSlider::sub-page:vertical {\n"
"        background-color: rgb(87, 97, 106);\n"
"        width:4px;\n"
"}"));
        reverbSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(reverbSlider, 0, 6, 1, 1);

        highFreqSlider = new QSlider(eqBox);
        highFreqSlider->setObjectName(QStringLiteral("highFreqSlider"));
        highFreqSlider->setStyleSheet(QLatin1String("QSlider::groove:vertical {                                \n"
"     border: 1px solid #999999;                  \n"
"     height: 105px;                                           \n"
"     margin: 1px;                                         \n"
"     left: 8px; right:8px;\n"
"     bottom: 30px; top:30 px;\n"
" }                                                          \n"
"QSlider::handle:vertical {                                                \n"
"     border: 1px solid #5c5c5c;                \n"
"     border-image:url(../Resources/slider.png);\n"
"     width:20px;                                             \n"
"     margin: -10px -10px;                           \n"
" }\n"
"QSlider::add-page:vertical {\n"
"        background-color: rgb(37, 168, 198);\n"
"        width:4px;\n"
"}\n"
"QSlider::sub-page:vertical {\n"
"        background-color: rgb(87, 97, 106);\n"
"        width:4px;\n"
"}"));
        highFreqSlider->setOrientation(Qt::Vertical);
        highFreqSlider->setInvertedAppearance(true);
        highFreqSlider->setInvertedControls(false);

        gridLayout->addWidget(highFreqSlider, 0, 4, 1, 1);

        midLabel = new QLabel(eqBox);
        midLabel->setObjectName(QStringLiteral("midLabel"));

        gridLayout->addWidget(midLabel, 1, 2, 1, 1);

        reverbLabel = new QLabel(eqBox);
        reverbLabel->setObjectName(QStringLiteral("reverbLabel"));

        gridLayout->addWidget(reverbLabel, 1, 6, 1, 1);

        highLabel = new QLabel(eqBox);
        highLabel->setObjectName(QStringLiteral("highLabel"));

        gridLayout->addWidget(highLabel, 1, 4, 1, 1);

        lowFreqSlider = new QSlider(eqBox);
        lowFreqSlider->setObjectName(QStringLiteral("lowFreqSlider"));
        lowFreqSlider->setStyleSheet(QLatin1String("QSlider::groove:vertical {                                \n"
"     border: 1px solid #999999;                  \n"
"     height: 105px;                                           \n"
"     margin: 1px;                                         \n"
"     left: 8px; right:8px;\n"
"     bottom: 30px; top:30 px;\n"
" }                                                          \n"
"QSlider::handle:vertical {                                                \n"
"     border: 1px solid #5c5c5c;                \n"
"     border-image:url(../Resources/slider.png);\n"
"     width:20px;                                             \n"
"     margin: -10px -10px;                           \n"
" }\n"
"QSlider::add-page:vertical {\n"
"        background-color: rgb(37, 168, 198);\n"
"        width:4px;\n"
"}\n"
"QSlider::sub-page:vertical {\n"
"        background-color: rgb(87, 97, 106);\n"
"        width:4px;\n"
"}"));
        lowFreqSlider->setOrientation(Qt::Vertical);
        lowFreqSlider->setInvertedAppearance(true);
        lowFreqSlider->setInvertedControls(false);

        gridLayout->addWidget(lowFreqSlider, 0, 0, 1, 1);

        midhighFreqSlider = new QSlider(eqBox);
        midhighFreqSlider->setObjectName(QStringLiteral("midhighFreqSlider"));
        midhighFreqSlider->setStyleSheet(QLatin1String("QSlider::groove:vertical {                                \n"
"     border: 1px solid #999999;                  \n"
"     height: 105px;                                           \n"
"     margin: 1px;                                         \n"
"     left: 8px; right:8px;\n"
"     bottom: 30px; top:30 px;\n"
" }                                                          \n"
"QSlider::handle:vertical {                                                \n"
"     border: 1px solid #5c5c5c;                \n"
"     border-image:url(../Resources/slider.png);\n"
"     width:20px;                                             \n"
"     margin: -10px -10px;                           \n"
" }\n"
"QSlider::add-page:vertical {\n"
"        background-color: rgb(37, 168, 198);\n"
"        width:4px;\n"
"}\n"
"QSlider::sub-page:vertical {\n"
"        background-color: rgb(87, 97, 106);\n"
"        width:4px;\n"
"}"));
        midhighFreqSlider->setOrientation(Qt::Vertical);
        midhighFreqSlider->setInvertedAppearance(true);
        midhighFreqSlider->setInvertedControls(false);

        gridLayout->addWidget(midhighFreqSlider, 0, 3, 1, 1);

        lowmidFreqSlider = new QSlider(eqBox);
        lowmidFreqSlider->setObjectName(QStringLiteral("lowmidFreqSlider"));
        lowmidFreqSlider->setStyleSheet(QLatin1String("QSlider::groove:vertical {                                \n"
"     border: 1px solid #999999;                  \n"
"     height: 105px;                                           \n"
"     margin: 1px;                                         \n"
"     left: 8px; right:8px;\n"
"     bottom: 30px; top:30 px;\n"
" }                                                          \n"
"QSlider::handle:vertical {                                                \n"
"     border: 1px solid #5c5c5c;                \n"
"     border-image:url(../Resources/slider.png);\n"
"     width:20px;                                             \n"
"     margin: -10px -10px;                           \n"
" }\n"
"QSlider::add-page:vertical {\n"
"        background-color: rgb(37, 168, 198);\n"
"        width:4px;\n"
"}\n"
"QSlider::sub-page:vertical {\n"
"        background-color: rgb(87, 97, 106);\n"
"        width:4px;\n"
"}"));
        lowmidFreqSlider->setOrientation(Qt::Vertical);
        lowmidFreqSlider->setInvertedAppearance(true);
        lowmidFreqSlider->setInvertedControls(false);

        gridLayout->addWidget(lowmidFreqSlider, 0, 1, 1, 1);

        extremhighFreqSlider = new QSlider(eqBox);
        extremhighFreqSlider->setObjectName(QStringLiteral("extremhighFreqSlider"));
        extremhighFreqSlider->setStyleSheet(QLatin1String("QSlider::groove:vertical {                                \n"
"     border: 1px solid #999999;                  \n"
"     height: 105px;                                           \n"
"     margin: 1px;                                         \n"
"     left: 8px; right:8px;\n"
"     bottom: 30px; top:30 px;\n"
" }                                                          \n"
"QSlider::handle:vertical {                                                \n"
"     border: 1px solid #5c5c5c;                \n"
"     border-image:url(../Resources/slider.png);\n"
"     width:20px;                                             \n"
"     margin: -10px -10px;                           \n"
" }\n"
"QSlider::add-page:vertical {\n"
"        background-color: rgb(37, 168, 198);\n"
"        width:4px;\n"
"}\n"
"QSlider::sub-page:vertical {\n"
"        background-color: rgb(87, 97, 106);\n"
"        width:4px;\n"
"}"));
        extremhighFreqSlider->setOrientation(Qt::Vertical);
        extremhighFreqSlider->setInvertedAppearance(true);
        extremhighFreqSlider->setInvertedControls(false);

        gridLayout->addWidget(extremhighFreqSlider, 0, 5, 1, 1);

        lowmidLabel = new QLabel(eqBox);
        lowmidLabel->setObjectName(QStringLiteral("lowmidLabel"));

        gridLayout->addWidget(lowmidLabel, 1, 1, 1, 1);

        midhighLabel = new QLabel(eqBox);
        midhighLabel->setObjectName(QStringLiteral("midhighLabel"));

        gridLayout->addWidget(midhighLabel, 1, 3, 1, 1);

        extremhighLabel = new QLabel(eqBox);
        extremhighLabel->setObjectName(QStringLiteral("extremhighLabel"));

        gridLayout->addWidget(extremhighLabel, 1, 5, 1, 1);

        sqGroupBox = new QGroupBox(SoundEffectDialogClass);
        sqGroupBox->setObjectName(QStringLiteral("sqGroupBox"));
        sqGroupBox->setGeometry(QRect(300, 0, 141, 101));
        gridLayout_2 = new QGridLayout(sqGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        rotateRadioButton = new QRadioButton(sqGroupBox);
        rotateRadioButton->setObjectName(QStringLiteral("rotateRadioButton"));

        gridLayout_2->addWidget(rotateRadioButton, 0, 0, 1, 1);

        echoRadioButton = new QRadioButton(sqGroupBox);
        echoRadioButton->setObjectName(QStringLiteral("echoRadioButton"));

        gridLayout_2->addWidget(echoRadioButton, 1, 0, 1, 1);

        flangerRadioButton = new QRadioButton(sqGroupBox);
        flangerRadioButton->setObjectName(QStringLiteral("flangerRadioButton"));

        gridLayout_2->addWidget(flangerRadioButton, 2, 0, 1, 1);

        confirmPushBtn = new QPushButton(SoundEffectDialogClass);
        confirmPushBtn->setObjectName(QStringLiteral("confirmPushBtn"));
        confirmPushBtn->setGeometry(QRect(300, 150, 61, 31));
        cancelPushBtn = new QPushButton(SoundEffectDialogClass);
        cancelPushBtn->setObjectName(QStringLiteral("cancelPushBtn"));
        cancelPushBtn->setGeometry(QRect(380, 150, 61, 31));

        retranslateUi(SoundEffectDialogClass);

        QMetaObject::connectSlotsByName(SoundEffectDialogClass);
    } // setupUi

    void retranslateUi(QDialog *SoundEffectDialogClass)
    {
        SoundEffectDialogClass->setWindowTitle(QApplication::translate("SoundEffectDialogClass", "\351\237\263\346\225\210", 0));
        eqBox->setTitle(QApplication::translate("SoundEffectDialogClass", "\345\235\207\350\241\241\345\231\250", 0));
        lowLabel->setText(QApplication::translate("SoundEffectDialogClass", "125Hz", 0));
        midLabel->setText(QApplication::translate("SoundEffectDialogClass", "1KHz", 0));
        reverbLabel->setText(QApplication::translate("SoundEffectDialogClass", "\346\267\267\345\223\215", 0));
        highLabel->setText(QApplication::translate("SoundEffectDialogClass", "8KHz", 0));
        lowmidLabel->setText(QApplication::translate("SoundEffectDialogClass", "400Hz", 0));
        midhighLabel->setText(QApplication::translate("SoundEffectDialogClass", "3KHz", 0));
        extremhighLabel->setText(QApplication::translate("SoundEffectDialogClass", "12KHz", 0));
        sqGroupBox->setTitle(QApplication::translate("SoundEffectDialogClass", "DSP", 0));
        rotateRadioButton->setText(QApplication::translate("SoundEffectDialogClass", "\346\227\213\350\275\254", 0));
        echoRadioButton->setText(QApplication::translate("SoundEffectDialogClass", "\345\233\236\345\243\260", 0));
        flangerRadioButton->setText(QApplication::translate("SoundEffectDialogClass", "\351\243\230\345\277\275", 0));
        confirmPushBtn->setText(QApplication::translate("SoundEffectDialogClass", "\347\241\256\350\256\244", 0));
        cancelPushBtn->setText(QApplication::translate("SoundEffectDialogClass", "\351\207\215\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class SoundEffectDialogClass: public Ui_SoundEffectDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUNDEFFECTDIALOG_H
