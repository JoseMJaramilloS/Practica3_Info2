#include "functions.h"

string binario;

string encryptProgram(unsigned int seed,int method, string texto){
    string codificado, particion, aux;

    binario += text2bin(texto);//FUNCION que convierte el texto a binario
    cout<<"Longitud de binario: "<<binario.size()<<endl;//CONTROL

    switch (method) {

    case 1:{
        for (unsigned long int i=0,k=0;i<binario.size();i++) {//Este ciclo crea particiones de n (seed) bits
            particion += binario[i];
            if(seed*(k+1)-1==i){
                cout<<particion;//CONTROL

                if(i<seed) {//n=seed
                    aux=particion;
                    codificado+=notStr(particion);//FUNCION que niega el primer termino
                    cout<<" codificado0: "<<codificado<<endl;//CONTROL
                }
                else{
                    codificado+=codecMethod1(particion,aux);//FUNCION que aplica reglas de codificacion
                    aux=particion;
                }
                cout<<endl;//CONTROL
                particion.clear(); //Se borra la particion
                k++;
            }

        }
        cout<<"Codificion FINAL: "<<codificado<<endl;//CONTROL
        cout<<"Longitud: "<<codificado.size()<<endl;//CONTROL
        break;
    }

    case 2:{
        for (unsigned long int i=0,k=0;i<binario.size();i++) {//Este ciclo crea particiones de n (seed) bits
            particion += binario[i];
            if(seed*(k+1)-1==i){
                cout<<particion<<endl;//CONTROL
                codificado+=codecMethod2(particion);
                particion.clear(); //Se borra la particion
                k++;
            }

        }
        cout<<"Codificion FINAL: "<<codificado<<endl;//CONTROL
        cout<<"Longitud: "<<codificado.size()<<endl;//CONTROL
        break;
    }

    }
    return codificado;
}
