#ifndef PERSONA_H
#define PERSONA_H

#include <QObject>

class Persona : public QObject
{
    Q_OBJECT
public:
    explicit Persona(QObject *parent = nullptr);

    Persona(QString m_Cedula,QString m_Nombre, int m_hora, int m_minuto);

    QString Cedula() const;
    void setCedula(const QString &Cedula);

    QString Nombre() const;
    void setNombre(const QString &Nombre);

    int hora() const;
    void setHora(int hora);

    int minuto() const;
    void setMinuto(int minuto);

    QString fecha() const;
    void setFecha(const QString &fecha);

private:
    QString m_Cedula;
    QString m_Nombre;
    int m_hora;
    int m_minuto;
    QString m_fecha;



signals:

};

#endif // PERSONA_H
