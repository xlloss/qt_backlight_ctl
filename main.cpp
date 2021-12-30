#include "backlight.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Backlight w;
    w.show();
    return a.exec();
}
