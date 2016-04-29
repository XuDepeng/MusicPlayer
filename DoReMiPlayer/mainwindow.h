#ifndef DOREMIPLAYER_H
#define DOREMIPLAYER_H

#include <QtWidgets/QMainWindow>
#include <QPointer>
#include <QStringList>

#include "Common.h"
#include "MusicParser.h"
#include "MusicLyric.h"
#include "ui_doremiplayer.h"

class MusicPlayer;
class SouncEffectDialog;
class WebSearchDialog;
struct MusicInfo;
struct WebMusicInfo;

class DoReMiPlayer : public QMainWindow{
	Q_OBJECT

	enum PlayerState{ // player's state
		PLAY,
		PAUSE,
		STOP
	};

	enum SortMode{
		TITLE,
		ARTIST,
		ALBUM
	};

public:
	DoReMiPlayer(QWidget *parent = 0);
	~DoReMiPlayer();

protected:
	void dragEnterEvent(QDragEnterEvent *e);
	void dropEvent(QDropEvent *e);
	void closeEvent(QCloseEvent *e);
private:
	void createBar(); // create menu and toolbar
	void createButton(); // create play,pause,forward and backward btn
	void createSlider(); // create self-made slider
	void createPlayList(); // create play list
	void createPlayer(); // create music player
	void createSkin();

	void connectDB();
	void addLrc(QString lrcName);

	void checkNetState();
private slots:
	void addSong(WebMusicInfo);
	void addSongs(); // add songs
	void addPlaylist(); // add songlist
	void savePlayList();

	void searchPlaylist();
	void sortPlayList(SortMode mode);

	void playSong(int); // play the song
	void pauseSong(); // pause the song
	void playPreSong();
	void playNextSong();

	void deleteSong(int);

	void updateMediaPos(int curPos);
	void updateLrc(int curPos);

	void createTab();
	void createSoundEff();
	void createWebSearch();
private:
	PlayerState m_playState;
	bool m_isOnline;

	QStringList m_songPaths;
	QString m_curSongPath;
	int m_curIndex;
	QMap<QString, MusicInfo> m_map;

	QPointer<QAction> addSongAction;
	QPointer<QAction> addNetSongAction;
	QPointer<QAction> addPlaylistAction;
	QPointer<QAction> savePlaylistAction;
	QPointer<QAction> editTagAction;
	QPointer<QAction> confAction;
	QPointer<QAction> searchAction;
	QPointer<QAction> sortAction;
	QPointer<QAction> exitAction;

	QPointer<MusicPlayer> m_bassPlayer;
	MusicParser m_musicParser;

	MusicLyric m_musicLrc;
	bool m_isLrcLoaded;
	int m_lrcIndex;
	
	Ui::DoReMiPlayerClass ui;
	QString m_styleSheet;

	QPointer<SouncEffectDialog> m_soundEffDlg;
	QPointer<WebSearchDialog> m_webSearchDlg;
	QPointer<QPushButton> m_searchBtn;
	QPointer<QLineEdit> m_searchLnEdit;
};

#endif // DOREMIPLAYER_H
