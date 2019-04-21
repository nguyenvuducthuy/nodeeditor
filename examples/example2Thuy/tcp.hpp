#ifndef MYSERVER_H
#define MYSERVER_H

#include <QtCore/QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtDebug>

class MyTcpServer : public QObject
{
	Q_OBJECT
public:
	explicit MyTcpServer(QObject *parent = 0);

	void setMsg(QString val);
	QString msg;

signals:

public slots:
	void newConnection();

private:
	QTcpServer *server;
};

#endif
