#include "ej15.h"
#include "ui_ej15.h"

Ej15::Ej15(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ej15)
{
    ui->setupUi(this);
}

Ej15::~Ej15()
{
    delete ui;
}

