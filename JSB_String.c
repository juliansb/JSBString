/**
******************************************************
* @file JSB_String.c
* @brief Conjunto de funciones para tratamioento de String
* @author Oscar Salas Mestres & Julian Salas Bartolome
* @version 1.0
* @date Agosto 2012
*
*
*******************************************************/

#include "JSB_String.h"

#define NULL 0


/**
******************************************************
* @brief Extrae una linea de una cadena
*
* Esta funcion se utiliza para extraer una linea de un texto, en delimitador se le debe pasar el/los caracteres final de linea 
* @post  Debe liberarse la memoria con free
* @return Devuelve un puntero a la cadena extraida
* @param cTexto Puntero al texto que queremos extraer la linea
* @param cLimitador Puntero a la secuencia de final de linea    
* @param nLinea Numero de la linea que se quiere extraerr, si ese numero de linea no existe, devuelve Null
*
* Ejemplo:
*
*   char cCadena[]="Hola Caracola \n Hola Mundo \n Adios Caracola \n Adios Mundo";
*   char cFinalLinea[]="\n";
*   char cTexto[20];
*
*   char *cDestino = JSB_SubStr (cCadena, cFinalLinea, 1 );
*   strcpy (cTexto, cDestino);   
*   .
*   .
*   free (cDestino);   
*
* Resultado:
*
*   cTexto = "Hola Mundo"    
*/
char* JSB_ExtraeLinea(char *cTexto, char *cLimitador, int nLinea){
   //-------------------------------------------------------------   
   //Definicion de variables
   //-------------------------------------------------------------   
   char *cDestino;
   int nLineaTmp=0;
   int nTmp=0;
   int nLongitud=0;
   int nPuntero=0;
   int nPosDelimitador=0;      
   int nLineasTexto;                              
   //-------------------------------------------------------------   
   nLineasTexto =  1 + JSB_StrCount ( cTexto, cLimitador, 1);                    //Contamos el numero de Lineas
   if ( nLinea > nLineasTexto )                                                  //Comrobamos que nLinea esta dentro del rango de lineas de cTexto
   {
      return NULL;                                                               //si la linea no existe devolvemos Nulo
                     
   }

                                                                                 //recorremos todas las lineas hasta llegar a la que buscamos utilizando la funcion buscaCadena
   if(nLinea==0){                                                                //Si la linea que pedimos es la 0
      nPosDelimitador=JSB_StrPos(cTexto,cLimitador,nPuntero);                    //Buscamos el Delimitados dentro del texto
         if(nPosDelimitador!=-1){                                                //Si existe el delimitador es que hay una linea
            nPuntero=0;                                                          //Como queriamos la linea 0 el puntero es 0
         }else{                                                                  //Si no existe Delimitados
            return NULL;                                                         //Devolvemos Nulo por que no hay linea
         }
   }else{                                                                        //Si pedimos una linea dsitinta de la 0
      while(nLineaTmp != nLinea){                                                //Vamos a recorrer todas las lineas hasta llegar a la solicitada
         nPosDelimitador=JSB_StrPos(cTexto,cLimitador,nPuntero);                 //Buscamos el Delimitados
         if(nPosDelimitador!=-1){                                                //Si lo encontramos
            nLineaTmp++;                                                         //Incrementamos la cuenta de linea
         }else{                                                                  //Si no encontramos delimitados, como no hemos llegado a la linea deseada devolvemos null
            return NULL;
         }
         nPuntero=nPosDelimitador+strlen(cLimitador);                            //Actualizamos el puntero al caracter siguiente al delimitador
      }
   }
                                                                                 //nPuntero apunta al primer caracter de la linea deseada
                                                                                 //Vamos a determinar la longitud de la linea
   nTmp=nPuntero;                                                                //Salvamos el Puntero
   int nTestFinFrase=JSB_StrPos(cTexto,cLimitador,nPuntero);                     //Comprobamos que posterior al primer caracter existe un Delimitador
   if(nTestFinFrase==-1){                                                        //Si no hay delimitador es la ultima linea del texto
      while(cTexto[nTmp]!='\0'){                                                 //Para determnar la longitud de la linea buscamos final de texto
         nLongitud++;
         nTmp++;
      }
   }else{                                                                        //Si si que hay delimitados es una linea intermedia del texto
      while(nTmp<nTestFinFrase){                                                 //Para eterminar la longitud de la liea buscamos el delimitador
         nLongitud++;
         nTmp++;
      }
   }
                                                                                 //ya tenemos donde empiez la linea en nPuntero y la longitud en nLongitud   
                                                                                 //Solo queda copiar la linea en la variable cDestino
   //nPos=nTmp;
   nTmp=0;
   cDestino=malloc(nLongitud+1);                                                 //Utilizaremos memoria dinamica
   
   if(nTestFinFrase==-1){                                                        //Si era la ultima linea
      while(cTexto[nPuntero]!='\0'){                                             //Vamos guardando en cDestino hasta que encontramos el final de frase
         cDestino[nTmp]=cTexto[nPuntero];
         nPuntero++;
         nTmp++;
      }
   }else{                                                                        //Si era linea intermedia
      while(nTmp<nLongitud){                                                     //Vamos gueardando en cDestino hasta alcanzar la longitud determinada anteriormente
         cDestino[nTmp]=cTexto[nPuntero];                                 
         nPuntero++;
         nTmp++;
      }
   }

   cDestino[nTmp]='\0';                                                          //Añadimos a cDestino el final de texto
   return cDestino;
}
/**
******************************************************
* @brief Retorna el numero de caracteres de un String
*
* @param cCadena Puntero a la cadena a la que se le quiere determinar la longitud
*
* @return Devuelve la longitud del String como int
*
* Ejemplo:
*
*   char cCadena[]="Hola Caracola \n Hola Mundo \n Adios Caracola \n Adios Mundo";
*
*   int nLongitud = JSB_StrLen (cCadena);
**
* Resultado:
*
*   nLongitud = 57 
*/
int JSB_strLen (char *cCadena)
{
   //-------------------------------------------------------------   
   //Definicion de variables
   //-------------------------------------------------------------   
   int nLen = 0;                                       				//Incializamos el puntero a 0
   //-------------------------------------------------------------   

   while ( cCadena[nLen] != '\0' )                                 		//Mientras el caracter apuntado sea distinto del final de texto
   {
      nLen++;                                       				//Incrementamos el punter
   }
   return nLen;                                       				//Retornamos el contenido del puntero que coincide con la longitud del texto   
}
/**
******************************************************
* @brief Devuelve una parte de cCadena delimitada por los parametros nInicio y nFinal
*
* @param cCadena Puntero a la cadena de entrada
* @param nInicio Posicion del Primer caracter, si no esta dentro del rango permitido devuelve Null   
* @param nFinal Posicion del ultimo caracter, si no esta dentro del rango permitido devuelve Null   
*
* @return Devuelve un puntero a la cadena extraida
*
* @post  Debe liberarse la memoria con free
* Ejemplo:
*
*   char cCadena[]="Hola Caracola";
*   char cTexto[20];
*
*   char *cDestino = JSB_SubStr (cCadena, 5, 12 );
*   strcpy (cTexto, cDestino);   
*   .
*   .
*   free (cDestino);   
*
* Resultado:
*
*   cTexto = "Caracola" 
*/
char* JSB_SubStr(char *cCadena,int nInicio, int nFinal){

   //-------------------------------------------------------------   
   //Definicion de variables
   //-------------------------------------------------------------   
   int nPunteroOrigen=nInicio;
   int nPunteroDestino=0;
   int nLongitud = JSB_strLen (cCadena);                              		//Determinamos la longitud de la cadena
   //-------------------------------------------------------------   

   if ( nInicio < 0 || nInicio > nLongitud )                           		//Comprobamos si nInicio está dentro de valores permitodos                     
   {
      return NULL;                                     				//Salimos devolviendo Null si no está
   }

   if ( nFinal < 0 || nFinal > nLongitud || nFinal < nInicio)               	//Comprobamos si nFinal está dentro de valores permitodos                     
   {
      return NULL;                                     
   }
   //-------------------------------------------------------------   
   //Definicion de variables
   //-------------------------------------------------------------      
   char *cDestino = malloc((nFinal-nInicio)+2);                            	//Reservamos tanta memoria como la diferencia de indices + 1 (para el '\0')
   //-------------------------------------------------------------      

   if(cDestino==NULL){
      return NULL;                                     				//Si el malloc falla, devolvemos NULL
   }



   while(nPunteroOrigen<=nFinal){                                 		//Unicamente recorreremos la frase entre los indices marcados por nInicio y nFinal
      cDestino[nPunteroDestino]=cCadena[nPunteroOrigen];
      nPunteroOrigen++;
      nPunteroDestino++;
   }
   cDestino[nPunteroDestino]='\0';                                 		//Ponemos un '\0' por si se utiliza la frase con alguna funcion de la libreria string.h
   return cDestino;
}

