#include "ventana.h"
#include "ui_ventana.h"

#include <QGridLayout>
#include <QLabel>
#include <QFont>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QNetworkRequest request(QUrl("https://freshprompts-blog-images.s3.amazonaws.com/background-drawing-ideas/color.jpg"));
    manager->get(request);

    ui->b1->setColor( Boton::Rojo );
    ui->b2->setColor( Boton::Magenta );
    ui->b3->setColor( Boton::Violeta );
    ui->b4->setColor( Boton::Azul );
    ui->b5->setColor( Boton::Verde );

    ui->b1->setFixedHeight(70);
    ui->b2->setFixedHeight(70);
    ui->b3->setFixedHeight(70);
    ui->b4->setFixedHeight(70);
    ui->b5->setFixedHeight(70);


    QGridLayout* layout = new QGridLayout;
    QLabel* label = new QLabel;
    QFont* font = new QFont;
    QPalette* palette = new QPalette;
    palette->setColor(QPalette::WindowText, Qt::white);

    font->setBold(true);
    font->setPointSize(10);

    connect(ui->b1, SIGNAL(signal_click()), this, SLOT(close()));
    label->setText("Mi Dentista");
    label->setFont(*font);
    label->setPalette(*palette);
    layout->addWidget(label, 0, 0, 1, 1, Qt::AlignLeft);
    ui->b1->setLayout(layout);

    layout = new QGridLayout;
    label = new QLabel;

    connect(ui->b2, SIGNAL(signal_click()), this, SLOT(close()));
    label->setText("Visitas");
    label->setFont(*font);
    label->setPalette(*palette);
    layout->addWidget(label, 0, 0, 1, 1, Qt::AlignLeft);
    ui->b2->setLayout(layout);

    layout = new QGridLayout;
    label = new QLabel;

    connect(ui->b3, SIGNAL(signal_click()), this, SLOT(close()));
    label->setText("Técnicas de Higiene");
    label->setFont(*font);
    label->setPalette(*palette);
    layout->addWidget(label, 0, 0, 1, 1, Qt::AlignLeft);
    ui->b3->setLayout(layout);

    layout = new QGridLayout;
    label = new QLabel;

    connect(ui->b4, SIGNAL(signal_click()), this, SLOT(close()));
    label->setText("Mi Boca");
    label->setFont(*font);
    label->setPalette(*palette);
    layout->addWidget(label, 0, 0, 1, 1, Qt::AlignLeft);
    ui->b4->setLayout(layout);

    layout = new QGridLayout;
    label = new QLabel;

    connect(ui->b5, SIGNAL(signal_click()), this, SLOT(close()));
    label->setText("Hora de Cepillarse");
    label->setFont(*font);
    label->setPalette(*palette);
    layout->addWidget(label, 0, 0, 1, 1, Qt::AlignLeft);
    ui->b5->setLayout(layout);
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::slot_descargaFinalizada(QNetworkReply* reply) {
    im = QImage::fromData(reply->readAll());
    this->repaint();
    this->show();
}

void Ventana::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if(!im.isNull()) {
        painter.drawImage(0, 0, im.scaled(this->size()));
    }
}
