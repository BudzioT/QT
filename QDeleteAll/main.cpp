#include <QCoreApplication>
#include <QTimer>

#include "test.h"

using testList = QList<Test*>;

testList getList()
{
    testList list;
    for (int i = 0; i < 5; i++) {
        list.append(new Test());
        list.last()->setObjectName("Test" + QString::number(i));
    }
    return list; /* QList<> isn't a QObject, it can be copied */
}

void display(const testList& list)
{
    foreach(Test* item, list)
        qInfo() << item;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testList list = getList();
    display(list);

    qInfo() << "Deleting...";
    qDeleteAll(list.begin(), list.end()); /* Deletes, but doesn't deallocate the memory */
    list.clear();

    display(list);

    return a.exec();
}
