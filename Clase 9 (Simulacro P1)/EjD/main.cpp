#include "fotos.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fotos w;
    w.show();
    return a.exec();
}
