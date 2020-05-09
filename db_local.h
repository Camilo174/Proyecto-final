#ifndef DB_LOCAL_H
#define DB_LOCAL_H

#include <string>
#include <sqlite3.h>

using namespace std;

class DB_Local{
private:
    sqlite3 *db;

    static int funcionLlamadaU(void *data, int argc, char **argv, char **azColName);

public:
    DB_Local();
    bool almacenarPaciente(string Nombre, string apellido, int edad, int documento, string ingresos, string genero, string raza);
    bool abrirDB( string path );
    bool compararDatosUsuario( string nombreUsuario, string contrasena );
    bool almacenarUsuario( string nombreUsuario, string password,  string Nombre, string apellido, int documento, int edad);
    bool cerrarDB();
};

#endif // DB_LOCAL_H
