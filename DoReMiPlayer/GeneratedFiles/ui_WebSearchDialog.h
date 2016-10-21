/********************************************************************************
** Form generated from reading UI file 'WebSearchDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBSEARCHDIALOG_H
#define UI_WEBSEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <webmusicplaylist.h>

QT_BEGIN_NAMESPACE

class Ui_WebSearchDialog
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *topLayout;
    QLineEdit *searchLnEdit;
    QPushButton *searchBtn;
    WebMusicPlaylist *songTableWidget;

    void setupUi(QDialog *WebSearchDialog)
    {
        if (WebSearchDialog->objectName().isEmpty())
            WebSearchDialog->setObjectName(QStringLiteral("WebSearchDialog"));
        WebSearchDialog->resize(600, 300);
        gridLayout_2 = new QGridLayout(WebSearchDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        topLayout = new QHBoxLayout();
        topLayout->setObjectName(QStringLiteral("topLayout"));
        searchLnEdit = new QLineEdit(WebSearchDialog);
        searchLnEdit->setObjectName(QStringLiteral("searchLnEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        searchLnEdit->setFont(font);

        topLayout->addWidget(searchLnEdit);

        searchBtn = new QPushButton(WebSearchDialog);
        searchBtn->setObjectName(QStringLiteral("searchBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchBtn->sizePolicy().hasHeightForWidth());
        searchBtn->setSizePolicy(sizePolicy);
        searchBtn->setFont(font);

        topLayout->addWidget(searchBtn);


        gridLayout_2->addLayout(topLayout, 0, 0, 1, 1);

        songTableWidget = new WebMusicPlaylist(WebSearchDialog);
        if (songTableWidget->columnCount() < 4)
            songTableWidget->setColumnCount(4);
        songTableWidget->setObjectName(QStringLiteral("songTableWidget"));
        songTableWidget->setFrameShape(QFrame::Box);
        songTableWidget->setShowGrid(false);
        songTableWidget->setSortingEnabled(false);
        songTableWidget->setColumnCount(4);
        songTableWidget->horizontalHeader()->setVisible(true);
        songTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        songTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        songTableWidget->horizontalHeader()->setStretchLastSection(false);
        songTableWidget->verticalHeader()->setVisible(false);

        gridLayout_2->addWidget(songTableWidget, 1, 0, 1, 1);


        retranslateUi(WebSearchDialog);

        QMetaObject::connectSlotsByName(WebSearchDialog);
    } // setupUi

    void retranslateUi(QDialog *WebSearchDialog)
    {
        WebSearchDialog->setWindowTitle(QApplication::translate("WebSearchDialog", "\346\220\234\347\264\242\347\275\221\347\273\234\346\255\214\346\233\262", 0));
        searchBtn->setText(QApplication::translate("WebSearchDialog", "\346\220\234\347\264\242", 0));
    } // retranslateUi

};

namespace Ui {
    class WebSearchDialog: public Ui_WebSearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBSEARCHDIALOG_H
