/********************************************************************************
** Form generated from reading UI file 'doremiplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOREMIPLAYER_H
#define UI_DOREMIPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MusicPlaylist.h"

QT_BEGIN_NAMESPACE

class Ui_DoReMiPlayerClass
{
public:
    QWidget *centralWidget;
    QWidget *gridWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    MusicPlaylist *playlistTableWidget;
    QSlider *processSlider;
    QGridLayout *gridLayout;
    QSpacerItem *rHorizontalSpacer;
    QLabel *coverLabel;
    QPushButton *backPushBtn;
    QPushButton *playPushBtn;
    QSpacerItem *lHorizontalSpacer;
    QPushButton *forwardPushBtn;
    QSlider *volumeSlider;
    QLabel *speakerLabel;
    QSpacerItem *lhorizontalSpacerII;
    QTabWidget *appendixTabWidget;
    QWidget *albumInfoTab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *albumInfoLayout;
    QTextEdit *albumInfoTextEdit;
    QWidget *songLrcTab;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *lrcLayout;
    QTableWidget *lrcTableWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DoReMiPlayerClass)
    {
        if (DoReMiPlayerClass->objectName().isEmpty())
            DoReMiPlayerClass->setObjectName(QStringLiteral("DoReMiPlayerClass"));
        DoReMiPlayerClass->resize(600, 641);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DoReMiPlayerClass->sizePolicy().hasHeightForWidth());
        DoReMiPlayerClass->setSizePolicy(sizePolicy);
        DoReMiPlayerClass->setFocusPolicy(Qt::ClickFocus);
        centralWidget = new QWidget(DoReMiPlayerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridWidget = new QWidget(centralWidget);
        gridWidget->setObjectName(QStringLiteral("gridWidget"));
        gridWidget->setGeometry(QRect(-10, -10, 611, 601));
        verticalLayout_2 = new QVBoxLayout(gridWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        playlistTableWidget = new MusicPlaylist(gridWidget);
        playlistTableWidget->setObjectName(QStringLiteral("playlistTableWidget"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        playlistTableWidget->setPalette(palette);
        playlistTableWidget->setFocusPolicy(Qt::NoFocus);
        playlistTableWidget->setFrameShape(QFrame::Box);
        playlistTableWidget->setFrameShadow(QFrame::Sunken);
        playlistTableWidget->setDragEnabled(true);
        playlistTableWidget->setDragDropMode(QAbstractItemView::NoDragDrop);
        playlistTableWidget->setDefaultDropAction(Qt::IgnoreAction);
        playlistTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        playlistTableWidget->setShowGrid(false);
        playlistTableWidget->setSortingEnabled(false);
        playlistTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        playlistTableWidget->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(playlistTableWidget);

        processSlider = new QSlider(gridWidget);
        processSlider->setObjectName(QStringLiteral("processSlider"));
        processSlider->setAutoFillBackground(true);
        processSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal {                                \n"
"     border: 1px solid #999999;                  \n"
"     height: 1px;                                           \n"
"     margin: 1px;                                         \n"
"     left: 8px; right:8px;                               \n"
" }                                                          \n"
"QSlider::handle:horizontal {                                                \n"
"     border: 1px solid #5c5c5c;                \n"
"     border-image:url(../Resources/slider.png);\n"
"     width:20px;                                             \n"
"     margin: -10px -10px -10px -10px;                                           \n"
" }\n"
"QSlider::add-page:horizontal {\n"
"        background-color: rgb(87, 97, 106);\n"
"        width:4px;\n"
"}\n"
"QSlider::sub-page:horizontal {\n"
"        background-color: rgb(37, 168, 198);\n"
"        width:4px;\n"
"}"));
        processSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(processSlider);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        rHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(rHorizontalSpacer, 0, 6, 1, 1);

        coverLabel = new QLabel(gridWidget);
        coverLabel->setObjectName(QStringLiteral("coverLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(coverLabel->sizePolicy().hasHeightForWidth());
        coverLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(coverLabel, 0, 0, 1, 1);

        backPushBtn = new QPushButton(gridWidget);
        backPushBtn->setObjectName(QStringLiteral("backPushBtn"));
        backPushBtn->setStyleSheet(QLatin1String("     border-width: 1px;\n"
"     border-style: none;\n"
"     border-color: rgb(255, 170, 0);\n"
""));
        backPushBtn->setIconSize(QSize(40, 40));
        backPushBtn->setFlat(true);

        gridLayout->addWidget(backPushBtn, 0, 3, 1, 1);

        playPushBtn = new QPushButton(gridWidget);
        playPushBtn->setObjectName(QStringLiteral("playPushBtn"));
        playPushBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"border:none;\n"
"}\n"
"QPushButton:hover{\n"
"color:lightgray;\n"
"}\n"
"QPushButton:pressed{\n"
"color:lightgray;\n"
"padding-top:-15px;\n"
"padding-bottom:-17px;\n"
"}"));
        playPushBtn->setIconSize(QSize(50, 50));
        playPushBtn->setFlat(true);

        gridLayout->addWidget(playPushBtn, 0, 4, 1, 1);

        lHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(lHorizontalSpacer, 0, 1, 1, 1);

        forwardPushBtn = new QPushButton(gridWidget);
        forwardPushBtn->setObjectName(QStringLiteral("forwardPushBtn"));
        forwardPushBtn->setStyleSheet(QLatin1String("     border-width: 1px;\n"
"     border-style: none;\n"
"     border-color: rgb(255, 170, 0);\n"
""));
        forwardPushBtn->setIconSize(QSize(40, 36));
        forwardPushBtn->setFlat(true);

        gridLayout->addWidget(forwardPushBtn, 0, 5, 1, 1);

        volumeSlider = new QSlider(gridWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(volumeSlider->sizePolicy().hasHeightForWidth());
        volumeSlider->setSizePolicy(sizePolicy2);
        volumeSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal {                                \n"
"     border: 1px solid #999999;                  \n"
"     height: 1px;                                           \n"
"     margin: 1px;                                         \n"
"     left: 8px; right:8px;                               \n"
" }                                                          \n"
"QSlider::handle:horizontal {                                                \n"
"     border: 1px solid #5c5c5c;                \n"
"     border-image:url(../Resources/slider.png);\n"
"     width:20px;                                             \n"
"     margin: -10px -10px -10px -10px;                           \n"
" }\n"
"QSlider::add-page:horizontal {\n"
"        background-color: rgb(87, 97, 106);\n"
"        width:4px;\n"
"}\n"
"QSlider::sub-page:horizontal {\n"
"        background-color: rgb(37, 168, 198);\n"
"        width:4px;\n"
"     }"));
        volumeSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(volumeSlider, 0, 8, 1, 1);

        speakerLabel = new QLabel(gridWidget);
        speakerLabel->setObjectName(QStringLiteral("speakerLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(speakerLabel->sizePolicy().hasHeightForWidth());
        speakerLabel->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(speakerLabel, 0, 7, 1, 1);

        lhorizontalSpacerII = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(lhorizontalSpacerII, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        appendixTabWidget = new QTabWidget(gridWidget);
        appendixTabWidget->setObjectName(QStringLiteral("appendixTabWidget"));
        appendixTabWidget->setMaximumSize(QSize(16777215, 225));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        appendixTabWidget->setFont(font);
        appendixTabWidget->setTabPosition(QTabWidget::East);
        appendixTabWidget->setTabShape(QTabWidget::Triangular);
        appendixTabWidget->setElideMode(Qt::ElideNone);
        albumInfoTab = new QWidget();
        albumInfoTab->setObjectName(QStringLiteral("albumInfoTab"));
        verticalLayoutWidget = new QWidget(albumInfoTab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, -1, 561, 261));
        albumInfoLayout = new QVBoxLayout(verticalLayoutWidget);
        albumInfoLayout->setSpacing(6);
        albumInfoLayout->setContentsMargins(11, 11, 11, 11);
        albumInfoLayout->setObjectName(QStringLiteral("albumInfoLayout"));
        albumInfoLayout->setContentsMargins(0, 0, 0, 0);
        albumInfoTextEdit = new QTextEdit(verticalLayoutWidget);
        albumInfoTextEdit->setObjectName(QStringLiteral("albumInfoTextEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(albumInfoTextEdit->sizePolicy().hasHeightForWidth());
        albumInfoTextEdit->setSizePolicy(sizePolicy4);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        font1.setUnderline(false);
        albumInfoTextEdit->setFont(font1);
        albumInfoTextEdit->setFrameShape(QFrame::NoFrame);
        albumInfoTextEdit->setReadOnly(true);

        albumInfoLayout->addWidget(albumInfoTextEdit);

        appendixTabWidget->addTab(albumInfoTab, QString());
        songLrcTab = new QWidget();
        songLrcTab->setObjectName(QStringLiteral("songLrcTab"));
        verticalLayoutWidget_2 = new QWidget(songLrcTab);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(-1, -1, 561, 221));
        lrcLayout = new QVBoxLayout(verticalLayoutWidget_2);
        lrcLayout->setSpacing(6);
        lrcLayout->setContentsMargins(11, 11, 11, 11);
        lrcLayout->setObjectName(QStringLiteral("lrcLayout"));
        lrcLayout->setContentsMargins(0, 0, 0, 0);
        lrcTableWidget = new QTableWidget(verticalLayoutWidget_2);
        lrcTableWidget->setObjectName(QStringLiteral("lrcTableWidget"));
        lrcTableWidget->setFrameShape(QFrame::NoFrame);

        lrcLayout->addWidget(lrcTableWidget);

        appendixTabWidget->addTab(songLrcTab, QString());

        verticalLayout->addWidget(appendixTabWidget);


        verticalLayout_2->addLayout(verticalLayout);

        DoReMiPlayerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DoReMiPlayerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        DoReMiPlayerClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(DoReMiPlayerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setAutoFillBackground(true);
        DoReMiPlayerClass->setStatusBar(statusBar);

        retranslateUi(DoReMiPlayerClass);

        appendixTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DoReMiPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *DoReMiPlayerClass)
    {
        DoReMiPlayerClass->setWindowTitle(QApplication::translate("DoReMiPlayerClass", "DoReMiPlayer", 0));
        coverLabel->setText(QString());
        backPushBtn->setText(QString());
        playPushBtn->setText(QString());
        forwardPushBtn->setText(QString());
        speakerLabel->setText(QString());
        appendixTabWidget->setTabText(appendixTabWidget->indexOf(albumInfoTab), QApplication::translate("DoReMiPlayerClass", "\347\256\200\344\273\213", 0));
        appendixTabWidget->setTabText(appendixTabWidget->indexOf(songLrcTab), QApplication::translate("DoReMiPlayerClass", "\346\255\214\350\257\215", 0));
#ifndef QT_NO_TOOLTIP
        statusBar->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        statusBar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class DoReMiPlayerClass: public Ui_DoReMiPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOREMIPLAYER_H
