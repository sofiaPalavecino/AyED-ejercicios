/*Desarrollar una función que reciba un valor
que corresponda al año, mes y día de una fecha en formato AAAAMMDD
y devuelva los valores día, mes y año de la fecha recibida*/
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

struct fecha{
    int dia;
    int mes;
    int anio;
    int fechaAAAAMMDD;
};

void pedirFecha(fecha & fecha);
void obtenerDatos(fecha & fecha);

int main(){
    fecha fecha;
    pedirFecha(fecha);
    obtenerDatos(fecha);
    cout<<fecha.anio<<"/"<<fecha.mes<<"/"<<fecha.dia<<endl;
}

void pedirFecha(fecha & fecha){
    cout<<"Ingresar fecha en formato AAAAMMDD"<<endl;
    cin>>fecha.fechaAAAAMMDD;
}

void obtenerDatos(fecha & fecha){
    int aux = fecha.fechaAAAAMMDD/100;
    fecha.dia = fecha.fechaAAAAMMDD % 100;
    fecha.mes = aux % 100;
    fecha.anio = aux / 100;
}