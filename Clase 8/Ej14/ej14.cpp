#include "ej14.h"
#include "ui_ej14.h"

Ej14::Ej14(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ej14)
{
    ui->setupUi(this);
}

Ej14::~Ej14()
{
    delete ui;
}

