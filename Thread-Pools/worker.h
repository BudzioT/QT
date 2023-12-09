#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QRunnable>
#include <QThread>

class Worker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();

signals:
    void started();
    void finished();

public slots:
    void work();

    // QRunnable interface
public:
    void run();
};

#endif // WORKER_H
