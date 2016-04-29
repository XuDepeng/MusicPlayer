#include "WebSearchDialog.h"
#include "Common.h"

#include <QFile>
#include <QTextStream>
#include <QJsonDocument>

#include <QMenu>
#include <QMessageBox>
#include <QContextMenuEvent>

#include "NetParser.h"

WebSearchDialog* WebSearchDialog::m_instance = nullptr;

WebSearchDialog* WebSearchDialog::CreateWebSearch(){
	if (!m_instance){
		m_instance = new WebSearchDialog;
	}
	return m_instance;
}
void WebSearchDialog::DestroyWebSearch(WebSearchDialog* instance){
	if (instance){
		delete m_instance;
		m_instance = nullptr;
	}
}

WebSearchDialog::WebSearchDialog(QWidget* parent) :
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

	connect(ui.searchBtn, SIGNAL(clicked()), this, SLOT(searchWeb()));
	connect(ui.searchLnEdit, SIGNAL(returnPressed()), ui.searchBtn, SLOT(click()));
	connect(this, SIGNAL(searchFinished()), this, SLOT(showWebResults()));

	connect(ui.songTableWidget, SIGNAL(sigPlayCurSong(int)), this, SLOT(slotPlayCurSong(int)));
	connect(ui.songTableWidget, SIGNAL(sigAddCurSong(int)), this, SLOT(slotAddCurSong(int)));

	m_isSearching = false;
	m_target = QString::null;
}

void WebSearchDialog::searchWeb(){
	if (m_isSearching){
		return;
	}
	QString target = ui.searchLnEdit->text();
	if (target == m_target){
		return;
	}
	m_target = target;
	m_isSearching = true;

	m_tiList.clear();
	m_arList.clear();
	m_idlList.clear();
	ui.songTableWidget->clearContents();
	ui.songTableWidget->setRowCount(0);

	QString apiOfSuggestion =
		"http://sug.music.baidu.com/info/suggestion?format=json&word=%1&version=2&from=0";
	QJsonDocument idResult = NetParser::getJson(apiOfSuggestion.arg(target));
	if (!idResult.isObject()){
		return;
	}

	QJsonObject idObj = idResult.object();
	QJsonObject idDat = idObj["data"].toObject();
	QJsonArray songArr = idDat["song"].toArray();

	for (QJsonArray::ConstIterator iter = songArr.constBegin(); iter != songArr.constEnd(); ++iter){
		QJsonObject song = (*iter).toObject();
		m_tiList << song["songname"].toString();
		m_arList << song["artistname"].toString();
		QString songID = song["songid"].toString();
		const QString apiOfSongLink =
			"http://play.baidu.com/data/music/songinfo?songIds=%1";
		QJsonDocument alResult = NetParser::getJson(apiOfSongLink.arg(songID));
		QString album;
		if (!alResult.isObject()){
			album = QStringLiteral("未知");
			continue;;
		}

		QJsonObject alObj = alResult.object();
		QJsonObject alDat = alObj["data"].toObject();
		QJsonArray alArr = alDat["songList"].toArray();

		QJsonObject al = alArr.at(0).toObject();
		album= al["albumName"].toString();
		m_idlList << songID;

		ui.songTableWidget->addRow(m_tiList.last(), m_arList.last(), album,
			m_idlList.last());		
	}

	m_isSearching = false;
	emit searchFinished();
}

void WebSearchDialog::showWebResults(){
	QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("搜索完成！"));
}

void WebSearchDialog::slotPlayCurSong(int index){
	WebMusicInfo wmf;
	wmf.title = ui.songTableWidget->item(index, 0)->text();
	wmf.artist = ui.songTableWidget->item(index, 1)->text();
	wmf.album = ui.songTableWidget->item(index, 2)->text();

	const QString apiOfSongLink =
		"http://play.baidu.com/data/music/songlink?songIds=%1&type=m4a,mp3";
	QJsonDocument songlinkResult = NetParser::getJson(apiOfSongLink.arg(m_idlList.at(index)));
	if (!songlinkResult.isObject()){
		return;
	}

	QJsonObject songObj = songlinkResult.object();
	QJsonObject songDat = songObj["data"].toObject();
	QJsonArray songArr = songDat["songList"].toArray();

	QJsonObject song = songArr.at(0).toObject();
	QString songlink = song["songLink"].toString();
	if (songlink.isEmpty()){
		return;
	}

	QTime songDuration(0, 0, 0, 0);
	songDuration = songDuration.addSecs(song["time"].toInt());
	QString songTime=songDuration.toString("mm:ss");
	
	wmf.duration = songTime;
	wmf.songLink = songlink;

	emit sigPlayCurSong(wmf);
}

void WebSearchDialog::slotAddCurSong(int index){
	WebMusicInfo wmf;
	wmf.title = ui.songTableWidget->item(index, 0)->text();
	wmf.artist = ui.songTableWidget->item(index, 1)->text();
	wmf.album = ui.songTableWidget->item(index, 2)->text();

	const QString apiOfSongLink =
		"http://play.baidu.com/data/music/songlink?songIds=%1&type=m4a,mp3";
	QJsonDocument songlinkResult = NetParser::getJson(apiOfSongLink.arg(m_idlList.at(index)));
	if (!songlinkResult.isObject()){
		return;
	}

	QJsonObject songObj = songlinkResult.object();
	QJsonObject songDat = songObj["data"].toObject();
	QJsonArray songArr = songDat["songList"].toArray();

	QJsonObject song = songArr.at(0).toObject();
	QString songlink = song["songLink"].toString();
	if (songlink.isEmpty()){
		return;
	}

	QTime songDuration(0, 0, 0, 0);
	songDuration = songDuration.addSecs(song["time"].toInt());
	QString songTime = songDuration.toString("mm:ss");

	wmf.duration = songTime;
	wmf.songLink = songlink;

	emit sigAddCurSong(wmf);
}