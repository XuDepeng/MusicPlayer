#include "MusicParser.h"

#include <QPixmap>
#include <QTime>

#include <taglib/tag.h>
#include <taglib/tfile.h>
#include <taglib/fileref.h>
#include <taglib/tpropertymap.h>

#include <taglib/tbytevector.h>
#include <taglib/attachedpictureframe.h>

#include <taglib/id3v2tag.h>
#include <taglib/mpegfile.h>
#include <taglib/id3v2frame.h>

#include "NetParser.h"

MusicParser::MusicParser(QObject* parent) :
QThread(parent){
	m_fileRef = nullptr;
}

MusicParser::~MusicParser(){
	if (m_fileRef){
		delete m_fileRef;
		m_fileRef = nullptr;
	}
}

void MusicParser::loadSong(const QString& songName){
	m_name = songName;
	if (songName.startsWith("http")){
		m_isLocalSong = false;
	}
	m_isLocalSong = true;


	m_fileRef = TagLib::FileRef::create(m_name.toLocal8Bit().constData());
}

void MusicParser::unloadSong(){
	if (m_fileRef){
		delete m_fileRef;
		m_fileRef = nullptr;
	}
}

QString MusicParser::getTitle(){
	if (!m_fileRef->tag()){
		return QString::fromUtf8("未知");
	}

	TagLib::String songTitle = m_fileRef->tag()->title();
	QString title = QString::fromStdWString(songTitle.toCWString());

	return title;
}

QString MusicParser::getArtist(){
	if (!m_fileRef->tag()){
		return QString::fromUtf8("未知");
	}

	TagLib::String songArtist = m_fileRef->tag()->artist();
	QString artist = QString::fromStdWString(songArtist.toCWString());
	
	return artist;
}

QString MusicParser::getAlbum(){
	if (!m_fileRef->tag()) {		
		return QString::fromUtf8("未知");
	}


	TagLib::String songAlbum = m_fileRef->tag()->album();
	QString album = QString::fromStdWString(songAlbum.toCWString());
	
	return album;
}

QString MusicParser::getDuration(){
	//if (!m_isLocalSong){
	//	const QString apiOfSongLink =
	//		"http://play.baidu.com/data/music/songlink?songIds=%1&type=m4a,mp3";
	//	QJsonDocument alResult = NetParser::getJson(apiOfSongLink.arg(songID));
	//	if (!alResult.isObject()){
	//		return QString::fromUtf8("未知");
	//	}

	//	QJsonObject duObj = alResult.object();
	//	QJsonObject duDat = duObj["data"].toObject();
	//	QJsonArray duArr = duDat["songList"].toArray();

	//	QJsonObject du = duArr.at(0).toObject();
	//	QTime songDuration(0, 0, 0, 0);
	//	songDuration = songDuration.addSecs(du["time"].toInt());
	//	return songDuration.toString("mm:ss");
	//}

	if (!m_fileRef->audioProperties()){
		return QString::fromUtf8("未知");
	}

	TagLib::AudioProperties *properties = m_fileRef->audioProperties();
	QTime songDuration(0, 0, 0, 0);
	songDuration = songDuration.addSecs(properties->length());
	return songDuration.toString("mm:ss");

}

int MusicParser::getCover(QPixmap& cover){
	static const char *IdPicture = "APIC";
	if (!m_fileRef){
		return 0;
	}
	TagLib::MPEG::File* mpegFile = dynamic_cast<TagLib::MPEG::File*>(m_fileRef);
	TagLib::ID3v2::Tag *id3v2tag = mpegFile->ID3v2Tag();

	if (id3v2tag){
		// picture frame
		TagLib::ID3v2::FrameList Frame;
		TagLib::ID3v2::AttachedPictureFrame *PicFrame;
		Frame = id3v2tag->frameListMap()[IdPicture];
		if (!Frame.isEmpty()){
			for (TagLib::ID3v2::FrameList::ConstIterator it = Frame.begin(); it != Frame.end(); ++it){
				PicFrame = (TagLib::ID3v2::AttachedPictureFrame *)(*it);
				// extract image (in it's compressed form)
				cover.loadFromData((uchar*)PicFrame->picture().data(), PicFrame->picture().size());
				return 1;
			}
		}
	}
	return 0;
}

