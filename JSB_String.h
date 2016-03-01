/**
******************************************************
* @file JSB_String.h
* @brief Conjunto de funciones para tratamioento de String
* @author Oscar Salas Mestres & Julian Salas Bartolome
* @version 1.0
* @date Agosto 2012
*
*
*******************************************************/
#ifndef _JSBString
#define _JSBString

#include <stdio.h>
#include <stdlib.h>

nt JSB_strLen (char *cCadena);
int JSB_StrPos(char *cCadena, char *cLimitador,int nInicio);
int JSB_StrCount (char *cCadena, char *cLimitador,int nInicio);
char* JSB_ExtraeLinea(char *cTexto, char *cLimitador, int nLinea);
char* JSB_SubStr(char *cCadena,int nInicio,int nFinal);



#endif