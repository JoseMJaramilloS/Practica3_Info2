#include "functions.h"

string binario;

string encryptProgram(int seed,int method, string texto){
    string codificado, particion, aux;

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
                        codificado+=notStr(particion);//FUNCION que niega el primer termino
                        cout<<" codificado0: "<<codificado<<endl;//CONTROL
                    }
                    else{
                        codificado+=codecRules(particion,aux);//FUNCION que aplica reglas de codificacion
                        aux=particion;
                    }
                    cout<<endl;//CONTROL
                    particion.clear(); //Se borra la particion
                    k++;
                }

            }
            cout<<"Codificion FINAL: "<<codificado<<endl;
            cout<<"Longitud: "<<codificado.size()<<endl;
            break;
        case 2:

        break;

    }
    return codificado;
}
