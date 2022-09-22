#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;

#define _CANT_AUTOS 100 
#define _CANT_ALQUILERES 20 

struct fecha{
    int dia;
    int mes;
    int anio;
};

struct automovil{
    int patente;
    string marca;
    int anioFabricacion;
    string modelo;
    int cantKilometros;
    float valorDiarioAlquiler;
    fecha fechaUltimoAlquiler;
    string estado;
};

struct alquiler{
    int patente;
    string tipoOperacion;
    int cantKilometros;
    fecha fechaAlquiler;
};

typedef automovil tAutomoviles[_CANT_AUTOS];
typedef alquiler tAlquileres[_CANT_ALQUILERES];
typedef string palabra[20];

void inicializarAutos(tAutomoviles & autos);
void ingresarAutos(tAutomoviles & autos);
void ingresarAlquileres(tAlquileres & alquileres);
void mostrarAutosPtoC(tAutomoviles autos);
void listadoOrdenadoAutosPtoD(tAutomoviles autos);
void parsear(palabra & palabra, string & cadenaAParsear);
void parsearAuto(palabra palabra, automovil & automovil);
void parsearAlquiler(palabra & palabra, alquiler & alquiler);
void procesarAlquileres(tAlquileres & alquileres, tAutomoviles & autos);
void obtenerFecha(int aaaammdd, fecha & fecha);
float mostrarMonto(alquiler alquiler, automovil automovil);
int diferenciaFechas(fecha f1, fecha f2);
int buscarAuto(tAutomoviles autos, int patente);
void ordenarAutos(tAutomoviles autos, tAutomoviles & autosDepositoOrdenados, int & indice);

int main(){
    tAutomoviles autos;
    tAlquileres alquileres;
    inicializarAutos(autos);  
    ingresarAutos(autos);  
    procesarAlquileres(alquileres, autos);  
    mostrarAutosPtoC(autos);  
    listadoOrdenadoAutosPtoD(autos);
}

void inicializarAutos(tAutomoviles & autos){
    for (int i = 0; i < _CANT_AUTOS; i++){
        autos[i].patente = 0;
        autos[i].marca = "";
        autos[i].anioFabricacion = 0;
        autos[i].modelo = "";
        autos[i].cantKilometros = 0;
        autos[i].valorDiarioAlquiler = 0;
        obtenerFecha(0, autos[i].fechaUltimoAlquiler);
        autos[i].estado = "";
    }
    
}

void ingresarAutos(tAutomoviles & autos){
    palabra palabra;
    automovil automovil;
    int i = 0;
    string cadena;
    ifstream archAutos("autos.csv");
    while (getline(archAutos,cadena)){
        parsear(palabra,cadena);
        parsearAuto(palabra,automovil);
        i++;
    }
    archAutos.close();
}

void procesarAlquileres(tAlquileres & alquileres, tAutomoviles & autos){
    ingresarAlquileres(alquileres);
    float montoTotalAcumulado = 0;
    for (int i = 0; i < _CANT_ALQUILERES; i++){
        int indiceAuto = buscarAuto(autos, alquileres[i].patente);
        if(alquileres[i].tipoOperacion == "D"){
            autos[indiceAuto].cantKilometros += alquileres[i].cantKilometros; //le sumo al auto la cantidad de km recorridos durante el alquiler
            montoTotalAcumulado += mostrarMonto(alquileres[i],autos[indiceAuto]); //agrego el valor del alquiler que acaba de terminar al total facturado
            autos[buscarAuto(autos, alquileres[i].patente)].fechaUltimoAlquiler = alquileres[i].fechaAlquiler; //guardo la fecha de devolución del auto
            autos[buscarAuto(autos, alquileres[i].patente)].estado = "D"; //marco que el auto está en depósito
        }
        else{
            autos[buscarAuto(autos, alquileres[i].patente)].estado = "A"; //marco el auto como alquilado
            autos[buscarAuto(autos, alquileres[i].patente)].fechaUltimoAlquiler = alquileres[i].fechaAlquiler; //guardo la info. del comienzo del alquiler
        }
    }
    
    cout<<"El total facurado es de: "<<montoTotalAcumulado<<endl;
}

