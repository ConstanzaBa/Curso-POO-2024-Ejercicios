#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

// Al ser la Clase o tener la frase Q_OBJECT, le habilita crear sus propias señales

class Formulario : public QWidget
{
    Q_OBJECT
private:
        QLabel* lLegajo, *lNombre, *lApellido, *lCaptcha, *lCaptchaValue;
        QLineEdit* leLegajo, *leNombre, *leApellido;
        QPushButton* pbAlta;
        QGridLayout* layout;

public:
    Formulario();

private slots:
    void finalizar_Programa();

};

#endif // FORMULARIO_H
