#ifndef CERTIFIICADO_H
#define CERTIFIICADO_H

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QDateTime>
#include <QPen>
#include <QPainter>
#include <QPixmap>
#include <QMainWindow>
#include "login.h"
#include "ui_login.h"
#include "usuarios.h"

namespace Ui {
class Certifiicado;
}

class Certifiicado : public QMainWindow
{
    Q_OBJECT

public:
    explicit Certifiicado(Usuarios *persona,QWidget *parent = nullptr);
    ~Certifiicado();
    QImage crearimagenconsuperposicion(const QImage& baseImage, const QImage& overlayImage);
private slots:

    void on_cmdGuardar_released();

    void on_cmdFinalizar_released();

private:
    Ui::Certifiicado *ui;
    QString fecha;
    QPixmap pixmap;
    void generarCertificado(QString Cedula, QString Nombre,QString Lugar, int Hora, int Minuto, QString fecha,QString foto);
};

#endif // CERTIFIICADO_H
