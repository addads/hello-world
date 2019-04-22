#include "miniclass.h"


//void miniclass::mini()
//{
   /* QNetworkAccessManager networkManager;

    QUrl url("");
    QNetworkRequest request;
    request.setUrl(url);

    QNetworkReply* currentReply = networkManager.get(request);
*/


//}

//void miniclass::onResult(QNetworkReply* reply)
//{
  /*  if (m_currentReply->error() != QNetworkReply::NoError)
        return;  // ...only in a blog post

    QString data = (QString) reply->readAll();

    QScriptEngine engine;
    QScriptValue result = engine.evaluate(data);


    QScriptValue entries = result.property("feed").property("entry");
    QScriptValueIterator it(entries);
    while (it.hasNext()) {
        it.next();
        QScriptValue entry = it.value();

        QString link = entry.property("content").property("src").toString();
        int viewCount = entry.property("yt$statistics").property("viewCount").toInteger();

        // Do something with those...
    }*/
//}




void MainWindow::toPopulate() {
    qDebug() << "Populating!";

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    QUrl url("https://jsonplaceholder.typicode.com/posts/1");
    request.setUrl(url);
    QNetworkReply *reply = manager->get(request);
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloading(qint64,qint64)));
    connect(reply, SIGNAL(finished()), this, SLOT(onResult()));
}

void MainWindow::downloading(qint64 bytesReceived, qint64 bytesTotal) {
    qDebug() << "Downloading " << bytesReceived/bytesTotal*100 << " %.";
}

void MainWindow::onResult() {
    QNetworkReply* reply = qobject_cast<QNetworkReply*> (QObject::sender());
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error downloading. " << reply->errorString();
        return;
    }
    reply->deleteLater();
    QByteArray result = reply->readAll();
    qDebug() << "Response! " << reply->readAll();

    QJsonDocument jsonResponse = QJsonDocument::fromJson(result);
    QJsonObject obj = jsonResponse.object();

    QJsonArray array = obj["body"].toArray();

    for(const QJsonValue value : array) {
        qDebug()<< "text: " <<value.toString();
    }
}
