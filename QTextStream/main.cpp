#include <QCoreApplication>
#include <QTextStream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* QTextStream */
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    /* Endl */
    qout << "Please enter your name" << Qt::endl;

    /* Reading */
    QString name = qin.readLine();

    /* Flushing */
    qout << "You entered " << name << '\n';
    qout << "Please enter your age: " << '\n';
    qout.flush();

    /* Example */
    bool isAgeOk;
    int age = qin.readLine().toInt(&isAgeOk);

    if (isAgeOk)
        qout << "You are " << age << " years old" << '\n';
    else
        qout << "You haven't been able to enter a valid number!" << '\n';
    qout.flush();

    return a.exec();
}
