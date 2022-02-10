#include "functions.h"

/*
La decodificacion para el primer metodo se raliza invirtiendo la primera particion y
a partir de allí usando las particiones DECODIFICADAS como referencia
*/

string desencryptProgram(unsigned int seed,int method, string binario){
    string decoBinario, texto, particion,aux;
    switch (method) {
    case 1:{
        for (unsigned long int i=0,k=0;i<binario.size();i++) {//Este ciclo crea particiones de n (seed) bits
            particion += binario[i];
            if(seed*(k+1)-1==i){
                //cout<<particion;//CONTROL

                if(i<seed) {//n=seed
                    aux=notStr(particion);//FUNCION que niega el primer termino. En este caso se tiene la referencia del decodificado
                    decoBinario+=aux;//
                    //cout<<" decodificado0: "<<decoBinario<<endl;//CONTROL
                }
                else{
                    aux=codecMethod1(particion,aux);//Se sigue tomando como referencia las particiones ya decodificadas, la funcion de decodificacion es la misma que de codificacion.
                    decoBinario+=aux;

                }
                //cout<<endl;//CONTROL
                particion.clear(); //Se borra la particion
                k++;
            }

        }
        cout<<"Decodificion FINAL: "<<decoBinario<<endl;//CONTROL
        cout<<"Longitud: "<<decoBinario.size()<<endl;//CONTROL
        break;
    }

    case 2:{
        for (unsigned long int i=0,k=0;i<binario.size();i++) {//Este ciclo crea particiones de n (seed) bits
            particion += binario[i];
            if(seed*(k+1)-1==i){
                //cout<<particion<<endl;//CONTROL
                decoBinario+=decodecMethod2(particion);//FUNCION que aplica reglas de DEcodificacion2
                particion.clear(); //Se borra la particion
                k++;
            }

        }
        //cout<<"Decodificion FINAL: "<<decoBinario<<endl;//CONTROL
        //cout<<"Longitud: "<<decoBinario.size()<<endl;//CONTROL
        break;
    }

    }
    //En caso de que el numero de bits no sea multiplo de la semilla, este debio rellenarse con '0s'
    //tamaño'= tamaño - tamaño%8
    //Por lo que es necesario eliminarlos

    decoBinario.erase(decoBinario.size()-decoBinario.size()%8,decoBinario.size()-1);
    cout<<"Longitud fixed: "<<decoBinario.size()<<endl;//CONTROL

    texto =bin2text(decoBinario);

    return texto;
}

