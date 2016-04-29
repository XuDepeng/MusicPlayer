#include "NetParser.h"

QString NetParser::getHtml(QString url)	{
	QPointer<QNetworkAccessManager> manager = new QNetworkAccessManager;
	QPointer<QNetworkReply> reply = manager->get(QNetworkRequest(QUrl(url)));
	QEventLoop eventLoop;
	connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	eventLoop.exec();       //block until finish
	QByteArray responseData = reply->readAll();
	reply->deleteLater();
	return QString(responseData);
}

QDomDocument NetParser::getXml(QString url){
	QPointer<QNetworkAccessManager> manager = new QNetworkAccessManager;
	QPointer<QNetworkReply> reply = manager->get(QNetworkRequest(QUrl(url)));
	QEventLoop eventLoop;
	connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	eventLoop.exec();       //block until finish
	QByteArray responseData = reply->readAll();
	reply->deleteLater();
	QDomDocument doc;
	doc.setContent(responseData);
	return doc;
}

QJsonDocument NetParser::getJson(QString url){
	QPointer<QNetworkAccessManager> manager = new QNetworkAccessManager;
	QPointer<QNetworkReply> reply = manager->get(QNetworkRequest(QUrl(url)));
	QEventLoop eventLoop;
	connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	eventLoop.exec();       //block until finish
	QByteArray responseData = reply->readAll();
	QString str = QString::fromUtf8(responseData);
	reply->deleteLater();
	return QJsonDocument::fromJson(str.toUtf8());
}

bool NetParser::downloadLrc(QString url, QString lrcName){
	QPointer<QNetworkAccessManager> manager = new QNetworkAccessManager;
	QPointer<QNetworkReply> reply = manager->get(QNetworkRequest(QUrl(url)));
	QEventLoop eventLoop;
	connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	eventLoop.exec();       //block until finish

	QTextCodec* codec = QTextCodec::codecForName("utf8");
	//QString all = codec->toUnicode(reply->readAll());
	QByteArray responseData = reply->readAll();

	QFile lrcFile(lrcName);
	if (!lrcFile.open(QIODevice::WriteOnly | QIODevice::Text)){
		return false;
	}

	lrcFile.write(responseData, responseData.length());
	lrcFile.close();
	reply->deleteLater();
	return true;
}

