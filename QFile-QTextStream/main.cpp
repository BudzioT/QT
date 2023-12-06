#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>


void basics()
{
    QFile file("test.txt");
    if (!file.open(QFile::ReadWrite)) {
        qCritical() << "Couldn't open the file:";
        qCritical() << file.errorString();
        return;
    }

    qInfo() << "Writing file...";
    file.write(QByteArray("Hello World"));
    file.flush(); /* Pushes the data to the device */

    qInfo() << "Reading file...";
    file.seek(0);
    qInfo() << file.readAll();

    file.close(); /* Automatically flushes */
}

bool writeFile(const QString& fileName)
{
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly)) {
        qCritical() << file.errorString();
        return false;
    }

    QTextStream stream(&file);
    for (int i = 0; i < 5; i++) {
        stream << QString::number(i) << " Hello World\r\n";
    }

    file.close();
    return true;
}

void readFile(const QString& fileName)
{
    QFile file(fileName);

    if (!file.exists()) {
        qCritical() << "File not found";
        return;
    }

    if (!file.open(QFile::ReadOnly)) {
        qCritical() << file.errorString();
        return;
    }

    QTextStream stream(&file);
    //QString data = stream.readAll();
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        qInfo() << line;
    }


    file.close();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //basics();
    //writeFile("test.txt");
    readFile("test.txt");

    return a.exec();
}
