#include "login.h"

Login::Login() {

    bloq = new Bloqueado();

    lBienvenido = new QLabel("Bienvenido");
    lBienvenido->setAlignment(Qt::AlignCenter);
    QFont fontBienvenido = lBienvenido->font();
    fontBienvenido.setBold(true);
    fontBienvenido.setPointSize(12);
    lBienvenido->setFont(fontBienvenido);

    lTemperatura = new QLabel("Temperatura Actual: ");
    leTemperatura = new QLineEdit();
    leTemperatura->setEnabled(false);

    lUsuario = new QLabel("Usuario");
    lClave = new QLabel("Clave");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    leClave->setEchoMode( QLineEdit::Password );
    pbEntrar = new QPushButton("Entrar");
    pbEsconderTemperatura = new QPushButton("Esconder Temperatura");

    layout = new QGridLayout;
    layout->addWidget(lBienvenido, 0, 0, 1, 3);
    layout->addWidget(lTemperatura, 1, 0, 1, 1);
    layout->addWidget(leTemperatura, 1, 1, 1, 2);
    layout->addWidget(lUsuario, 2, 0, 1, 1);
    layout->addWidget(lClave, 3, 0, 1, 1);
    layout->addWidget(leUsuario, 2, 1, 1, 2);
    layout->addWidget(leClave, 3, 1, 1, 2);
    layout->addWidget(pbEntrar, 4, 0, 1, 3);
    layout->addWidget(pbEsconderTemperatura, 5, 0, 1, 3);

    QObject::connect( pbEntrar, SIGNAL( clicked(bool) ), this , SLOT( slot_validarUsuario() ) );
    QObject::connect( pbEsconderTemperatura, SIGNAL( clicked(bool) ), this , SLOT( slot_esconderTemperatura() ) );
    this->setLayout(layout);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_descargaFinalizada(QNetworkReply * )));
    QNetworkRequest request(QUrl("https://media.geeksforgeeks.org/wp-content/uploads/20230426115225/computer-image-660.jpg"));
    manager->get(request);

    Clima* clima = new Clima(-31.4135, -64.18105);
    connect(clima, &Clima::ClimaChanged, this, &Login::slot_actualizarTemperatura);
    clima->obtenerTemperatura();
}

void Login::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if(!im.isNull()) {
        painter.drawImage(0, 0, im.scaled(this->size()));
        QLabel* lURL = new QLabel("URL IMG: https://media.geeksforgeeks.org/wp-content/uploads/20230426115225/computer-image-660.jpg");
        lURL->setAlignment(Qt::AlignCenter);
        layout->addWidget(lURL, 6, 0, 1, 0);
    }
}

void Login::slot_esconderTemperatura() {
    if (leTemperatura->echoMode() == QLineEdit::Normal) {
        leTemperatura->setEchoMode(QLineEdit::NoEcho);
    } else {
        leTemperatura->setEchoMode(QLineEdit::Normal);
    }
}

void Login::slot_descargaFinalizada(QNetworkReply* reply) {
    im = QImage::fromData(reply->readAll());
    this->repaint();
}

void Login::slot_actualizarTemperatura(const QString &temperatura) {
    leTemperatura->setText(temperatura);
}

void Login::slot_validarUsuario() {
    if (admindb->validarUsuario( "usuarios", leUsuario->text(), leClave->text()))  {
            form = new Formulario();
            form->show();
            this->close();
        } else {
        intentos++;
        if(intentos == 3) {
            bloq->show();
            this->hide();
            double time = (1000 * (60 * 5));
            QTimer::singleShot(time, this, SLOT(slot_end_block()));
        }
        leClave->clear();
    }
}

void Login::slot_bloqueado() {
    bloq->hide();
    this->show();
    intentos = 0;
}
