#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    ~Test();

    QString name() const;
    void setName(const QString& name);

    int age() const;
    void setAge(int age);
signals:

private:
    QString m_name;
    int m_age;
};

#endif // TEST_H
