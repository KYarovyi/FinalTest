#ifndef BUTTON_H
#define BUTTON_H

#include <QMainWindow>
#include <QPushButton>

class cButton: public QWidget{
private:
    QPushButton *butt;
public:
    cButton(QWidget *widg, QString name, qint16 y = 40,
            qint16 x = 640, qint16 width = 120,qint16 height = 80)
    {
        butt = new QPushButton(widg);
        butt->setText(name);
        butt->setGeometry(x, y, width, height);
    }
    ~cButton()
    {
        delete butt;
    }
};

#endif // BUTTON_H
