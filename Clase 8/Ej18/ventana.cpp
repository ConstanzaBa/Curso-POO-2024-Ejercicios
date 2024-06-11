#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager( this );

    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(Reply(QNetworkReply *)));

}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter){
        QUrl url(ui->leUrl->text());
        QNetworkRequest request(url);
        manager->get(request);
    }

}

void Ventana::Reply(QNetworkReply *reply){

    if (reply->error() == QNetworkReply::NoError) {
           QString html = reply->readAll();
           ui->teHtml->setHtml(html);
       } else {
          ui->teHtml->setPlainText("Error: " + reply->errorString());
       }
       reply->deleteLater();
}
