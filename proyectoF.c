#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void imprimirFechaAct(int dia, int mes, int anio){
    //variable que almacena el tiempo del equipo.
    time_t sisTime;
    //varible puntero para poder acceder a los valores de la estructura 'tm'
    struct tm *fActual;

    time(&sisTime); //asignamos la fecha actual a la variable que almacenar� el tiempo del equipo por medio de la fucion 'time()'
     // convertimos los valores almacenados en la variable 'sisTime' a compatibles con la estructura 'tm' y lo asignamos al puntero
    fActual = localtime(&sisTime);
    //impresion de la fecha, accediendo a los campos de la estructura 'tm' (temporal)
    printf("Hoy es: %i/%i/%i\n", fActual->tm_mday, fActual->tm_mon, 1900+fActual->tm_year);
}

int anioBisiesto(int anio, int mes){
    int febrero;

    if (anio % 4 != 0 || (anio % 100 == 0 && anio % 400 !=0)) // Dado que un año bisiesto es divisible entre 4 usamos la siguiente formula
        febrero = 29;
    else
        febrero = 28;

    return febrero;
}

void calendario(int dia, int mes, int anio){
    int opcion, i, semana, m,diasem;
    int bisiesto = anioBisiesto(anio,mes);
    int totalMes;
    int d,a;
    int result1,result2,result3,result4,result5;

    //int totalM = anioBisiesto(anio, mes);
    time_t sisTime;
    //varible puntero para poder acceder a los valores de la estructura 'tm'
    struct tm *fActual;
    time(&sisTime); //asignamos la fecha actual a la variable que almacenar� el tiempo del equipo por medio de la fucion 'time()'
     // convertimos los valores almacenados en la variable 'sisTime' a compatibles con la estructura 'tm' y lo asignamos al puntero
    fActual = localtime(&sisTime);


    dia=fActual->tm_mday; //Acceder al valor de dia de la estructura tm y se asigna
    mes=fActual->tm_mon+1;  //Acceder al mes de la estructura tm y se asigna
    anio=(fActual->tm_year)+1900; //Contador apartir de 1900
    printf("Elige una opcion:\n1.-Visualizar calendario de un mes\n2.-Visualizar calendario del mes actual\n3.-Saber el dia de la semana de una fecha\n4.-Salir\n");
    scanf("%i",&opcion);


  switch(opcion)
  {
    case 1:

      printf("Introduce un anio: (Apartir de 1900)");
      scanf("%i",&anio);
      printf("Que mes? ");
      scanf("%i",&mes);

      system("cls");

      switch(mes){
        case 1:
            printf("\t\tENERO\t%i",anio);
            totalMes = 31;
            break;
        case 2:
            printf("\t\tFEBRERO\t%i",anio);
            totalMes = bisiesto;
            break;
        case 3:
            printf("\t\tMARZO\t%i",anio);
            totalMes = 31;
            break;
        case 4:
            printf("\t\tABRIL\t%i",anio);
            totalMes = 30;
            break;
        case 5:
            printf("\t\tMAYO\t%i",anio);
            totalMes = 31;
            break;
        case 6:
            printf("\t\tJUNIO\t%i",anio);
            totalMes = 30;
            break;
        case 7: printf("\t\tJULIO\t%i",anio);
            totalMes = 31;
            break;
        case 8: printf("\t\tAGOSTO\t%i",anio);
            totalMes = 31;
            break;
        case 9: printf("\t\tSEPTIEMBRE\t%i",anio);
            totalMes = 30;
            break;
        case 10: printf("\t\tOCTUBRE\t%i",anio);
            totalMes = 31;
            break;
        case 11: printf("\t\tNOVIEMBRE\t%i",anio);
            totalMes = 30;
            break;
        case 12: printf("\t\tDICIEMBRE\t%i",anio);
            totalMes = 31;
            break;
      }
      semana=((anio-1)%7+ ((anio-1)/4 -(3*((anio-1)/100+1)/4))%7+totalMes+1%7)%7;
      printf("\nSe muestra el calendario solicitado\n");
      printf("\n Dom \tLun \tMar\tMie\tJue\tVie\tSab\n");

      for(m=0;m<semana;m++){
        printf("\t");
        for(i=1;i<=totalMes;i++){
            if(i==8-semana||i==15-semana||i==22-semana||i==29-semana||i==36-semana){
                printf("\n%i\t",i);
            }
            else{
                printf("%i\t",i);
            }
        }
        break;
      }
      break;

      case 2:
        semana=((anio-1)%7+ ((anio-1)/4 -(3*((anio-1)/100+1)/4))%7+totalMes+1%7)%7;
        printf("\n Dom \tLun \tMar\tMie\tJue\tVie\tSab\n");

        switch(mes){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                totalMes = 31;
                break;
            case 2:
                totalMes = bisiesto;
                break;
            case 4: case 6: case 9: case 11:
                totalMes = 30;
                break;
        }
        for(m=0;m<semana;m++){
            printf("\t");
            for(i=1;i<=totalMes;i++){
                if(i==8-semana||i==15-semana||i==22-semana||i==29-semana||i==36-semana){
                    printf("\n%i\t",i);
                }
                else{
                    printf("%i\t",i);
                }
            }
            break;
        }
      break;
      case 3:
      	printf("Introduce un dia de la semana en numero: ");
			scanf("%d",&d);
			printf("Introduce un mes en numero: ");
			scanf("%d",&m);
			printf("Introduce un anyo en numero: ");
			scanf("%d",&a);
            result1=(a-1)%7;
            result2=(a-1)/4;
            result3=(3*(((a-1)/100)+1))/4;
            result4=(result2-result3)%7;
            result5=d%7;
            d=(result1+result4+m+result5)%7;


			result1=(a-1)%7;
			result2=(a-1)/4;
			result3=(3*(((a-1)/100)+1))/4;
			result4=(result2-result3)%7;
			result5=d%7;
			d=(result1+result4+m+result5)%7;
			switch(d)
			{
				case 1:
				printf("DOMINGO\n");
				break;
				case 2:
				printf("LUNES\n");
				break;
				case 3:
				printf("MARTES\n");
				break;
				case 4:
				printf("MIERCOLES\n");
				break;
				case 5:
				printf("JUEVES\n");
				break;
				case 6:
				printf("VIERNES\n");
				break;
				case 7:
				printf("SABADO\n");
				break;
			}
			system("pause");
      break;


      case 4:
        system("exit");
        break;
    }
}

int main(){
    //variables para almacenar los valores de dia, mes y a�o de la estructura tm
    int dia, mes, anio;

    imprimirFechaAct(dia,mes,anio);
    anioBisiesto(anio,mes);
    calendario(dia,mes,anio);

  return 0;
}
