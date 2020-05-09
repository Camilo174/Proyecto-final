#ifndef FORMULARIO_USUARIO_H
#define FORMULARIO_USUARIO_H

#include <QDialog>
#include <string>
#include <QDate>
#include "mainwindow.h"
#include "clave_erronea.h"

using namespace std;

namespace Ui {
class formulario_usuario;
}

class formulario_usuario : public QDialog
{
    Q_OBJECT

public:
    explicit formulario_usuario(QWidget *parent = 0);
    ~formulario_usuario();
signals:
    void enviarDatos( string username, string usrpassword );

    void envioDatosUsuarioNew(string usernameN,string nameN,string apellidoN,string passwordN,int docIdN,int dayNR,int monthNR,int yearNR,bool aceptadoUs); //falta fecha

private slots:
    void on_buttonBox_accepted();

    void on_cdm_RegUsr_clicked();

private:
    Ui::formulario_usuario *ui;

    string claveAdmin = "123";
};

#endif // FORMULARIO_USUARIO_H
