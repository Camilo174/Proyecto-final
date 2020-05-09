#include "datos_usuario.h"

datos_usuario::datos_usuario()
{

}

datos_usuario::datos_usuario(user_data datos)
{
    _user_data = datos;
    setUsrData(_user_data);
}
