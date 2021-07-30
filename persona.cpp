#include "persona.h"

Persona::Persona(QObject *parent) : QObject(parent)
{
    //codigo de usuario
    m_Cedula="";
    m_Nombre="";
    m_hora=0;
    m_minuto=0;
}

QString Persona::Cedula() const
{
    return m_Cedula;
}

void Persona::setCedula(const QString &Cedula)
{
    m_Cedula = Cedula;
}

QString Persona::Nombre() const
{
    return m_Nombre;
}

void Persona::setNombre(const QString &Nombre)
{
    m_Nombre = Nombre;
}

int Persona::hora() const
{
    return m_hora;
}

void Persona::setHora(int hora)
{
    m_hora = hora;
}

int Persona::minuto() const
{
    return m_minuto;
}

void Persona::setMinuto(int minuto)
{
    m_minuto = minuto;
}

QString Persona::fecha() const
{
    return m_fecha;
}

void Persona::setFecha(const QString &fecha)
{
    m_fecha = fecha;
}

Persona::Persona(QString m_Cedula, QString m_Nombre, int m_hora, int m_minuto)
{
    this->m_Cedula=m_Cedula;
    this->m_Nombre=m_Nombre;
    this->m_hora=m_hora;
    this->m_minuto=m_minuto;

}
