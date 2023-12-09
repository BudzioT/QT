#ifndef OFFICE_H
#define OFFICE_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>

class Office : public QObject
{
    Q_OBJECT
public:
    explicit Office(QObject *parent = nullptr);

signals:
    void next(QString receipt);
    void close();

public slots:
    QString serve();
    void start();
    void quit();

private:
    void timeout();

private:
    QTimer* m_timer;
    int m_time;
    static int receipt_count;
};

#endif // OFFICE_H
