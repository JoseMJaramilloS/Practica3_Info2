#include <iostream>
#include "functions.h"

using namespace std;


int main()
{
    string texto_original,codificado,codificado2,text_decodificado;
    int seed=5, method=1;

    //CODIFICACION
    texto_original= funcLeer("smooth_criminal.txt"); //FUNCION para LEER
    cout<<texto_original<<endl;
    codificado=encryptProgram(seed,method,texto_original);
    funcEscribir("codificado_smooth_criminal.txt",codificado);

    //DECODIFICACION
    codificado2=funcLeer("codificado_smooth_criminal.txt"); //FUNCION para LEER
    text_decodificado=desencryptProgram(seed,method,codificado2);
    funcEscribir("decodificado_smooth_criminal.txt",text_decodificado);

    //VERIFICACION
    strComparate(texto_original,text_decodificado);

    return 0;
}
