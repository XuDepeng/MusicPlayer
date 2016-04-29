#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>

#include <QFile>
#include <QVariant>

#include <QMessageBox>

#include "MusicDatabase.h"

MusicDatabase* MusicDatabase::m_instance = nullptr;

MusicDatabase* MusicDatabase::CreateInstance(){
	if (!m_instance){
		m_instance = new MusicDatabase;
	}
	return m_instance;
}

void MusicDatabase::DestroyInstance(MusicDatabase* mdb){
	if (m_instance){
		delete m_instance;
		m_instance = nullptr;
	}
}

QStringList MusicDatabase::getSongList(){
	QString dbName = "../data/musiclist.db";
	if (!QFile::exists(dbName)){
		return QStringList();
	}

	QSqlDatabase db;
	if (QSqlDatabase::contains("qt_sql_default_connection")){
		db = QSqlDatabase::database("qt_sql_default_connection");
	}
	else{
		db = QSqlDatabase::addDatabase("QSQLITE");;
	}	
	db.setDatabaseName(dbName);

	QStringList pathList;
	if (!db.open()){
		QMessageBox::critical(0, "Database Error", db.lastError().text());
		return pathList;
	}

	QSqlQuery query;
	bool test=query.exec("SELECT id,path FROM musiclist");
	while (query.next()){
		QString path = query.value(1).toString();
		if (QFile::exists(path)){
			pathList << path;
		}
		
	}
	db.close();
	return pathList;
}

void MusicDatabase::addSongList(QStringList songList){
	QString dbName = "../data/musiclist.db";
	if (QFile::exists(dbName)){
		if (!QFile::remove(dbName)){
			return;
		}
	}

	QSqlDatabase db;
	if (QSqlDatabase::contains("qt_sql_default_connection")){
		db = QSqlDatabase::database("qt_sql_default_connection");
	}
	else{
		db = QSqlDatabase::addDatabase("QSQLITE");;
	}

	db.setDatabaseName(dbName);
	if (!db.open()){
		QMessageBox::critical(0, "Database Error", db.lastError().text());
	}

	QSqlQuery query;
	if (!query.exec("create table musiclist ("
		"id int primary key,"
		"path varchar)")){
		QMessageBox::critical(0, "Database Error", db.lastError().text());
		return;
	}
	query.prepare("insert into musiclist (id,path) values (?,?)");
	QVariantList ids,paths;
	for (size_t i = 0; i < songList.count(); ++i){
		ids << i;
		paths << songList.at(i);
	}
	query.addBindValue(ids);
	query.addBindValue(paths);
	if (!query.execBatch()){
		QMessageBox::critical(0, "Database Error", db.lastError().text());
		return;
	}
	query.finish();
	db.close();
}




