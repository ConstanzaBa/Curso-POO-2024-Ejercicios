#ifndef LOGIN_H
#define LOGIN_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <formulario.h>

// Al ser la Clase o tener la frase Q_OBJECT, le habilita crear sus propias señales

class Login : public QWidget {
    Q_OBJECT
    private:
        QLabel* lUsuario, *lClave;
        QLineEdit* leUsuario, *leClave;
        QPushButton* pbEntrar;
        QGridLayout* layout;

    public:
        Login();

    private slots:
        void slot_validarUsuario(); // Sintaxis: slots_(funcion)
};

#endif // LOGIN_H
