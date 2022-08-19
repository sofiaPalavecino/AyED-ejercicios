/*Desarrollar un programa que pida números enteros positivos (finaliza en 0)
y arme dos vectores, uno con los números pares y otro con los impares.
El número máximo de valores a pedir es 100.*/

#include <iostream>
#include <ostream>
#include <string>
using namespace std;

#define _TOPE_ENTEROS 100

typedef int tValores[_TOPE_ENTEROS];

void pedirValores(tValores & valoresImpares, tValores & valoresPares);
void mostrarArray(tValores valores);

int main(){
    tValores valoresImpares;
    tValores valoresPares;
    pedirValores(valoresImpares, valoresPares);
    cout<<"Valores impares"<<endl;
    mostrarArray(valoresImpares);
    cout<<"Valores pares"<<endl;
    mostrarArray(valoresPares);
}

void pedirValores(tValores & valoresImpares, tValores & valoresPares){
    int valor = -1;
    int indicePar, indiceImpar = 0;
    cout<<"Ingresar valores enteros. 0 para terminar"<<endl;
    cin>>valor;
    while (indiceImpar < _TOPE_ENTEROS && indicePar < _TOPE_ENTEROS && valor !=0) {
        if(valor%2 == 0){
            valoresPares[indicePar] = valor;
            indicePar++;
        }else{
            valoresImpares[indiceImpar] = valor;
            indiceImpar++;
        }
        cout<<"Ingresar valores enteros. 0 para terminar"<<endl;
        cin>>valor;
    }
    
}

void mostrarArray(tValores valores){
    for (int i = 0; valores[i] != 0; i++){
        cout<<valores[i];
        if(valores[i+1] != 0) cout<<", ";
    }
    cout<<endl;
}