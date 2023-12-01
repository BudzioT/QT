#include <QCoreApplication>
#include <QRandomGenerator>
#include <QSharedPointer>
#include <QMap>

#include "test.h"


/************************ Creating a QMap ************************/
using testMap = QMap<QString, QSharedPointer<Test>>;
testMap getTests()
{
    testMap tests;

    for (int i = 0; i < 5; i++) {
        QSharedPointer<Test> ptr(new Test());
        ptr->setAge(QRandomGenerator::global()->bounded(1, 5));
        ptr->setName("Unknown");
        tests.insert("test" + QString::number(i), ptr);
    }

    return tests;
}

/************************ Displaying a QMap ************************/
void display(const testMap& tests)
{
    foreach (const QString& key, tests.keys()) {
        QSharedPointer test = tests.value(key);
        qInfo() << key << test->name() << test->age() << test.data();
    }

}

/************************ Modifying an item ************************/
void modifyTest(testMap& tests, const QString& key)
{
    if (tests.contains(key)) {
        qInfo() << "Modifying:" << key;
        tests[key]->setAge(99);
        tests[key]->setName("Test");
        display(tests);
    }
}

/************************ Adding and inserting ************************/
void addTest(testMap& tests)
{
    qInfo() << "Adding and inserting";
    QSharedPointer<Test> test(new Test());
    test->setAge(1000);
    test->setName("Test");
    tests.insert("test", test);
    //tests["test"] = test;
    display(tests);
}

/************************ Searching for an item ************************/
void findTest(const testMap& tests, const QString& key)
{
    qInfo() << "Exists:" << tests.contains(key);

    auto iter = tests.find(key);
    if (iter != tests.end())
        qInfo() << iter.key() << iter.value();

    foreach (QSharedPointer<Test> value, tests.values())
        qInfo() << value;

    foreach (const QString& key, tests.keys())
        qInfo() << "Key:" << key << "value:" << tests.value(key);
}

/************************ Removing an item ************************/
void removeTest(testMap& tests, const QString& key)
{
    if (!tests.contains(key)) {
        qWarning() << "Test not found";
        return;
    }

    tests.remove(key);
    display(tests);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* Creating a QMap */
    testMap tests = getTests();
    //qInfo() << tests;

    /* Displaying a QMap */
    //display(tests);

    /* Modifying an item */
    //modifyTest(tests, "test2");

    /* Adding and inserting */
    //addTest(tests);

    /* Searching for an item */
    //findTest(tests, "test");

    /* Removing an item */
    //removeTest(tests, "test");

    /* Cleanup */
    qInfo() << "Clearing";
    tests.clear();


    return a.exec();
}
