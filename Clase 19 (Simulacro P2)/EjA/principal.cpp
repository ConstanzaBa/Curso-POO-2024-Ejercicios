#include "principal.h"
#include "ui_principal.h"

#include <QDebug>
#include <QPainter>
#include "linea.h"


Principal::Principal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::conectarYleerLinea()
{
        if (!AdminDB::getInstancia()->conectar("../EjA/db.sqlite")) {
            qDebug()<< "Error al conectar a la base de datos." ;
            return;
        }

        int x_inicial, y_inicial, x_final, y_final;
        if (AdminDB::getInstancia()->leerLinea(1, x_inicial, y_inicial, x_final, y_final)) {
            Linea linea(x_inicial, y_inicial, x_final, y_final);

        } else {
           qDebug() << "No se encontró el registro con id = 1.";
        }
}

void Principal::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

        if (linea) {
            QPainter painter(this);
            painter.setPen(QPen(Qt::blue, 2));
            painter.drawLine(linea->getX_inicial(), linea->getY_inicial(),
                             linea->getX_final(), linea->getY_final());
        }
}

