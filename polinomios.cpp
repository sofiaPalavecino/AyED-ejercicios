/* Desarrollar un programa para calcular polinomios,
que pida por pantalla pares de valores (ai, bi) que finalizan en el par (0,0)
y que correspondientes a números y potencias que representen el polinomio
f(x) = asub4 * x4 + asub3 * x3 + asub2 * x2 + asub1 * x1 + asub0 * x0*/

#include <iostream>
#include <ostream>
#include <string>
using namespace std;

#define _TOPE_PAR 20

struct par{
    int x;
    int y;
};

typedef par tPar[_TOPE_PAR];

void pedirValores(tPar & valores);
float armarPolinomio(tPar valores);
float calcularPotencia(int numero, int potencia);
float obtenerPotencia(int numero, int potencia);

int main(){
    tPar valores;
    pedirValores(valores);
    cout<<armarPolinomio(valores);
}

void pedirValores(tPar & valores){
    par valor;
    valor.x,valor.y = 1;
    for (int i = 0; i < _TOPE_PAR && !(valor.x == 0 && valor.y == 0); i++){
        cout<<"ingresar constante y potencia separados por enter. (0,0) para terminar"<<endl;
        cin>>valor.x;
        cin>>valor.y;
        if(valor.x != 0 && valor.y != 0) valores[i]=valor;
    }
}

float armarPolinomio(tPar valores){
    int x;
    float resultado = 0;
    cout<<"Ingresar variable"<<endl;
    cin>>x;
    for (int i = 0; i < _TOPE_PAR && !(valores[i].x == 0 && valores[i].y == 0); i++){
        cout<<valores[i].x<<" * "<<x<<"^"<<valores[i].y<<" + ";
        resultado += valores[i].x * obtenerPotencia(x,valores[i].y);
    }
    cout<<endl;
    return resultado;
}

float obtenerPotencia(int numero, int potencia){
    if(potencia > 0){
        return(calcularPotencia(numero, potencia));
    }else if(potencia < 0){
        potencia *= -1;
        return(1/calcularPotencia(numero, potencia));
    }
    return 1;
}

float calcularPotencia(int numero, int potencia){
    int resultado = numero;
    while (potencia > 1){
        resultado *= numero;
        potencia--;
    }
    return resultado;
}