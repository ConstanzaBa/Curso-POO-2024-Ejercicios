#include "boton.h"

#include <QPainter>

Boton::Boton(QWidget *parent) : QWidget(parent) {}

void Boton::setColor(Color co)
{
    color = co;
    this->repaint();
}

void Boton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if (color == Color::Azul) {
        painter.fillRect(0, 0, this->width(), this->height(), QColor(0, 0, 255, 128));
    } else if (color == Color::Verde) {
        painter.fillRect(0, 0, this->width(), this->height(), QColor(0, 255, 0, 128));
    } else if (color == Color::Magenta) {
        painter.fillRect(0, 0, this->width(), this->height(), QColor(255, 0, 255, 128));
    } else if (color == Color::Rojo) {
        painter.fillRect(0, 0, this->width(), this->height(), QColor(255, 0, 0, 128));
    } else if(color == Color::Violeta) {
        painter.fillRect(0,0, this->width(), this->height(), QColor(128, 0, 128, 128));
    } else {
        painter.fillRect(0, 0, this->width(), this->height(), QColor(0, 255, 0, 128));
    }
}

void Boton::mousePressEvent(QMouseEvent *event) {
    emit signal_click();
}
