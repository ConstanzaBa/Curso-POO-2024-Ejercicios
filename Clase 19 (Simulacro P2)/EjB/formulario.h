#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QVector>

#include "instrumento.h"
#include "guitarra.h"
#include "teclado.h"
#include "viento.h"

namespace Ui { class Formulario; }

class Formulario : public QWidget {
    Q_OBJECT

public:
    Formulario(QWidget *parent = nullptr);
    ~Formulario();

private slots:
    void agregarInstrumentoButton();
    void verStockButton();
    void tipoInstrumentoComboBox(int index);


private:
    Ui::Formulario *ui;
    QVector<Instrumento *> instrumentos;
};
#endif // FORMULARIO_H
