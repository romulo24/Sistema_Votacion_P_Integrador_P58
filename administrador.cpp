#include "administrador.h"
#include "ui_administrador.h"

Administrador::Administrador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Administrador)
{
    ui->setupUi(this);
    admin.insert("12345");          //Clave de los estructura Qset
    ui->inContrasenia->setEchoMode(QLineEdit::Password);
}

Administrador::~Administrador()
{
    delete ui;
}

void Administrador::on_cmdIngresarAdmin_released()
{
    QString contra = ui->inContrasenia->text();

    if(admin.contains(contra)){
        Estadistica *estadistica = new Estadistica();
        this->hide();
        estadistica->show();
    }else{
        QMessageBox::warning(0, "AVISO", "Recuerda llenar la informacion pertinente");
    }
}
