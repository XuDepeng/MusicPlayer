#include <QMenu>

#include <QHeaderView>
#include <QContextMenuEvent>

#include "WebMusicPlaylist.h"
#include "NoFocusDelegate.h"

WebMusicPlaylist::WebMusicPlaylist(QWidget* parent) :
QTableWidget(parent){
	QFont font;
	font.setFamily(QStringLiteral("微软雅黑"));
	setFont(font);

	setFrameStyle(QFrame::NoFrame);
	horizontalHeader()->setSectionsClickable(true);
	horizontalHeader()->setFrameStyle(QFrame::NoFrame);

	verticalHeader()->setHidden(true);
	horizontalHeader()->setStretchLastSection(true);
	horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	setRowCount(0);
	setColumnCount(4);
	hideColumn(3);

	QStringList tableHeader;
	tableHeader << QStringLiteral("歌曲") << QStringLiteral("艺术家") << QStringLiteral("专辑") 
		<< QStringLiteral("SONGID");
	setHorizontalHeaderLabels(tableHeader);

	setShowGrid(false);
	setSelectionMode(QAbstractItemView::SingleSelection);
	setSelectionBehavior(QAbstractItemView::SelectRows);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setItemDelegate(new NoFocusDelegate(this));

	m_curRow = 0;
	createActions();
}

void WebMusicPlaylist::addRow(QString title, QString artist, QString album, QString ID){
	int curNRow = rowCount() + 1;
	setRowCount(curNRow);

	setItem(curNRow - 1, 0, new QTableWidgetItem(title));
	setItem(curNRow - 1, 1, new QTableWidgetItem(artist));
	setItem(curNRow - 1, 2, new QTableWidgetItem(album));
	setItem(curNRow - 1, 3, new QTableWidgetItem(ID));
}

void WebMusicPlaylist::addRows(QStringList titles, QStringList artists, QStringList albums, 
	QStringList IDs){
	int preNRow = rowCount();
	int curNRow = preNRow + titles.count();
	setRowCount(curNRow);

	for (size_t i = 0; i < titles.count(); ++i){
		setItem(preNRow + i, 0, new QTableWidgetItem(titles.at(i)));
		setItem(preNRow + i, 1, new QTableWidgetItem(artists.at(i)));
		setItem(preNRow + i, 2, new QTableWidgetItem(albums.at(i)));
		setItem(preNRow + i, 3, new QTableWidgetItem(IDs.at(i)));
	}
}

void WebMusicPlaylist::createActions(){
	m_popMenu = new QMenu;
	playSongAction = new QAction(QIcon("../Resources/rplay.png"), QStringLiteral("播放"), this);
	addSongAction = new QAction(QIcon("../Resources/radd.png"), QStringLiteral("添加"), this);

	connect(playSongAction, SIGNAL(triggered()), this, SLOT(slotPlayCurSong()));
	connect(addSongAction, SIGNAL(triggered()), this, SLOT(slotAddCurSong()));
}

void WebMusicPlaylist::contextMenuEvent(QContextMenuEvent *e){
	m_popMenu->clear();
	QPoint point = e->pos();
	QTableWidgetItem *item = this->itemAt(point);

	if (item != nullptr){
		m_curRow = item->row();

		m_popMenu->addAction(playSongAction);
		m_popMenu->addAction(addSongAction);

		m_popMenu->setStyleSheet(QLatin1String("QMenu{\n"
			"background-color: #3A3939;\n"
			"border: 1px solid #3A3939;\n"
			"color: silver;\n"
			"margin: 2px;\n"
			"}\n"
			"QMenu::icon{\n"
			"margin: 5px;\n"
			"}\n"
			"QMenu::item{\n"
			"padding: 5px 30px 5px 30px;\n"
			"margin - left: 5px;\n"
			"border: 1px solid transparent;\n"
			"}\n"
			"QMenu::item:selected{\n"
			"background-color: #3d8ec9;\n"
			"color: black;\n"
			"}\n"
			));

		m_popMenu->exec(QCursor::pos());
		e->accept();
	}
}

void WebMusicPlaylist::slotPlayCurSong(){
	emit sigPlayCurSong(m_curRow);
}

void WebMusicPlaylist::slotAddCurSong(){
	emit sigAddCurSong(m_curRow);
}