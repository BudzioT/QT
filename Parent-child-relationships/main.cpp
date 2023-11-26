#include <QCoreApplication>
#include <QTimer>

#include "test.h"

Test* getTest(QObject* parent)
{
    return new Test(parent); /* No memory leak, if this has a parent */
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* Call the quit slot after 3 seconds */
    QTimer timer;
    timer.singleShot(3000, &a, &QCoreApplication::quit);

    /* Setting in the constructor */
    Test* dog = getTest(&a);
    dog->setObjectName("dog");

    /* Setting up after the constructor */
    Test* smallerDog = getTest(nullptr);
    smallerDog->setObjectName("smallerDog");
    smallerDog->setParent(dog);

    int value = a.exec();

    qInfo() << "Return value: " << value << '\n';

    return value;
}
