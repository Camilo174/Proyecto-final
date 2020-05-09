#include "formulario_paciente.h"
#include "ui_formulario_paciente.h"


using namespace std;

formulario_paciente::formulario_paciente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formulario_paciente)
{
    ui->setupUi(this);
}

formulario_paciente::~formulario_paciente()
{
    delete ui;
}

void formulario_paciente::on_buttonBox_accepted()
{
    string NombrePnt = ui->nombre_pnt->text().toStdString();
    string ApellidoPnt = ui->apellido_pnt->text().toStdString();
    int docPnt = ui->doc_pnt->text().toInt();

    string generoPnt;
    string nivelSEpnt;
    string razaPnt;

    int anoN = ui->fechaN_pnt->date().year();
    int mesN = ui->fechaN_pnt->date().month();
    int diaN = ui->fechaN_pnt->date().day();

    QDate fecha_actual = QDate::currentDate();
    int anoA = fecha_actual.year();
    int mesA = fecha_actual.month();
    int diaA = fecha_actual.day();
    int edad = calcular_edad(anoN, mesN, diaN, anoA, mesA, diaA);

    bool genero_fem = ui->fem_pnt->isChecked();

    if(genero_fem){
        generoPnt = "Femenino";}
    else{
        generoPnt = "Masculino";
    }

    bool alto = ui->alto_pnt->isChecked();
    bool medio = ui->medio_pnt->isChecked();

    if(alto){
        nivelSEpnt = "Alto";
    }else{
        if(medio){
            nivelSEpnt = "Medio";
        }
        else{
            nivelSEpnt = "Bajo";
        }
    }

    bool mezt = ui->mezt->isChecked();
    bool afro = ui->afro->isChecked();

    if(mezt){
        razaPnt = "Mestizo";
    }else{
        if(afro){
            razaPnt = "Afrodescendiente";
        }
        else{
            razaPnt = "Indigena";
        }
    }

    bool aceptado = true;

    emit enviarDatosPnt(NombrePnt,ApellidoPnt,edad,docPnt,generoPnt,razaPnt,nivelSEpnt,aceptado);
}

int formulario_paciente::calcular_edad(int anoN, int mesN, int diaN, int ano_actual, int mes_actual, int dia_actual)
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
