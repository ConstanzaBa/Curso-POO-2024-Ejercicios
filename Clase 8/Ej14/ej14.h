#ifndef EJ14_H
#define EJ14_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Ej14; }
QT_END_NAMESPACE

class Ej14 : public QWidget
{
    Q_OBJECT

public:
    Ej14(QWidget *parent = nullptr);
    ~Ej14();

private:
    Ui::Ej14 *ui;
};
#endif // EJ14_H
