#include "estadistica.h"
#include "ui_estadistica.h"
#include <QDebug>

Estadistica::Estadistica(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Estadistica)
{
    ui->setupUi(this);
    abrirArchivoVoto();
    lienzo = QPixmap (500,500);             //Ponemos las dimenciones d enuestro lienzo
    dibujar();
    mostrarPorcentaje();
}

Estadistica::~Estadistica()
{
    delete ui;
}

void Estadistica::abrirArchivoVoto()
{
    QStack <QString> lasso;            // Estructura tipo pila para lasso
    QStack <QString> arauz;            // Estructura tipo pila para arauz
    QStack <QString> blanco;           // Estructura tipo pila para blanco
    QStack <QString> nulo;             // Estructura tipo pila para nulo

    // Definimos variables para almacenar el dato;
    QFile archivoVotos;                // Creamos nuestro variable ruta del archivo
    archivoVotos.setFileName("C:/Users/Usuario/Desktop/Login/Recursos/Votaciones.txt");     // Mandamos su direccion
    QTextStream votos;

    // Abrir el archivo
    archivoVotos.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!archivoVotos.isOpen()){
        QMessageBox::warning(0,"AVISO IMPORTANTE", "No se pudo abrir el archivo con los votos");
        return;
    }

    votos.setDevice(&archivoVotos);         // Seteamos la direccion y mandamos por referencia
    while(!votos.atEnd()){
        auto linea = votos.readLine();
        auto split = linea.split(";");
        // Obtener datos del txt
        for(int i=0; i<split.size(); i++ ){
            auto datos = split.at(0);
            if(i == 0){
                if(datos == "1" ){      //( 1 = lasso )
                    m_contadorLasso = datos;
                    lasso.push(m_contadorLasso);
                    m_glasso = lasso.size();
                }
                if(datos == "2"){      //( 2 = arauz )
                    m_contadorArauz = datos;
                    arauz.push(m_contadorArauz);
                }
                if(datos == "3"){     // ( 3 = blanco )
                    m_contadorBlanco = datos;
                    blanco.push(m_contadorBlanco);
                    qDebug () << m_contadorBlanco;
                }
                if(datos == "4"){     // ( 4 = nulo )
                    m_contadorNulo = datos;
                    nulo.push(m_contadorNulo);
                    qDebug () << m_contadorNulo;
                }
            }
        }
    }
    archivoVotos.close();

    m_glasso = lasso.size();
    qDebug () << "CONVERSION A ENTEROS LASSO" <<m_glasso;
    m_garauz = arauz.size();
    qDebug () << "CONVERSION A ENTEROS ARAUZ" <<m_garauz;
    m_gblanco = blanco.size();
    qDebug () <<"CONVERSION A ENTEROS BLANCO"<< m_gblanco;
    m_gnulo = nulo.size();
    qDebug () <<"CONVERSION A ENTEROS NULO"<< m_gnulo;
}

