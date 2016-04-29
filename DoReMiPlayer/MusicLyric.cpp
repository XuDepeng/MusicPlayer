#include "MusicLyric.h"

#include <QFile>
#include <QTextStream>

#include <QDebug>

MusicLyric::MusicLyric(){
	// do nothing
}

MusicLyric::~MusicLyric(){
	if (m_time.count()){
		m_time.clear();
	}
	if (m_lines.count()){
		m_lines.clear();
	}
}

int MusicLyric::getCurIndex(QTime curPos){
	//采用二分查找，时间复杂度O(logn)
	int lt, rt, mid;
	lt = 0; rt = m_time.count();
	while (lt < rt - 1){
		mid = (lt + rt) >> 1;
		if (m_time[mid] > curPos) 
			rt = mid;
		else
			lt = mid;
	}
	return lt;
}

QString MusicLyric::getLineAt(int index){
	return m_lines[index];
}

int MusicLyric::getLineCount(){
	return m_lines.count();
}

/*[offset:时间补偿值]其单位是秒，正值表示整体提前，负值相反，这是用于总体调整显示快慢的*/
void MusicLyric::readFromFile(QString lrcName){
	m_lrcName = lrcName;
	if (m_lines.count()){
		m_lines.clear();
	}
	if (m_time.count()){
		m_time.clear();
	}

	//时间复杂度O(n)
	QFile lrcfile(lrcName);
	if (!lrcfile.exists()) return;
	lrcfile.open(QIODevice::ReadOnly | QIODevice::Text);

	QTextStream ts(&lrcfile);
	ts.setCodec("utf8");

	while (!ts.atEnd()){
		QString line = ts.readLine();
		// check if it starts with brackets
		if (!line.startsWith("[")){
			continue;
		}

		// check if it's a tag
		if (line.startsWith("[ti")){
			int startIndex = line.indexOf(":");
			m_title = line.mid(startIndex + 1,line.count()-1-startIndex);
			continue;
		}

		if (line.startsWith("[ar")){
			int startIndex = line.indexOf(":");
			m_artist = line.mid(startIndex + 1, line.count() - 1 - startIndex);
			continue;
		}

		if (line.startsWith("[al")){
			int startIndex = line.indexOf(":");
			m_album = line.mid(startIndex + 1, line.count() - 1 - startIndex);
			continue;
		}

		// check if it's unknown and not supported
		if (line.count() <= 1 || !line.at(1).isNumber()) {
			continue;
		}

		// main process!
		int startIndex = line.lastIndexOf("]");
		if (line.endsWith("]")){
			continue;
		}
		QString lrc = line.mid(startIndex + 1);
		m_lines.append(lrc);

		QString startTime = line.mid(line.lastIndexOf("[") + 1, 
			line.lastIndexOf("]") - 1 - line.lastIndexOf("["));
		startTime = startTime + "0";
		QTime curTime = QTime::fromString(startTime, "mm:ss.zzz");
		m_time.append(curTime);
		//line.count("[");
	}

	lrcfile.close();
}