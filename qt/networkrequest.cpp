#include "networkrequest.h"



networkRequest::networkRequest(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readyRead(QNetworkReply* )));
}

void networkRequest::makeRequest(QString url)
{
    manager->get(QNetworkRequest(QUrl(url)));
}

void networkRequest::readyRead(QNetworkReply *reply)
{
    QByteArray read = reply->readAll();
    QString txt(read);

    qDebug () << "readyRead: " << txt;
    emit dataOutOfTheOven(read);
}
