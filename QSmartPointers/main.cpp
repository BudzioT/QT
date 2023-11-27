#include <QCoreApplication>
#include <QTimer>

#include "test.h"

using testList = QList<Test*>;

/* Scoped pointer exists only in that scope */
void testScoped()
{
    QScopedPointer<Test> ptr(new Test());
    ptr->message("Hello");
}

void finish(QSharedPointer<Test> ptr)
{
    ptr->message("Finished");
}

void work(QSharedPointer<Test> ptr)
{
    ptr->message("Working...");
}

void step(QSharedPointer<Test> ptr)
{
    ptr->message("Stepping...");
    for (int i = 0; i < 3; i++)
        work(ptr);
    finish(ptr);
}

/* Shared pointer, deletes itself if reference count == 0 */
void testShared(Test* test)
{
    QSharedPointer<Test> ptr(test);
    ptr->message("Starting...");
    step(ptr);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testScoped();
    Test* test = new Test();
    testShared(test);

    return a.exec();
}