/**
******************************************************
* @brief Encuentra la posición de la primera ocurrencia de una subcadena en una cadena a partir de una posicion determinada
*
* @param cCadena Puntero a la cadena donde vamos a buscar cSubcadena
* @param cSubCadena Puntero a la subcadena que queremos buscar   
* @param nInicio Posicion de cCadena desde donde se va buscar    
*
* @return Devuelve la posicion donde se encuentra la subcadena tomando como 0 el primer caracter de la cadena, -1 en caso de no encontrar la cadena
*
* @pre nInicio  deben ser valido
*
* Ejemplo:
*
*   char cCadena[]="Hola Caracola \n Hola Mundo \n Adios Caracola \n Adios Mundo";
*   char cSubCadena[]="cola";
*
*   int nPosicion=JSB_StrPos (cCadena, cSubCadena, 5);
*
* Resultado:
*
*   nPosicion = 39   
*/
int JSB_StrPos(char *cCadena, char *cSubCadena, int nInicio){
   //-------------------------------------------------------------   
   //Definicion de variables
   //-------------------------------------------------------------   
   int nPuntero=nInicio;
   int nLongitudCadena=JSB_strLen(cCadena);                 			//Determinamos la longitud de la cadena
   int nLongitudSubCadena=JSB_strLen(cSubCadena);                            	//Determinamos la longitud de cSubCadena
   int lSalida=-1;
   int nPosSubCadena=0;
   int nTmpPosCadena = 0;
   //-------------------------------------------------------------   
   

   while( nPuntero<nLongitudCadena && lSalida==-1 ){                        	//Recorreemos cCadena hasta el final o hasta que encontremos la coincidencia de cSubCadedna                  
      nPosSubCadena = 0;
      if(cCadena[nPuntero]==cSubCadena[nPosSubCadena]){                     	//Si el caracter de cCadena apuntado coincide con el primero de cSubcadena
         nTmpPosCadena = nPuntero;
         while (cCadena[nTmpPosCadena]==cSubCadena[nPosSubCadena] && nPosSubCadena<nLongitudSubCadena)   //recorremos cCadena mientras vaya coincidiendo con el contenido de cSubCadena
         {
            nTmpPosCadena++;
            nPosSubCadena++;
             
         }
      }
      if ( nPosSubCadena==nLongitudSubCadena )                        		//Si el numero de caracteres coincidentes es igual a la longitud de cSubcadena se ha encontrado
      {
         lSalida = nPuntero;                              			//Igualamos lSalida a la posicion donde hemos encontrado cSubcadena y así se saldra del bucle
      }else{
         nPuntero++;                                 				//Si no hay coincidnecia, incrementamos el puntero para seguir recorriendo cCadena
      }
   }
   return lSalida;
}
/**
******************************************************
* @brief Cuenta el numero de veces que cCadena contiene a cSubCadena desde la posicion nInicio
*
* @param cCadena Puntero a la cadena donde vamos a buscar cSubcadena
* @param cSubCadena Puntero a la subcadena que queremos buscar   
* @param nInicio Posicion de cCadena desde donde se va buscar, si es mayor que la longitud de la cadena devuelve Null    
*
* @return Devuelve el numero de repeticiones de cSubcadena en cCadena como int
* 
*
* Ejemplo:
*
*   char cCadena[]="Hola Caracola \n Hola Mundo \n Adios Caracola \n Adios Mundo";
*   char cSubCadena[]="la";
*
*   int nRepeticiones=JSB_StrCount (cCadena, cSubCadena, 0);
*
* Resultado:
*
*   nRepeticiones = 4   
*/
int JSB_StrCount (char *cCadena, char *cSubCadena, int nInicio){
   //-------------------------------------------------------------   
   //Definicion de variables
   //-------------------------------------------------------------      
   int nRepeticiones = 0;
   int nPosicion = 0;
   int nLongitud = JSB_strLen (cCadena);                              		//Determianmos la longitud de la cadena
   //-------------------------------------------------------------   
   if ( nInicio < 0 || nInicio > nLongitud )                           		//Comprobamos si nInicio está dentro de valores permitodos                     
   {
      return NULL;                                     				//Salimos devolviendo Null si no está
   }

   
   nPosicion=JSB_StrPos(cCadena, cSubCadena, nInicio);                        	//Buacamos la primera coincidencia
   while ( nPosicion  != -1 )                                 			//Si se encuentra, incrementamos nRepeticiones
   {                                                            		//Y comprobamos si existe otra coincidneica despues de la encontrada
      nRepeticiones++;                                 				//por eso incrementamos la posicion desde donde se debe buscar
      nPosicion++;
      nPosicion=JSB_StrPos(cCadena, cSubCadena, nPosicion);
   }

   return nRepeticiones;
   
} 

