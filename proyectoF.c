#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//funcion que determina si al año es bisiesto o no. (Jar)
int anioBisiesto(int anio, int mes){
    int febrero;

    if ((anio % 4 == 0) && (anio%100!=0) || (anio%400==0)) // Dado que un año bisiesto es divisible entre 4 usamos la siguiente formula
        febrero = 29;
    else
        febrero = 28;

    return febrero;
}
//funcion que imprime en pantalla el calendario de un mes (Os)
void impresionMes(int mes, int anio){
    //Variables
    int bisiesto = anioBisiesto(mes,anio); //llamamos a la funcion que comprueba si el año es bisiesto o no. Guardamos lo que retorne en un variable.
    int totalMes, moduloMes, semana, i, m;
    //comprobamos si el mes tienes 30, 31, 28 o 29 en caso de ser bisiesto
    switch(mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            totalMes = 31;
        break;
        case 2:
            totalMes = bisiesto;
        break;
        case 4:  case 6: case 9: case 11:
            totalMes = 30;
        break;
    }
    //imprimimos el nombre del mes
    switch(mes){
        case 1:printf("\t\tENERO\t%i",anio);break;
        case 2:printf("\t\tFEBRERO\t%i",anio);break;
        case 3:printf("\t\tMARZO\t%i",anio);break;
        case 4:printf("\t\tABRIL\t%i",anio);break;
        case 5:printf("\t\tMAYO\t%i",anio);break;
        case 6:printf("\t\tJUNIO\t%i",anio);break;
        case 7: printf("\t\tJULIO\t%i",anio);break;
        case 8: printf("\t\tAGOSTO\t%i",anio);break;
        case 9: printf("\t\tSEPTIEMBRE\t%i",anio);break;
        case 10: printf("\t\tOCTUBRE\t%i",anio);break;
        case 11: printf("\t\tNOVIEMBRE\t%i",anio);break;
        case 12: printf("\t\tDICIEMBRE\t%i",anio);break;
    }
    //Para que el calendario se muestre correctamente. La variable 'moduloMes' nos ayudara a calcular el primer dia de la semana
    if (bisiesto==29){
        switch (mes){
            case 1:moduloMes=0;break;
            case 2:moduloMes=3;break;
            case 3:moduloMes=4;break;
            case 4:moduloMes=0;break;
            case 5:moduloMes=2;break;
            case 6:moduloMes=5;break;
            case 7:moduloMes=0;break;
            case 8:moduloMes=3;break;
            case 9:moduloMes=6;break;
            case 10:moduloMes=1;break;
            case 11:moduloMes=4;break;
            case 12:moduloMes=6;break;
    }
  }
    else{
    switch (mes){
            case 1:moduloMes=0;break;
            case 2:moduloMes=3;break;
            case 3:moduloMes=3;break;
            case 4:moduloMes=6;break;
            case 5:moduloMes=1;break;
            case 6:moduloMes=4;break;
            case 7:moduloMes=6;break;
            case 8:moduloMes=2;break;
            case 9:moduloMes=5;break;
            case 10:moduloMes=0;break;
            case 11:moduloMes=3;break;
            case 12:moduloMes=5;break;
        }
  }
      semana=((anio-1)%7+ ((anio-1)/4 -(3*((anio-1)/100+1)/4))%7+moduloMes+1%7)%7; //formula para calcular el primer dia de la semana
      printf("\nSe muestra el calendario solicitado\n");
      printf("\nDom\tLun\tMar\tMie\tJue\tVie\tSab\n");

      for(m=0;m<semana;m++){ //ciclo que hace las tabulaciones necesarias para la impresion correcta del primer dia del mes
        printf("\t");
      }
      for(i=1;i<=totalMes;i++){ //imprimir los dias correspondientes del mes
            if(i==8-semana||i==15-semana||i==22-semana||i==29-semana||i==36-semana){ //condicion que hace que el ciclo, cada 7 dias del mes,  imprima un salto de linea.
                printf("\n%i\t",i);
            }
            else{
                printf("%i\t",i);
            }
        }
}

