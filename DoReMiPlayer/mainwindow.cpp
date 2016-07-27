#include "mainwindow.h"

#include <QPixmap>
#include <QBitmap>
#include <QTime>

#include <QLineEdit>
#include <QHBoxLayout>

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTableWidgetItem>

#include <QDragEnterEvent>
#include <QMimeData>

#include <QNetworkConfigurationManager>

#include <QDebug>

#include "MusicPlayer.h"
#include "MusicDatabase.h"
#include "MusicLyric.h"

#include "MusicPlaylist.h"
#include "SoundEffectDialog.h"
#include "WebSearchDialog.h"


DoReMiPlayer::DoReMiPlayer(QWidget *parent)
: QMainWindow(parent){
	m_playState = STOP;
	m_isOnline = false;
	m_curIndex = -1;

	resize(600, 450);
	setMinimumWidth(400);
	ui.setupUi(this);

	QIcon ico("../Resources/player.png");
	setWindowIcon(ico);
	setWindowTitle(QStringLiteral("大脸鹿音乐播放器"));

#if 0
	//set background color
	QPalette palette;
	palette.setBrush(this->backgroundRole(), QBrush(QColor(51, 51, 51)));
	setPalette(palette);
	setAutoFillBackground(true);
#endif

	setCentralWidget(ui.gridWidget);
	setAcceptDrops(true); // catch drops	

	createSkin();
	createBar();
	createButton();
	createPlayList();
	createSlider();
	createTab();

	createPlayer();

	connectDB();
	checkNetState();

	connect(ui.playlistTableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(playSong(int)));
	connect(ui.playlistTableWidget, SIGNAL(sigDeleteCurSong(int)), this, SLOT(deleteSong(int)));
	connect(ui.playlistTableWidget, SIGNAL(sigPlayCurSong(int)), this, SLOT(playSong(int)));
	connect(ui.playlistTableWidget, SIGNAL(sigPauseCurSong(int)), this, SLOT(pauseSong()));

	connect(ui.playPushBtn, SIGNAL(clicked()), this, SLOT(pauseSong()));
	connect(ui.backPushBtn, SIGNAL(clicked()), this, SLOT(playPreSong()));
	connect(ui.forwardPushBtn, SIGNAL(clicked()), this, SLOT(playNextSong()));

	connect(ui.processSlider, SIGNAL(sliderMoved(int)), this, SLOT(updateMediaPos(int)));
	connect(ui.volumeSlider, SIGNAL(sliderMoved(int)), this->m_bassPlayer, SLOT(setVolume(int)));

	connect(m_bassPlayer, SIGNAL(positionChanged(int)), ui.processSlider, SLOT(setValue(int)));
	connect(m_bassPlayer, SIGNAL(positionChanged(int)), this, SLOT(updateLrc(int)));
	connect(m_bassPlayer, SIGNAL(songFinished()), this, SLOT(playNextSong()));
}

DoReMiPlayer::~DoReMiPlayer(){
}

void DoReMiPlayer::createSkin(){
	// default: dark metal style
	QFile f("../qdarkstyle/style.qss");
	if (!f.exists()){
		return;
	}
	else{
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		setStyleSheet(ts.readAll());
	}
}

