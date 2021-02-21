#include "pageHendler.h"

pageHendler::pageHendler(QString host, QObject *parent):
    QObject(parent), m_host(host), m_nam(new QNetworkAccessManager(this)){

    connect(m_nam, SIGNAL(finished(QNetworkReply*)), SLOT(on_load(QNetworkReply*)));
}

void pageHendler::on_page(QObject* obj, TaskType  type, QString url){
        // сообщение адресовано другому объекту
    if(this != obj)
        return;
    m_pageType = type;
    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("text/plain"));
    m_nam->post(req, "");
}

void pageHendler::on_load(QNetworkReply *reply){
    QByteArray buff = reply->readAll();
    qint16 idx = 0, start = -1, finish = -1;
    switch (m_pageType) {
    case TaskType::External:{
            QString
                patProjStart = "<div class=\"proj public\" >",
                patAddrStart = "<a class=\"ptitle\" href=\"",
                patAddrFinish  = "\"";
            for(;;){
                idx = buff.indexOf(patProjStart,idx);
                if(idx < 0) break;
                idx = idx + patProjStart.length();

                idx = buff.indexOf(patAddrFinish, idx);
                Q_ASSERT(idx > 0);
                finish = idx;

                qDebug() << m_host + buff.mid(start, finish - start);
            }
        }
        break;
    }
    delete  reply;
}
