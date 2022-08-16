/*Desarrollar un programa que pida números que representan edades (máximo 60 edades),
calcule el promedio y muestre cuántos superan el promedio.
*/
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

#define _TOPE_PERSONAS 60

typedef int tEdades[_TOPE_PERSONAS];

void inicializarVector(tEdades & edades);
void pedirEdades(tEdades & edades, int & cantidad);
int calcularPromedio(tEdades edades, int cantidad);
int cantPersonasMayoresPromedio(tEdades edades, int cantidad);

int main(){
    tEdades edades;
    int cantidad = 0;
    inicializarVector(edades);
    pedirEdades(edades, cantidad);
    cout<<"La cantidad de personas que superan el promedio de edad son: "<<cantPersonasMayoresPromedio(edades,cantidad);
}

void inicializarVector(tEdades & edades){
    for (int i = 0; i < _TOPE_PERSONAS; i++){
        edades[i] = 0;
    }
}

void pedirEdades(tEdades & edades, int & cantidad){
    int edad = 0;
    cout<<"Ingresar edad. -1 para terminar"<<endl;
    cin>>edad;
    for (int i = 0; i < _TOPE_PERSONAS && edad != -1; i++){
        edades[i] = edad;
        cantidad++;
        while (edades[i] < -1){
            cout<<"Ingresar edad. -1 para terminar"<<endl;
            cin>>edad;
        }
    }
}

int cantPersonasMayoresPromedio(tEdades edades, int cantidad){
    int promedio = calcularPromedio(edades,cantidad);
    cout<<"Promedio de edad: "<<promedio<<endl;
    int cantMayores = 0;
    for (int i = 0; i < cantidad; i++){
        if(edades[i] > promedio) cantMayores++;
    }
    return cantMayores;
}

int calcularPromedio(tEdades edades, int cantidad){
    int sumatoria = 0;
    for (int i = 0; i < cantidad; i++){
        sumatoria += edades[i];
    }
    return sumatoria/cantidad;
}