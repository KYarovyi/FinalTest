#ifndef RESULTDRIVER_H
#define RESULTDRIVER_H

# include <QObject>

class QFile;

class ResultDriver{
public:
    explicit ResultDriver(QString fname, QObject *parent = 0);

signals:
    //!< сигнал информирует о том, что данные сохранены
    void finished();

public slots:
    //!< поступил проект
    void on_project(QString);
    //!< закрывает файл, вырабатывает сигнал finished
    void saveAll();
protected:
    QFile *m_file;
};

#endif // RESULTDRIVER_H
