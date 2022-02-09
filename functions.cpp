#include "functions.h"

string funcLeer(string nombre){
    string linea,texto,binario;
    ifstream archivoLectura;

    archivoLectura.open(nombre); //Abrir el archivo en modo lectura

    if(archivoLectura.fail()){//Hay error al abrir el archivo
        cout<<"No se pudo abrir el archivo. Error de Lectura."<<endl;
        exit(-1); //Finalizar la ejecucion del programa
    }

    while (!archivoLectura.eof()) {//mientras no se haya llegado al final del archivo
        getline(archivoLectura,linea,'\n');
        texto += linea+'\n';
        //cout<<linea<<endl;//CONTROL
    }
    //cout<<texto<<endl;
    //binario += text2bin(texto);//funcion que convierte el texto a binario
    archivoLectura.close();
    return texto;
}

void funcEscribir(string nombre, string texto)
{
    ofstream archivoEscritura;

    archivoEscritura.open(nombre); //Abrir el archivo en modo lectura

    if(archivoEscritura.fail()){//Hay error al abrir el archivo
        cout<<"No se pudo abrir el archivo. Error de escritura."<<endl;
        exit(-1); //Finalizar la ejecucion del programa
    }

    archivoEscritura<<texto;
    archivoEscritura.close();
}

string text2bin(string texto){//convierte el texto a binario
    string bin,eightBits;
    int n;
    for (unsigned long int i=0;i < texto.size();i++) {//cadena.size: retorna el tamaño de la cadena
        n=int(texto[i]);//Casteo de variable string a entero

        cout<<texto[i]<<endl;//CONTROL
        cout<<n<<endl;//CONTROL

        eightBits="";
        for(int i=1;i<=8;i++) {
            if(n%2==0) eightBits+= '0';
            else eightBits+= '1';
            n /= 2;
        }
        cout<<strInverter(eightBits)<<endl;//CONTROL
        bin += strInverter(eightBits);//FUNCION que invierte la cadena
    }
    cout<<bin<<endl;
    return bin;
}

string strInverter(string original){//invierte una cadena tipo string
    string invertida;
    for (int i=original.size()-1;i>=0;i--) {
        invertida += original[i];
    }
    return invertida;
}

string notStr(string particion){//invierte los bits de una cadena string
    string codificado;

    for (unsigned long int i=0;i<particion.size();i++) {
        if(particion[i]=='0') codificado += '1';
        else codificado += '0';
    }
    return codificado;
}

string codecRules(string particion, string aux){//Esta funcion aplica las 3 reglas de codificiacion basandose en el numero de 0s y 1s de la particion anterior (aux)
    string codificado;
    unsigned int count=0;
    for (unsigned long int i=0;i<aux.size();i++) {
        if(aux[i]=='1') count++;
    }
    if (count == aux.size()/2){     //Caso 1 '0s'=='1s'
        cout<<" caso 1"<<endl;//CONTROL
        for (unsigned long int i=0;i<particion.size();i++) {
            if(particion[i]=='0') codificado += '1'; //se invierte el bit
            else codificado += '0';

        }
    }

    else if(count < aux.size()/2){  //Caso 2 '0s'>'1s'
        cout<<" caso 2"<<endl;//CONTROL
        for (unsigned long int i=0,k=0;i<particion.size();i++) {
            if(2*(k+1)-1==i){       //si es multiplo par (considerando que se indexa desde cero)
                if(particion[i]=='0') codificado += '1'; //se invierte el bit
                else codificado += '0';
                k++;
            }
            else codificado += particion[i];//sino se pasa igual
        }
    }
    else{                           //Caso 3 '0s'<'1s'
        cout<<" caso 3"<<endl;//CONTROL
        for (unsigned long int i=0,k=0;i<particion.size();i++) {
            if(3*(k+1)-1==i){       //si es multiplo par (considerando que se indexa desde cero)
                if(particion[i]=='0') codificado += '1'; //se invierte el bit
                else codificado += '0';
                k++;
            }
            else codificado += particion[i];//sino se pasa igual
        }
    }

    cout<<" codificado: "<<codificado<<endl; //CONTROL
    return codificado;
}


