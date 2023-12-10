#include <QCoreApplication>
#include <QtConcurrent>
#include <QDebug>
#include <QThread>
#include <QThreadPool>
#include <QTimer>

#include "worker.h"


/* No threads
 * + Easy
 * - The slowest option
 * - Blocking the thread means blocking the entire application
*/
void testMain()
{
    qInfo() << "Testing on main";
    Worker* worker = new Worker();
    worker->run();
    worker->deleteLater();

    qInfo() << "Testing...";
}

/* QThread
 * + Better than using only the main thread
 * - Memory managment
 * - Complexity of adding connections
*/
void testThread()
{
    QThread* thread = new QThread();
    thread->setObjectName("Worker Thread");
    qInfo() << "Testing on Worker Thread";
    Worker* worker = new Worker();

    worker->moveToThread(thread);

    QObject::connect(thread, &QThread::started, worker, &Worker::run);
    QObject::connect(worker, &Worker::finished, worker, &Worker::deleteLater);
    QObject::connect(worker, &Worker::finished, thread, &QThread::quit);
    QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();

    qInfo() << "Testing...";
}

/* QThreadPool
 * + Very easy to implement
 * + Auto memory managment
 * + Threads are auto managed
 * - Sometimes Qt::AutoConnection is misleading, have to change to Qt::DirectConnection
*/
void testPool()
{
    qInfo() << "Testing on Thread Pool";
    Worker* worker = new Worker;
    worker->setAutoDelete(true);
    QThreadPool::globalInstance()->start(worker);

    qInfo() << "Testing...";
}

/* QtConcurrent
 * + Very easy to use, implement
 * + Very clean look, can use smart pointers to manage memory
 * + Everything is automated (can even use Future and more)
 * - Have to run call it by concurrent
*/
void testConcurrent()
{
    qInfo() << "Testing on Concurrent";
    QScopedPointer<Worker> worker(new Worker);
    worker->run();

    qInfo() << "Testing...";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    //testMain();
    //testThread();
    //testPool();
    QFuture<void> value = QtConcurrent::run(testConcurrent);

    qInfo() << "Finished in" << QThread::currentThread();

    return a.exec();
}
