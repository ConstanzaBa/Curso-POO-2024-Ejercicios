#include <QCoreApplication>
#include <iostream>
#include "ZonaTrabajo.h"
using namespace std;


int main(int argc, char *argv[])
{
    cout << "---------------------------" << endl;
    cout << "Version de QT actual: ";
    EKFunctions::GET_LATEST_QT_VERSION();
    cout << "---------------------------" << endl;

    cout << "---------------------------" << endl;
    cout << "Version de libreria actual: ";
    EKFunctions::GET_LIBRARY_VERSION();
    cout << "---------------------------" << endl;
}