void Estadistica::dibujar()
{
    // Rellenamos de color blanco el fonndo
    lienzo.fill(Qt::white);
    
    // Pintor que trabaja sobre el lienzo
    QPainter pintor (&lienzo);

    int ancho = 50;
    int x = 50;                     // Ditancia entre barras
    int y = 50 ;                    // Posición incio
    int alto1  = m_glasso*15;
    int alto2  = m_garauz*15;
    int alto3  = m_gblanco*15;
    int alto4  = m_gnulo*15;

    qDebug () <<"Alto1 :"<< alto1;
    qDebug () <<"Alto2 :"<< alto2;
    qDebug () <<"Alto3 :"<< alto3;
    qDebug () <<"Alto4 :"<< alto4;


    // Primera barra (Lasso)
    QPen pincel;                     // Creamos el pincel
    pincel.setWidth(5);              // Ancho del pincel
    pincel.setColor(Qt::black);      // Seleccionamos el color
    pincel.setJoinStyle(Qt::MiterJoin);

    // Nombres debajo de las barras
    QColor nota(Qt::black);
    pincel.setColor(nota);
    pintor.setPen(pincel);
    for(int o=x; o<450; o+=100){
        QString nota1 = "LASSO";
        pintor.drawText(x+9, y+415, nota1);
        QString nota2 = "ARAUZ";
        pintor.drawText(x+115, y+415, nota2);
        QString nota3 = "BLANCO";
        pintor.drawText(x+223, y+415, nota3);
        QString nota4 = "NULO";
        pintor.drawText(x+338, y+415, nota4);
    }

    // Seteamos valores del pincel
    pintor.setPen(pincel);

    // Colorear la barra
    QColor colorBorde1 (72,107,186);
    QColor colorRelleno1(72,107,186);

    // Colorear de azul
    pincel.setColor(colorBorde1);

    // Seteamos el pincel
    pintor.setPen(pincel);

    // Rellenamos con el color 1
    pintor.setBrush(colorRelleno1);

    // Dibujo de la primera recta
    pintor.drawRect(x,y+(400-alto1), ancho, alto1);

    // Segunda barra (Arauz)

    // Establecemos colores para la barra 2
    QColor colorBorde2 (255,172,81);
    QColor colorRelleno2(255,172,81);

    // Cambiamos el color del pincel
    pincel.setColor(colorBorde2);

    // Volver a establecer al objeto painter
    pintor.setPen(pincel);

    // Volver a establecer al objeto painter
    pintor.setPen(pincel);

    // Establecer el color de la brovcha
    pintor.setBrush(colorRelleno2);

    // Grafica de segunda barra
    pintor.drawRect(x+110,y+(400-alto2), ancho, alto2);

    // Tercera barra (Blanco)
    QColor colorBorde3 (172,169,173);
    QColor colorRelleno3(228,227,228);

    // Cambiamos el color del pincel
    pincel.setColor(colorBorde3);

    // Volver a establecer al objeto painter
    pintor.setPen(pincel);

    // Volver a establecer al objeto painter
    pintor.setPen(pincel);

    // Establecer el color de la brocha
    pintor.setBrush(colorRelleno3);

    // Grafica de segunda barra
    pintor.drawRect(x+220,y+(400-alto3), ancho, alto3);

    // Cuarta barra (nulo)
    QColor colorBorde4 (203,155,0);
    QColor colorRelleno4(203,155,0);

    // Cambiamos el color del pincel
    pincel.setColor(colorBorde4);

    // Volver a establecer al objeto painter
    pintor.setPen(pincel);

    // Volver a establecer al objeto painter
    pintor.setPen(pincel);

    // Establecer el color de la brovcha
    pintor.setBrush(colorRelleno4);

    // Grafica de segunda barra
    pintor.drawRect(x+330,y+(400-alto4), ancho, alto4);

    // Graficamos en nuestra pantalla
    ui->outEstadistica->setPixmap(lienzo);
}

void Estadistica::mostrarPorcentaje()
{
    QString porcentajeLasso = QString::number(m_glasso);
    ui->outPLasso->setText("VOTOS :" + porcentajeLasso);

    QString porcentajeArauz = QString::number(m_garauz);
    ui->outPArauz->setText("VOTOS :" + porcentajeArauz);

    QString porcentajeBlanco = QString::number(m_gblanco);
    ui->outPBlanco->setText("VOTOS :" + porcentajeBlanco);

    QString porcentajeNulo = QString::number(m_gnulo);
    ui->outPnulo->setText("VOTOS :" + porcentajeNulo);
}

void Estadistica::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if(!nombreArchivo.isEmpty()){
        if(lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar Imagen","Archivo guardado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Estadistica::on_actionPrincipal_triggered()
{
    Login *inicial = new Login ();
    hide();
    inicial->show();
    hide();
    this->close();
}
