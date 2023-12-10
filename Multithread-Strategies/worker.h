#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QRunnable>
#include <QEventLoop>
#include <QScopedPointer>
#include <QTimer>

class Worker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();
signals:
    void finished();

public:
    void run();

public slots:
    void work();
};

#endif // WORKER_H
