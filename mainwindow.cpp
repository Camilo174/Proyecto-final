#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QString>
#include<QDate>
#include<QTime>

#include <formulario_paciente.h>
#include <formulario_usuario.h>
#include <datos_usuario.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    base.abrirDB("/home/alseuser/ProyectoALSE/base_datos");

    ui->setupUi(this);

    rd = new QPixmap("/home/alseuser/ProyectoALSE/12.png"); //led apagado
    rl = new QPixmap("/home/alseuser/ProyectoALSE/13.png"); //led encendido



    ui->boton_1->setIcon(*rd);
    ui->boton_1->setIconSize(rd->rect().size());
    ui->boton_2->setIcon(*rd);
    ui->boton_2->setIconSize(rd->rect().size());
    ui->boton_3->setIcon(*rd);
    ui->boton_3->setIconSize(rd->rect().size());
    ui->boton_4->setIcon(*rd);
    ui->boton_4->setIconSize(rd->rect().size());
    ui->boton_5->setIcon(*rd);
    ui->boton_5->setIconSize(rd->rect().size());
    ui->boton_6->setIcon(*rd);
    ui->boton_6->setIconSize(rd->rect().size());
    ui->boton_7->setIcon(*rd);
    ui->boton_7->setIconSize(rd->rect().size());
    ui->boton_8->setIcon(*rd);
    ui->boton_8->setIconSize(rd->rect().size());
    ui->boton_9->setIcon(*rd);
    ui->boton_9->setIconSize(rd->rect().size());
    ui->boton_10->setIcon(*rd);
    ui->boton_10->setIconSize(rd->rect().size());

    ui->cmd_inicio->setEnabled(false);
    ui->RegPnt->setEnabled(false);
}

MainWindow::~MainWindow()
{
    base.cerrarDB();
    delete ui;
}

void MainWindow::reciboDatosUsuarioReg(string username, string password)
{
    string usuario = username;
    string clave = password;
    bool estado_registro = base.compararDatosUsuario(usuario,clave);
}

int MainWindow::calcular_edad(int anoN, int mesN, int diaN, int ano_actual, int mes_actual, int dia_actual)
{
    int edad;
    if(anoN>ano_actual){
        anoN -= 100;
    }

    if(mes_actual>mesN){
        edad = ano_actual - anoN;
    }
    else{
        if(mesN == mes_actual){
            if(dia_actual<diaN){
                edad = ano_actual - anoN -1;
            }
            else{
                edad = ano_actual -anoN;
            }
        }
        else{
            edad = ano_actual - anoN -1;
        }
    }

    return edad;
}

void MainWindow::reciboDatosUsuarioNew(string usernameN, string nameN, string apellidoN, string passwordN, int docIdN, int dayNR, int monthNR, int yearNR,bool aceptadoUs)
{
    string usuarioNew = usernameN;
    string claveNew = passwordN;
    string nameNew = nameN;
    string apellidoNew = apellidoN;
    int docId = docIdN;

    int diaN = dayNR;
    int mesN = monthNR;
    int anoN = yearNR;

    QDate fecha_actual = QDate::currentDate();
    int dia_actual = fecha_actual.day();
    int mes_actual = fecha_actual.month();
    int ano_actual = fecha_actual.year();

    int edad = calcular_edad(anoN, mesN, diaN, ano_actual, mes_actual, dia_actual);

    ui->_lbl_username->setText(QString::fromStdString(usuarioNew));
    ui->_lbl_usrnombre->setText(QString::fromStdString(nameNew));
    ui->_lbl_usrapellido->setText(QString::fromStdString(apellidoNew));

    if(aceptadoUs){ui->RegPnt->setEnabled(true);}

    base.almacenarUsuario(usuarioNew,claveNew,nameNew,apellidoNew,docId,edad);
}

void MainWindow::reciboDatosPaciente(string nombrePnt, string apellidoPnt, int edad, long docPnt, string generoPnt, string razaPnt, string nivelSEpnt, bool aceptado)
{
  ui->_lbl_pntnombre->setText(QString::fromStdString(nombrePnt));
  ui->_lbl_apellido->setText(QString::fromStdString(apellidoPnt));
  ui->_lbl_edadpnt->setText(QString::fromStdString((std::to_string(edad))));
  ui->_lbl_genero->setText(QString::fromStdString(generoPnt));
  ui->_lbl_idpnt->setText(QString::fromStdString(std::to_string(docPnt)));

  base.almacenarPaciente(nombrePnt,apellidoPnt,edad,docPnt,nivelSEpnt,generoPnt,razaPnt);

  if(aceptado){ui->cmd_inicio->setEnabled(true);}

}

