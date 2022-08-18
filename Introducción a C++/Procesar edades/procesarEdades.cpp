#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;

#define _TOPE_PERSONAS 50

struct fecha{
    int dia;
    int mes;
    int anio;
    int aaaammdd;
};

struct persona{
    string nombre;
    int edad;
    fecha fechaNacimiento;
};

typedef persona tPersonas[_TOPE_PERSONAS];

int diferenciaFechasDias(fecha fecha1, fecha fecha2);
void calcularEdad(persona & persona,fecha fechaActual);
void obtenerDatos(fecha & fecha);
persona obtenerPersonaSegunParametro(tPersonas personas, string pm);
int obtenerCantPersonasSegunEdad(tPersonas personas, int edadDesde, int edadHasta);
void cargarPersonas(tPersonas personas);
void parsear(string cadenaAParsear, persona & persona);

int main(){
    tPersonas personas;
    cargarPersonas(personas);
    cout<<"El nombre de la persona más grande es: "<<obtenerPersonaSegunParametro(personas, "b").nombre<<endl;
    cout<<"El nombre de la persona más chica es: "<<obtenerPersonaSegunParametro(personas, "s").nombre<<endl;
    cout<<"Cantidad de personas con hasta 20 años: "<<obtenerCantPersonasSegunEdad(personas, 0, 20)<<endl;
    cout<<"Cantidad de personas de entre 21 y 30 años: "<<obtenerCantPersonasSegunEdad(personas, 21, 30)<<endl;
    cout<<"Cantidad de personas mayores de 30 años: "<<obtenerCantPersonasSegunEdad(personas, 31, 101)<<endl;
}

void cargarPersonas(tPersonas personas){
    fecha fechaActual;
    cout<<"Ingresar fecha de hoy en formato AAAAMMDD"<<endl;
    cin>>fechaActual.aaaammdd;
    obtenerDatos(fechaActual);
    string cadena;
    persona persona;
    int i = 0;
    ifstream archPersonas("personas.csv");
    while (getline(archPersonas,cadena)){
        parsear(cadena,persona);
        calcularEdad(persona,fechaActual);
        personas[i] = persona;
        i++;
    }
    archPersonas.close();
}

void parsear(string cadenaAParsear, persona & persona) {
    int primero = 0, ultimo = 0, k = 0;
    string palabra[20];

    while(ultimo < cadenaAParsear.size()){
        ultimo = cadenaAParsear.find(",", primero); // cuando no lo encuentra devuelve -1
        if (ultimo == -1) ultimo = cadenaAParsear.size();
        palabra[k] = cadenaAParsear.substr(primero, ultimo - primero) + '\0';
        k++;
        primero = ultimo + 1;
    }
    
    persona.nombre = palabra[0];
    persona.fechaNacimiento.aaaammdd = stoi(palabra[1]);
}

void calcularEdad(persona & persona,fecha fechaActual){
    obtenerDatos(persona.fechaNacimiento);
    persona.edad = fechaActual.anio - persona.fechaNacimiento.anio;
    int mes = persona.fechaNacimiento.mes - persona.fechaNacimiento.mes;
    if(mes<0 || (mes == 0 && persona.fechaNacimiento.dia<fechaActual.dia)) persona.edad--;
}

void obtenerDatos(fecha & fecha){
    int aux = fecha.aaaammdd/100;
    fecha.dia = fecha.aaaammdd % 100;
    fecha.mes = aux % 100;
    fecha.anio = aux / 100;
}

int diferenciaFechasDias(fecha fecha1, fecha fecha2){
    int dif;
    dif = int((((fecha1.anio-fecha2.anio)*12+(fecha1.mes-fecha2.mes))*30+fecha1.dia-fecha2.dia)/360);
    return dif;
}

persona obtenerPersonaSegunParametro(tPersonas personas, string pm){
    persona perAux;
    perAux.edad = -1;
    for (int i = 0; i < _TOPE_PERSONAS; i++){
        if(pm == "b"){ //b de "bigger"
            if(personas[i].edad > perAux.edad) perAux = personas[i];
        }else{
            if(personas[i].edad < perAux.edad || i == 0) perAux = personas[i];
        }
    }
    return perAux;
}

int obtenerCantPersonasSegunEdad(tPersonas personas, int edadDesde, int edadHasta){
    int cantidad = 0;
    for (int i = 0; i < _TOPE_PERSONAS; i++){
        if(personas[i].edad >= edadDesde && personas[i].edad<=edadHasta) cantidad++;
    }
    return cantidad;
}