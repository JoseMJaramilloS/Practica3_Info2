#include "functions.h"

string texto, binario;

void encryptProgram(int seed,int method){
    string codificado, particion, aux;

    texto= funcLeer("prueba3.txt"); //FUNCION para leer ----- Nombre del archivo
    cout<<texto<<endl;
    binario += text2bin(texto);//FUNCION que convierte el texto a binario

    cout<<"Longitud de binario: "<<binario.size()<<endl;//CONTROL

    switch (method) {
        case 1:




        for (unsigned long int i=0,k=0;i<binario.size();i++) {//Este ciclo crea particiones de n (seed) bits
            particion += binario[i];
            if(seed*(k+1)-1==i){
                cout<<particion;//CONTROL

                if(i<4) {
                    aux=particion;
                    codificado+=notStr(particion);
                    cout<<" codificado0: "<<codificado<<endl;//CONTROL
                }
                else{
                    codecRules(particion,aux);
                    aux=particion;
                }

                cout<<endl;

                particion.clear();
                k++;
            }


        }

            break;
        case 2:

            break;
    }
}
