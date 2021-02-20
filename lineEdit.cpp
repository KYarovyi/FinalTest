#include "lineEdit.h"

Line::Line(QWidget *parent)
    : QWidget(parent)
{
    inputURL = new QLineEdit;
    inputURL->setPlaceholderText("input URL");
    inputURL->setMaximumWidth(550);

    inputCountThreads = new QLineEdit;
    inputCountThreads->setPlaceholderText("set max count threads");
    inputCountThreads->setMaximumWidth(550);

    inputMaxCountURL = new QLineEdit;
    inputMaxCountURL->setPlaceholderText("set max URL");
    inputMaxCountURL->setMaximumWidth(550);


    // Set connections in feature
    /*connect(echoComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &lineEdit::echoChanged);
    connect(validatorComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &lineEdit::validatorChanged);
    connect(alignmentComboBox, QOverload<int>::of(&QComboBox::activated),
            this, &lineEdit::alignmentChanged);
    */

    QGridLayout *Layout = new QGridLayout;
    Layout->addWidget(inputURL, 0, 2);
    Layout->addWidget(inputCountThreads);
    Layout->addWidget(inputMaxCountURL);


    parent->setLayout(Layout);

}