void DoReMiPlayer::createBar(){
	// file menu
	addSongAction = new QAction(QIcon("../Resources/music.png"), QStringLiteral("添加本地歌曲"), this);
	addSongAction->setShortcut(tr("ctrl+o"));
	connect(addSongAction, SIGNAL(triggered(bool)), this, SLOT(addSongs()));
	QPointer<QMenu> file = ui.menuBar->addMenu(QStringLiteral("文件"));
	file->addAction(addSongAction);

	addNetSongAction = new QAction(QIcon("../Resources/net.png"), QStringLiteral("添加网络歌曲"), this);
	addNetSongAction->setShortcut(tr("ctrl+shift+o"));
	connect(addNetSongAction, SIGNAL(triggered(bool)), this, SLOT(createWebSearch()));
	file->addAction(addNetSongAction);

	addPlaylistAction = new QAction(QIcon("../Resources/playlist.png"), QStringLiteral("添加本地歌单"), this);
	addPlaylistAction->setShortcut(tr("ctrl+p"));
	connect(addPlaylistAction, SIGNAL(triggered(bool)), this, SLOT(addPlaylist()));
	file->addAction(addPlaylistAction);

	savePlaylistAction = new QAction(QIcon("../Resources/saveplaylist.png"), QStringLiteral("保存本地歌单"), this);
	savePlaylistAction->setShortcut(tr("shift+ctrl+s"));
	connect(savePlaylistAction, SIGNAL(triggered(bool)), this, SLOT(savePlayList()));
	file->addAction(savePlaylistAction);

	exitAction = new QAction(QIcon("../Resources/close.png"), QStringLiteral("退出"), this);
	exitAction->setShortcut(tr("ctrl+shift+c"));
	connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(close()));
	file->addAction(exitAction);

	// editor menu
	editTagAction = new QAction(QIcon("../Resources/editor.png"), QStringLiteral("Tag"), this);
	editTagAction->setShortcut(tr("ctrl+e"));
	QPointer<QMenu> editor = ui.menuBar->addMenu(QStringLiteral("编辑"));
	editor->addAction(editTagAction);

	searchAction = new QAction(QIcon("../Resources/search.png"), QStringLiteral("搜索"), this);
	searchAction->setShortcut(tr("ctrl+s"));
	editor->addAction(searchAction);

	sortAction = new QAction(QIcon("../Resources/sort.png"), QStringLiteral("整理"), this);
	sortAction->setShortcut(tr("ctrl+t"));
	editor->addAction(sortAction);

	// configuration menu
	confAction = new QAction(QIcon("../Resources/eq.png"), QStringLiteral("音效"), this);
	confAction->setShortcut(tr("ctrl+c"));
	QPointer<QMenu> conf = ui.menuBar->addMenu(QStringLiteral("设置"));
	connect(confAction, SIGNAL(triggered(bool)), this, SLOT(createSoundEff()));
	conf->addAction(confAction);

	// help menu
	ui.menuBar->addMenu(QStringLiteral("帮助"));

	QPointer<QWidget> searchWidget = new QWidget(ui.menuBar);
	QPointer<QHBoxLayout> searchLayout = new QHBoxLayout;
	m_searchLnEdit = new QLineEdit(searchWidget);
	m_searchBtn = new QPushButton(QStringLiteral("搜索"), searchWidget);
	m_searchBtn->setFixedHeight(24);
	m_searchBtn->setFlat(true);
	QFont font;
	font.setFamily(QStringLiteral("微软雅黑"));
	m_searchBtn->setFont(font);
	m_searchLnEdit->setFont(font);
	searchLayout->addWidget(m_searchLnEdit);
	searchLayout->addWidget(m_searchBtn);
	searchLayout->setContentsMargins(0, 4, 12, 0);
	searchWidget->setLayout(searchLayout);
	ui.menuBar->setCornerWidget(searchWidget, Qt::TopRightCorner);

	connect(m_searchLnEdit, SIGNAL(returnPressed()), m_searchBtn, SLOT(click()));
	connect(m_searchBtn, SIGNAL(clicked()), this, SLOT(searchPlaylist()));
}

void DoReMiPlayer::createButton(){
	QPixmap pixmap("../Resources/play.png");
	ui.playPushBtn->setFlat(true);
	ui.playPushBtn->setIcon(pixmap);
	ui.playPushBtn->setDisabled(true);

	QPixmap forwardPm("../Resources/forward.png");
	ui.forwardPushBtn->setFlat(true);
	ui.forwardPushBtn->setIcon(forwardPm);
	ui.forwardPushBtn->setDisabled(true);

	QPixmap backPm("../Resources/backward.png");
	ui.backPushBtn->setFlat(true);
	ui.backPushBtn->setIcon(backPm);
	ui.backPushBtn->setDisabled(true);

	QPixmap coverImg("../Resources/imusic.png");
	ui.coverLabel->setPixmap(coverImg.scaledToWidth(64, Qt::SmoothTransformation));

	QPixmap speakerImg("../Resources/speaker.png");
	ui.speakerLabel->setPixmap(speakerImg.scaledToWidth(42, Qt::SmoothTransformation));
}

