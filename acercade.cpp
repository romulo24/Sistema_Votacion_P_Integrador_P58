#include "acercade.h"
#include "ui_acercade.h"

Acercade::Acercade(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Acercade)
{
    ui->setupUi(this);
}

Acercade::~Acercade()
{
    delete ui;
}
