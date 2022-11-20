#include <iostream>
#include <clocale>
#include <ctime>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include "rlutil.h"
#include "funciones.h"

using namespace std;



/**
 * @brief fdado Función para el marco blanco de los dados.
 *
 * @param inicioX Posición inicial en X
 * @param inicioY Posición inicial en Y
 * @param finX Posición final en X
 * @param finY Posición final en Y
 */

void fdado(int inicioX,int inicioY,int finX,int finY) {

	for(int x=inicioX;x<finX;x++) {
	for(int y=inicioY;y<finY;y++) {
	rlutil::locate(x,y);
	rlutil::setBackgroundColor(rlutil::WHITE);
	cout<<" ";
	rlutil::setBackgroundColor(rlutil::BLACK);
            }
        }
}

/**
 * @brief dados Función para cada valor de los dados.
 * Ampliación:habrá 3 IF por cada número de dado y a su vez en cada if un SWITCH con las 6 caras de los dados.
 *
 * @param numDado Número de dado (1,2 o 3)
 * @param numRandom Valor que devoverá la función random (del 1 al 6).
 */

void dados(int numDado,int numRandom) {

{
    if(numDado==1) {

    switch(numRandom) {

    case 1:
    fdado(18,9,32,16);
     //medio
     rlutil::locate(24,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

    case 2:
    fdado(18,9,32,16);
     //00
     rlutil::locate(21,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     //FF
     rlutil::locate(27,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

    case 3:
    fdado(18,9,32,16);
     //00
     rlutil::locate(21,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     //medio
     rlutil::locate(24,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     //FF
     rlutil::locate(27,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

     case 4:
    fdado(18,9,32,16);
     //00
     rlutil::locate(21,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
	//F0
     rlutil::locate(27,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     	//0F
     rlutil::locate(21,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
      //FF
     rlutil::locate(27,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

      case 5:
    fdado(18,9,32,16);
     //00
     rlutil::locate(21,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
	//F0
     rlutil::locate(27,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     	//0F
     rlutil::locate(21,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
      //FF
     rlutil::locate(27,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     //medio
     rlutil::locate(24,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

      case 6:
    fdado(18,9,32,16);
     //00
     rlutil::locate(21,10);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
	//0M
     rlutil::locate(21,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     	//0F
     rlutil::locate(21,14);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";

	//00
     rlutil::locate(27,10);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
	//0M
     rlutil::locate(27,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     	//0F
     rlutil::locate(27,14);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;


    }
    } else {

    if(numDado==2) {
 switch(numRandom) {

    case 1:
    fdado(18+20,9,32+20,16);
     //medio
     rlutil::locate(24+20,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

    case 2:
    	fdado(18+20,9,32+20,16);
     //00
     rlutil::locate(21+20,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     //FF
     rlutil::locate(27+20,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

    case 3:
    	fdado(18+20,9,32+20,16);
     //00
     rlutil::locate(21+20,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     //medio
     rlutil::locate(24+20,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     //FF
     rlutil::locate(27+20,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

     case 4:
     	fdado(18+20,9,32+20,16);
     //00
     rlutil::locate(21+20,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
	//F0
     rlutil::locate(27+20,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     	//0F
     rlutil::locate(21+20,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
      //FF
     rlutil::locate(27+20,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

      case 5:
	fdado(18+20,9,32+20,16);
     //00
     rlutil::locate(21+20,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
	//F0
     rlutil::locate(27+20,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     	//0F
     rlutil::locate(21+20,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
      //FF
     rlutil::locate(27+20,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     //medio
     rlutil::locate(24+20,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

      case 6:
	fdado(18+20,9,32+20,16);
     //00
     rlutil::locate(21+20,10);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
	//0M
     rlutil::locate(21+20,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     	//0F
     rlutil::locate(21+20,14);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";

	//00
     rlutil::locate(27+20,10);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
	//0M
     rlutil::locate(27+20,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     	//0F
     rlutil::locate(27+20,14);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

 }


    } else {

	switch(numRandom) {

    case 1:
    fdado(18+40,9,32+40,16);
     //medio
     rlutil::locate(24+40,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

    case 2:
    	 fdado(18+40,9,32+40,16);
     //00
     rlutil::locate(21+40,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     //FF
     rlutil::locate(27+40,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

    case 3:
    	 fdado(18+40,9,32+40,16);
     //00
     rlutil::locate(21+40,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     //medio
     rlutil::locate(24+40,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     //FF
     rlutil::locate(27+40,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

     case 4:
     	 fdado(18+40,9,32+40,16);
     //00
     rlutil::locate(21+40,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
	//F0
     rlutil::locate(27+40,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     	//0F
     rlutil::locate(21+40,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
      //FF
     rlutil::locate(27+40,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

      case 5:
	 fdado(18+40,9,32+40,16);
     //00
     rlutil::locate(21+40,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
	//F0
     rlutil::locate(27+40,11);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     	//0F
     rlutil::locate(21+40,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
      //FF
     rlutil::locate(27+40,13);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     //medio
     rlutil::locate(24+40,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;

      case 6:
	 fdado(18+40,9,32+40,16);
     //00
     rlutil::locate(21+40,10);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
	//0M
     rlutil::locate(21+40,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     	//0F
     rlutil::locate(21+40,14);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";

	//00
     rlutil::locate(27+40,10);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
	//0M
     rlutil::locate(27+40,12);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
     	//0F
     rlutil::locate(27+40,14);
     rlutil::setBackgroundColor(rlutil::MAGENTA);
     cout<<"  ";
    break;
 }

    }

    }

}

}

/**
 * @brief lanzamiento Función que muestra en pantalla las tiradas de los dados a partir de la funcón srand de la librería time.
 * Ampliación: Se añade un IF que habilita el tercer dado si la bandera esta en 1.
 *
 * @param dado1,dado2,dado3 Valor de cada dado por referencia, ya que necesitará ser almacenada en la matriz "int jugador[2][10]" declarada en main.
 * @param banderadado3 Valor de la bandera que habilita el tercer dado: 0 false, 1 true.
 * @param sumaJugador La suma que se pasa por referencia a main para los preliminares de los dados 1 y 2. Se muestra por pantalla en main.

 */

void lanzamiento(int &dado1,int &dado2,int &dado3, int &banderadado3, int &sumaJugador)
{
    system("pause");
    srand(time(NULL));
    dado1=rand()%(6)+1;
    dado2=rand()%(6)+1;

    sumaJugador=dado1+dado2;
    dados(1,dado1);
    dados(2,dado2);

    if (banderadado3==0)
    {
        cout <<endl<<endl;
    }
    if(banderadado3==1)
    {
        dado3=rand()%(6)+1;
        dados(3,dado3);
    }
    cout <<endl<<endl;
    cout <<endl<<endl;
    cout <<endl<<endl;
    rlutil::setBackgroundColor(rlutil::BLACK);
}

/**
 * @brief VectoresACero Inicializa los acumuladores y contadores en 0.
 *
 *
 * @param turno Cantidad de turnos totales entre los jugadores. Hoy vale 10.
 * @param VecLanz[10] Guarda la cantidad de lanzamientos que se hizo en cada ronda. Se iniciliza en 0.
 * @param Matjugador[2][10] Es la matriz jugador[2][10] que almacena todos los datos esenciales pasada por referencia. Se iniciliza en 0.
 * Comentario: Los vectores y matrices siempre se pasan por referencia cuando son parámetros de una función.
 */

void VectoresACero(int turno, int VecLanz[10])
{
    int i,j;
    for(i=0; i<turno; i++)
        {
            VecLanz[i]=0;
        }

}
