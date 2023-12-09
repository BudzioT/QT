#ifndef QUEUE_H
#define QUEUE_H

#include <QObject>
#include <QThread>
#include <QRandomGenerator>
#include <QDebug>

class Queue : public QObject
{
    Q_OBJECT
public:
    explicit Queue(QObject *parent = nullptr);

signals:
    void end();

public slots:
    void move(QString receipt);
    void add();
    void start();
    void quit();

private:
    int m_count;
};

#endif // QUEUE_H
