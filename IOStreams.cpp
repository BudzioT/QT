#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>

#include <iostream>
#include <string>

void cpp_way()
{
    std::cout << "Please enter your name: ";
    std::string name;
    std::getline(std::cin, name);
    std::cout << "Welcome " << name << std::endl;
}

void qt_way()
{
    QTextStream qin(stdin);
    QTextStream qout(stdout);
    qout << "Please enter your name: ";
    qout.flush();
    QString name = qin.readLine();
    qout << "Welcome " << name << '\n';
    qout.flush();
}

void mix_way()
{
    QTextStream qin(stdin);
    qInfo() << "Please enter your name: ";
    QString name = qin.readLine();
    qInfo() << "Hello " << name;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //cpp_way();
    //qt_way();
    mix_way();

    return a.exec();
}
