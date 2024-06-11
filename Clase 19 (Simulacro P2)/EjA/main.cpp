#include <QApplication>
#include "principal.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Principal principal;
    principal.show();

    return a.exec();
}
