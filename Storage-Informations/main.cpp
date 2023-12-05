#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QStorageInfo>


/* Storage details */
void display(const QStorageInfo& storage, const QString& title)
{
    qInfo() << "-----" << title << "-----";
    qInfo() << "Name:" << storage.name();
    qInfo() << "Display:" << storage.displayName();
    qInfo() << "Root:" << storage.isRoot();
    qInfo() << "Path:" << storage.rootPath();
    qInfo() << "Device:" << storage.device();
    qInfo() << "File system:" << storage.fileSystemType();
    qInfo() << "ReadOnly:" << storage.isReadOnly();
    qInfo() << "Ready:" << storage.isReady();
    qInfo() << "Size:" << storage.bytesTotal() / 1000 / 1000 << "MB";
    qInfo() << "Available:" << storage.bytesAvailable() / 1000 / 1000 << "MB";
    qInfo() << "Free:" << storage.bytesFree() / 1000 / 1000 << "MB";
    qInfo() << "---------------";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* Getting the root */
    QStorageInfo root = QStorageInfo::root();
    display(root, "root");

    /* Mounted devices */
    QList<QStorageInfo> devices = QStorageInfo::mountedVolumes();
    foreach (QStorageInfo device, devices) {
        display(device, device.name());
        qInfo() << "";
    }

    return a.exec();
}