void DoReMiPlayer::createSlider(){
	// ui file
	ui.volumeSlider->setRange(0, 100);
	ui.volumeSlider->setValue(30);

	ui.processSlider->setDisabled(true);

	//ui.processSlider->setSingleStep(100);
	//ui.processSlider->setTickInterval(100);
}

void DoReMiPlayer::createPlayList(){
	// ui file
	ui.playlistTableWidget->setAcceptDrops(false);
}

void DoReMiPlayer::searchPlaylist(){
	ui.playlistTableWidget->clearSelection();
	ui.playlistTableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	QString target = m_searchLnEdit->text();
	int nSong = m_songPaths.count();
	for (size_t i = 0; i < nSong;++i){
		QString title = ui.playlistTableWidget->item(i, 0)->text();
		QString artist = ui.playlistTableWidget->item(i, 1)->text();

		if (title.contains(target)||artist.contains(target)){
			ui.playlistTableWidget->selectRow(i);
		}
	}
	ui.playlistTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}

void DoReMiPlayer::sortPlayList(SortMode mode){
	return;
}

void DoReMiPlayer::createTab(){
	ui.albumInfoTab->setLayout(ui.albumInfoLayout);
	ui.songLrcTab->setLayout(ui.lrcLayout);

	ui.albumInfoTextEdit->setReadOnly(true);
	ui.albumInfoTextEdit->show();

	ui.lrcTableWidget->verticalHeader()->hide();
	ui.lrcTableWidget->horizontalHeader()->hide();
	ui.lrcTableWidget->horizontalHeader()->setStretchLastSection(true);
	ui.lrcTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	ui.lrcTableWidget->setColumnCount(1);
	ui.lrcTableWidget->setShowGrid(false);
	ui.lrcTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

	m_isLrcLoaded = false;
	m_lrcIndex = -1;
}

void DoReMiPlayer::createSoundEff(){
	if (!m_soundEffDlg){
		m_soundEffDlg = SouncEffectDialog::CreateSoundEffect();

		connect(m_soundEffDlg, SIGNAL(lowFreqChanged(int)), m_bassPlayer, SLOT(setLowFreq(int)));
		connect(m_soundEffDlg, SIGNAL(midFreqChanged(int)), m_bassPlayer, SLOT(setMidFreq(int)));
		connect(m_soundEffDlg, SIGNAL(highFreqChanged(int)), m_bassPlayer, SLOT(setHighFreq(int)));

		connect(m_soundEffDlg, SIGNAL(lowmidFreqChanged(int)), m_bassPlayer, SLOT(setLowmidFreq(int)));
		connect(m_soundEffDlg, SIGNAL(midhighFreqChanged(int)), m_bassPlayer, SLOT(setMidhighFreq(int)));
		connect(m_soundEffDlg, SIGNAL(extremhighFreqChanged(int)), m_bassPlayer, SLOT(setExtremhighFreq(int)));

		connect(m_soundEffDlg, SIGNAL(reverbChanged(int)), m_bassPlayer, SLOT(setReverb(int)));

		connect(m_soundEffDlg, SIGNAL(echoChanged(bool)), m_bassPlayer, SLOT(setEcho(bool)));
		connect(m_soundEffDlg, SIGNAL(rotateChanged(bool)), m_bassPlayer, SLOT(setRotate(bool)));
		connect(m_soundEffDlg, SIGNAL(flangerChanged(bool)), m_bassPlayer, SLOT(setFlanger(bool)));
	}

	if (m_playState != PLAY){
		m_soundEffDlg->setDisabled(true);
	}
	else{
		m_soundEffDlg->setEnabled(true);
	}
	m_soundEffDlg->show();
}

