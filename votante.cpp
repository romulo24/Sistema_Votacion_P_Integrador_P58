#include "votante.h"

Votante::Votante(QObject *parent) : QObject(parent)
{
    this->m_horaR = "\0";
    this->m_minutosR = "\0";
    this->m_voto = 0;
}

Votante::Votante(int voto, QString horaR, QString minutosR)
{
    this->m_horaR = horaR;
    this->m_minutosR = minutosR;
    this->m_voto = voto;
}

QString Votante::horaR() const
{
    return m_horaR;
}

void Votante::setHoraR(const QString &horaR)
{
    m_horaR = horaR;
}

QString Votante::minutosR() const
{
    return m_minutosR;
}

void Votante::setMinutosR(const QString &minutosR)
{
    m_minutosR = minutosR;
}

int Votante::voto() const
{
    return m_voto;
}

void Votante::setVoto(int voto)
{
    m_voto = voto;
}

QString Votante::nombre() const
{
    return m_nombre;
}

void Votante::setNombre(const QString &nombre)
{
    m_nombre = nombre;
}

QString Votante::cedula() const
{
    return m_cedula;
}

void Votante::setCedula(const QString &cedula)
{
    m_cedula = cedula;
}
