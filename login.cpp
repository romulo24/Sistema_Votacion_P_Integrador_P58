#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    leerPadronElectoral();
}

Login::~Login()
{
    delete ui;
}

void Login::GuardarVotantes(QString m_cedula)
{
    QFile archivoVoto;
    QTextStream lectura;
    archivoVoto.setFileName("C:/Users/Usuario/Desktop/Login/Recursos/VotacionesRealizadas.txt");
    archivoVoto.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text);
    if(!archivoVoto.isOpen()){
        QMessageBox::warning(0,"AVISO","No se pudo guardar la informacion del Votante");
        return ;
    }
    if(m_cedula.isEmpty())
    {
        return;
    }else{
        lectura.setDevice(&archivoVoto);
        lectura << m_cedula << endl;
        archivoVoto.close();
        this->hide();
    }
}

bool Login::VerificarsiVoto(QString m_cedula)
{
    QFile archivoVotos;     //creamos nuestro variable ruta del archivo
    archivoVotos.setFileName("C:/Users/Usuario/Desktop/Login/Recursos/VotacionesRealizadas.txt");     //madamos su direccion
    QTextStream votos;
    archivoVotos.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!archivoVotos.isOpen()){
        QMessageBox::warning(0,"AVISO IMPORTANTE", "No se pudo abrir el archivo con los votos");
    }
    votos.setDevice(&archivoVotos);         //Setamos la direccion y mandamos por referencia
    while(!votos.atEnd()){

        auto linea = votos.readLine();
        auto split = linea.split("/n");

        for(int i=0; i<split.size(); i++ ){
            auto datos = split.at(0);
            if(i == 0){

                if(m_cedula==datos){
                    return false;

                }
            }
        }
    }
    archivoVotos.close();
    return true;
}

void Login::on_cmdIngresar_clicked()
{
    QString numeroCedula = ui->inCedula->text();
    if(VerificarsiVoto(numeroCedula)==false){
        QMessageBox::warning(this,"Aviso","Usted ya ha realizo el proceso de votacion");
        ui->inCedula->clear();
        return;
    }
    validarCedula();
    GuardarVotantes(numeroCedula);
    return;
}

void Login::leerPadronElectoral()
{
    //Variables que nos permitan abrir archivo
    QFile archivo;                  //variable para gestionar los archivos
    QTextStream cedulasTxt;         //Nos permiten tener lectura de archivos

    QString id,cedula,nombre,foto;   //

    ui->inCedula->setEchoMode(QLineEdit::Normal);

    QString nombreArchivo = "C:/Users/Usuario/Desktop/Login/Recursos/Usuarios.txt";       //Variable que contienen la direccion del txt

    archivo.setFileName(nombreArchivo);                                 //setamos a archivo y le damos la direccion guardada en una variable antes

    archivo.open(QIODevice::ReadOnly | QIODevice::Text);                //Abrimos el archivo
    if(!archivo.isOpen()){                                              //Condidcional para saber si el txt no se abre
        return;
    };
    cedulasTxt.setDevice(&archivo);                                     //referencia de archivo para su gestion del txt

    int filacodigo = 0, filacedula = 0,filanombre = 0,filafoto = 0;

    while(!cedulasTxt.atEnd()){
        auto linea = cedulasTxt.readLine();
        auto valores = linea.split(";");
        for(int i=0; i<valores.size();i++){
            auto dato=valores.at(i);
            // Codigo
            if(i == 0 or filacodigo == i){
                id = dato;
                filacodigo += 4;
            }
            // Cedula
            if(i == 1 or filacedula == i){
                cedula = dato;
                filacedula += 4;
            }
            // Nombre
            if(i == 2 or filanombre == i){
                nombre = dato;
                filanombre +=4;
            }
            // Foto
            if(i == 3 or filafoto == i){
                foto = dato;
                filafoto += 4;
                m_usuarios.append(new Usuarios(cedula,nombre,foto));  // Mandamos a la lista lo leido
            }
        }
    }
    ui->inCedula->setFocus();
}

//ADMIN
void Login::on_action_Iniciar_sesion_triggered()
{
    Administrador *admin = new Administrador();
    hide();
    admin->show();
}

void Login::validarCedula()
{
    QString numeroCedula = ui->inCedula->text();

    bool bandera = false;

    if (numeroCedula.isEmpty() || numeroCedula<10){
        QMessageBox::warning(0,"Aviso","Revise los datos");
        return;
    }
    for(int i=1;i<m_usuarios.length();i++){
        if(m_usuarios.at(i)->getCedula() == numeroCedula){
            QString nombre = m_usuarios.at(i)->getNombre();
            QString cedula = m_usuarios.at(i)->getCedula();
            QString foto = m_usuarios.at(i)->getFoto();
            m_persona = new Usuarios(cedula,nombre,foto);
            QMessageBox::information(0,"CNE","Bienvenido " + nombre + ", elige tu voto con responsabilidad");
            bandera = true;
        }
    }
    if(bandera == false){
        QMessageBox::warning(0,"Aviso","No estas en la lista de votantes permitidos");
        ui->inCedula->clear();
    }else{
        // Llamar a la nueva ventana
        ui->inCedula->setText("");
        Votacion *ingreso = new Votacion(this);
        ingreso->obtenerDatos(m_persona);
        ingreso->setWindowModality(Qt::ApplicationModal);
        hide();
        ingreso->show();
    }
}

void Login::on_action_Salir_triggered()
{
    this->close();
}

void Login::on_actionA_cerca_de_triggered()
{
    Acercade *acerca = new Acercade();
    acerca->show();
}
