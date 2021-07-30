#ifndef VOTACION_H
#define VOTACION_H

#include <QMainWindow>
#include <usuarios.h>
#include "certifiicado.h"
#include "ui_certifiicado.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QTextStream>
#include <QDateTime>
#include "votante.h"
#include "certifiicado.h"

namespace Ui {
class Votacion;
}

class Votacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit Votacion(QWidget *parent = nullptr);
    void validacionVoto ();
    void guardarVotos ();

    int m_Voto;

    ~Votacion();

    int getVotoLasso() const;
    void setVotoLasso(int value);

    int getVotoArauz() const;
    void setVotoArauz(int value);

    int getNulo() const;
    void setNulo(int value);

    int getBlanco() const;
    void setBlanco(int value);

    int getVoto() const;
    void setVoto(int Voto);

    Usuarios *getPersona() const;
    void obtenerDatos(Usuarios *persona);
private slots:
    void on_cmdVotar_released();

private:
    Ui::Votacion *ui;

    QList < Votante * > m_datosVotante;

    QString m_nombres;
    QString m_cedula;
    int m_hora;
    int m_minutos;

    int m_votoLasso = 0;
    int m_votoArauz = 0;
    int m_nulo = 0;
    int m_blanco = 0;

    QString m_fecha;

    //Datos para certificado
    QString nombres,cedula, foto, estado;
    int horas, minutos;
    Usuarios *m_persona;

};

#endif // VOTACION_H