void DoReMiPlayer::createWebSearch(){
	if (!m_webSearchDlg){
		m_webSearchDlg = WebSearchDialog::CreateWebSearch();

		connect(m_webSearchDlg, SIGNAL(sigPlayCurSong(WebMusicInfo)), this, SLOT(addSong(WebMusicInfo)));
		//connect(m_webSearchDlg, SIGNAL(sigAddCurSong(WebMusicInfo)), this, SLOT(addSong(WebMusicInfo)));
	}

	m_webSearchDlg->setModal(true);
	m_webSearchDlg->show();
}

void DoReMiPlayer::createPlayer(){
	m_bassPlayer = new MusicPlayer(this);
	if (m_bassPlayer){
		m_bassPlayer->setVolume(30);
	}
}

void DoReMiPlayer::connectDB(){
	MusicDatabase* mdb = MusicDatabase::CreateInstance();
	m_songPaths = mdb->getSongList();

	// update music table
	for (size_t i = 0; i < m_songPaths.count(); ++i){
		// use taglib, need to add zlib dependency
		MusicInfo musicInfo;
		m_musicParser.loadSong(m_songPaths.at(i));

		musicInfo.title = m_musicParser.getTitle();
		musicInfo.artist = m_musicParser.getArtist();
		musicInfo.duration = m_musicParser.getDuration();
		musicInfo.album = m_musicParser.getAlbum();
		m_map.insert(m_songPaths.at(i), musicInfo);

		m_musicParser.unloadSong();

		ui.playlistTableWidget->addRow(musicInfo.title, musicInfo.artist, musicInfo.duration);
	}

	MusicDatabase::DestroyInstance(mdb);

	if (m_songPaths.count()){
		if (m_bassPlayer){
			ui.playPushBtn->setEnabled(true);
		}
	}
}

void DoReMiPlayer::addLrc(QString lrcName){
	m_musicLrc.readFromFile(lrcName);

	int nLine = m_musicLrc.getLineCount();
	ui.lrcTableWidget->setRowCount(nLine);

	for (size_t i = 0; i < nLine; ++i){
		QTableWidgetItem* item = new QTableWidgetItem;
		item->setText(m_musicLrc.getLineAt(i));
		item->setTextAlignment(Qt::AlignCenter);
		ui.lrcTableWidget->setItem(i, 0, item);
	}
	
}

void DoReMiPlayer::addSong(WebMusicInfo wmf){
	int preSongCount = m_songPaths.count();
	if (m_songPaths.contains(wmf.songLink)){
		QString warn = QString::fromLocal8Bit("请不要重复添加歌曲：%1");

		QMessageBox::information(this, QStringLiteral("提示"), warn.arg(wmf.songLink));
		return;
	}
	m_songPaths.push_back(wmf.songLink);

	m_musicParser.loadSong(wmf.songLink);
	MusicInfo musicInfo;
	musicInfo.title = wmf.title;
	musicInfo.artist = wmf.artist;
	musicInfo.duration = wmf.duration;
	musicInfo.album = wmf.album;
	m_map.insert(m_songPaths.last(), musicInfo);
	m_musicParser.unloadSong();

	ui.playlistTableWidget->addRow(musicInfo.title, musicInfo.artist, musicInfo.duration);
	
	if (m_songPaths.count()){
		if (m_bassPlayer){
			ui.playPushBtn->setEnabled(true);
		}
	}
}