void MainWindow::on_cmd_ingreso_clicked()
{
    formulario_usuario a(this);
    a.setModal( true );
    connect( &a, &formulario_usuario::enviarDatos, this, &MainWindow::reciboDatosUsuarioReg );
    connect( &a, &formulario_usuario::envioDatosUsuarioNew, this, &MainWindow::reciboDatosUsuarioNew );
    a.show();
    a.exec();
}

void MainWindow::on_cmd_inicio_clicked()
{
    QTime hora = QTime::currentTime();

    ui->hora_inicio->setTime(hora);

    int tiempo_prueba = ui->_tiempo_prueba->value();
    tiempo_prueba *= 1000;

    _aciertos = _errores = 0;
    ui->_lbl_aciertos->setText(QString::fromStdString(std::to_string(_aciertos)));
    ui->_lbl_errores->setText(QString::fromStdString(std::to_string(_errores)));

    ui->_lbl_finPrueba->setText("");

    _estado = random1_10();
    _timer1 = new QTimer(this);
    _timer2 = new QTimer(this);
    connect(_timer1, &QTimer::timeout, this, &MainWindow::cambio_estado );
    connect(_timer2, &QTimer::timeout, this, &MainWindow::terminar_prueba );
    _timer1->setInterval( 3000 );
    _timer2->setInterval(tiempo_prueba + 3000);
    _timer2->start();
    _timer1->start();
}

int MainWindow::random1_10()
{
    return rand() % 10 + 1;
}

void MainWindow::terminar_prueba()
{
    QTime hora = QTime::currentTime();

    ui->hora_final->setTime(hora);

    _estado = 11;
}

