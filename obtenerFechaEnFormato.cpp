/*Desarrollar una función que reciba los valores D, M y A
correspondientes al día, mes y año de una fecha
y la devuelva en el formato AAAAMMDD*/

#include <iostream>
#include <ostream>
#include <string>
using namespace std;

struct fecha{
    int dia;
    int mes;
    int anio;
    string fechaAAAAMMDD;
};

void pedirFecha(fecha & fecha);
void formatearFecha(fecha & fecha);

int main(){
    fecha fecha;
    pedirFecha(fecha);
    formatearFecha(fecha);
    cout<<fecha.fechaAAAAMMDD<<endl;
}

void pedirFecha(fecha & fecha){
    int dia,mes,anio=0;
    cout<<"Ingresar día, mes y año"<<endl;
    while (dia<=0 || dia>31 || mes<=0 || mes>12 || anio<=0 || anio<1969){
        cout<<"Día debe ser mayor a 0 y <= a 31"<<endl;
        cout<<"Día debe ser mayor a 0 y <= a 12"<<endl;
        cout<<"Día debe ser mayor a 0 y >= a 1969"<<endl;
        cin>>dia>>mes>>anio;
        //cin>>mes;
        //cin>>anio;
    }
    
    fecha.dia=dia;
    fecha.mes=mes;
    fecha.anio=anio;
}


void formatearFecha(fecha & fecha){
    string dia = to_string(fecha.dia);
    string mes = to_string(fecha.mes);
    if(fecha.dia<10) dia = "0" + dia;
    if(fecha.mes<10) mes = "0" + mes;
    fecha.fechaAAAAMMDD=to_string(fecha.anio) + mes + dia;
}