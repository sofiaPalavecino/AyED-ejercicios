# Procesar las edades de un conjunto de personas de las cuales nos informan su nombre y fecha de nacimiento.
## Se debe mostrar por pantalla:
- el nombre de la persona mayor;
- el nombre de la persona menor;
- cuántas personas tienen hasta 20 años;
- cuántas personas tienen entre 21 y 30 años;
- cuántas personas tienen más de 30 años

Supongan que no hay dos personas que hayan nacido el mismo día.

**Pista 1:** para conocer la edad en años de cada estudiante pueden usar la siguiente función (buscar el programa en los ejemplos publicados)

**int diferenciaFechas(int dia1, int mes1, int anio1, int dia2, int mes2, int anio2) {**
   **int dif;**
   **dif = int((((anio1-anio2)*12+(mes1-mes2))*30+dia1-dia2)/360);**
   **return dif;**
**}**

Recibe 2 fechas y devuelve la cantidad de días entre ambas considerando que todos los meses tienen 30 días (es lo más que podemos hacer ahora, prometo que en poco tiempo van a poder mejorar esta función)

Para que siempre devuelva un valor mayor a 0 (independientemente del orden que ingresan las fechas) al cálculo se le aplica la función "abs" que recibe un número y devuelve el valor positivo del número

**Pista 2:** para calcular cuántos años tiene cada estudiante deben comparar su fecha de nacimiento con la fecha del proceso, la cual se debe pedir al inicio del programa
