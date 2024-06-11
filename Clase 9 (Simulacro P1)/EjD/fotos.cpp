// Fotos.cpp

#include <fotos.h>

Fotos::Fotos() {
    lBienvenida = new QLabel("Bienvenido!");
    lBienvenida->setAlignment(Qt::AlignCenter);
    QFont fontBienvenida = lBienvenida->font();
    fontBienvenida.setBold(true);
    fontBienvenida.setPointSize(12);
    lBienvenida->setFont(fontBienvenida);

    lDescripcion = new QLabel("Aplicación de Fotos.");
    lDescripcion->setAlignment(Qt::AlignCenter);
    pbIngresar = new QPushButton("COMENZAR");
    layout = new QGridLayout(this);
    layout->addWidget(lBienvenida, 0, 1, 1, 1);
    layout->addWidget(lDescripcion, 1, 1, 1, 1);
    layout->addWidget(pbIngresar, 2, 1, 2, 2);
    this->setLayout(layout);
    connect(pbIngresar, SIGNAL( clicked(bool) ), this , SLOT( slot_Iniciar() ) );
}

void Fotos::slot_Iniciar() {
    ventana = new Ventana();
    this->hide();
    ventana->show();
}