void DoReMiPlayer::addSongs(){
	QStringList songPath = QFileDialog::getOpenFileNames(this,
		QStringLiteral("添加本地歌曲"),
		"../",
		QStringLiteral("音频文件 (*.mp3 *.mp4)"));
	if (songPath.isEmpty()){
		QMessageBox::information(this,
			QStringLiteral("提示"),
			QStringLiteral("请添加本地歌曲文件！"),
			QStringLiteral("是"));
		return;
	}

	int preSongCount = m_songPaths.count();
	QStringList::const_iterator constIterator;
	for (constIterator = songPath.constBegin(); constIterator != songPath.constEnd();
		++constIterator){
		if (m_songPaths.contains(*constIterator)){
			QString warn = QString::fromLocal8Bit("请不要重复添加歌曲：%1");

			QMessageBox::information(this,
				QStringLiteral("提示"),
				warn.arg(*constIterator));
			continue;
		}
		m_songPaths.push_back(*constIterator);
	}

	// update music table
	for (size_t i = preSongCount; i < m_songPaths.count(); ++i){
		// use taglib, need to add zlib dependency
		MusicInfo musicInfo;
		if (m_map.contains(m_songPaths.at(i))){
			musicInfo = m_map.value(m_songPaths.at(i));
		}

		else{
			m_musicParser.loadSong(m_songPaths.at(i));

			musicInfo.title = m_musicParser.getTitle();
			musicInfo.artist = m_musicParser.getArtist();
			musicInfo.duration = m_musicParser.getDuration();
			musicInfo.album = m_musicParser.getAlbum();
			m_map.insert(m_songPaths.at(i), musicInfo);

			m_musicParser.unloadSong();
		}

		ui.playlistTableWidget->addRow(musicInfo.title, musicInfo.artist, musicInfo.duration);
	}

	if (m_songPaths.count()){
		if (m_bassPlayer){
			ui.playPushBtn->setEnabled(true);
		}
	}
}

void DoReMiPlayer::addPlaylist(){
	QString listPath = QFileDialog::getOpenFileName(this,
		QStringLiteral("添加本地歌单"),
		".",
		QStringLiteral("歌单文件 (*.xml)"));
	if (listPath.isEmpty()){
		QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("请添加本地歌单文件！"));
		return;
	}

	// add song url to m_songPaths;
	// ...

	// update music list
	ui.playlistTableWidget->clearContents();
	ui.playlistTableWidget->setRowCount(m_songPaths.count());
	for (size_t i = 0; i < m_songPaths.count(); ++i){
		// use taglib, need to add zlib dependency
		m_musicParser.loadSong(m_songPaths.at(i));
		ui.playlistTableWidget->setItem(i, 0, new QTableWidgetItem(m_musicParser.getTitle()));
		ui.playlistTableWidget->setItem(i, 1, new QTableWidgetItem(m_musicParser.getArtist()));
		ui.playlistTableWidget->setItem(i, 2, new QTableWidgetItem(m_musicParser.getDuration()));
		m_musicParser.unloadSong();
	}
}

void DoReMiPlayer::playSong(int index){
	// if state is pause, then
	if (m_playState == PAUSE){
		if (m_curIndex != index){
			m_playState = PLAY;
			playSong(index);
			return;
		}
		pauseSong();
		return;
	}

	// if state is stop or play, then
	if (m_playState == PLAY || m_playState == STOP){
		if (m_curIndex == index){
			pauseSong();
			return;
		}

		else{
			m_curSongPath = m_songPaths.at(index);
			m_curIndex = index;
			m_playState = PLAY;

			// select this row
			ui.playlistTableWidget->selectRow(m_curIndex);

			// update button
			QPixmap pixmap("../resources/pause.png");
			ui.playPushBtn->setIcon(pixmap);
			ui.playPushBtn->setFlat(true);

			// update slider
			m_musicParser.loadSong(m_curSongPath);
			ui.processSlider->setEnabled(true);
			if (m_bassPlayer){
				m_bassPlayer->play(m_curSongPath);

				int songLenth = m_bassPlayer->getTotalPosByte();
				ui.processSlider->setRange(0, songLenth);

				// enable forward and backward button
				ui.forwardPushBtn->setEnabled(true);
				ui.backPushBtn->setEnabled(true);

				QString album = m_map.value(m_curSongPath).album;
				ui.albumInfoTextEdit->setText(m_musicParser.getBrief(album));
				ui.albumInfoTextEdit->setStyleSheet("color:gray");
				ui.lrcTableWidget->clearContents();
				ui.lrcTableWidget->setRowCount(0);
				m_isLrcLoaded = false;


				QString artist = ui.playlistTableWidget->item(index, 1)->text();
				QString title = ui.playlistTableWidget->item(index, 0)->text();
				// get and add lrc
				if (m_musicParser.getLrc(artist,title)){
					m_isLrcLoaded = true;
					QString lrcName = QStringLiteral("../data/%1-%2.lrc").arg(artist).arg(title);
					addLrc(lrcName);
				}

				QPixmap coverImg("../resources/playlist.png");
				if (m_musicParser.getCover(coverImg)){
					ui.coverLabel->setPixmap(coverImg.scaledToWidth(64));
				}
				ui.coverLabel->setScaledContents(true);
			}
			m_musicParser.unloadSong();
		}
	}
}

