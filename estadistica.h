#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include <QTextStream>
#include <QPixmap>
#include <QPainter>
#include <QFileDialog>
#include <QStack>
#include "login.h"
#include "ui_login.h"

namespace Ui {
class Estadistica;
}

class Estadistica : public QMainWindow
{
    Q_OBJECT

public:
    explicit Estadistica(QWidget *parent = nullptr);
    ~Estadistica();

    void abrirArchivoVoto ();

private slots:
    void on_actionGuardar_triggered();

    void on_actionPrincipal_triggered();

private:
    Ui::Estadistica *ui;
    
    //Variables para resgitrar lso votos al leer txt

    QString m_contadorNulo;
    QString m_contadorBlanco;
    QString m_contadorLasso;
    QString m_contadorArauz;
    
    //Variables globales para guardar el tamanio de las pilas 
    
    int m_glasso;
    int m_garauz;
    int  m_gblanco;
    int m_gnulo;
    
    //Variables para pintar las estadisticas 
    
    QPixmap lienzo ;
    void dibujar();
    void mostrarPorcentaje ();

    //opcin para guardar

    QImage *m_imagen;
    
    
    
    
};

#endif // ESTADISTICA_H
