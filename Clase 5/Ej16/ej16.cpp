#include "ej16.h"
#include "ui_ej16.h"

Ej16::Ej16(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ej16)
{
    ui->setupUi(this);
}

Ej16::~Ej16()
{
    delete ui;
}

