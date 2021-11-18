#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //variables para los ciclos
    int i=0,m;
    //variables para almacenar los valores de dia, mes y a�o de la estructura tm
    int regular[] = {0,3,3,6,1,4,6,2,5,0,3,5};
    int bisiesto[] = {0,3,4,0,2,5,0,3,6,1,4,6};
    //Arreglos para calcular el moduloMes
    int dia,semana,moduloMes=30, mes, anio = 2005,opcion ;
    //variable que almacena el tiempo del equipo.
    time_t sisTime;
    //varible puntero para poder acceder a los valores de la estructura 'tm'
    struct tm *fActual;

    time(&sisTime); //asignamos la fecha actual a la variable que almacenar� el tiempo del equipo por medio de la fucion 'time()'
     // convertimos los valores almacenados en la variable 'sisTime' a compatibles con la estructura 'tm' y lo asignamos al puntero
    fActual = localtime(&sisTime);
    //impresion de la fecha, accediendo a los campos de la estructura 'tm' (temporal)
    printf("Hoy es: %i/%i/%i", fActual->tm_mday, fActual->tm_mon, 1900+fActual->tm_year);

if (anio % 4 != 0 || (anio % 100 == 0 && anio % 400 !=0)) // Dado que un año bisiesto es divisible entre 4 usamos la siguiente formula
  printf("\nNo es  año bisiesto");
  else
  printf("\nEs año bisiesto");
  printf("\n\n\n");

dia=fActual->tm_mday; //Acceder al valor de dia de la estructura tm y se asigna
mes=fActual->tm_mon;  //Acceder al mes de la estructura tm y se asigna
anio=fActual->tm_year; //Contador apartir de 1900

  printf("Elige una opcion:\n1.-Visualizar calendario del mes\n2.-Visualizar calendario completo del anio\n3.-Saber el dia de la semana de una fecha\n4.-Salir\n");
  scanf("%i",&opcion);

  switch(opcion)
  {
    case 1:

    while(i==0)
    {
      printf("Introduce un anio: (Apartir de 1900)");
      scanf("%i",&anio);
      printf("Que mes? ");
      scanf("%i",&mes);

      if(anio>=1900)
      {
        if(mes>0 && mes<=12)
        i=1;
      }
      break;

      case 2:
      break;

      case 3:
      if((anio%4==0) && !(anio%100==0))
      {
        mes=bisiesto[mes-1];
      }
      else if (anio%400==0)
      {
        mes=bisiesto[mes-1];
      }
      else
      {
        mes=regular[mes-1];
      }
      /*comprobamos primero si el año es bisiesto o es regular
        si es bisiesto, asignamos a mes la posición del vector bisiesto -1
        si es regular, asignamos a mes la posición del vector regular -1
      */
      semana=((anio-1)%7+ ((anio-1)/4 -(3*((anio-1)/100+1)/4))%7+semana+1%7)%7; //Calculo del primer dia de la semana
      printf("%i",semana);
      break;
    }
  }

  return 0;
}
