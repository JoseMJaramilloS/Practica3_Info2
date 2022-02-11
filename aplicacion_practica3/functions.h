#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

string encryptProgram(unsigned int seed, int method, string texto);
string desencryptProgram(unsigned int seed,int method, string binario);
string funcLeer(string nombre);
void funcEscribir(string nombre, string texto);
void funcEscribirFIX(string nombre, string texto);
string text2bin(string texto);
string strInverter(string);
string notStr(string);
string codecMethod1(string particion, string aux);
string codecMethod2(string particion);
string decodecMethod2(string particion);
void strComparate(string,string);
string bin2text(string binario);
int potencia(int base, int exp);
void usersInfo(string users,size_t posicion, string *cedula,string *pass,string *saldo);
