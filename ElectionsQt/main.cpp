#include "electionsqt.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ElectionsQt w;
    w.show();
    return a.exec();
}
