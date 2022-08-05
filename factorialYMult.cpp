#include <iostream>
#include <ostream>
#include <string>
using namespace std;

#define _PRIM_MULTIPLO 3
#define _SEC_MULTIPLO 5
#define _CANT_VALORES 10

typedef int tValores[_CANT_VALORES];

struct tMultiplos{
    string nombre;
    tValores multiplos;
    int cantidad = 0;
};

typedef tMultiplos tListMult[4];

void inicializarListMultiplos(tListMult & listasDeMultiplos);
void pedirValores(tValores & valores);
int calcularFactorial(int numero);
void obtenerFactoriales(tValores valores);
void obtenerMultiplos(tValores valores, tListMult & listasDeMultiplos);
void mostrarMultiplos(tListMult listasDeMultiplos);
void mostrarValores(tValores valores, int indice);

int main(){
    tValores valores;
    tListMult listasDeMultiplos;
    inicializarListMultiplos(listasDeMultiplos);
    pedirValores(valores);
    obtenerFactoriales(valores);
    obtenerMultiplos(valores,listasDeMultiplos);
    mostrarMultiplos(listasDeMultiplos);
}

void inicializarListMultiplos(tListMult & listasDeMultiplos){
    listasDeMultiplos[0].nombre = "Multiplo de " + to_string(_PRIM_MULTIPLO) + " y " + to_string(_SEC_MULTIPLO);
    listasDeMultiplos[1].nombre = "Multiplo de " + to_string(_PRIM_MULTIPLO);
    listasDeMultiplos[2].nombre = "Multiplo de " + to_string(_SEC_MULTIPLO);
    listasDeMultiplos[3].nombre = "No es multiplo de ninguno";
}

void pedirValores(tValores & valores){
    cout<<"Ingresar "<<_CANT_VALORES<<" valores"<<endl;
    for (int i = 0; i < _CANT_VALORES; i++){
        int v;
        cin>>v;
        valores[i]=v;
    }
}

int calcularFactorial(int numero){
    int resultado = 1;
    while(numero > 0){
        resultado *= numero; 
        numero--;
    }
    return resultado;
}

void obtenerFactoriales(tValores valores){
    for (int i = 0; i < _CANT_VALORES; i++){
        cout<<"Factorial de "<<valores[i]<<": "<<calcularFactorial(valores[i])<<endl;
    } 
}

void obtenerMultiplos(tValores valores, tListMult & listasDeMultiplos){
    for (int i = 0; i < _CANT_VALORES; i++){
        if(valores[i]%_PRIM_MULTIPLO == 0 && valores[i]%_SEC_MULTIPLO == 0){
            listasDeMultiplos[0].multiplos[listasDeMultiplos[0].cantidad] = valores[i];
            listasDeMultiplos[0].cantidad++;
        }
        if(valores[i]%_PRIM_MULTIPLO == 0){
            listasDeMultiplos[1].multiplos[listasDeMultiplos[1].cantidad] = valores[i];
            listasDeMultiplos[1].cantidad++;
        }else if(valores[i]%_SEC_MULTIPLO == 0){
            listasDeMultiplos[2].multiplos[listasDeMultiplos[2].cantidad] = valores[i];
            listasDeMultiplos[2].cantidad++;
        }else{
            listasDeMultiplos[3].multiplos[listasDeMultiplos[3].cantidad] = valores[i];
            listasDeMultiplos[3].cantidad++;
        }
    }
}

void mostrarMultiplos(tListMult listasDeMultiplos){
    for (int i = 0; i < 4; i++){
        cout<<listasDeMultiplos[i].nombre<<endl;
        mostrarValores(listasDeMultiplos[i].multiplos,listasDeMultiplos[i].cantidad);
    }
    
}

void mostrarValores(tValores valores, int indice){
    for (int i = 0; i < indice; i++){
        cout<<valores[i];
        if(i == indice-1){
            cout<<endl;
        }else{
            cout<<", ";
        }
    }
}