#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

string encryptProgram(unsigned int seed, int method, string texto);
string funcLeer(string nombre);
void funcEscribir(string nombre, string texto);
string text2bin(string texto);
string strInverter(string);
string notStr(string);
string codecMethod1(string particion, string aux);
string codecMethod2(string particion);
