/*De un censo realizado en una población se conocen los siguientes datos:
- Fecha de nacimiento en formato AAAAMMDD
- genero ('M'=varón 'F'=mujer)
Con estos datos de cada habitante se forma un conjunto finalizado con un día = 0.
Desarrollar un programa que determine e imprima:
1) Cuántos nacimientos hubo en el mes de octubre de todos los años.
2) Cuántos nacimientos hubo antes del 9 de julio de 1990.
3) Cuántos nacimientos de mujeres hubo en la primavera del 1982.
4) genero de la persona más vieja (solo existe una).*/

#include <iostream>
#include <ostream>
#include <string>
using namespace std;

#define _TOPE_PERSONAS 100


struct fecha{
    int dia;
    int mes;
    int anio;
    int fechaAAAAMMDD = 1;
};

struct persona{
    fecha fechaNacimiento;
    string sexo;
};

typedef persona tPersonas[_TOPE_PERSONAS];

void obtenerPersonas(tPersonas & personas, int & indice);
void obtenerGeneroDeMayor(tPersonas personas, int indice);
int obtenerNacimientos(int indice, fecha fechaDesde, fecha fechaHasta, string sexo, tPersonas personas);
fecha setearFecha(int aaaammdd);
int diferenciaFechas(fecha fechaDesde, fecha fechaHasta);
int convFormato(fecha fecha);

int main(){
    tPersonas personas;
    int indice = 0;
    obtenerPersonas(personas, indice);
    cout << "Cant. personas que nacieron en octubre: " << obtenerNacimientos(indice,setearFecha(1001),setearFecha(1031),"x",personas);
    cout << "Cant. personas que nacieron antes del 1990/07/09: " << obtenerNacimientos(indice,setearFecha(0),setearFecha(19900709),"x",personas);
    cout << "Cant. mujeres que nacieron en la primavera del 1982: " << obtenerNacimientos(indice,setearFecha(19820921),setearFecha(19821221),"m",personas);
    obtenerGeneroDeMayor(personas,indice);
}

void obtenerPersonas(tPersonas & personas, int & indice){
    persona persona;
    for (int i = 0; i < _TOPE_PERSONAS && persona.fechaNacimiento.fechaAAAAMMDD != 0; i++){
        cout<<"Ingresar fecha de nacimiento en formato AAAAMMDD"<<endl;
        cin>>persona.fechaNacimiento.fechaAAAAMMDD;
        persona.fechaNacimiento = setearFecha(persona.fechaNacimiento.fechaAAAAMMDD);
        if (persona.fechaNacimiento.fechaAAAAMMDD != 0){
            cout<<"Ingresar género de la persona (f o m)"<<endl;
            cin>>persona.sexo;
            personas[i] = persona;
            indice = i;
        }
    }
}

fecha setearFecha(int aaaammdd){
    fecha fecha;
    fecha.fechaAAAAMMDD = aaaammdd;
    int aux = aaaammdd / 100;
    fecha.dia = aaaammdd % 100;
    fecha.mes = aux % 100;
    fecha.anio = aux / 100;
    return fecha;
}

int obtenerNacimientos(int indice,fecha fechaDesde, fecha fechaHasta, string sexo, tPersonas personas){
    int cantidad = 0;
    for (int i = 0; i <= indice; i++){
        if(fechaDesde.anio == 0){
            fechaDesde.anio = personas[i].fechaNacimiento.anio;
            fechaDesde.fechaAAAAMMDD = convFormato(fechaDesde);
        } 
        if(fechaHasta.anio == 0) {
            fechaHasta.anio = personas[i].fechaNacimiento.anio;
            fechaHasta.fechaAAAAMMDD = convFormato(fechaHasta);
        }
        if(diferenciaFechas(fechaDesde,personas[i].fechaNacimiento)>=0 && diferenciaFechas(personas[i].fechaNacimiento,fechaHasta)>=0){
            cantidad++;
        }
    }
    return cantidad;
}

void obtenerGeneroDeMayor(tPersonas personas, int indice){
    int fechaMayor = 0;
    string generoMayor;
    for (int i = 0; i < indice; i++){
        if(personas[i].fechaNacimiento.fechaAAAAMMDD>fechaMayor){
            fechaMayor = personas[i].fechaNacimiento.fechaAAAAMMDD;
            generoMayor = personas[i].sexo;
        }
    }
    cout<<generoMayor<<endl;
}

//hasta más grande
//desde más chico

int diferenciaFechas(fecha fechaDesde, fecha fechaHasta){
    return (fechaHasta.fechaAAAAMMDD - fechaDesde.fechaAAAAMMDD); 
}

int convFormato(fecha fecha){
    return fecha.anio * 10000 + fecha.mes * 100 + fecha.dia *1;
}