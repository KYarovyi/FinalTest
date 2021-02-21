#ifndef TASK_H
#define TASK_H

# include <QObject>

//! тип задачи (обрабатываемой страницы)
enum TaskType{
    Internal, External
};

//! состояние задачи
enum TaskState{
  Free,
  Bound
};

class Task: public QObject{
  Q_OBJECT
public:
    Task(TaskType type, TaskState state, QString url, QObject *parent = 0);
    TaskType type();
    TaskState state();
    QString url();

    void state(TaskState state);
protected:
    TaskType m_type;
    TaskState m_state;
    QString m_url;
};

#endif // TASK_H
