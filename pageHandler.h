#ifndef LOADURL_H
#define LOADURL_H

#include <QWidget>
#include <QNetworkReply>

#include "task.h"

class pageHendler: public QObject{
    Q_OBJECT
public:
    explicit pageHendler(QString host, QObject *parent = 0);

public slots:
    //!< страница запрошена
    void on_page(QObject*, TaskType, QString);

private slots:
    //!< обработка сигнала finished QNetworkAccessManager
    void on_load(QNetworkReply* );

signals:
    //!< \brief завершена обработка страницы
    //!< менеджер удаляет страницу из очереди
    void pageHandled(TaskType type, QString url);

    //!< обработчик готов к приему следующей задачи
    void finished();

    //!< сигнал с информацией о новой странице для обработки
    void task(TaskType type, QString url);

    //!< сигнал с резульутатом обработки проекта
    void project(QString result);

protected:
        //!< менеджер загрузки страниц
    QNetworkAccessManager *m_nam;
        //!< хост обрабатываемой страницы
    QString m_host;
        //!< тип обрабатываемой страницы
    TaskType m_pageType;
};

#endif // LOADURL_H
