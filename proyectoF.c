#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main(){
    //variables para los ciclos
    int i, m;
    //variables para almacenar los valores de dia, mes y año de la estructura tm
    int dia, mes, anio;
    //variable que almacena el tiempo del equipo.
    time_t sisTime;
    //varible puntero para poder acceder a los valores de la estructura 'tm'
    struct tm *fActual;

    time(&sisTime); //asignamos la fecha actual a la variable que almacenará el tiempo del equipo por medio de la fucion 'time()'
     // convertimos los valores almacenados en la variable 'sisTime' a compatibles con la estructura 'tm' y lo asignamos al puntero
    fActual = localtime(&sisTime);
    //impresion de la fecha, accediendo a los campos de la estructura 'tm' (temporal)
    printf("Hoy es: %i/%i/%i", fActual->tm_mday, fActual->tm_mon, 1900+fActual->tm_year);

    return 0;
}
