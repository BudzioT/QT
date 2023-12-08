#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QRandomGenerator>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

    bool producer() const;
    void setProducer(bool newProducer);

signals:
    void produced(int value);
    void finished();

public slots:
    void consume(int value);
    void start();
    void quit();

private:
    void timeout();

private:
    QTimer* m_timer; /* Timers can't be started from another thread */
    bool m_producer;
    int m_count;
};

#endif // WORKER_H
