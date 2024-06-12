#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui { class Login; }

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    static Login *getInstancia();

private:
    Ui::Login *ui;
    static Login *instancia;

private slots:
    void slot_solicitarValidez();

signals:
    void signal_ingresar();
    void signal_solicitarValidez( QString, QString );
};

#endif // LOGIN_H
