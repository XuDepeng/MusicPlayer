#pragma once

#include <QPointer>
#include <QTableWidget>

class MusicPlaylist :public QTableWidget{
	Q_OBJECT
public:
	explicit MusicPlaylist(QWidget* parent=0);

	void addRow(QString title, QString artist, QString duration);
	void addRows(QStringList title, QStringList artist, QStringList duration);

signals:
	void sigPlayCurSong(int index);
	void sigPauseCurSong(int index);
	void sigDeleteCurSong(int index);

	void sigViewCurSong(int index);
private:
	void createActions();
	void contextMenuEvent(QContextMenuEvent *e);

	QPointer<QAction> playSongAction;
	QPointer<QAction> pauseSongAction;
	QPointer<QAction> deleteSongAction;
	QPointer<QAction> viewSongTagAction;

	QPointer<QMenu> m_popMenu;
	int m_curRow;

private slots:
	void slotPlayCurSong();
	void slotPauseCurSong();
	void slotDeleteCurSong();

	void slotViewCurSong();
};