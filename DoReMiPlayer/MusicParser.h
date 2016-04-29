#pragma once

#include <QString>
#include <QThread>

namespace TagLib{
	class FileRef;
	class File;
}

class QPixmap;

class MusicParser:public QThread{
public:
	MusicParser(QObject* parent = 0);
	~MusicParser();

	void loadSong(const QString& songName);
	void unloadSong();

	QString getTitle();
	QString getArtist();
	QString getAlbum();
	QString getDuration();
	int getCover(QPixmap& cover);

	QString getBrief(QString al); // !!need net
	bool getLrc(QString ar, QString ti);
private:
	QString m_name;
	bool m_isLocalSong;
	TagLib::File* m_fileRef;
};