#include <QCoreApplication>
#include <QDebug>
#include <QThread>

#include "office.h"
#include "queue.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread officeThread;
    QThread queueThread;

    Office office;
    Queue queue;
    office.moveToThread(&officeThread);
    queue.moveToThread(&queueThread);

    officeThread.setObjectName("Office Thread");
    queueThread.setObjectName("Queue Thread");
    office.setObjectName("Office");
    queue.setObjectName("Queue");

    QObject::connect(&officeThread, &QThread::started, &office, &Office::start);
    QObject::connect(&queueThread, &QThread::started, &queue, &Queue::start);

    QObject::connect(&office, &Office::next, &queue, &Queue::move);

    QObject::connect(&queue, &Queue::end, &office, &Office::quit);
    QObject::connect(&office, &Office::close, &queue, &Queue::quit);

    qInfo() << "Started the simulation" << QThread::currentThread();

    queueThread.start();
    officeThread.start();

    qInfo() << "Ended the simulation" << QThread::currentThread();

    return a.exec();
}
