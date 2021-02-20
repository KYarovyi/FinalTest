#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QMainWindow>
#include <QtWidgets>

class Line : public QWidget
{


public:
    Line(QWidget *parent = nullptr);

public slots:
    void inputURLChanged(int);
    void inputCountThreadsChanged(int);
    void inputMaxCountURLChanged(int);

private:
    QLineEdit *inputURL;
    QLineEdit *inputCountThreads;
    QLineEdit *inputMaxCountURL;
};
#endif // LINEEDIT_H
