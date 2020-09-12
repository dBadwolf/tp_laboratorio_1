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
//#include <stdio_ext.h>



/* Integers */

/** \brief Valida que el numero recibido este dentro de los parametros maximo y minumo, y lo guarda en pResult
 *
 * \param Valor correspondiente a la direccion de memoria de pResult
 * \param Valor correspondiente a la direccion de memoria de inputMessage
 * \param Valor correspondiente a la direccion de memoria de errorMessage
 * \param Valor correspondiente a la variable min
 * \param Valor correspondiente a la variable max
 * \param Valor correspondiente a la variable retries
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
			puts(inputMessage);

			if(getInt(&bufferInt)==0 && bufferInt >= min && bufferInt <= max) //
			{
				*pResult=bufferInt;
				ret=0;
				break;
			}else
			{
				puts(errorMessage);
				retries--;
			}
		}while(retries>=0);
	}

	return ret;
}





/** \brief Valida si se trata e un numero o si es una cadena de caracteres
 *
 * \param Valor correspondiente a la direccion de memoria de pString
 * \return Devuelve si hubo error o no
 *
 */
int isNumber(char* pString)
{
	int i=0;
	int ret = 1;
	if (pString != NULL && strlen (pString) > 0)
	{
		while (pString[i] != '\0' )
		{
			if (pString[i] < '0' || pString[i] > '9' )
			{
				if(!(i==0 && pString[i] == '-' && strlen(pString) > 1)) //Valida que si en la posicion anterior al numero hay un signo (-) se trata de un numero negativo y no lo descarta como char
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


/** \brief Valida que si la cadena esta compuesta solo por n�meros, entonces transforma el contenido a int y lo pasa a pResultado
 *
 * \param Valor correspondiente a la direccion de memoria de pResult
 * \return Devuelve si hubo error o no
 *
 */
int getInt(int* pResult)
{
	int ret=-1;
	char buffer[64];
	if (pResult != NULL)
	{
		if (getChar(buffer, sizeof (buffer))==0 && isNumber(buffer)) // obtiene una cadena y si es un numero la transforma a entero
		{
			*pResult = atoi (buffer);
			ret = 0;
		}
	}
	return ret;
}


/* ------------------------------------------------------------------------------------------------------------------ */
/* Chars */

/** \brief Obtiene una cadena de caracteres y reemplaza el \n por \0
 *
 * \param Valor correspondiente a la direccion de memoria de pResult
 * \return Devuelve si hubo error o no
 *
 */
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


