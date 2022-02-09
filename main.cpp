#include <iostream>
#include "functions.h"

using namespace std;


int main()
{   //C:\\Users\\jossa\\Desktop\\prueba3.txt
    string texto,codificado;

    texto= funcLeer("prueba3.txt"); //FUNCION para leer ----- Nombre del archivo
    cout<<texto<<endl;
    codificado=encryptProgram(4,1,texto);
    funcEscribir("codificado_prueba3.txt",codificado);

    return 0;
}