QString MusicParser::getBrief(QString al){
	QString baseQuery = "http://api.douban.com/music/subjects?";
	QString album = al.remove("同名专辑");
	QString tagQuery = "tag=" + album;
	tagQuery.remove(' ');
	QString completeQuery = baseQuery + tagQuery + "&start-index=1&max-results=1";

	QDomDocument doc = NetParser::getXml(completeQuery);
	QDomElement ele = doc.documentElement();

	QString albumUrl;
	QDomNode n = ele.firstChild();
	while (!n.isNull()){
		QDomElement e = n.toElement();
		if (!e.isNull()){
			if (e.tagName()=="entry"){
				QDomNode entryNode = e.firstChild();
				while (!entryNode.isNull()){
					QDomElement entryEle = entryNode.toElement();
					if (entryEle.tagName() == "link"){
						albumUrl = entryEle.attribute("href");
						break;
					}
					entryNode = entryNode.nextSibling();
				}
				break;
			}
		}
		n = n.nextSibling();
	}

	QDomDocument albumDoc = NetParser::getXml(albumUrl);

	QString summary;
	QDomNode albumNode = albumDoc.firstChild();
	while (!albumNode.isNull()){
		QDomElement albumEle = albumNode.toElement();
		if (albumEle.tagName()=="entry"){
			QDomNode entryNode = albumEle.firstChild();
			while (!entryNode.isNull()){
				QDomElement entryEle = entryNode.toElement();
				if (entryEle.tagName() == "summary"){
					summary = entryEle.text();
					break;
				}
				entryNode = entryNode.nextSibling();
			}
			break;
		}
		albumNode = albumNode.nextSibling();
	}
	summary = "    " + summary.replace("\n", "\n    ");
	return summary;
}

bool MusicParser::getLrc(QString ar,QString ti){
	// check if lyric exists
	QString lrcName = "../data/" + ar+ "-" + ti + ".lrc";
	if (QFile::exists(lrcName)){
		return true;
	}

	QString apiOfSuggestion = 
		"http://sug.music.baidu.com/info/suggestion?format=json&word=%1&version=2&from=0";
	QJsonDocument idResult = NetParser::getJson(apiOfSuggestion.arg(ti));
	if (!idResult.isObject()){
		return false;
	}

	QJsonObject idObj = idResult.object();
	QJsonObject idDat = idObj["data"].toObject();
	QJsonArray songArr = idDat["song"].toArray();

	QString songID;
	for (QJsonArray::ConstIterator iter = songArr.constBegin(); iter != songArr.constEnd(); ++iter){
		QJsonObject song = (*iter).toObject();
		QString title = song["songname"].toString();
		QString artist = song["artistname"].toString();
		if ((title.compare(ti,Qt::CaseInsensitive)>=0)&&
			(artist.compare(ar, Qt::CaseInsensitive))>=0){
			songID = song["songid"].toString();
			break;
		}
	}

	const QString apiOfSongLink = 
		"http://play.baidu.com/data/music/songlink?songIds=%1&type=m4a,mp3";
	QJsonDocument lrclinkResult = NetParser::getJson(apiOfSongLink.arg(songID));
	if (!lrclinkResult.isObject()){
		return false;
	}

	QJsonObject lrcObj=lrclinkResult.object();
	QJsonObject lrcDat=lrcObj["data"].toObject();
	QJsonArray lrcArr=lrcDat["songList"].toArray();

	QJsonObject lrc=lrcArr.at(0).toObject();
	QString lrclink=lrc["lrcLink"].toString();
	if (lrclink.isEmpty()){
		return false;
	}
	NetParser::downloadLrc(lrclink, lrcName);

	return true;
}
