#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>


/* Current folder */
void test_current()
{
    qInfo() << QDir::currentPath();

    QDir dir;
    qInfo() << dir.absolutePath();
}

/* Listing */
void test_list(const QString& path, bool recursive = false)
{
    QDir root(path);
    if (!root.exists()) {
        qWarning() << "Path not found:" << path;
        return;
    }

    QFileInfoList list = root.entryInfoList(QDir::Filter::NoDotAndDotDot | QDir::Filter::AllEntries);
    foreach (const QFileInfo& info, list) {
        qInfo() << "--------------------";
        qInfo() << "Name:" << info.fileName();
        qInfo() << "Path:" << info.path();
        qInfo() << "Absolute:" << info.absoluteFilePath();
        qInfo() << "Created:" << info.birthTime().toString();
        qInfo() << "Modified:" << info.lastModified().toString();
        qInfo() << "Size:" << info.size();

        QString type = "Unknown";
        info.isDir() ? type = "Dir" : type = "File";
        qInfo() << "Type:" << type;

        if (recursive && info.isDir())
            test_list(info.absoluteFilePath(), recursive);
    }
}

/* Modifying */
void test_modify(QDir root)
{
    if (root.exists("test")) {
        qInfo() << "Test folder already exists";
        return;
    }

    if (root.mkdir("test")) {
        QDir dir("test");
        qInfo() << "Created" << dir.absolutePath();

        if (root.rename("test", "test2")) {
            qInfo() << "Renamed" << dir.absolutePath();
            qInfo() << "Test" << dir.exists();

            if (root.exists("test2")) {
                if (!root.rmdir("test2")) {
                    qInfo() << "Failed - couldn't remove the directory";
                }
            }
        }
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //test_current();
    //test_list(QDir::currentPath(), true);
    test_modify(QDir::current());

    return a.exec();
}
