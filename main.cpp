#include <QCoreApplication>
#include "QProcess"

int main()
{
    QProcess process;
    QString appPath = "bin/SNF_gui";

#ifdef Q_OS_LINUX
    QString oldPath = qgetenv("LD_LIBRARY_PATH");
    QByteArray newPath = ("./libs:"+ oldPath).toLocal8Bit();

    QString pathPrefix="./";

    qputenv("LD_LIBRARY_PATH", newPath);
    process.startDetached(pathPrefix + appPath);
#endif
#ifdef Q_OS_WIN32
    QString oldPath = qgetenv("PATH");
    QByteArray newPath = ("libs;"+ oldPath).toLocal8Bit();

    qputenv("PATH", newPath);
    process.startDetached(appPath);
#endif

    return 0;
}
