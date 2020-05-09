#include "usuario.h"
#include "ui_usuario.h"
#include <iostream>
#include <string>

using namespace std;

usuario::usuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usuario)
{
    ui->setupUi(this);
}

usuario::~usuario()
{
    delete ui;
}
