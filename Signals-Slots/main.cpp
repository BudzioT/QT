#include <QCoreApplication>

#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test test;

    //Connect the signal and the slot
    QObject::connect(&test, &Test::close, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    test.doStuff();

    int value = a.exec();

    qInfo() << "Return value: " << value << '\n';

    return value;
}