void mostrarAutosPtoC(tAutomoviles autos){
    cout << " Patente " << setw(3) << "|" << " Modelo " << setw(4) << "|" << " Kilómetros " << setw(1) << "|" <<endl;

    int cantidadModelos[3] = {0,0,0};

    for (int i = 0; i < _CANT_AUTOS; i++){
        if(autos[i].modelo == "CHICO") cantidadModelos[0] += 1;
        else if(autos[i].modelo == "MEDIANO") cantidadModelos[1] += 1;
        else cantidadModelos[2] += 1;
        cout << autos[i].patente << setw(3) << "|" << autos[i].modelo << setw(4) << "|" << autos[i].cantKilometros << setw(1) << "|" <<  endl;
    }

    cout<< "Autos CHICOS: "   << cantidadModelos[0] <<endl;
    cout<< "Autos MEDIANOS: " << cantidadModelos[1] <<endl;
    cout<< "Autos GRANDES: "  << cantidadModelos[2] <<endl;
}

void listadoOrdenadoAutosPtoD(tAutomoviles autos){
    tAutomoviles autosDepositoOrdenados;
    int indice = 0;
    ordenarAutos(autos, autosDepositoOrdenados, indice);
    for (int i = 0; i < indice; i++){
        cout<<autosDepositoOrdenados[i].patente<<" | "<<autosDepositoOrdenados[i].modelo<<" | "<<autosDepositoOrdenados[i].estado<<endl;
    }
}

void ingresarAlquileres(tAlquileres & alquileres){
    palabra palabra;
    alquiler alquiler;
    int i = 0;
    string cadena;
    ifstream archAlquileres("alquileres.csv");
    while (getline(archAlquileres,cadena)){
        parsear(palabra,cadena);
        parsearAlquiler(palabra,alquiler);
        i++;
    }
    archAlquileres.close();
}

void parsear(palabra & palabra, string & cadenaAParsear){
    int primero = 0, ultimo = 0, k = 0;

    while(ultimo < cadenaAParsear.size()){
        ultimo = cadenaAParsear.find(",", primero); // cuando no lo encuentra devuelve -1
        if (ultimo == -1) ultimo = cadenaAParsear.size();
        palabra[k] = cadenaAParsear.substr(primero, ultimo - primero) + '\0';
        k++;
        primero = ultimo + 1;
    }
}

void parsearAuto(palabra palabra, automovil & automovil){
    automovil.patente = stoi(palabra[0]);
    automovil.marca = palabra[1];
    automovil.anioFabricacion = stoi(palabra[2]);
    automovil.modelo = palabra[3];
    automovil.cantKilometros = stoi(palabra[4]);
    automovil.valorDiarioAlquiler = stoi(palabra[5]);
    obtenerFecha(stoi(palabra[6]), automovil.fechaUltimoAlquiler);
    automovil.estado = palabra[7];
}

void parsearAlquiler(palabra & palabra, alquiler & alquiler){
    alquiler.patente = stoi(palabra[0]);
    alquiler.cantKilometros = stoi(palabra[1]);
    obtenerFecha(stoi(palabra[2]), alquiler.fechaAlquiler);
    alquiler.tipoOperacion = palabra[3];
}

void obtenerFecha(int aaaammdd, fecha & fecha){
    int aux = aaaammdd/100;
    fecha.dia = aaaammdd % 100;
    fecha.mes = aux % 100;
    fecha.anio = aux / 100;
}

int buscarAuto(tAutomoviles autos, int patente){
    int i = 0;
    
    while (i < _CANT_AUTOS && patente != autos[i].patente){
        i ++;
    }

    if (i > _CANT_AUTOS || autos[i].patente != patente) {
        i = -1;
    }

    return i;
}

float mostrarMonto(alquiler alquiler, automovil automovil){
    int dif = diferenciaFechas(alquiler.fechaAlquiler, automovil.fechaUltimoAlquiler);
    float montoAlquiler = dif * automovil.valorDiarioAlquiler;
    cout<<"Valor a cobrar para el alquiler del auto de patente "<<alquiler.patente<<": "<<endl;
    cout<<"Cantidad de días alquilado: "<<dif<<endl;
    cout<<"Precio por día: "<<automovil.valorDiarioAlquiler<<endl;
    cout<<"Total: "<<montoAlquiler<<endl;
    return montoAlquiler;
}

int diferenciaFechas(fecha f1, fecha f2){
    int dif = abs((f1.anio-f2.anio)*12 +(f1.mes-f2.mes)*30 + (f1.dia-f2.dia));
    return dif;
}

void ordenarAutos(tAutomoviles autos, tAutomoviles & autosDepositoOrdenados, int & indice){
    string modelos[3] = {"GRANDE","MEDIANO","CHICO"};
    for (int i = 0; i < 3; i++){
        for (int j = 0; i < _CANT_AUTOS; i++){
            if(autos[j].estado == "D" && autos[j].modelo == modelos[i]){
                autosDepositoOrdenados[indice] = autos[j];
                indice++;
            }
        }
    }
}