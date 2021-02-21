#ifndef TASKMANAGERHANDLER_H
#define TASKMANAGERHANDLER_H

# include "pageHandler.h"

# include <QObject>

//! состояние обработчика с точки зрения менеджера
enum TaskManagerHandlerState{
    Ready, Busy
};

//! обработчик задач с точки зрения менеджера
struct TaskManagerHandler{
    TaskManagerHandler(PageHandler *handler_);

    PageHandler *handler;
    TaskManagerHandlerState state;
};

#endif // TASKMANAGERHANDLER_H
