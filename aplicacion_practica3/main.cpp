#include "functions.h"

int main()
{
    int select = 0;
    string password,aux,sudo,users,user,cedula,pass,saldo;
    size_t posicion;
    int retiro,transac;

    cout<< "\tBIENVENIDO A SU CAJERO ELECTRONICO" << endl;
    cout<<"MENU PRINCIPAL: "<<endl;
    cout<<"(1) Ingresar como administrador"<<endl;
    cout<<"(2) Ingresar como usuario"<<endl;
    cout<<"(3) Salir"<<endl;
    while (true) {

        cout<<"\nDigite una opcion: "; cin>>select;

        switch (select) {
        case 1://==============================MENU ADMINISTRADOR===================================
            cout<<"Contrasenia de administrador: ";
            fflush(stdin);
            getline(cin,password);
//            aux=encryptProgram(3,2,funcLeer("sudo_ini.txt"));//Inicializacion de la base de datos
//            funcEscribir("sudo.txt",aux);
            sudo=desencryptProgram(3,2,funcLeer("sudo.txt"));
            if(password==sudo){                             //Validando ingreso del administrador
                cout<<"Logeado correctamente\n\n\tBIENVENIDO ADMINISTRADOR: \n"<<endl;
                cout<<"(1) Listar usuarios"<<endl;
                cout<<"(2) Ingresar nuevo usuario"<<endl;
                cout<<"(3) Salir"<<endl;
                sudo.clear();

                bool menu_admin=true;
                while (menu_admin) {
                    cout<<"\nDigite una opcion: "; cin>>select;
                    switch (select) {

                    case 1:
//                        aux=encryptProgram(3,2,funcLeer("users_ini.txt"));//Inicializacion de la base de datos
//                        funcEscribir("users_test.txt",aux);
                        cout<<"\n\tLista de usuarios"<<endl;
                        users=desencryptProgram(3,2,funcLeer("users_test.txt")); //Se lee el archivo encriptado
                        cout<<users<<endl;
                        break;

                    case 2:{
                        cout<<"Ingrese nuevo usuario con el formato (cedula,clave,saldo): ";
                        fflush(stdin);
                        getline(cin,aux);
                        users=desencryptProgram(3,2,funcLeer("users_test.txt"));
                        users+= aux+'\n';

                        funcEscribir("users_test.txt",encryptProgram(3,2,users));//se agrega la informacion en el archivo encriptado

                        cout<<"\n\tLista de usuarios"<<endl;
                        cout<<desencryptProgram(3,2,funcLeer("users_test.txt"))<<endl;

                        users.clear();
                        break;

                    }
                    case 3:
                        menu_admin=false;
                        cout<<"CERRANDO SESION"<<endl;
                        cout<<"Devuelta al MENU PRINCIPAL"<<endl;
                        cout<<"(1) Ingresar como administrador"<<endl;
                        cout<<"(2) Ingresar como usuario"<<endl;
                        cout<<"(3) Salir"<<endl;
                        break;

                    default:
                        cout<<"Opcion invalida"<<endl;
                        break;
                    }
                }
            }
            else cout<<"Contrasenia incorrecta"<<endl;
            break;

        case 2://==============================MENU USUARIO===================================
            users=desencryptProgram(3,2,funcLeer("users_test.txt"));
            cout<<"Ingrese su numero de usuario: ";
            fflush(stdin);
            getline(cin,user);
            posicion=users.find(user);//retorna la posicion del usuario si existe

            if(posicion != string::npos){
                usersInfo(users,posicion,&cedula,&pass,&saldo);//extrae la informacion del usuario
                cout<<"Ingrese su clave: ";
                fflush(stdin);
                getline(cin,password);

                if (password==pass) {
                    cout<<"Logeado correctamente\n\n\tBIENVENIDO USUARIO: \n"<<endl;
                    cout<<"(1) Consultar saldo"<<endl;
                    cout<<"(2) Retirar dinero"<<endl;
                    cout<<"(3) Salir"<<endl;
                    sudo.clear();

                    bool menu_user=true;
                    while (menu_user) {

                        users=desencryptProgram(3,2,funcLeer("users_test.txt"));
                        usersInfo(users,posicion,&cedula,&pass,&saldo);
                        cout<<"\nDigite una opcion: "; cin>>select;
                        switch (select) {

                        case 1:
                            if (1000>stoi(saldo)) {
                                cout<<"No puede realizar esta operacion, saldo insuficiente"<<endl;
                            }
                            else{
                                cout<<"Saldo disponible: "<<saldo<<endl;
                                transac=stoi(saldo);//stoi: de string a entero
                                transac-=1000;
                                users.replace(users.find(saldo,posicion),saldo.size(),to_string(transac));
                                funcEscribir("users_test.txt",encryptProgram(3,2,users));
                            }

                            break;

                        case 2:{
                            cout<<"Cuanto dinero desea retirar: "; cin>>retiro;
                            transac=stoi(saldo);//stoi: de string a entero
                            if (retiro>stoi(saldo)) {
                                cout<<"No puede retirar esa cantidad"<<endl;
                            }
                            else{
                                transac-=retiro-1000;
                                users.replace(users.find(saldo,posicion),saldo.size(),to_string(transac));
                                cout<<"Nuevo saldo: "<<transac<<endl;
                                funcEscribir("users_test.txt",encryptProgram(3,2,users));
                            }


                        }
                            break;
                        case 3:
                            menu_user=false;
                            cout<<"CERRANDO SESION"<<endl;
                            cout<<"Devuelta al MENU PRINCIPAL"<<endl;
                            cout<<"(1) Ingresar como administrador"<<endl;
                            cout<<"(2) Ingresar como usuario"<<endl;
                            cout<<"(3) Salir"<<endl;
                            break;

                        default:
                            cout<<"Opcion invalida"<<endl;
                            break;
                        }
                    }
                }
                else cout<<"Clave incorrecta"<<endl;

            }
            else cout<<"Ese usuario no esta registrado"<<endl;
            break;
        case 3:
            exit(-1);
            break;
        default:
            cout<<"Opcion invalida"<<endl;
            break;


        }
    }


    return 0;
}
