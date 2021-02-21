#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "task.h"
#include "taskManagerHandler.h"

# include <QObject>
# include <QList>

class PageHandler;
class QThread;

// менеджер задач
// распределяет задачи по свободным обработчикам
// контролирует правильное уничтожение потоков обработчиков
class TaskManager: public QObject{
    Q_OBJECT
public:
    explicit TaskManager(QObject *parent = 0);
    ~TaskManager();
        // добавление объекта-исполнителя
    void addHandler(PageHandler *hObj, QThread *threadObj);

signals:
        // сигнал с задачей, должен быть обработан объектом receiver
    void task(QObject *reciver, TaskType type, QString url);
        // обработка завершена
    void finished();
public slots:
    void addTask(TaskType type, QString url);
    void removeTask(TaskType type, QString url);
        // слот обработки сигнала готовности исполнителя
        // (используется sender()) для получения исполнителя
    void onHandlerReady();

private:
    QList<Task*>                m_tasks;
    QList<TaskManagerHandler*>  m_handlers;
    QList<QThread*>             m_threads;
};


#endif // TASKMANAGER_H
