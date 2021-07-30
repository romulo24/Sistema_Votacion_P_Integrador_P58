#include "usuarios.h"
#include <QDebug>

Usuarios::Usuarios(QObject *parent) : QObject(parent)
{
    m_Id = "";
    m_Cedula = "";
    m_Nombre = "";

}

Usuarios::Usuarios(QString m_Cedula, QString m_Nombre,QString m_Foto)
{
    this->m_Cedula = m_Cedula;
    this->m_Nombre = m_Nombre;
    this->m_Foto = m_Foto;
}

QString Usuarios::getId() const
{
    return m_Id;
}

QString Usuarios::getCedula() const
{
    return m_Cedula;
}

QString Usuarios::getNombre() const
{
    return m_Nombre;
}

QString Usuarios::getFoto() const
{
    return m_Foto;
}

