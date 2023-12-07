#include <QCoreApplication>
#include <QTextStream>

#include "inventory.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Inventory inventory;

    qInfo() << "Available commands:";
    qInfo() << "add <name> <qty>";
    qInfo() << "remove <name> <qty>";
    qInfo() << "save";
    qInfo() << "load";
    qInfo() << "list";
    qInfo() << "quit";

    QTextStream stream(stdin);

    bool quit = false;
    while (!quit) {
        qInfo() << "Enter a command:";
        QString line = stream.readLine();

        QStringList list = line.split(" ");
        if (list.size() == 0) {
            quit = true;
            continue;
        }

        QString command = list.at(0).toUpper();
        if (command == "QUIT")
            quit = true;
        else if (command == "LIST")
            inventory.list();
        else if (command == "SAVE")
            inventory.save();
        else if (command == "LOAD")
            inventory.load();

        else if (command == "ADD" || command == "REMOVE") {
            if (list.size() < 3) {
                qWarning() << "Not enough informations";
                continue;
            }

            QString name = list.at(1);
            bool isOk;
            int qty;
            qty = list.at(2).toInt(&isOk);
            if (!isOk) {
                qWarning() << "Invalid quantity!";
                continue;
            }

            if (command == "ADD")
                inventory.add(name, qty);
            else
                inventory.remove(name, qty);
        }
    }

    inventory.save();
    qInfo() << "Complete";

    return 0;
}
