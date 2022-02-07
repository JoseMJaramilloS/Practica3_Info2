#include "functions.h"

string funcLeer(string nombre){
    string linea,texto,binario;
    ifstream archivoLectura;

    archivoLectura.open(nombre); //Abrir el archivo en modo lectura

    if(archivoLectura.fail()){//Hay error al abrir el archivo
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(-1); //Finalizar la ejecucion del programa
    }

    while (!archivoLectura.eof()) {//mientras no se haya llegado al final del archivo
        getline(archivoLectura,linea,'\n');
        texto += linea+'\n';
        //cout<<linea<<endl;//control
    }
    //cout<<texto<<endl;
    //binario += text2bin(texto);//funcion que convierte el texto a binario
    archivoLectura.close();
    return texto;
}

string text2bin(string texto){//convierte el texto a binario (aun esta por definir si no retorna nada)
    string bin,eightBits;
    int n;
    for (unsigned long int i=0;i < texto.size();i++) {//cadena.size: retorna el tamaño de la cadena
        n=int(texto[i]);//Casteo de variable string a entero

        cout<<texto[i]<<endl;//control
        cout<<n<<endl;//control

        eightBits="";
        for(int i=1;i<=8;i++) {
            if(n%2==0) eightBits+= '0';
            else eightBits+= '1';
            n /= 2;
        }
        cout<<strInverter(eightBits)<<endl;//control
        bin += strInverter(eightBits);//funcion que invierte la cadena
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

//string codecRules(string particion){
//    string codificado;
//    int num = int(codificado);
//    if()


//    return codificado
//}
