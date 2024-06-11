#ifndef EJ15_H
#define EJ15_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Ej15; }
QT_END_NAMESPACE

class Ej15 : public QWidget
{
    Q_OBJECT

public:
    Ej15(QWidget *parent = nullptr);
    ~Ej15();

private:
    Ui::Ej15 *ui;
};
#endif // EJ15_H
