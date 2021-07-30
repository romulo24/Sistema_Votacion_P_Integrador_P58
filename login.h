#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "votacion.h"
#include <usuarios.h>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QtDebug>
#include "ui_administrador.h"
#include "administrador.h"
#include "acercade.h"

QT_BEGIN_NAMESPACE

namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void GuardarVotantes(QString m_cedula);
    bool VerificarsiVoto(QString m_cedula);
private slots:
    void on_cmdIngresar_clicked();
    void leerPadronElectoral();
    void on_action_Iniciar_sesion_triggered();
    void on_action_Salir_triggered();
    void on_actionA_cerca_de_triggered();

private:
    Ui::Login *ui;
    QList<Usuarios*>m_usuarios;
    Usuarios *m_persona;
    void validarCedula();
    QString m_cedula;
};
#endif // LOGIN_H