//CAMBIO DE ESTADO-------------------------
void MainWindow::cambio_estado()
{
    if(_estado==11){
        _estado=11;
    }else{_estado = random1_10();}

    switch (_estado) {
    case 1:
        ui->boton_1->setIcon(*rl);
        ui->boton_1->setIconSize(rl->rect().size());
        ui->boton_2->setIcon(*rd);
        ui->boton_2->setIconSize(rd->rect().size());
        ui->boton_3->setIcon(*rd);
        ui->boton_3->setIconSize(rd->rect().size());
        ui->boton_4->setIcon(*rd);
        ui->boton_4->setIconSize(rd->rect().size());
        ui->boton_5->setIcon(*rd);
        ui->boton_5->setIconSize(rd->rect().size());
        ui->boton_6->setIcon(*rd);
        ui->boton_6->setIconSize(rd->rect().size());
        ui->boton_7->setIcon(*rd);
        ui->boton_7->setIconSize(rd->rect().size());
        ui->boton_8->setIcon(*rd);
        ui->boton_8->setIconSize(rd->rect().size());
        ui->boton_9->setIcon(*rd);
        ui->boton_9->setIconSize(rd->rect().size());
        ui->boton_10->setIcon(*rd);
        ui->boton_10->setIconSize(rd->rect().size());
        _timer1->setInterval( 1000 );
        _timer1->start();
        break;
    case 2:
        ui->boton_1->setIcon(*rd);
        ui->boton_1->setIconSize(rd->rect().size());
        ui->boton_2->setIcon(*rl);
        ui->boton_2->setIconSize(rl->rect().size());
        ui->boton_3->setIcon(*rd);
        ui->boton_3->setIconSize(rd->rect().size());
        ui->boton_4->setIcon(*rd);
        ui->boton_4->setIconSize(rd->rect().size());
        ui->boton_5->setIcon(*rd);
        ui->boton_5->setIconSize(rd->rect().size());
        ui->boton_6->setIcon(*rd);
        ui->boton_6->setIconSize(rd->rect().size());
        ui->boton_7->setIcon(*rd);
        ui->boton_7->setIconSize(rd->rect().size());
        ui->boton_8->setIcon(*rd);
        ui->boton_8->setIconSize(rd->rect().size());
        ui->boton_9->setIcon(*rd);
        ui->boton_9->setIconSize(rd->rect().size());
        ui->boton_10->setIcon(*rd);
        ui->boton_10->setIconSize(rd->rect().size());
        _timer1->setInterval( 1000 );
        _timer1->start();
        break;
    case 3:
        ui->boton_1->setIcon(*rd);
        ui->boton_1->setIconSize(rd->rect().size());
        ui->boton_2->setIcon(*rd);
        ui->boton_2->setIconSize(rd->rect().size());
        ui->boton_3->setIcon(*rl);
        ui->boton_3->setIconSize(rl->rect().size());
        ui->boton_4->setIcon(*rd);
        ui->boton_4->setIconSize(rd->rect().size());
        ui->boton_5->setIcon(*rd);
        ui->boton_5->setIconSize(rd->rect().size());
        ui->boton_6->setIcon(*rd);
        ui->boton_6->setIconSize(rd->rect().size());
        ui->boton_7->setIcon(*rd);
        ui->boton_7->setIconSize(rd->rect().size());
        ui->boton_8->setIcon(*rd);
        ui->boton_8->setIconSize(rd->rect().size());
        ui->boton_9->setIcon(*rd);
        ui->boton_9->setIconSize(rd->rect().size());
        ui->boton_10->setIcon(*rd);
        ui->boton_10->setIconSize(rd->rect().size());
        _timer1->setInterval( 1000 );
        _timer1->start();
        break;
    case 4:
        ui->boton_1->setIcon(*rd);
        ui->boton_1->setIconSize(rd->rect().size());
        ui->boton_2->setIcon(*rd);
        ui->boton_2->setIconSize(rd->rect().size());
        ui->boton_3->setIcon(*rd);
        ui->boton_3->setIconSize(rd->rect().size());
        ui->boton_4->setIcon(*rl);
        ui->boton_4->setIconSize(rl->rect().size());
        ui->boton_5->setIcon(*rd);
        ui->boton_5->setIconSize(rd->rect().size());
        ui->boton_6->setIcon(*rd);
        ui->boton_6->setIconSize(rd->rect().size());
        ui->boton_7->setIcon(*rd);
        ui->boton_7->setIconSize(rd->rect().size());
        ui->boton_8->setIcon(*rd);
        ui->boton_8->setIconSize(rd->rect().size());
        ui->boton_9->setIcon(*rd);
        ui->boton_9->setIconSize(rd->rect().size());
        ui->boton_10->setIcon(*rd);
        ui->boton_10->setIconSize(rd->rect().size());
        _timer1->setInterval( 1000 );
        _timer1->start();
        break;
    case 5:
        ui->boton_1->setIcon(*rd);
        ui->boton_1->setIconSize(rd->rect().size());
        ui->boton_2->setIcon(*rd);
        ui->boton_2->setIconSize(rd->rect().size());
        ui->boton_3->setIcon(*rd);
        ui->boton_3->setIconSize(rd->rect().size());
        ui->boton_4->setIcon(*rd);
        ui->boton_4->setIconSize(rd->rect().size());
        ui->boton_5->setIcon(*rl);
        ui->boton_5->setIconSize(rl->rect().size());
        ui->boton_6->setIcon(*rd);
        ui->boton_6->setIconSize(rd->rect().size());
        ui->boton_7->setIcon(*rd);
        ui->boton_7->setIconSize(rd->rect().size());
        ui->boton_8->setIcon(*rd);
        ui->boton_8->setIconSize(rd->rect().size());
        ui->boton_9->setIcon(*rd);
        ui->boton_9->setIconSize(rd->rect().size());
        ui->boton_10->setIcon(*rd);
        ui->boton_10->setIconSize(rd->rect().size());
        _timer1->setInterval( 1000 );
        _timer1->start();
        break;
    case 6:
        ui->boton_1->setIcon(*rd);
        ui->boton_1->setIconSize(rd->rect().size());
        ui->boton_2->setIcon(*rd);
        ui->boton_2->setIconSize(rd->rect().size());
        ui->boton_3->setIcon(*rd);
        ui->boton_3->setIconSize(rd->rect().size());
        ui->boton_4->setIcon(*rd);
        ui->boton_4->setIconSize(rd->rect().size());
        ui->boton_5->setIcon(*rd);
        ui->boton_5->setIconSize(rd->rect().size());
        ui->boton_6->setIcon(*rl);
        ui->boton_6->setIconSize(rl->rect().size());
        ui->boton_7->setIcon(*rd);
        ui->boton_7->setIconSize(rd->rect().size());
        ui->boton_8->setIcon(*rd);
        ui->boton_8->setIconSize(rd->rect().size());
        ui->boton_9->setIcon(*rd);
        ui->boton_9->setIconSize(rd->rect().size());
        ui->boton_10->setIcon(*rd);
        ui->boton_10->setIconSize(rd->rect().size());
        _timer1->setInterval( 1000 );
        _timer1->start();
        break;
    case 7:
        ui->boton_1->setIcon(*rd);
        ui->boton_1->setIconSize(rd->rect().size());
        ui->boton_2->setIcon(*rd);
        ui->boton_2->setIconSize(rd->rect().size());
        ui->boton_3->setIcon(*rd);
        ui->boton_3->setIconSize(rd->rect().size());
        ui->boton_4->setIcon(*rd);
        ui->boton_4->setIconSize(rd->rect().size());
        ui->boton_5->setIcon(*rd);
        ui->boton_5->setIconSize(rd->rect().size());
        ui->boton_6->setIcon(*rd);
        ui->boton_6->setIconSize(rd->rect().size());
        ui->boton_7->setIcon(*rl);
        ui->boton_7->setIconSize(rl->rect().size());
        ui->boton_8->setIcon(*rd);
        ui->boton_8->setIconSize(rd->rect().size());
        ui->boton_9->setIcon(*rd);
        ui->boton_9->setIconSize(rd->rect().size());
        ui->boton_10->setIcon(*rd);
        ui->boton_10->setIconSize(rd->rect().size());
        _timer1->setInterval( 1000 );
        _timer1->start();
        break;
    case 8:
        ui->boton_1->setIcon(*rd);
        ui->boton_1->setIconSize(rd->rect().size());
        ui->boton_2->setIcon(*rd);
        ui->boton_2->setIconSize(rd->rect().size());
        ui->boton_3->setIcon(*rd);
        ui->boton_3->setIconSize(rd->rect().size());
        ui->boton_4->setIcon(*rd);
        ui->boton_4->setIconSize(rd->rect().size());
        ui->boton_5->setIcon(*rd);
        ui->boton_5->setIconSize(rd->rect().size());
        ui->boton_6->setIcon(*rd);
        ui->boton_6->setIconSize(rd->rect().size());
        ui->boton_7->setIcon(*rd);
        ui->boton_7->setIconSize(rd->rect().size());
        ui->boton_8->setIcon(*rl);
        ui->boton_8->setIconSize(rl->rect().size());
        ui->boton_9->setIcon(*rd);
        ui->boton_9->setIconSize(rd->rect().size());
        ui->boton_10->setIcon(*rd);
        ui->boton_10->setIconSize(rd->rect().size());
        _timer1->setInterval( 1000 );
        _timer1->start();
        break;
    case 9:
        ui->boton_1->setIcon(*rd);
        ui->boton_1->setIconSize(rd->rect().size());
        ui->boton_2->setIcon(*rd);
        ui->boton_2->setIconSize(rd->rect().size());
        ui->boton_3->setIcon(*rd);
        ui->boton_3->setIconSize(rd->rect().size());
        ui->boton_4->setIcon(*rd);
        ui->boton_4->setIconSize(rd->rect().size());
        ui->boton_5->setIcon(*rd);
        ui->boton_5->setIconSize(rd->rect().size());
        ui->boton_6->setIcon(*rd);
        ui->boton_6->setIconSize(rd->rect().size());
        ui->boton_7->setIcon(*rd);
        ui->boton_7->setIconSize(rd->rect().size());
        ui->boton_8->setIcon(*rd);
        ui->boton_8->setIconSize(rd->rect().size());
        ui->boton_9->setIcon(*rl);
        ui->boton_9->setIconSize(rl->rect().size());
        ui->boton_10->setIcon(*rd);
        ui->boton_10->setIconSize(rd->rect().size());
        _timer1->setInterval( 1000 );
        _timer1->start();
        break;
    case 10:
        ui->boton_1->setIcon(*rd);
        ui->boton_1->setIconSize(rd->rect().size());
        ui->boton_2->setIcon(*rd);
        ui->boton_2->setIconSize(rd->rect().size());
        ui->boton_3->setIcon(*rd);
        ui->boton_3->setIconSize(rd->rect().size());
        ui->boton_4->setIcon(*rd);
        ui->boton_4->setIconSize(rd->rect().size());
        ui->boton_5->setIcon(*rd);
        ui->boton_5->setIconSize(rd->rect().size());
        ui->boton_6->setIcon(*rd);
        ui->boton_6->setIconSize(rd->rect().size());
        ui->boton_7->setIcon(*rd);
        ui->boton_7->setIconSize(rd->rect().size());
        ui->boton_8->setIcon(*rd);
        ui->boton_8->setIconSize(rd->rect().size());
        ui->boton_9->setIcon(*rd);
        ui->boton_9->setIconSize(rd->rect().size());
        ui->boton_10->setIcon(*rl);
        ui->boton_10->setIconSize(rl->rect().size());
        _timer1->setInterval( 1000 );
        _timer1->start();
        break;
    default:
        ui->boton_1->setIcon(*rd);
        ui->boton_1->setIconSize(rd->rect().size());
        ui->boton_2->setIcon(*rd);
        ui->boton_2->setIconSize(rd->rect().size());
        ui->boton_3->setIcon(*rd);
        ui->boton_3->setIconSize(rd->rect().size());
        ui->boton_4->setIcon(*rd);
        ui->boton_4->setIconSize(rd->rect().size());
        ui->boton_5->setIcon(*rd);
        ui->boton_5->setIconSize(rd->rect().size());
        ui->boton_6->setIcon(*rd);
        ui->boton_6->setIconSize(rd->rect().size());
        ui->boton_7->setIcon(*rd);
        ui->boton_7->setIconSize(rd->rect().size());
        ui->boton_8->setIcon(*rd);
        ui->boton_8->setIconSize(rd->rect().size());
        ui->boton_9->setIcon(*rd);
        ui->boton_9->setIconSize(rd->rect().size());
        ui->boton_10->setIcon(*rd);
        ui->boton_10->setIconSize(rd->rect().size());
        _timer1->setInterval(500);
        _timer1->stop();
        _timer2->stop();
        ui->_lbl_finPrueba->setText("Fin de la prueba.");
        break;
    }
}
//-----------------------------------------

