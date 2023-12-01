#include "test.h"

Test::Test(QObject *parent) : QObject{parent}
{
    qInfo() << this << " Constructed ";
}

Test::~Test()
{
    qInfo() << this << " Destructed ";
}

QString Test::name() const
{
    return m_name;
}

void Test::setName(const QString &name)
{
    m_name = name;
}

int Test::age() const
{
    return m_age;
}

void Test::setAge(int age)
{
    m_age = age;
}


