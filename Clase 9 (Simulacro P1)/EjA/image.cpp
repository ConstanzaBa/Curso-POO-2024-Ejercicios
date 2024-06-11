// image.cpp

#include <image.h>

Image::Image() {
    layout = new QGridLayout;

    QWidget::setWindowTitle("Imágen");

    QString url = R"("#")"; // ruta de acceso imagen
    QPixmap img(url);

    lImage = new QLabel(this);
    lImage->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    lImage->setScaledContents(true);
    lImage->setMaximumSize(100, 100);
    lImage->setPixmap(img);

    lImage->setFrameShape(QFrame::Panel);
    lImage->setFrameShadow(QFrame::Sunken);
    lImage->setLineWidth(3);
    lImage->QFrame::setStyleSheet("QFrame { background-color:blue; }");

    layout->addWidget(lImage, 0, 1, 1, 1, Qt::AlignCenter);
    this->setLayout(layout);
    this->repaint();
}
