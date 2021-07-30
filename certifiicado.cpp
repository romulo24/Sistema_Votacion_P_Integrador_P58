#include "certifiicado.h"
#include "ui_certifiicado.h"
#include<QPixmap>

Certifiicado::Certifiicado(Usuarios *persona,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Certifiicado)
{
    ui->setupUi(this);
    int m_horaInicial = QDateTime::currentDateTime().time().hour();
    int m_minutosInicial = QDateTime::currentDateTime().time().minute();
    QString nombres = persona->getNombre();
    QString cedulas = persona->getCedula();
    QString foto = persona->getFoto();
    QString fechas = QDateTime::currentDateTime().toString("dd/MM/yyyy");
    //Definir el tamaño del área de trabajo - Qlabel(tamaño de la etiqueta)
    pixmap = QPixmap(ui->imagen->size());
    //Definir el fondo
    pixmap.fill(Qt::white);
    QPixmap pix(foto);
    ui->imagen2->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    ui->imagen->setPixmap(pixmap);
    generarCertificado(cedulas,nombres,"Junta N°20",m_horaInicial,m_minutosInicial, fechas,foto);
}

Certifiicado::~Certifiicado()
{
    delete ui;
}

QImage Certifiicado::crearimagenconsuperposicion(const QImage &baseImage, const QImage &overlayImage)
{
    QImage imageWithOverlay = QImage(baseImage.size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&imageWithOverlay);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(imageWithOverlay.rect(), Qt::transparent);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(0, 0, baseImage);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(20, 25, overlayImage);
    painter.end();
    return imageWithOverlay;
}

void Certifiicado::generarCertificado(QString Cedula, QString Nombre, QString Lugar, int Hora, int Minuto, QString fecha,QString foto)
{
    QString horas = QString::number(Hora);
    QString minutos = QString::number(Minuto);

    QPainter painter(&pixmap);
    QPen pen;
    pen.setColor(Qt::red);
    painter.drawText(250,20,"Nombre: ");
    painter.drawText(300,20,Nombre);
    painter.drawText(250,45,"Cedula: ");
    painter.drawText(300,45,Cedula);
    painter.drawText(250,70,"Lugar: ");
    painter.drawText(300,70,Lugar);
    painter.drawText(250,95,"Provincia: ");
    painter.drawText(300,95,"  Pichincha");
    painter.drawText(250,120,"Hora: ");
    painter.drawText(300,120,horas+":"+minutos);
    painter.drawText(250,145,"Fecha: ");
    painter.drawText(300,145,fecha);
    QImage Foto(foto);
    QPixmap pix(foto);
    QImage baseImage("C:/Users/Usuario/Desktop/Login/Recursos/Fondo.png");
    QImage logo = crearimagenconsuperposicion(baseImage,Foto);
    ui->imagen2->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    ui->imagen->setPixmap(pixmap);
}

void Certifiicado::on_cmdGuardar_released()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (pixmap.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guardado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Certifiicado::on_cmdFinalizar_released()
{
    Login *inicial = new Login ();
    inicial->show();
    this->close();
}
