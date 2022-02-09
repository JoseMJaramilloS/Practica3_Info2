#include <iostream>
#include "functions.h"

using namespace std;


int main()
{
    string texto,codificado;

    texto= funcLeer("prueba3.txt"); //FUNCION para leer ----- Nombre del archivo
    cout<<texto<<endl;
    codificado=encryptProgram(5,2,texto);
    funcEscribir("codificado_prueba3.txt",codificado);

    return 0;
}