void Menucalendario(){
    //Variables (Jor)
    int dia, mes, anio;
    int opcion;

    time_t sisTime;
    //varible puntero para poder acceder a los valores de la estructura 'tm'
    struct tm *fActual;
    time(&sisTime); //asignamos la fecha actual a la variable que almacenar� el tiempo del equipo por medio de la fucion 'time()'
     // convertimos los valores almacenados en la variable 'sisTime' a compatibles con la estructura 'tm' y lo asignamos al puntero
    fActual = localtime(&sisTime);


    dia=fActual->tm_mday; //Acceder al valor de dia de la estructura tm y se asigna
    mes=fActual->tm_mon+1;  //Acceder al mes de la estructura tm y se asigna
    anio=(fActual->tm_year)+1900; //Contador apartir de 1900
    //por medio de un bucle 'do while' conseguimos que el programa no finalize hasta que el usuario lo decida.

    do{
    printf("Hoy es:%i/%i/%i",dia,mes,anio);//impresion de la fecha actual
    //Menú de usuario (Om)
    printf("\nElige una opcion:\n1.-Visualizar calendario de un mes\n2.-Visualizar calendario del mes actual\n3.-Saber el dia de la semana de una fecha\n4.-Salir\n");
    scanf("%i",&opcion);

    switch(opcion){
        case 1: //impresion de una fecha que el usuario quiera consultar
            printf("Introduce un anio: (Apartir de 1900):");
            scanf("%i",&anio);
            printf("Que mes?:");
            scanf("%i",&mes);

            system("cls");
            //condicional que evita que el programa caiga en un bucle infinito provocado por valores, ingresados por el usuario, que exceden los limites.
            if(anio >= 1900 && mes < 13){
                impresionMes(mes,anio);
            }
            else {
                printf("Hubo un error con el anio y/o el mes\n");
            }
            //limpieza de la pantalla.
            printf("\n");
            system("pause");
            system("cls");
      break;

      case 2: //impresion del mes actual
            system("cls");

            impresionMes(mes,anio);

            printf("\n");
            system("pause");
            system("cls");
      break;
      case 3: ;//impresion de un dia de la semana de una fecha
        int d,m,a;
        //Vectores con valores similares a los que toma la variable 'moduloMes'
        int regular[12] = {0,3,3,6,1,4,6,2,5,0,3,5};
        int bisiesto[12] = {0,3,4,0,2,5,0,3,6,1,4,6};
        int result1,result2,result3,result4,result5; //variables que simplifican la formula para calcular el dia

        system("cls");

      	printf("Introduce un dia de la semana en numero: ");
			scanf("%d",&d);
			printf("Introduce un mes en numero: ");
			scanf("%d",&m);
			printf("Introduce un anyo en numero: ");
			scanf("%d",&a);
            //comprobacion de que el año es bisiesto o no
            if((a%4==0) && !(a%100==0)){
                m=bisiesto[m-1];
            }
            else if (a%400==0){
                m=bisiesto[m-1];
            }
            else{
                m=regular[m-1];
            }
            //formula
            result1=(a-1)%7;
            result2=(a-1)/4;
            result3=(3*(((a-1)/100)+1))/4;
            result4=(result2-result3)%7;
            result5=d%7;
            d=(result1+result4+m+result5)%7;
            //determinamos a que dia de la semana corresponde
			switch(d)
			{
				case 0:
				printf("DOMINGO\n");
				break;
				case 1:
				printf("LUNES\n");
				break;
				case 2:
				printf("MARTES\n");
				break;
				case 3:
				printf("MIERCOLES\n");
				break;
				case 4:
				printf("JUEVES\n");
				break;
				case 5:
				printf("VIERNES\n");
				break;
				case 6:
				printf("SABADO\n");
				break;
			}
            printf("\n");
            system("pause");
            system("cls");
      break;


      case 4: //salir del programa
        system("exit");
        break;
      default: //Si el usuario ingresa un numero de opcion invalido.
        printf("Error, opcion invalida. Vuelvalo a intentar\n");
        system("pause");
        system("cls");
    }

    }while(opcion != 4);
}

int main(){
    //funcion del menu del calendario
    Menucalendario();
  return 0;
}
