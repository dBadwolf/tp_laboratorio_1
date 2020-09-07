
/*
En el archivo principal o main, se ubica la lógica del programa, sin incluir funciones o cadenas de caracteres,
los cuales deberían ir en un archivo aparte para luego llamar a dichas funciones cuando sea necesario utilizarlas.
*/

#include <stdio.h>
//#include <stdio ext.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <conio.h>
#include "operations.h"
#include "menu.h"
#include "inout.h"
#include "validations.h"
#include "strings_eng.h"

int main()
{
	setbuf(stdout, NULL);

    int   state=0;
    int   error=0;

    int   valueA;
    int   valueB;

    float result;
    bool  exit=0;
    char  operation;

    //IMPORTANTE: En Linux en lugar de fflush() se debe utilizar la funci�n __fpurge(), para lo cual es necesario incluir el archivo stdio_ext.h


    system("cls"); //Limpiar pantalla. system("clear"); para Linux

    //state=getChar(&operation, MSG_INPUT_CHAR, MSG_INVALID_CHAR_INPUT, 65, 74, 1);

    //state = getCharByType  (&operation, MSG_INPUT_CHAR, MSG_INVALID_CHAR_INPUT, 'M', 1);

    //printf("El caracter es: %c", operation);



    welcome();

    do
    {
        fflush(stdin); //Limpia el buffer. __fpurge(stdin); para Linux
        state=getInt(&valueA, MSG_INPUT_VALUE_A, MSG_INVALID_CHAR_INPUT, -9999999, 9999999, 10); //Se ingresa el primer valor numerico de tipo entero. Cuando la variable valueA recibe correctamente un numero valido, el estado de scanf pasa a ser 1
        system("cls");

    }while(state!=0); // state!=1 valida que se haya ingresado un numero correctamente

    do
    {
        system("cls");
        fflush(stdin);
        state=getInt(&valueB, MSG_INPUT_VALUE_B, MSG_INVALID_CHAR_INPUT, -9999999, 9999999, 10);

    }while(state!=0); // state!=1 valida que se haya ingresado un numero

    system("cls");

    while(exit==0) //Mientras la variable Exit, que es e tipo booleano, sea igual a cero, el programa ejecutará las sentencias para realizar operaciones o seleccionar nuevos valores
    {
    	printValues(valueA, valueB);

    	menuOptions();

    	fflush(stdin);

    	printInputOperation();
    //	operation=getch(); //le asigna a la variable operation un caracter ingresado por teclado
    	getCharByType  (&operation, MSG_INPUT_CHAR, MSG_INVALID_OPERATION, 'A', 999999);

        system("cls");

    	printLine();

    	switch(operation) //Mediante la selecion de caracteres, elegimos que operacion realizar con los valores previamente ingresados
    	{
    	    case '+':
    	        result=add(valueA, valueB);
    	        printSum(result);
    	        break;

            case '-':
                result=subtract(valueA, valueB);
                printSubtraction(result);
                break;

            case '*':
                result=multiply(valueA, valueB);
                printMultiplication(result);
                break;

            case '/':
            	error=divide(valueA, valueB, &result);
                if(error!=0)
                {
                	printErrorDivByCero();
                }else
                {
                	printDivision(result);
                }
                break;

            case 'a':
                if(valueA<0)
                {
                    printErrorFactNegative();
                }else
                {
                    result=factorial(valueA);
                    printFactorialA(result);
                }
                break;

            case 'b':
        	    if(valueB<0)
                {
                    printErrorFactNegative();
                }else
                {
                    result=factorial(valueB);
                    printFactorialB(result);
                }
                break;

            case 'c':                 //En caso de que se ingrese el caracter 'c', se volverá a pedir en ingreso de las variableas
                system("cls");

                do
				{
					fflush(stdin);
					state=getInt(&valueA, MSG_INPUT_VALUE_A, MSG_INVALID_CHAR_INPUT, -9999999, 9999999, 10);
					system("cls");

				}while(state!=0);

				do
				{
					fflush(stdin);
					state=getInt(&valueB, MSG_INPUT_VALUE_B, MSG_INVALID_CHAR_INPUT, -9999999, 9999999, 10);
					system("cls");

				}while(state!=0);

                break;

            case 'S':
            case 'E':
            	system("cls");
            	printExitConfirm();

            	fflush(stdin);
            //	operation=getch();
            	scanf("%c", &operation);

            	if(operation=='n')
            	{
            		system("cls");
            		break;
            	}

            	if(operation=='S'||operation=='Y')
            	{
            		exit=1;
            		system("cls");
            		printGoodbye();
            		break;
            	}
            	break;

            default:
            	printInvalidOperation();
            	break;
    	}

    	printLine();
    }

    return 0;
}
