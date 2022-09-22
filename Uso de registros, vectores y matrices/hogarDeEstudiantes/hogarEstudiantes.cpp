/*Desarrollar un programa que procese datos de los estudiantes de un curso (máximo 60):
nombre, fecha de nacimiento y lugar de residencia ('C' = Casa, 'D' = Departamento)
y arme dos vectores uno con aquellos que viven en casas y otros que viven en departamento.*/
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
using namespace std;

#define _TOPE_ESTUDIANTES 60

struct estudiante{
    string nombre;
    string lugarDeResidencia;
    int fechaNacimiento;
};

typedef estudiante tEstudiantes[_TOPE_ESTUDIANTES];

void cargarEstudiantes(tEstudiantes & estudiantesDepto, tEstudiantes & estudiantesCasa);
void parsear(string cadenaAParsear, estudiante & estudiante);
void mostrarEstudiantes(tEstudiantes estudiantes);

int main(){
    tEstudiantes estudiantesDepto;
    tEstudiantes estudiantesCasa;
    cargarEstudiantes(estudiantesDepto, estudiantesCasa);
    cout<<"Estudiantes que viven en departamento"<<endl;
    mostrarEstudiantes(estudiantesDepto);
    cout<<"Estudiantes que viven en una casa"<<endl;
    mostrarEstudiantes(estudiantesCasa);
}

void cargarEstudiantes(tEstudiantes & estudiantesDepto, tEstudiantes & estudiantesCasa){
    estudiante estudiante;
    int i = 0;
    string cadena;
    ifstream archestudiantes("estudiantes.csv");
    while (getline(archestudiantes,cadena)){
        parsear(cadena,estudiante);
        if(estudiante.lugarDeResidencia == "D") estudiantesDepto[i] = estudiante;
        else estudiantesCasa[i] = estudiante;
        i++;
    }
    archestudiantes.close();
}

void parsear(string cadenaAParsear, estudiante & estudiante){
    int primero = 0, ultimo = 0, k = 0;
    string palabra[20];

    while(ultimo < cadenaAParsear.size()){
        ultimo = cadenaAParsear.find(",", primero); // cuando no lo encuentra devuelve -1
        if (ultimo == -1) ultimo = cadenaAParsear.size();
        palabra[k] = cadenaAParsear.substr(primero, ultimo - primero) + '\0';
        k++;
        primero = ultimo + 1;
    }
    
    estudiante.nombre = palabra[0];
    estudiante.lugarDeResidencia = "d";
}

void mostrarEstudiantes(tEstudiantes estudiantes){
    for (int i = 0; estudiantes[i].fechaNacimiento != 0; i++){
        cout<<estudiantes[i].nombre<<", ";
        cout<<estudiantes[i].fechaNacimiento<<endl;
    }
}