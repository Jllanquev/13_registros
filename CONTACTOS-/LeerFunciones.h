#ifndef LEER_FUNCION
#define LEER_FUNCION
#include "struct.h"
#include <iostream>
using namespace std;

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);


#endif