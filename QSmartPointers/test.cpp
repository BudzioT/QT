#include "test.h"

Test::Test(QObject *parent) : QObject{parent}
{
    qInfo() << this << " Constructed " << parent << '\n';
}

Test::~Test()
{
    qInfo() << this << " Destructed " << parent() << '\n';
}

void Test::message(const QString &msg)
{
    qInfo() << this << " " << msg;
}
