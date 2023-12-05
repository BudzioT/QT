#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>


void compileTest()
{
#ifdef Q_OS_MACROS
    qDebug() << "This is mac";
#endif

#ifdef Q_OS_LINUX
    qDebug() << "This is linux";
#endif

#ifdef Q_OS_WIN
    qDebug() << "This is windows";
#endif

#ifdef Q_OS_WIN32
    qDebug() << "This is Windows 32 bit";
#endif

#ifdef Q_OS_WIN64
    qDebug() << "This is Windows 64 bit";
#endif
}

void runtimeTest()
{
    QSysInfo system;
    qInfo() << "prettyProductName:" << system.prettyProductName();
    qInfo() << "productType:" << system.productType();
    qInfo() << "productVersion:" << QSysInfo::productVersion(); /* Functions are static */
    qInfo() << "machineHostName:" << QSysInfo::machineHostName();
    qInfo() << "machineUniqueId:" << system.machineUniqueId();
    qInfo() << "currentCpuArchitecture:" << system.currentCpuArchitecture();
    qInfo() << "buildCpuArchitecture:" << system.buildCpuArchitecture();
    qInfo() << "buildAbi:" << system.buildAbi();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    compileTest();
    runtimeTest();

    return a.exec();
}
