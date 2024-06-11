// Ventana.cpp

#include <ventana.h>

Ventana::Ventana() {
    pbSiguiente = new QPushButton("Siguiente");
    pbAnterior = new QPushButton("Anterior");
    layout = new QGridLayout();

    layout->addWidget(pbSiguiente, 0, 1, 1, 1);
    layout->addWidget(pbAnterior, 0, 2, 1, 1);
    this->setLayout(layout);

    QString filePath = "#"; // ruta de acceso imagen
    QFile inputFile(filePath);
    int POS = 0;
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            if (POS == 0) {
                lineone = in.readLine();
            } else if (POS == 1) {
                linetwo = in.readLine();
            } else {
                linethree = in.readLine();
            }
            POS++;
        }
        inputFile.close();
    }

    QObject::connect( pbSiguiente, SIGNAL( clicked(bool) ), this , SLOT( slot_Siguiente() ) );
    QObject::connect( pbAnterior, SIGNAL( clicked(bool) ), this , SLOT( slot_Anterior() ) );

    if (posicion == 1) {
        img_one();
    } else if (posicion == 2) {
        img_two();
    } else {
        img_three();
    }

}

void Ventana::img_one() {
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QString urlString = lineone;
    QUrl url(urlString);
    QNetworkRequest request(url);
    manager->get(request);

    qDebug() << "img uno";
}

void Ventana::img_two() {
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QString urlString = linetwo;
    QUrl url(urlString);
    QNetworkRequest request(url);
    manager->get(request);

    qDebug() << "img dos";
}

void Ventana::img_three() {
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QString urlString = linethree;
    QUrl url(urlString);
    QNetworkRequest request(url);
    manager->get(request);

    qDebug() << "img tres";
}

void Ventana::slot_descargaFinalizada(QNetworkReply* reply) {
    img = QImage::fromData(reply->readAll());
    this->repaint();
    qDebug() << "descarga finalizada";
}

void Ventana::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if(!img.isNull()) {
        this->show();
        painter.drawImage(0, 0, img.scaled(this->size()));
        qDebug() << "no es nula la imagen";
    }
}

void Ventana::slot_Siguiente() {
    switch (posicion) {
        case 1:
            posicion++;
            img_two();
            break;
        case 2:
            posicion++;
            img_three();
            break;
        case 3:
            posicion = 1;
            img_one();
            break;
    }
}

void Ventana::slot_Anterior() {
    switch (posicion) {
        case 1:
            posicion = 3;
            img_three();
            break;
        case 2:
            posicion = 1;
            img_one();
            break;
        case 3:
            posicion = 2;
            img_two();
            break;
    }
}
