#include <QCoreApplication>
#include "QProcess"

int main(int argc, char *argv[])
{
    QProcess process;
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();

#ifdef Q_OS_LINUX
    env.insert("LD_LIBRARY_PATH", "./libs:" + env.value ("LD_LIBRARY_PATH"));
    process.setProcessEnvironment(env);
    process.start("./SNF_gui");
#endif
#ifdef Q_OS_WIN32
    env.insert("PATH", "libs;" + env.value("PATH"));
    process.setProcessEnvironment(env);
    process.start("SNF_gui");
#endif

    process.waitForFinished(-1);

    return 0;
}
