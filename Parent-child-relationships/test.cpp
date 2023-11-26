#include "test.h"

Test::Test(QObject *parent) : QObject{parent}
{
    qInfo() << this << " Constructed " << parent << '\n';
}

Test::~Test()
{
    foreach(QObject* child, children())
        qInfo() << this << " -- child -- " << child;
    qInfo() << this << " Destructed " << parent() << '\n';
}

