#include "votacion.h"
#include "ui_votacion.h"

Votacion::Votacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Votacion)
{
    ui->setupUi(this);
    m_fecha = QDateTime::currentDateTime().toString("dd/MM/yyyy");
}

void Votacion::validacionVoto()
{
    // Obtenemos el valor entero voto de checkbox
    m_votoLasso = ui->inLasso->checkState();
    m_votoArauz = ui->inArauz->checkState();

    // ( 1 = LASSO ) (2 = ARAUZ) (3 = BLANCO ) ( 4 = NULO )
    if((m_votoLasso == 2) && (m_votoArauz == 0) ){
        m_Voto = 1;
    }
    if((m_votoArauz == 2) && (m_votoLasso == 0)){
        m_Voto = 2;
    }
    if((m_votoLasso == 0) && (m_votoArauz == 0)){
        m_Voto = 3;
    }
    if((m_votoLasso == 2 ) && (m_votoArauz == 2 )){
        m_Voto = 4;
    }
}

void Votacion::guardarVotos()
{
    QFile archivoVoto;          //Variable para acceder a los txt
    QTextStream lectura;        //Lectura de archivos

    int registroVotoHora  = QDateTime::currentDateTime().time().hour();             //Obtenemos las horas
    int registroVotoMinuto = QDateTime::currentDateTime().time().minute();           //Obtenemos los minutos

    QString hora = QString::number(registroVotoHora);
    QString minutos = QString::number(registroVotoMinuto);

    m_datosVotante.append(new Votante(m_Voto, hora, minutos));                      //Constructor

    archivoVoto.setFileName("C:/Users/Usuario/Desktop/Login/Recursos/Votaciones.txt"); //Ruta del txt a guardar info

    archivoVoto.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text);
    if(!archivoVoto.isOpen()){
        QMessageBox::warning(0,"AVISO","No se pudo guardar la informacion del Votante");
        return ;
    }

    lectura.setDevice(&archivoVoto);
    lectura << m_Voto<<";"
            << m_datosVotante.at(0)->horaR() << ";"
            << m_datosVotante.at(0)->minutosR() << endl;

    archivoVoto.close();
    this->hide();
}
int Votacion::getVoto() const
{
    return m_Voto;
}

void Votacion::setVoto(int Voto)
{
    m_Voto = Voto;
}

Votacion::~Votacion()
{
    delete ui;
}

Usuarios *Votacion::getPersona() const
{
    return m_persona;
}

void Votacion::obtenerDatos(Usuarios *persona)
{
    m_persona = persona;
    ui->Usuario->setText("Nombre: " + m_persona->getNombre());
    ui->outCedula->setText("Cedula: " + m_persona->getCedula());
}

int Votacion::getBlanco() const
{
    return m_blanco;
}

void Votacion::setBlanco(int value)
{
    m_blanco = value;
}

int Votacion::getNulo() const
{
    return m_nulo;
}

void Votacion::setNulo(int value)
{
    m_nulo = value;
}

int Votacion::getVotoArauz() const
{
    return m_votoArauz;
}

void Votacion::setVotoArauz(int value)
{
    m_votoArauz = value;
}

int Votacion::getVotoLasso() const
{
    return m_votoLasso;
}

void Votacion::setVotoLasso(int value)
{
    m_votoLasso = value;
}

void Votacion::on_cmdVotar_released()
{
    // Analizamos el voto del ciudadano
    validacionVoto();
    guardarVotos();

    Certifiicado *cert = new Certifiicado(m_persona,this);
    this->hide();
    cert->show();
}
