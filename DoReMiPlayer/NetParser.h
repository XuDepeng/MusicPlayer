
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QtCore>

#include <QDomDocument>
#include <QJsonDocument>
#include <QTextStream>

class NetParser : public QObject{
	Q_OBJECT
public:
	static QString getHtml(QString url);

	static QDomDocument getXml(QString url);

	static QJsonDocument getJson(QString url);

	static bool downloadLrc(QString url, QString lrcName);
private:
	explicit NetParser(QObject* parent = 0){};
	NetParser(const NetParser&)Q_DECL_EQ_DELETE;
	NetParser& operator=(NetParser rhs)Q_DECL_EQ_DELETE;
};