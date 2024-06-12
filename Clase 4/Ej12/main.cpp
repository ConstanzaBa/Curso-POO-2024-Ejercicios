#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label;

    QPixmap imagen("#"); // ruta de acceso imagen

    label.setPixmap(imagen);

    label.setFixedSize(imagen.size());

    label.showMaximized();

    QTimer::singleShot(3000, &app, SLOT(quit()));

    return app.exec();
}
