#include <QCoreApplication>


void stats(const QByteArray& data)
{
    qInfo() << "Length" << data.length() << "Capacity" << data.capacity();
    qInfo() << data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /****************************** Creating an array ******************************/
    QByteArray stuff;
    qInfo() << stuff;

    QByteArray data("Hello");
    qInfo() << data;

    QByteArray buffer(10, '\t');
    qInfo() << buffer;

    QByteArray person(QString("Budzio").toLocal8Bit());
    qInfo() << person;

    /****************************** Sizing the array ******************************/
    data.reserve(25);
    stats(data);

    data.resize(10);
    stats(data);

    data.truncate(8);
    stats(data);

    data.clear();
    stats(data);

    /****************************** Modifying the array ******************************/
    data.resize(5);
    data.fill('\x02');
    stats(data);

    data.replace(0, 99, QByteArray("Sweet"));
    stats(data);

    data.fill('*');
    data.insert(3, "Hello World");
    stats(data);

    data.append('!');
    stats(data);

    data.remove(0, 3);
    stats(data);

    /****************************** Reading the data ******************************/
    int first = data.indexOf('*');
    int last = data.lastIndexOf('*');
    qInfo() << "First" << first << "Last" << last;

    if (first > -1 && last > -1)
        qInfo() << data.mid(first, (last - first) + 1);

    data.clear();
    data.append("Budzio Tudzio");

    for (int i = 0; i < data.length(); i++)
        qInfo() << "At" << data.at(i) << "or" << data[i];

    foreach (auto item, data.split(' '))
        qInfo() << "Item" << item;

    /****************************** Encoding the data ******************************/
    qInfo() << "Normal" << data;
    qInfo() << "Repeat" << data.repeated(3);

    data.append("\t\r\n");
    data.insert(0, "      \t\t\t");
    qInfo() << "Trimmed" << data.trimmed();
    qInfo() << "Actual" << data;
    data = data.trimmed();
    qInfo() << "Actual" << data;

    QByteArray hex = data.toHex();
    qInfo() << "Hex" << hex;
    QByteArray from_hex = QByteArray::fromHex(hex);
    qInfo() << "From hex" << from_hex;

    QByteArray base64 = data.toBase64();
    qInfo() << "Base64" << base64;
    QByteArray from_base64 = QByteArray::fromBase64(base64);
    qInfo() << "From base64" << from_base64;


    return a.exec();
}
