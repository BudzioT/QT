#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>

#include <iostream>

#include "test.h"


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    }
}

void test()
{
    qDebug() << "test";
    qInfo() << "test";
    qWarning() << "test";
    qCritical() << "test";
    //qFatal() << "Fatal message";

    Test test;
    test.msg();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* Setup */
    QTextStream qin(stdin);
    std::cout << "Starting" << std::endl;

    bool running = true;
    do {
        std::cout << "Running a command (start, stop, test or exit)" << std::endl;
        QString command = qin.readLine();
        qInfo() << "You entered:" << command;

        /* Install */
        if (command.toUpper() == "START")
            qInstallMessageHandler(myMessageOutput);

        /* Uninstall */
        else if (command.toUpper() == "STOP")
            qInstallMessageHandler(0);

        /* Test */
        else if (command.toUpper() == "TEST")
            test();

        /* Exit */
        else if (command.toUpper() == "EXIT")
            running = false;
    } while (running);

    std::cout << "Finished" << std::endl;

    return a.exec();
}
