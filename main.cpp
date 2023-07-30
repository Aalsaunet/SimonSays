#include "simonsays.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimonSays w(&a);
    w.show();
    return a.exec();
}
