#ifndef CLAVE_ERRONEA_H
#define CLAVE_ERRONEA_H

#include <QDialog>

namespace Ui {
class clave_erronea;
}

class clave_erronea : public QDialog
{
    Q_OBJECT

public:
    explicit clave_erronea(QWidget *parent = 0);
    ~clave_erronea();

private:
    Ui::clave_erronea *ui;
};

#endif // CLAVE_ERRONEA_H
