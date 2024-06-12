#include "manager.h"
#include "login.h"
#include "ventana.h"
#include "admindb.h"

Manager::Manager(QObject *parent) : QObject(parent), ventana(new Ventana())
{
    connect(Login::getInstancia(), SIGNAL(signal_solicitarValidez(QString,QString)), this, SLOT(slot_validarUsuario(QString,QString)));
    connect(this->ventana, SIGNAL(signal_volver()), Login::getInstancia(), SLOT(show()));
}

void Manager::iniciar()
{
    Login::getInstancia()->show();
}

void Manager::slot_validarUsuario(QString usuario, QString clave)
{
    AdminDB::getInstancia()->conectar("../EjC/base.sqlite");
    if(!AdminDB::getInstancia()->validarUsuario(usuario, clave).empty()) {
        Login::getInstancia()->hide();
        this->ventana->show();
    }
}
