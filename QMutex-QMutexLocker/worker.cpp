#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{}

void Worker::run()
{
    for (int i = 0; i < 10; i++) {
        QMutexLocker locker(m_mutex); /* Lock Mutex for the entire scope */
        int value = *m_count;
        ++value;
        *m_count = value;

        qInfo() << QThread::currentThread() << *m_count;
        /* Unlocks Mutex */
    }

    qInfo() << QThread::currentThread() << "Done";
}

void Worker::setCount(int *newCount)
{
    m_count = newCount;
}

void Worker::setMutex(QMutex *newMutex)
{
    m_mutex = newMutex;
}
