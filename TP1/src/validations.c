/*
 * validations.c
 *
 *  Created on: 29 ago. 2020
 *      Author: John
 */
#include "validations.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <stdbool.h>
//#include <stdio_ext.h>



/* Integers */

/** \brief Recibe dos valores num�ricos enteros, calcula la suma y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable A
 * \param Valor correspondiente a la variable B
 * \param Valor correspondiente a la variable pResult
 * \return Devuelve si hubo error o no
 *
 */
int inputInt(int* pResult, char* inputMessage, char* errorMessage, int min, int max, int retries)
{
	int ret = -1;

	if(pResult!=NULL && inputMessage!=NULL && errorMessage!=NULL && min<=max && retries>=0)
	{
		int bufferInt;

		do
		{
			printf("%s", inputMessage);

			if(getInt(&bufferInt)==0 && bufferInt >= min && bufferInt <= max) // Valida que sea un numero y est� dentro de los parametros maximo y minumo
			{
				*pResult=bufferInt;
				ret=0;
				break;
			}else
			{
				printf("%s\n", errorMessage);
				retries--;
			}
		}while(retries>=0);
	}

	return ret;
}


int isNumber(char* cadena)
{
	int i=0;
	int ret = 1;
	if (cadena != NULL && strlen (cadena) > 0)
	{
		while (cadena[i] != '\0' )
		{
			if (cadena[i] < '0' || cadena[i] > '9' )
			{
				if(!(i==0 && cadena[i] == '-' && strlen(cadena) > 1)) //Valida que si en la posicion anterior al numero hay un signo (-) se trata de un numero negativo y no lo descarta
				{
					ret = 0;
					break ;
				}
			}
			i++;
		}
	}
	return ret;
}



int getInt(int* pResultado)
{
	int ret=-1;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (getChar(buffer, sizeof (buffer))==0 && isNumber(buffer))
		{
			*pResultado = atoi (buffer);
			ret = 0;
		}
	}
	return ret;
}

/* ------------------------------------------------------------------------------------------------------------------ */
/* Floats */

int getFloat(float* pResult, char* inputMessage, char* errorMessage, float min, float max, int retries)
{
	int ret = -1;

		if(pResult!=NULL && inputMessage!=NULL && errorMessage!=NULL && min<=max && retries>=0)
		{
			float bufferFloat;

			do
			{
				printf("%s", inputMessage);
				fflush(stdin);
				scanf("%f", &bufferFloat);

				if(bufferFloat >= min && bufferFloat <= max)
				{
					*pResult=bufferFloat;
					ret=0;
					break;
				}else
				{
					printf("%s", errorMessage);
					retries--;
				}
			}while(retries>=0);
		}

		return ret;
}


/* ------------------------------------------------------------------------------------------------------------------ */
/* Chars */


int getChar(char* cadena, int longitud)
{
	int ret=-1;
	fflush (stdin);
	if (cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush (stdin); // fflush o __fpurge
		if (strlen (cadena) > 1 && cadena[ strlen (cadena)-1] == '\n')
		{
			cadena[ strlen (cadena)-1] = '\0' ;
		}
	ret=0;
	}
	return ret;
}


int getCharByNum(char* pResult, char* inputMessage, char* errorMessage, char min, char max, int retries)
{
	int ret = -1;

		if(pResult!=NULL && inputMessage!=NULL && errorMessage!=NULL && min<=max && retries>=0)
		{
			char bufferChar;

			do
			{
				printf("%s", inputMessage);
				fflush(stdin);
				scanf("%c", &bufferChar);

				if(bufferChar >= min && bufferChar <= max)
				{
					*pResult=bufferChar;
					ret=0;
					break;
				}else
				{
					printf("%s", errorMessage);
					retries--;
				}
			}while(retries>=0);
		}

		return ret;
}


//Instructions to validate chars by type (4th argument):
//Only Mayusc:              M
//Only Minusc:              m
//Both Mayusc and minusc:   b
//All (with symbols):       A

int getCharByType(char* pResult, char* inputMessage, char* errorMessage, char typeChar, int retries)
{
	int ret = -1;

		if(pResult!=NULL && inputMessage!=NULL && errorMessage!=NULL && (typeChar=='M' || typeChar=='m' || typeChar=='b' || typeChar=='A') && retries>=0)
		{
			char bufferChar;

			do
			{
				printf("%s", inputMessage);
				fflush(stdin);
				scanf("%c", &bufferChar);

				switch(typeChar)
					{
						case 'M':
							if(bufferChar>=65 && bufferChar<=90)
							{
								*pResult=bufferChar;
								retries=-1;
								ret=0;
							}else
							{
								printf("%s", errorMessage);
								retries--;
							}
							break;

						case 'm':
							if(bufferChar>=97 && bufferChar<=122)
							{
								*pResult=bufferChar;
								retries=-1;
								ret=0;
							}else
							{
								printf("%s", errorMessage);
								retries--;
							}
							break;

						case 'b':
							if((bufferChar>=65 && bufferChar<=90) || (bufferChar>=97 && bufferChar<=122))
							{
								*pResult=bufferChar;
								retries=-1;
								ret=0;
							}else
							{
								printf("%s", errorMessage);
								retries--;
							}
							break;

						case 'A':
							if(bufferChar>=32 && bufferChar<=255)
							{
								*pResult=bufferChar;
								retries=-1;
								ret=0;
							}else
							{
								printf("%s", errorMessage);
								retries--;
							}
							break;
					}

			}while(retries>=0);

		}

		return ret;
}



