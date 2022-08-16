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
void pedirEdades(tEdades & edades);
int calcularPromedio(tEdades & edades, int cantidad);
int cantPersonasMayoresPromedio(tEdades, int cantidad);

int main(){

}