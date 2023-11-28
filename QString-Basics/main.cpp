#include <QCoreApplication>

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /********************** Creating **********************/
    QString line("Hello World!");
    qInfo() << line;

    QString name;
    name = "Budzio Tudzio";
    qInfo() << name;

    int num1 = 123;
    int num2 = 456;
    /* Can use variables with the help of '%' and .arg function! */
    QString status = QString("Processing numbers %1 and %2").arg(num1).arg(num2);
    qInfo() << status;

    /********************** Reading each char **********************/
    for (int i = 0; i < line.length(); i++) {
        QChar ch = line[i];
        qInfo() << ch;
    }

    /********************** Comparing and searching **********************/
    /* Can set case sensitivity (default is sensentive)! */
    qInfo() << "Compare" << line.compare("hello world", Qt::CaseSensitivity::CaseSensitive);
    qInfo() << "Starts" << line.startsWith("hello", Qt::CaseInsensitive);
    qInfo() << "Ends" << line.endsWith("world", Qt::CaseInsensitive);
    qInfo() << "Contains" << line.contains("world");
    qInfo() << "Index" << line.indexOf("World");

    /********************** Modifying and parsing **********************/
    line.append("\r\nHow are you?");
    qInfo() << "Escape" << line;
    line.append("\r\n<i>This</i>is HTML<br>");
    qInfo() << "HTML" << line.toHtmlEscaped();

    line.replace('?', '!');
    qInfo() << "Replaced" << line;

    qInfo() << "Upper" << line.toUpper();
    qInfo() << "Lower" << line.toLower();
    qInfo() << "Mid" << line.mid(3, 5);

    QStringList list = line.split("\n");
    foreach(QString item, list)
        qInfo() << "item" << item.trimmed(); /* trims the white characters in this example '\r' */

    /********************** Conversion **********************/
    std::cout << "std " << line.toStdString() << std::endl;

    qInfo() << "UTF8" << line.toUtf8();
    qInfo() << "Base64" << line.toUtf8().toBase64(); /* Working with QByteArray */
    qInfo() << "Hex" << line.toUtf8().toHex();

    return a.exec();
}
