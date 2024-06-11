#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QPaintEvent>

class Boton : public QWidget
{
    Q_OBJECT
public:
    explicit Boton(QWidget *parent = nullptr);
    enum Color { Azul, Verde, Magenta, Rojo, Violeta };
    void setColor(Color co);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Color color;

signals:
    void signal_click();
};

#endif // BOTON_H
