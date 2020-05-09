#include "clave_erronea.h"
#include "ui_clave_erronea.h"

clave_erronea::clave_erronea(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clave_erronea)
{
    ui->setupUi(this);
}

clave_erronea::~clave_erronea()
{
    delete ui;
}
