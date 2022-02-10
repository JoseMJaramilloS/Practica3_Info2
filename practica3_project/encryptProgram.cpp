#include "functions.h"

string binario;

string encryptProgram(unsigned int seed,int method, string texto){
    string codificado, particion, aux;

    binario += text2bin(texto);//FUNCION que convierte el texto a binario
    cout<<"Longitud de binario: "<<binario.size()<<endl;//CONTROL

    //En caso de que el numero de bits no sea multiplo de la semilla, se debe rellenar con '0s' tamaño'= tamaño + tamaño%semilla)
    if (binario.size()%seed != 0) {
        for (unsigned int i=1;i<=binario.size()%seed;i++) {
            binario += '0';
        }
    }

    cout<<"Longitud de binario fixed: "<<binario.size()<<endl;//CONTROL

    switch (method) {

    case 1:{
        for (unsigned long int i=0,k=0;i<binario.size();i++) {//Este ciclo crea particiones de n (seed) bits
            particion += binario[i];
            if(seed*(k+1)-1==i){
                //cout<<particion;//CONTROL

                if(i<seed) {//n=seed
                    aux=particion;
                    codificado+=notStr(particion);//FUNCION que niega el primer termino
                    //cout<<" codificado0: "<<codificado<<endl;//CONTROL
                }
                else{
                    codificado+=codecMethod1(particion,aux);//FUNCION que aplica reglas de codificacion1
                    aux=particion;
                }
                //cout<<endl;//CONTROL
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
                //cout<<particion<<endl;//CONTROL
                codificado+=codecMethod2(particion);//FUNCION que aplica reglas de codificacion2
                particion.clear(); //Se borra la particion
                k++;
            }

        }
        //cout<<"Codificion FINAL: "<<codificado<<endl;//CONTROL
        //cout<<"Longitud: "<<codificado.size()<<endl;//CONTROL
        break;
    }

    }


    return codificado;
}
