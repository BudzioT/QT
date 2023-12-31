#include "manager.h"

Manager::Manager(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Created" << this << QThread::currentThread();
}

void Manager::start()
{
    for (int i = 0; i < 1; i++) {
        Worker* worker = new Worker();
        worker->setAutoDelete(true);

        /* DirectConnection - works on the thread that emitted the singal
         * QueuedConnection - works on the reciver's thread */
        connect(worker, &Worker::started, this, &Manager::started, Qt::QueuedConnection);
        connect(worker, &Worker::finished, this, &Manager::finished, Qt::QueuedConnection);
        connect(this, &Manager::work, worker, &Worker::work, Qt::QueuedConnection);

        QThreadPool::globalInstance()->start(worker);
    }
}

void Manager::started()
{
    Worker* worker = qobject_cast<Worker*>(sender());
    if (!worker)
        return;

    qInfo() << "Started" << worker << QThread::currentThread();

    /* Tell the worker to work */
    //Worker->work(); BAD
    //emit work() works on main thread because it is the thread that created the worker
}

void Manager::finished()
{
    Worker* worker = qobject_cast<Worker*>(sender());
    if (!worker)
        return;

    qInfo() << "Finished" << worker << QThread::currentThread();
}
