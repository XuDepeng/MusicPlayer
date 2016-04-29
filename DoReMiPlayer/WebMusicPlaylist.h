#pragma once

#include <QPointer>
#include <QTableWidget>

class WebMusicPlaylist :public QTableWidget{
	Q_OBJECT
public:
	explicit WebMusicPlaylist(QWidget* parent = 0);

	void addRow(QString title, QString artist, QString album, QString ID);
	void addRows(QStringList titles, QStringList artists, QStringList albums, QStringList IDs);
signals:
	void sigPlayCurSong(int index);
	void sigAddCurSong(int index);
private:
	void createActions();
	void contextMenuEvent(QContextMenuEvent *e);

	QPointer<QAction> playSongAction;
	QPointer<QAction> addSongAction;

	QPointer<QMenu> m_popMenu;
	int m_curRow;

private slots:
	void slotPlayCurSong();
	void slotAddCurSong();
};