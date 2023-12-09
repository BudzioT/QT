#include "office.h"

Office::Office(QObject *parent)
    : QObject{parent}
{
    m_time = QRandomGenerator::global()->bounded(500, 2000);
}

QString Office::serve()
{
    qInfo() << this << "Serving receipt " << QString::number(receipt_count) << QThread::currentThread();
    m_time = QRandomGenerator::global()->bounded(500, 2000);
    return "Receipt id: " + QString::number(receipt_count++);
}

void Office::start()
{
    m_timer = new QTimer(this);
    m_timer->setInterval(m_time);
    qInfo() << "Opening office" << QThread::currentThread();

    connect(m_timer, &QTimer::timeout, this, &Office::timeout);
    m_timer->start();
}

void Office::quit()
{
    qInfo() << "Quiting office" << QThread::currentThread();
    m_timer->stop();
    emit close();
}

void Office::timeout()
{
    QString result = serve();
    qInfo() << this << "Please next!" << QThread::currentThread();
    emit next(result);
}

int Office::receipt_count = 0;

