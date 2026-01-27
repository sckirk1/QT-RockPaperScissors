#include "rockpaperscissorswindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RockPaperScissorsWindow w;
    w.show();
    return a.exec();
}
