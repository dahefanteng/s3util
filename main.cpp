#include <QCoreApplication>
#include <QTimer>
#include "s3consolemanager.h"
#include <QStringList>
#include <QDebug>
#include <iostream>
#include <QObject>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qWarning() << "enter main" << "\n";

    S3ConsoleManager m;
    QObject::connect(&m,SIGNAL(Finished()),&a,SLOT(quit()));
    QTimer::singleShot(0, &m, SLOT(Execute()));
//    QCoreApplication::quit();
    return a.exec();
}

