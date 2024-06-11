#ifndef EJ16_H
#define EJ16_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Ej16; }
QT_END_NAMESPACE

class Ej16 : public QWidget
{
    Q_OBJECT

public:
    Ej16(QWidget *parent = nullptr);
    ~Ej16();

private:
    Ui::Ej16 *ui;
};
#endif // EJ16_H
