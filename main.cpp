#include "mainwindow.h"
#include "lineEdit.h"

#include <QApplication>

#include <QtWidgets>
#include <QLabel>
#include <QVBoxLayout>

void setButton(QWidget *widg, QString name, qint16 y = 40,
               qint16 x = 640, qint16 width = 120,qint16 height = 80){
    QPushButton *butt = new QPushButton(widg);
    butt->setText(name);
    butt->setGeometry(x, y, width, height);
}

void func(QWidget *widg,  qint16 y = 40,
          qint16 x = 640, qint16 width = 120,qint16 height = 80){
    QLabel* plblText = new QLabel("&Text");
    QLineEdit* pText = new QLineEdit;
    QVBoxLayout* pvboxLayout =  new QVBoxLayout;
    plblText->setBuddy(pText);
    pvboxLayout->addWidget(plblText);
    pvboxLayout->addWidget(pText);



    widg->setLayout(pvboxLayout);
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget widg;


    widg.resize(800,800);
    qint16 spaceBtn = 100;
    QString ButtonName[3] = {"Start", "Stop", "Pause"};
    for(qint8 i = 0; i < 3; ++i)
    {
        setButton(&widg, static_cast<QString>(ButtonName[i]), spaceBtn*i);
    }

    //Line ln(&widg);
    //func(&widg);

    widg.show();
    return a.exec();
}
