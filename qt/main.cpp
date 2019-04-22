#pragma once
#include <QUrl>
#include <QByteArray>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValueIterator>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QJsonDocument>

#include "miniclass.h"

int main()
{
   /* QNetworkAccessManager *manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished,
                    [](QNetworkReply *reply)
    {
        QByteArray response = reply->readAll();
        qDebug() << "Response body:" << response;
        if (reply->error())
            qDebug() << "System error msg:" << reply->errorString();
        else
            qDebug() << "Success!";
    });

    qDebug() << "Sending request:";
    QString initApi = "https://jira.harman.com/";
    QUrl url = QUrl(initApi);
    QNetworkRequest request = QNetworkRequest(url);
    //request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));


    QNetworkReply *replyy = manager->get(request);
    qDebug() << replyy->readAll();
  //  QJsonDocument *doc = new QJsonDocument();
   // qDebug() << "url:" << url.toString() << "\nbody:" << doc->toJson();

  //  manager->post(request, doc->toJson());*/
    MainWindow m;
    m.toPopulate();


    return 0;
}
