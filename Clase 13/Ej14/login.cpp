#include "login.h"
#include "ui_login.h"

Login* Login::instancia = nullptr;

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    this->ui->setupUi(this);
    this->ui->leUsuario->setFocus();

    connect(this->ui->pbIngresar, SIGNAL(pressed()), this, SLOT(slot_solicitarValidez()));
    connect(this->ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_solicitarValidez()));
}

Login::~Login()
{
    delete ui;
}

Login *Login::getInstancia()
{
    instancia = instancia ? instancia : new Login();
    return instancia;
}

void Login::slot_solicitarValidez()
{
    emit signal_solicitarValidez(this->ui->leUsuario->text(),this->ui->leClave->text());
}