void DoReMiPlayer::pauseSong(){
	if (m_bassPlayer){
		if (m_playState == PAUSE){
			m_bassPlayer->resume();
			m_playState = PLAY;

			QPixmap pixmap("../Resources/pause.png");
			ui.playPushBtn->setFlat(true);
			ui.playPushBtn->setIcon(pixmap);
			return;
		}

		if (m_playState == STOP){
			return;
		}

		if (m_playState == PLAY){
			m_bassPlayer->pause();
			m_playState = PAUSE;

			QPixmap pixmap("../Resources/play.png");
			ui.playPushBtn->setIcon(pixmap);
			ui.playPushBtn->setFlat(true);
		}
	}
}

void DoReMiPlayer::playNextSong(){
	if (m_curIndex >= ui.playlistTableWidget->rowCount() - 1){
		int isEnd = QMessageBox::question(this,
			QStringLiteral("提示"),
			QStringLiteral("歌曲已到达列表末尾，是否从头开始播放？"),
			QStringLiteral("是"), QStringLiteral("否"));

		if (isEnd){
			ui.forwardPushBtn->setEnabled(false);
			return;
		}
		m_curIndex = -1;
	}

	playSong(m_curIndex + 1);
}

void DoReMiPlayer::playPreSong(){
	if (m_curIndex - 1 < 0){
		ui.backPushBtn->setDisabled(true);
		return;
	}

	playSong(m_curIndex - 1);
}

void DoReMiPlayer::deleteSong(int index){
	if (m_bassPlayer){
		m_map.remove(m_songPaths.at(index));
		m_songPaths.removeAt(index);

		if (m_curIndex != index){
			return;
		}

		// if this song is playing
		m_bassPlayer->stop();
		m_playState = STOP;

		m_curIndex = -1;

		QPixmap pixmap("../Resources/play.png");
		ui.playPushBtn->setFlat(true);
		ui.playPushBtn->setIcon(pixmap);
	}
}

void DoReMiPlayer::updateMediaPos(int curPos){
	m_bassPlayer->setPosition(curPos);
}

void DoReMiPlayer::updateLrc(int curPos){
	if (!m_isLrcLoaded){
		return;
	}
	QTime curTime(0, 0, 0);
	curTime=curTime.addSecs(curPos+1);

	int index = m_musicLrc.getCurIndex(curTime);
	if (index == m_lrcIndex){
		return;
	}
	m_lrcIndex = index;
	ui.lrcTableWidget->selectRow(m_lrcIndex);
}

void DoReMiPlayer::savePlayList(){
}

void DoReMiPlayer::closeEvent(QCloseEvent *e){ // write to database
	MusicDatabase* mdb = MusicDatabase::CreateInstance();
	mdb->addSongList(m_songPaths);
	MusicDatabase::DestroyInstance(mdb);
}

void DoReMiPlayer::dragEnterEvent(QDragEnterEvent *e){
	if (e->mimeData()->hasFormat("text/uri-list")){ 
		// problems here, supposed to be audio/mpeg but invalid for no reason
		e->acceptProposedAction();
	}
}

