#include "login.h"
#include <QApplication>
#include <QDateTime>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;

    QString Fecha;
    QString nombreArchivo = "C:/Users/Usuario/Desktop/Login/Recursos/Fecha.txt";
    QFile archivo(nombreArchivo);

    int m_horaInicial = QDateTime::currentDateTime().time().hour();                       // Horas de inicio de sistema
    int m_minutosInicial = QDateTime::currentDateTime().time().minute();                  // Minutos para ingresar al sistema

    QString horaInicial = QString::number(m_horaInicial);                               // Convertimos a string la hora del sistema
    QString minutosInicial = QString::number(m_minutosInicial);                         // convertinmos a string los minutos inciiales

    QString m_horainicial=0,  m_minutoinicial=0, m_horafinal=0, m_minutofinal=0;        // Variables para obtener desde el archivo de fechas

    QString FechaSistema = QDateTime::currentDateTime().toString("dd/MM/yyyy");           // Variable tipo string para obtener fecha del sistema
    QTextStream aux;

    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!archivo.isOpen()){
        return 0;
    }
    aux.setDevice(&archivo);

    while(!aux.atEnd()){
        auto linea = aux.readLine();
        auto valores=linea.split(";");

        for(int i=0; i<valores.size();i++){
            auto dato=valores.at(i);                // Obtenemos los datos
            if(i == 0){
                Fecha=dato;                         // Autentificamos la fecha de votación
            };
            if(i == 1){
                m_horainicial = dato;                 // Obtenemos las horas de inicio
            };

            if(i == 2){
                m_minutoinicial= dato;                // Obtenmos el minuto incial
            };
            if(i == 3){
                m_horafinal = dato;                   // Obtenemos la hor final
            };
            if(i == 4){
                m_minutofinal = dato;                 // Obtenemos los minutos finales de votacion
            };
        }
    }
    archivo.close();        //Cerrando archivo

    // Validación de la fecha de inicio
    if(Fecha != FechaSistema){
        QMessageBox::critical(0,"Aviso","Sistema no habilitado espere la fecha correcta");
        return 0;
    }

    // Validación de la hora de inicio
    if((horaInicial != m_horainicial) || (minutosInicial != m_minutoinicial)){
        QMessageBox::warning(0,"Aviso","Sistema no habilitado espera la hora correcta");
        return -1; // Nos ayuda a no mostrar la ventana siguiente si no se cumple las horas exactas
    }

    // Validación de hora de cierre
    w.show();
    return a.exec();
}
