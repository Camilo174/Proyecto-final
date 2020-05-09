#ifndef USUARIO_H
#define USUARIO_H

#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
class usuario;
}

class usuario : public QDialog
{
    Q_OBJECT

public:
    explicit usuario(QWidget *parent = 0);
    ~usuario();
signals:

private slots:

    void on_buttonBox_accepted();

private:
    Ui::usuario *ui;
};

#endif // USUARIO_H
