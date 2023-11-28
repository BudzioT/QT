#include <QCoreApplication>

#include <iostream>

void writeName(QString &name)
{
    name.insert(0, "Mr. ");
    qInfo() << name;
}

void readOnly(QStringView name) /* It is fast, becuase it is only a pointer, not the whole string */
{
    qInfo() << "Name" << name.data() << name;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString firstName = "Budzio";
    QString lastName = "Tudzio";

    qInfo() << "Original" << firstName;
    qInfo() << "Name" << firstName.data() << firstName;
    readOnly(firstName);

    QString fullname = firstName + ' ' + lastName;
    foreach (QStringView part, fullname.split(' ')) {
        qInfo() << "part" << part;
        if (part.startsWith(firstName, Qt::CaseInsensitive)) {
            qInfo() << "First name detected!";
            readOnly(firstName.mid(1, 3));
        }

    }

    return a.exec();
}
