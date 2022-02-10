#include <iostream>
#include "functions.h"

using namespace std;


int main()
{
    string texto,codificado,codificado2,text_decodificado;
    int seed=4, method=2;

    //CODIFICACION
    texto= funcLeer("prueba3.txt"); //FUNCION para leer ----- Nombre del archivo
    cout<<texto<<endl;
    codificado=encryptProgram(seed,method,texto);
    funcEscribir("codificado_prueba3.txt",codificado);

    //DECODIFICACION
    codificado2=funcLeer("codificado_prueba3.txt");
    text_decodificado=desencryptProgram(seed,method,codificado2);
    funcEscribir("decodificado_prueba3.txt",text_decodificado);

    //VERIFICACION
    strComparate(texto,text_decodificado);

    return 0;
}
