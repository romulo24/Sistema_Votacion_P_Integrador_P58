#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <QMainWindow>

#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QTextStream>
#include "estadistica.h"
#include "ui_estadistica.h"
#include <QSet>

namespace Ui {
class Administrador;
}

class Administrador : public QMainWindow
{
    Q_OBJECT

public:
    explicit Administrador(QWidget *parent = nullptr);

    ~Administrador();

private slots:
    void on_cmdIngresarAdmin_released();

private:
    Ui::Administrador *ui;

    //variables globales

    QString m_contrasenia;

    //SET
    QSet < QString > admin;
};

#endif // ADMINISTRADOR_H
