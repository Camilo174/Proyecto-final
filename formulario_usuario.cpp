#include "formulario_usuario.h"
#include "ui_formulario_usuario.h"
#include "formulario_paciente.h"
#include "mainwindow.h"

formulario_usuario::formulario_usuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formulario_usuario)
{
    ui->setupUi(this);

    string claveAdminUI = ui->clvadminNR->text().toStdString();

}

formulario_usuario::~formulario_usuario()
{
    delete ui;
}

void formulario_usuario::on_buttonBox_accepted()
{
    string username = ui->_username->text().toStdString();
    string usrpassword = ui->_usrpassword->text().toStdString();
    emit enviarDatos(username,usrpassword);
}

void formulario_usuario::on_cdm_RegUsr_clicked()
{
    string nameNew = ui->nomuNR->text().toStdString();
    string claveNew = ui->passNR->text().toStdString();
    string apellidoNew = ui->apeNR->text().toStdString();
    string usernameN = ui->usuNR->text().toStdString();
    string claveAdminUI = ui->clvadminNR->text().toStdString();


    int dayNR = ui->fnNR->date().day();
    int monthNR = ui->fnNR->date().month();
    int  yearNR = ui->fnNR->date().year();
    int docId = ui->docNR->text().toInt();

    bool aceptadoUs = true;

    if(claveAdminUI == claveAdmin){
        emit envioDatosUsuarioNew(usernameN,nameNew,apellidoNew,claveNew,docId,dayNR,monthNR,yearNR,aceptadoUs);
    }else{
        clave_erronea a(this);
        a.setModal( true );
        a.show();
        a.exec();
    }
}
