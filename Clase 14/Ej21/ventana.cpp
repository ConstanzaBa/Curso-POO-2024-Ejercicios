#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
    connect(ui->pbVolver, SIGNAL(clicked()), this, SIGNAL(BackToLogin()));

}

Ventana::~Ventana()
{
    delete ui;
}
