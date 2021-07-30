#ifndef USUARIOS_H
#define USUARIOS_H

#include <QObject>
#include <QQueue>

class Usuarios : public QObject
{
    Q_OBJECT
public:

    explicit Usuarios(QObject *parent = nullptr);
    Usuarios(QString m_Cedula,QString m_Nombre,QString m_Foto);
    QString getId() const;
    QString getCedula() const;
    QString getNombre() const;

    QString getFoto() const;

private:
    QString m_Id;
    QString m_Cedula;
    QString m_Nombre;
    QString m_Foto;

};

#endif // USUARIOS_H
