#include <QCoreApplication>
#include "QProcess"

int main(int argc, char *argv[])
{
    QProcess process;

#ifdef Q_OS_LINUX
    QString oldPath = qgetenv("LD_LIBRARY_PATH");
    QByteArray newPath = ("./libs:"+ oldPath ).toLocal8Bit();
    qputenv("LD_LIBRARY_PATH", newPath);
    process.startDetached("./bin/SNF_gui");
#endif
#ifdef Q_OS_WIN32
    QString oldPath = qgetenv("PATH");
    QByteArray newPath = ("libs;"+ oldPath ).toLocal8Bit();
    qputenv("PATH", newPath);
    process.startDetached("bin/SNF_gui");
#endif

    return 0;
}
