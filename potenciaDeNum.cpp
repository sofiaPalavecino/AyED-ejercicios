#include <iostream>
#include <ostream>
using namespace std;

void pedirValores(int & numero, float & potencia);
float calcularPotencia(int numero, float potencia);
float obtenerPotencia(int numero, float potencia);

int main(){
    int numero;
    float potencia;
    pedirValores(numero,potencia);
    cout<<"Resultado de "<<numero<<"^"<<potencia<<": "<<obtenerPotencia(numero,potencia);
}

void pedirValores(int & numero, float & potencia){
    bool salir = false;
    cout<<"Ingresar numero"<<endl;
    cin>>numero;
    cout<<"Ingresar potencia"<<endl;
    cin>>potencia;
}

float obtenerPotencia(int numero, float potencia){
    if(potencia > 0){
        return(calcularPotencia(numero, potencia));
    }else if(potencia < 0){
        potencia *= -1;
        return(1/calcularPotencia(numero, potencia));
    }
    return 1;
}

float calcularPotencia(int numero, float potencia){
    int resultado = numero;
    while (potencia > 1){
        resultado *= numero;
        potencia--;
    }
    return resultado;
}