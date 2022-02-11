#include <iostream>
#include "functions.h"

using namespace std;


int main()
{
    string texto_original,codificado,codificado2,text_decodificado,name;
    int opcion=0,seed=5, method=1;
    bool main_menu=true;

    cout<<"\tPROGRAMA DE ENCRIPTADO/DESENCRIPTADO"<<endl;
    cout<<"(1) Encriptar"<<endl;
    cout<<"(2) Desencriptar"<<endl;
    cout<<"(3) Salir"<<endl;


    while (main_menu) {
        cout<<"\nSeleccione una opcion: "; cin>>opcion;

        switch (opcion) {
        case 1:
            //ENCRIPTACION
            cout<<"\nENCRIPTACION"<<endl;
            cout<<"Ingrese nombre del archivo (incluya extension): ";
            fflush(stdin);
            getline(cin,name);
            cout<<"Ingrese semilla: "; cin>>seed;
            cout<<"Ingrese metodo: "; cin>>method;

            texto_original= funcLeer(name); //FUNCION para LEER
            cout<<texto_original<<endl;
            codificado=encryptProgram(seed,method,texto_original);
            cout<<"\nComo desea guardar el archivo encriptado: ";
            fflush(stdin);
            getline(cin,name);
            funcEscribir(name,codificado); //FUNCION para ESCRIBIR
            cout<<"Archivo encripado guardado correctamente como "<<name<<endl;
            break;

        case 2:
            //DESENCRIPTACION
            cout<<"\nDESENCRIPTACION"<<endl;
            cout<<"Ingrese nombre del archivo (incluya extension): ";
            fflush(stdin);
            getline(cin,name);
            cout<<"Ingrese semilla: "; cin>>seed;
            cout<<"Ingrese metodo: "; cin>>method;

            codificado2=funcLeer(name); //FUNCION para LEER
            text_decodificado=desencryptProgram(seed,method,codificado2);
            cout<<"\nComo desea guardar el archivo desencriptado: ";
            fflush(stdin);
            getline(cin,name);
            funcEscribir(name,text_decodificado); //FUNCION para ESCRIBIR
            cout<<"Archivo desencripado guardado correctamente como "<<name<<endl;
            break;
        case 3:
            main_menu=false;
            break;
        default:
            cout<<"Opcion invalida"<<endl;
            break;
        }
    }


    //VERIFICACION
    //strComparate(texto_original,text_decodificado);

    return 0;
}
