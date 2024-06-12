#include "Pintura.h"
#include "ui_Pintura.h"

Pintura::Pintura(QWidget *parent) : QWidget(parent),
                                    ui(new Ui::Pintura)
{
    ui->setupUi(this);
    setMouseTracking(true);
    paintSize = 1;
    currentColor = 0;

    repaintTimer = new QTimer(this);
    connect(repaintTimer, SIGNAL(timeout()), this, SLOT(slot_keep_painting()));
}

Pintura::~Pintura()
{
    delete ui;
}

void Pintura::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        repaintTimer->start(25);
        qDebug() << "Pintando";
    }
}

void Pintura::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        repaintTimer->stop();
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event) {
    position.setX(event->pos().x());
    position.setY(event->pos().y());
}

void Pintura::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_R) {
        currentColor = 0;
        qDebug() << "Seteado en Rojo";
    } else if (event->key() == Qt::Key_G) {
        currentColor = 1;
        qDebug() << "Seteado en Verde";
    } else if (event->key() == Qt::Key_B) {
        currentColor = 2;
        qDebug() << "Seteado en Azul";
    } else if (event->key() == Qt::Key_Escape) {
        allDrawings.clear();
        eraseCheck = true;
        this->repaint();
    }
}

void Pintura::wheelEvent(QWheelEvent *event) {

    paintSize += event->angleDelta().y() > 0 ? 1 : -1;

    paintSize = qMax(1, paintSize);

    qDebug() << "Número de Pixeles es " << paintSize;
}

void Pintura::slot_keep_painting() {
    this->repaint();
}

void Pintura::paintEvent(QPaintEvent *) {
    QPainter Pintura(this);

    if (eraseCheck == true) {
        eraseCheck = false;
        return;
    }

    if (!allDrawings.empty()) {
        int temp = 0;
        while (temp != allDrawings.size()) {
            if (allDrawings.at(temp).currentColor == 0) {
                Pintura.setPen(Qt::red);
            } else if (allDrawings.at(temp).currentColor == 1) {
                Pintura.setPen(Qt::green);
            } else {
                Pintura.setPen(Qt::blue);
            }

            QPen temp_pen = Pintura.pen();
            temp_pen.setWidth(allDrawings.at(temp).paintSize);
            Pintura.setPen(temp_pen);

            Pintura.drawPoint(allDrawings.at(temp).position);
            temp++;
        }
    }

    if (currentColor == 0) {
        Pintura.setPen(Qt::red);
    } else if (currentColor == 1) {
        Pintura.setPen(Qt::green);
    } else {
        Pintura.setPen(Qt::blue);
    }

    QPen temp_pen = Pintura.pen();
    temp_pen.setWidth(paintSize);
    Pintura.setPen(temp_pen);

    Pintura.drawPoint(position);

    Pintura_Data temp;
    temp.position = position;
    temp.paintSize = paintSize;
    temp.currentColor = currentColor;
    allDrawings.push_front(temp);
}
