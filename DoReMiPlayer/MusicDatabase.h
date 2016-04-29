#pragma once
#include <QStringList>

class MusicDatabase{
public:
	static MusicDatabase* CreateInstance();
	static void DestroyInstance(MusicDatabase* mdb);

	QStringList getSongList();
	void addSongList(QStringList songList);
private:
	MusicDatabase(){};
	~MusicDatabase(){};
	MusicDatabase(const MusicDatabase& rhs)Q_DECL_EQ_DELETE;
	MusicDatabase operator =(const MusicDatabase rhs)Q_DECL_EQ_DELETE;

	static MusicDatabase* m_instance;
};