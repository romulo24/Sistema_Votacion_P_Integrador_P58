#ifndef ACERCA_H
#define ACERCA_H

#include <QObject>
#include "ui_Acerca.h"

class Acerca : public QObject
{
    Q_OBJECT
public:
    explicit Acerca(QObject *parent = nullptr);

signals:
private:
    QString version;

};
#endif // ACERCA_H
