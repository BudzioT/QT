#include "queue.h"

Queue::Queue(QObject *parent)
    : QObject{parent}, m_count(0)
{
}

void Queue::move(QString receipt)
{
    if (!m_count--) {
        qInfo() << "End of queue" << QThread::currentThread();
        emit end();
    }
    qInfo() << "Someone left with receipt" << receipt << QThread::currentThread();
}

void Queue::add()
{
    int people = QRandomGenerator::global()->bounded(0, 3);
    m_count += people;
    qInfo() << QString::number(people) << "entered the queue" << QThread::currentThread();
}

void Queue::start()
{
    qInfo() << "Starting the queue..." << QThread::currentThread();
    m_count = QRandomGenerator::global()->bounded(5, 10);
}

void Queue::quit()
{
    qInfo() << "The office closed, so the queue ended" << QThread::currentThread();
}