void DoReMiPlayer::dropEvent(QDropEvent *e){
	QList<QUrl> urls = e->mimeData()->urls();
	if (urls.isEmpty()){
		return;
	}

	QList<QUrl>::const_iterator urlIterator;
	for (urlIterator = urls.constBegin(); urlIterator != urls.constEnd();
		++urlIterator){
		QString songName = urlIterator->toLocalFile();
		int index = songName.lastIndexOf('.');
		QString format = songName.mid(index + 1);

		QStringList supportForms;
		supportForms << "mp3" << "wav" << "flac" << "ape";

		if (!supportForms.contains(format, Qt::CaseInsensitive)){
			QMessageBox::information(this, QStringLiteral("提示"),
				QStringLiteral("暂不支持该文件格式：%1").arg(format));
			return;
		}

		if (m_songPaths.contains(songName)){
			QMessageBox::information(this,
				QStringLiteral("提示"),
				QStringLiteral("请不要重复添加歌曲：%1").arg(songName));
			return;
		}
		m_songPaths.push_back(songName);
	}

	// update music table
	ui.playlistTableWidget->clearContents();
	ui.playlistTableWidget->setRowCount(m_songPaths.count());

	for (size_t i = 0; i < m_songPaths.count(); ++i){
		// use taglib, need to add zlib dependency
		MusicInfo musicInfo;
		if (m_map.contains(m_songPaths.at(i))){
			musicInfo = m_map.value(m_songPaths.at(i));
		}

		else{
			m_musicParser.loadSong(m_songPaths.at(i));

			musicInfo.title = m_musicParser.getTitle();
			musicInfo.artist = m_musicParser.getArtist();
			musicInfo.duration = m_musicParser.getDuration();
			m_map.insert(m_songPaths.at(i), musicInfo);

			m_musicParser.unloadSong();
		}

		ui.playlistTableWidget->setItem(i, 0, new QTableWidgetItem(musicInfo.title));
		ui.playlistTableWidget->setItem(i, 1, new QTableWidgetItem(musicInfo.artist));
		ui.playlistTableWidget->setItem(i, 2, new QTableWidgetItem(musicInfo.duration));
	}

	ui.playPushBtn->setEnabled(true);
}

void DoReMiPlayer::checkNetState(){
	//cost much time
	QNetworkConfigurationManager networkManger;
	if (networkManger.isOnline()){
		m_isOnline = true;
		QPointer<QLabel> netStateLabel = new QLabel(ui.statusBar);
		QPixmap ico("../Resources/green_light.png");
		netStateLabel->setPixmap(ico.scaledToHeight(15, Qt::SmoothTransformation));
		netStateLabel->setFrameStyle(QFrame::NoFrame | QFrame::Plain);
		netStateLabel->setStyleSheet("QLabel{border-width: 1px;	border-style: solid;border-color: #302F2F;}");
		QPointer<QLabel> netStateText = new QLabel;
		netStateText->setText(QStringLiteral("在线"));

		QFont font;
		font.setFamily(QStringLiteral("微软雅黑"));
		netStateText->setFont(font);
		ui.statusBar->addPermanentWidget(netStateLabel);
		ui.statusBar->addPermanentWidget(netStateText);

		return;
	}

	else{
		m_isOnline = false;
		QPointer<QLabel> netStateLabel = new QLabel(ui.statusBar);
		//netStateLabel->resize(10, 10);
		QPixmap ico("../Resources/red_light.png");
		netStateLabel->setPixmap(ico.scaledToHeight(15, Qt::SmoothTransformation));
		netStateLabel->setFrameStyle(QFrame::NoFrame | QFrame::Plain);
		netStateLabel->setStyleSheet("QLabel{border-width: 1px;	border-style: solid;border-color: #302F2F;}");
		ui.statusBar->addPermanentWidget(netStateLabel, 1);
		QPointer<QLabel> netStateText = new QLabel;
		netStateText->setText(QStringLiteral("离线"));
		ui.statusBar->addPermanentWidget(netStateText);
	}

}