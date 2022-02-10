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

void funcEscribir(string nombre, string texto)//Funcion que escribe "texto", en un archivo con "nombre"
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

string codecMethod1(string particion, string aux){//Esta funcion aplica las 3 reglas del metodo 1, basandose en el numero de 0s y 1s de la particion anterior (aux)
    string codificado;
    unsigned int count=0;

    for (unsigned long int i=0;i<aux.size();i++) {//Conteo de 0s y 1s de la particion anterior
        if(aux[i]=='1') count++;
    }

    if (count == aux.size()/2 && aux.size()%2 == 0){//Caso 1 '0s'=='1s' (restriccion de impares)
        cout<<" caso 1"<<endl;//CONTROL
        for (unsigned long int i=0;i<particion.size();i++) {
            if(particion[i]=='0') codificado += '1'; //se invierte el bit
            else codificado += '0';
        }
    }

    else if(count < aux.size()/2){//Caso 2 '0s'>'1s'
        cout<<" caso 2"<<endl;//CONTROL
        for (unsigned long int i=0,k=0;i<particion.size();i++) {
            if(2*(k+1)-1==i){       //si es multiplo de 2 (considerando que se indexa desde cero)
                if(particion[i]=='0') codificado += '1'; //se invierte el bit
                else codificado += '0';
                k++;
            }
            else codificado += particion[i];//sino se pasa igual
        }
    }
    else{//Caso 3 '0s'<'1s'
        cout<<" caso 3"<<endl;//CONTROL
        for (unsigned long int i=0,k=0;i<particion.size();i++) {
            if(3*(k+1)-1==i){       //si es multiplo de 3 (considerando que se indexa desde cero)
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

string codecMethod2(string particion)//Segundo metodo de codificacion
{   string codificado;

    codificado += particion[particion.size()-1];//Guardo el ultimo bit del arreglo original
    for (unsigned long int i=0;i<particion.size()-1;i++) {//Guardo a partir de ahí en orden
        codificado += particion[i];
    }
    cout<<" codificado: "<<codificado<<endl; //CONTROL
    return codificado;
}

string decodecMethod2(string particion)//Segundo metodo de DEcodificacion
{   string codificado;

    for (unsigned long int i=1;i<particion.size();i++) {//Guardo a partir del segundo bit en orden
        codificado += particion[i];
    }
    codificado += particion[0];//Guardo el primer bit del arreglo original
    cout<<" codificado: "<<codificado<<endl; //CONTROL
    return codificado;
}


void strComparate(string texto1, string texto2)//Compara dos cadenas de strings
{
    if(texto1.size()==texto2.size()){
        for (unsigned long int i=0;i<texto1.size();i++) {
            if(texto1[i]!=texto2[i]) {
                cout<<"Las cadenas no coinciden"<<endl;
                break;
            }
        }
        cout<<"Las cadenas cocinciden"<<endl;
    }
    else cout<<"Las cadenas no coinciden"<<endl;

}

string bin2text(string binario)//convierte binario a texto
{
    string texto,eightBits;
    int num=0;
    for (unsigned long int i=0,k=0;i<binario.size();i++) {
        eightBits += binario[i];
        if(8*(k+1)-1==i){       //Particiones de 8 bits
            cout<<eightBits<<endl;//CONTROL

            for (int i=7;i>=0;i--) {//Recorre los 8 bits para convertirlo a decimal y luego a caracter
                if(eightBits[i]=='1'){
                    num += potencia(2,7-i);
                }
            }
            cout<<num<<": "<<char(num)<<endl; //CONTROL
            texto += char(num);
            num=0;
            eightBits.clear();
            k++;
        }

    }
    cout<<texto<<endl; //CONTROL
    return texto;
}

int potencia(int base, int exp)//realiza la operacion de potencia base^exp
{
    int result=1;
    for (int i=1;i<=exp;i++) {
        result *=base;
    }
    return result;
}
