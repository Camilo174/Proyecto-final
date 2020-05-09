#ifndef DATOS_USUARIO_H
#define DATOS_USUARIO_H
#include <string>

using namespace std;

struct user_data
{
    string nombre;
    string apellido;
    int doc_id;
    int dia_n,mes_n, a_n;
};

class datos_usuario
{
public:
    datos_usuario();
    ~datos_usuario();

    void setUsrData( user_data UsrData ){_user_data=UsrData;}
    user_data getUsrData(){return _user_data;}

    datos_usuario( user_data datos );

private:
    user_data _user_data;
};

#endif // DATOS_USUARIO_H
