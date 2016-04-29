#pragma once
#include <QDialog>
#include "ui_WebSearchDialog.h"
#include "Common.h"

class WebSearchDialog :public QDialog{
	Q_OBJECT	
public:
	static WebSearchDialog* CreateWebSearch();
	static void DestroyWebSearch(WebSearchDialog*);

private:
	Ui::WebSearchDialog ui;
	static WebSearchDialog *m_instance;

	bool m_isSearching;
	QString m_target;

	QStringList m_tiList;
	QStringList m_arList;
	QStringList m_idlList;

	WebSearchDialog(QWidget* parent = 0);
	WebSearchDialog(const WebSearchDialog&)Q_DECL_EQ_DELETE;
	WebSearchDialog operator =(const WebSearchDialog&)Q_DECL_EQ_DELETE;
private slots :
	void searchWeb();
	void showWebResults();

	void slotPlayCurSong(int index);
	void slotAddCurSong(int index);
signals:
	void searchFinished();

	void sigPlayCurSong(WebMusicInfo);
	void sigAddCurSong(WebMusicInfo);


};