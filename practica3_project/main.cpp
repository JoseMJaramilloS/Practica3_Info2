#include <iostream>
#include "functions.h"

using namespace std;


int main()
{
    string texto_original,codificado,codificado2,text_decodificado;
    int seed=5, method=1;

    //CODIFICACION
    texto_original= funcLeer("prueba2.txt"); //FUNCION para LEER
    cout<<texto_original<<endl;
    codificado=encryptProgram(seed,method,texto_original);
    funcEscribir("codificado_prueba2.txt",codificado);

    //DECODIFICACION
    codificado2=funcLeer("codificado_prueba2.txt"); //FUNCION para LEER
    text_decodificado=desencryptProgram(seed,method,codificado2);
    funcEscribir("decodificado_prueba2.txt",text_decodificado);

    //VERIFICACION
    strComparate(texto_original,text_decodificado);

    return 0;
}
