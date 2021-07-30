#ifndef VOTANTE_H
#define VOTANTE_H

#include <QObject>

class Votante : public QObject
{
    Q_OBJECT
public:
    explicit Votante(QObject *parent = nullptr);

    Votante(int voto, QString horaR, QString minutosR);


    QString horaR() const;
    void setHoraR(const QString &horaR);

    QString minutosR() const;
    void setMinutosR(const QString &minutosR);

    int voto() const;
    void setVoto(int voto);

    QString nombre() const;
    void setNombre(const QString &nombre);

    QString cedula() const;
    void setCedula(const QString &cedula);

signals:

private:

    QString m_horaR;
    QString m_minutosR;
    QString m_nombre;
    QString m_cedula;

    int m_voto;

};

#endif // VOTANTE_H
