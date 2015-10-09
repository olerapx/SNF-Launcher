#include <QCoreApplication>
#include "QProcess"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QProcess cmd;
    cmd.setWorkingDirectory(a.applicationDirPath());
    QProcessEnvironment env=QProcessEnvironment::systemEnvironment();
#ifdef Q_OS_LINUX
    env.insert("LD_LIBRARY_PATH", "./libs");
    cmd.setProcessEnvironment(env);
    cmd.start("./SNF_gui");
#endif
#ifdef Q_OS_WIN32
    env.insert("Path", env.value("path")+";libs");
    cmd.setProcessEnvironment(env);
    cmd.start("SNF_gui");
#endif

    cmd.waitForFinished(-1);

    return 0;
}