void MainWindow::on_boton_1_clicked()
{
    estado = 1;
    verificar_click(estado);
}

void MainWindow::on_boton_2_clicked()
{
    estado = 2;
    verificar_click(2);
}

void MainWindow::on_boton_3_clicked()
{
    estado = 3;
    verificar_click(estado);
}

void MainWindow::on_boton_4_clicked()
{
    estado = 4;
    verificar_click(estado);
}

void MainWindow::on_boton_5_clicked()
{
    estado = 5;
    verificar_click(estado);
}

void MainWindow::on_boton_6_clicked()
{
    estado = 6;
    verificar_click(estado);
}

void MainWindow::on_boton_7_clicked()
{
    estado = 7;
    verificar_click(estado);
}

void MainWindow::on_boton_8_clicked()
{
    estado = 8;
    verificar_click(estado);
}

void MainWindow::on_boton_9_clicked()
{
    estado = 9;
    verificar_click(estado);
}

void MainWindow::on_boton_10_clicked()
{
   estado = 10;
   verificar_click(estado);
}

void MainWindow::verificar_click(int estado)
{
    if(_estado == estado){
        _estado = estado;
        _aciertos++;
        ui->_lbl_aciertos->setText(QString::fromStdString(std::to_string(_aciertos)));
        cambio_estado();
    }
    else{_errores++;
        ui->_lbl_errores->setText(QString::fromStdString(std::to_string(_errores)));
         cambio_estado();}
}

void MainWindow::on_RegPnt_clicked()
{
    formulario_paciente b(this);
    b.setModal( true );
    connect( &b, &formulario_paciente::enviarDatosPnt, this, &MainWindow::reciboDatosPaciente);
    b.show();
    b.exec();
}
