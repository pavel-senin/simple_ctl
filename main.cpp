#include "crossroad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Crossroad w;
    w.show();
    return a.exec();
}
