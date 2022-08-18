/*. Desarrollar una función tal que dado un número entero positivo
calcule y retorne su factorial.
En factorial del N es el resultado de multiplicar 1x2x3x....xN*/

#include <iostream>
#include <ostream>
using namespace std;

void pedirNumero(int & numero);
int calcularFactorial(int numero);

int main(){
    int numero;
    pedirNumero(numero);
    if(numero>0){
        cout<<"Factorial de "<<numero<<": "<<calcularFactorial(numero)<<endl;
    }else{
        cout<<numero<<endl;
    }
}

void pedirNumero(int & numero){
    bool salir = false;
    cout<<"Ingresar número positivo para obtener su factorial"<<endl;
    cout<<"0 para salir"<<endl;
    cin>>numero;
    while (numero<=0 && !salir){
        if(numero == 0){
            salir = true;
        }else{
            cout<<"El número ingresado debe ser positivo"<<endl;
            cin>>numero;
        }
    }
    if(salir) cout<<"Exit"<<endl;
}

int calcularFactorial(int numero){
    int resultado = 1;
    while(numero > 0){
        resultado *= numero; 
        numero--;
    }
    return resultado;
}