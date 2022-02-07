#include "functions.h"

string texto, binario;

void encryptProgram(int seed,int method){
    string codificado, particion;
    texto= funcLeer("C:\\Users\\jossa\\Desktop\\prueba2.txt"); //funcion para leer
    cout<<texto<<endl;
    binario += text2bin(texto);//funcion que convierte el texto a binario
    switch (method) {
        case 1:

        for (unsigned long int i=0,k=0;i<binario.size();i++) {
            particion += binario[i];
            if(seed*(k+1)-1==i){
                cout<<particion<<endl;
                particion.clear();
                k++;
            }


        }

            break;
        case 2:

            break;
    }
}
