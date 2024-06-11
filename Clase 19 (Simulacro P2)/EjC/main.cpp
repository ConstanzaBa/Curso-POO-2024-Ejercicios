#include "login.h"

#include <QApplication>
#include "manager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Manager w;
    w.iniciar();
    return a.exec();
}
