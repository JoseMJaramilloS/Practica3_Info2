#include "functions.h"

string desencryptProgram(unsigned int seed,int method, string binario){
    string decodificado, texto, particion,aux;
    switch (method) {

    case 1:{
        for (unsigned long int i=0,k=0;i<binario.size();i++) {//Este ciclo crea particiones de n (seed) bits
            particion += binario[i];
            if(seed*(k+1)-1==i){
                cout<<particion;//CONTROL

                if(i<seed) {//n=seed
                    aux=particion;
                    decodificado+=notStr(particion);//FUNCION que niega el primer termino
                    cout<<" decodificado0: "<<decodificado<<endl;//CONTROL
                }
                else{
                    decodificado+=codecMethod1(particion,aux);//FUNCION que aplica reglas de codificacion1
                    aux=particion;
                }
                cout<<endl;//CONTROL
                particion.clear(); //Se borra la particion
                k++;
            }

        }
        cout<<"Decodificion FINAL: "<<decodificado<<endl;//CONTROL
        cout<<"Longitud: "<<decodificado.size()<<endl;//CONTROL
        break;
    }

    case 2:{
        for (unsigned long int i=0,k=0;i<binario.size();i++) {//Este ciclo crea particiones de n (seed) bits
            particion += binario[i];
            if(seed*(k+1)-1==i){
                cout<<particion<<endl;//CONTROL
                decodificado+=decodecMethod2(particion);//FUNCION que aplica reglas de DEcodificacion2
                particion.clear(); //Se borra la particion
                k++;
            }

        }
        cout<<"Decodificion FINAL: "<<decodificado<<endl;//CONTROL
        cout<<"Longitud: "<<decodificado.size()<<endl;//CONTROL
        break;
    }

    }

    texto =bin2text(decodificado);

    return texto;
}

