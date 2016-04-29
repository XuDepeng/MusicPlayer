#pragma once
#include <QList>
#include <QTime>

class MusicLyric{
public:
	MusicLyric();
	~MusicLyric();

	void readFromFile(QString lrcName);

	int getLineCount();
	int getCurIndex(QTime curPos);
	QString getLineAt(int index);
	
private:
	QString m_lrcName;

	QString m_title;
	QString m_artist;
	QString m_album;

	QList<QTime> m_time;
	QList<QString> m_lines;
};