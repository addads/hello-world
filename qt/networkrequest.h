#ifndef NETWORKREQUEST_H
#define NETWORKREQUEST_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>


class networkRequest : public QObject
{
    Q_OBJECT

public:  
    explicit networkRequest(QObject *parent = nullptr);
    void makeRequest(QString url);

signals:
    void dataOutOfTheOven(QByteArray);

public slots:
    void readyRead(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
};

#endif // NETWORKREQUEST_H
