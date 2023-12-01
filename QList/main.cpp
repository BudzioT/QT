#include <QCoreApplication>
#include <QRandomGenerator>
#include <QSharedPointer>
#include "test.h"


/************************ Creating and adding data ************************/
QList<int> getNumbers()
{
    QList<int> list;

    /* Use the operator */
    list << 300 << 400 << 500;

    int max = QRandomGenerator::global()->bounded(1, 10);
    for (int i = 0; i < max; i++)
        list.append(QRandomGenerator::global()->bounded(1, 100));

    return list;
}

void testNumbers()
{
    QList<int> list = getNumbers();
    qInfo() << list;

    qInfo() << "Length" << list.length();
    qInfo() << "Count" << list.count();
    qInfo() << "Size" << list.size();

    for (int i = 0; i < list.size(); i++)
        qInfo() << i << " = " << list[i];
    qInfo() << "---------------------------";
    foreach(int item, list)
        qInfo() << item;
}

/************************ Modifying existing data ************************/
void testModifying()
{
    QList<int> list = getNumbers();

    /* Direct mod */
    list[0] = 1000;
    /* Appending */
    list.append(99);
    /* Inserting */
    list.insert(0, 55);
    list.insert(1, 22);
    for (int i = 0; i < 7; i++)
        list.insert(1, 255);

    /* Removing */
    qInfo() << "Length" << list.length();
    list.removeAt(0);
    qInfo() << "RemoveAt" << list.length();
    list.removeOne(255);
    qInfo() << "RemoveOne" << list.length();
    list.removeAll(255);
    qInfo() << "RemoveAll" << list.length();
    list.remove(5, 7);
    qInfo() << "Remove" << list.length();

    for (int i = 0; i < list.size(); i++)
        qInfo() << i << " = " << list.at(i);
}

/************************ Searching ************************/
void testSearch()
{
    QList<int> list = getNumbers();
    int item = 999;
    list.insert(0, item);
    list.insert(3, item);
    list.append(item);

    for (int i = 0; i < list.size(); i++)
        qInfo() << i << " = " << list.at(i);

    /* First */
    int fPos = list.indexOf(item);
    qInfo() << "First" << fPos;

    /* Last */
    int lPos = list.lastIndexOf(item);
    qInfo() << "Last" << lPos;

    /* All */
    int pos = list.indexOf(item);
    while (pos > -1) {
        qInfo() << "Position" << pos;
        pos = list.indexOf(item, pos + 1);
    }
    qInfo() << list.contains(item);

    /* Get a slice */
    QList<int> items = list.sliced(1, 4);
    qInfo() << list;
    qInfo() << items;
}

/************************ Memory considerations ************************/
void testDeleteAll()
{
    QList<Test*> list;
    for (int i = 0; i < 5; i++)
        list.append(new Test());

    qInfo() << "Cleanup";
    qDeleteAll(list);
    list.clear();
    qInfo() << "Length" << list.length();
}

void testSmart()
{
    QList<QSharedPointer<Test>> list;
    for (int i = 0; i < 5; i++) {
        QSharedPointer<Test> item(new Test()); /* Auto memory management */
        list.append(item);
    }

    qInfo() << "Remove first";
    list.removeFirst();
    qInfo() << "Clear";
    list.clear();
    qInfo() << "Length" << list.length();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* Creating and adding data */
    //testNumbers();

    /* Modyfing existing data */
    //testModifying();

    /* Searching data */
    //testSearch();

    /* Memory considerations */
    //testDeleteAll();
    testSmart();

    return a.exec();
}
