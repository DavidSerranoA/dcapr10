#include <stdio.h>
#include <stdlib.h>

#include <libintl.h>
#include <locale.h>
#include <memory.h>

#define _(STRING) gettext(STRING)

void calcularSumas();
void calcularPrimos();
void seleccionarOpcion();
void calcularMultiplicacion();

void calcularSumas(){
    printf(_("Introduce el numero hasta el que quieres realizar sumas consecutivas: "));
    int n,i,res;
    for(i=1;i<=n;i++){
     res  = res + i;   
    }
    printf(_("El resultado de la suma desde 1 hasta %d es %d"),n,res);
    seleccionarOpcion();
}

void calcularPrimos(){
    printf(_("Introduce el numero hasta el que quieres calcular los numeros primos: "));
    int n;
    scanf("%d",&n);
    printf(_("\nSi has introducido un numero grande puede tardar un rato\n"));
    long i, j;
    printf(_("Los numeros primos hasta %d son: "),n);
    for(i=2; i<=n;i++){
        for(j=2;j<=i;j++){
            if(i%j==0 && j!=i){
               j=i;
            }else if(j==i){
               printf(_(" - %ld "),j);
            }
        }
    }
    printf(_("\n"));
    seleccionarOpcion();

}

void calcularMultiplicacion(){
    printf(_("Introduce el numero hasta el que quieres calcular la multiplicacion: "));
    int n,i;
    long res = 1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
     res  = res * i;   
    }
    printf(_("El resultado de la multiplicacion desde 1 hasta %d es %ld"),n,res);
    seleccionarOpcion();
}


void seleccionarOpcion(){
    printf(_("\n\nBIENVENIDO AL FASCINANTE MUNDO DE LAS MATEMATICAS\n"));
	printf(_("****************************************\n"));
    printf(_("SELECCIONA LA OPCION QUE DESEAS \n"));
    printf(_("1.- CALCULAR LAS SUMAS DESDE 1 HASTA N\n"));
    printf(_("2.- CALCULAR LOS NUMEROS PRIMOS HASTA UN NUMERO N\n"));
    printf(_("3.- CALCULAR MULTIPLICACION SUCESIVA DESDE 1 HASTA N\n"));
    printf(_("4.- SALIR DEL PROGRAMA\n\n"));
    printf(_("OPCION DESEADA: "));
    int opc;
    scanf("%d",&opc);
    
    switch(opc){
     
        case 1: calcularSumas();
            break;
        case 2: calcularPrimos();
            break;
        case 3: calcularMultiplicacion();
            break;
        case 4:   printf(_("HASTA LUEGO!!!!\n\n"));
            break;
        default:    printf(_("OPCION INCORRECTA\n"));
                    seleccionarOpcion();
            break;
    }
}









int main()
{
  /* Setting the i18n environment */
  setlocale (LC_ALL, "");
  bindtextdomain ("app",strcat(getenv("PWD"),"/po"));
  textdomain ("app");

  /* Example of i18n usage */
  printf(_("Hola mundo\n"));
  seleccionarOpcion();

  return EXIT_SUCCESS;
}
