#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QDate>
#include <QTimer>
#include <iostream>
#include "db_local.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:


private slots:

    void cambio_estado();

    void terminar_prueba();

    int random1_10();

    int calcular_edad(int anoN, int mesN, int diaN, int ano_actual, int mes_actual, int dia_actual);

    void reciboDatosUsuarioReg( string username, string password );
    void reciboDatosUsuarioNew(string usernameN, string nameN, string apellidoN , string passwordN, int docIdN, int dayNR, int monthNR, int yearNR, bool aceptadoUs);
    void reciboDatosPaciente(string nombrePnt, string apellidoPnt, int edad, long docPnt, string generoPnt, string razaPnt, string nivelSEpnt,bool aceptado);



    void on_cmd_ingreso_clicked();
    void on_cmd_inicio_clicked();
    void on_RegPnt_clicked();

    void on_boton_1_clicked();
    void on_boton_2_clicked();
    void on_boton_3_clicked();
    void on_boton_4_clicked();
    void on_boton_5_clicked();
    void on_boton_6_clicked();
    void on_boton_7_clicked();
    void on_boton_8_clicked();
    void on_boton_9_clicked();
    void on_boton_10_clicked();

    void verificar_click(int estado);

private:
    Ui::MainWindow *ui;
    QPixmap *rd, *rl;
    QTimer  *_timer1;
    QTimer  *_timer2;
    int _estado, estado, _aciertos, _errores;
    DB_Local base;
};

#endif // MAINWINDOW_H
