//#ifndef MINICLASS_H
//#define MINICLASS_H
#pragma once
#include <QUrl>
#include <QByteArray>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValueIterator>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

class MainWindow : public QObject
{
    Q_OBJECT
public:
    void toPopulate();

public slots:
    void downloading(qint64 bytesReceived, qint64 bytesTotal);

    void onResult();

};

//class miniclass
//{
//public:
//    void mini();
    //void onResult(QNetworkReply* reply);

//};

//#endif // MINICLASS_H
