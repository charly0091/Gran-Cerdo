#include <iostream>
#include <clocale>
#include <ctime>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include "rlutil.h"
#include "funciones.h"

using namespace std;

struct Jugador
{

    string nombre;
    int dado1;
    int dado2;
    int trufasRonda;
    int sumaDado;
    int PDV;
    int PDV50Trufas;
    int MaxLanzamiento;
    int Oink;
    int trufasTotalesAux;
    int trufasTotales;
    int porky;

} jugador1,jugador2;

int main()
{

    /**
     * @brief system title Le asigna un nombre al documento en la barra superior de la consola.
     */
    system("title JUEGO EL GRAN CERDO (°@°)~ ");
    setlocale(LC_ALL, "Spanish");

    /**
     * @brief Código para darle un tamaño predeterminado a la consola y la fuente.
     */
    static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 500;
    fontex.dwFontSize.X = 24;
    fontex.dwFontSize.Y = 24;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);


    /**
    * @brief Comentario de las variables que se inicializan:
    *
    * PARAMENTROS INT:
    * opcion: utilizada para el switch del menu.
    * i: inicializadores.
    * maximodado: utilizado en la ronda preliminar para almacenar el valor del dado más alto.
    * dadomasalto: Enumera cada dado para compararlos al empatar y saber si hubo uno mayor
    * lanzamientos[10]={} Vector que almacena la cantidad de lanzamientos por ronda.
    * maxlanz Almacena el lanzamiento mas alto acumulados en lanzamientos[10]
    * puntmax Se utiliza en las estadísticas para saber de cuanto es el puntaje record.
    * barro Bandera para saber si el jugador cayó en el barro, si la bandera pasa a 1, se activa el tercer dado.
    * finTurno Bandera que obliga al jugador a finalizar su turno.
    * tiraDeVuelta Bandera que obliga al jugador a tirar nuevamente.
    * resto Utilizado para dividir las rondas del jugador par o impar.
    * usarDado3 Habilita el tercer dado.
    * dado1,dado2,dado3 se utilizan para hacer las condiciones del juego. Clara quiere poner algo mas pero no se acuerda que
    * trufas Acumulador general de trufas por ronda para ambos jugadores. Luego dependiendo la ronda par o impar, almacena los resultados en la matriz jugador.
    * flagd3 Para mostrar por unica vez el mensaje que comenta el porque del tercer dado
    *
    * PARAMENTROS STRING:
    * jugador1.nombre,jugador2.nombre Almacena los nombres de los jugadores en la ronda preliminar
    * turno1,turno2 Almacena los nombres de los jugadores con el resultado de la ronda preliminar.
    * nombremax Se utiliza en las estadísticas para establecer quien tiene el record de puntos ganados.
    *
    * PARAMENTROS BOOL:
    * banderainicio Mientras sea falsa
    * banderacontinua Bandera para saber si se ingreso una opcion correcta en "Desea continuar?"
    * banderaestadistica: Bandera para saber si ya se jugo solo 1 partida, para almacenar esos valores como maximo en estadisticas
    ,banderainfo: Bandera para saber si aun no se jugo ninguna partida, para saber que no hay maximo almacenado en estadisticas
    ,banderasalir Activa las opciones del switch
    *
    * PARAMENTROS CHAR:
    * continua Seguir tirando S/N
    * salir Salir del juego S/N
    *
    */

    const int turno = 10;
    int opcion,i,maximodado,dadomasalto,lanzamientos[10]= {},maxlanz,puntmax,barro = 0,finTurno=0,tiraDeVuelta,resto,usarDado3=0,dado1,dado2,dado3,trufas=0,flagd3=0;
    string turno1,turno2,nombremax;
    bool banderainicio=false,banderacontinua=false,banderaestadistica=false,banderainfo=false,banderasalir=false,banderaporky=false;
    char continua,salir;

    //SE EJECUTA MIENTRAS EL USUARIO NO PONGA SALIR
    do
    {

        /**
         * @brief Dibujo de la cara del cerdito a la derecha del menu.
         * El primer for es para dibujar la cara del cerdito ya que es un cuadrado.
         * El resto de los dibujos son espacios con los colores que pisan dentro del cuadrado: ojos, orejas y hocico.
         *
         */

        //Cara del cerdo
        for(int x=71; x<100; x++)
        {
            for(int y=9; y<22; y++)
            {
                rlutil::locate(x,y);
                rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
                cout<<" ";
            }
        }

        //Orejas
        rlutil::locate(70,9);
        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        cout<<"     ";
        rlutil::locate(70,10);
        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        cout<<"     ";
        rlutil::locate(70,11);
        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        cout<<"   ";
        rlutil::locate(70,12);
        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        cout<<"   ";

        rlutil::locate(96,9);
        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        cout<<"     ";
        rlutil::locate(96,10);
        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        cout<<"     ";
        rlutil::locate(98,11);
        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        cout<<"   ";
        rlutil::locate(98,12);
        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        cout<<"   ";

        //Ojos
        rlutil::locate(78,13);
        rlutil::setBackgroundColor(rlutil::BLACK);
        cout<<"  ";
        rlutil::locate(91,13);
        rlutil::setBackgroundColor(rlutil::BLACK);
        cout<<"  ";

        //Hocico
        rlutil::locate(83,15);
        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        cout<<"     ";
        rlutil::locate(81,16);
        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        cout<<"         ";
        rlutil::locate(81,17);
        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        cout<<"         ";
        rlutil::locate(83,18);
        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        cout<<"     ";
        rlutil::locate(83,16);
        rlutil::setBackgroundColor(rlutil::BLACK);
        cout<<"  ";
        rlutil::locate(86,16);
        rlutil::setBackgroundColor(rlutil::BLACK);
        cout<<"  ";

        //Menu
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::LIGHTMAGENTA);
        rlutil::locate(10,8);
        cout << " GRAN CERDO " << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(10,10);
        cout << "------------------------"<<endl;
        rlutil::locate(10,12);
        cout << "1- JUGAR" << endl;
        rlutil::locate(10,14);
        cout << "2- ESTADISTICAS"<< endl;
        rlutil::locate(10,16);
        cout << "3- CERDITOS" << endl;
        rlutil::locate(10,18);
        cout << "------------------------"<<endl;
        rlutil::locate(10,20);
        cout << "0- SALIR" << endl;
        rlutil::locate(10,22);
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            system("title JUEGO EL GRAN CERDO (°@°)~ Veamos quién Comienza!");
            banderainfo=true;
            banderainicio=false;
            banderacontinua=false;
            banderaestadistica=false;
            banderaporky=false;
            barro = 0;
            trufas=0;
            flagd3=0;
            usarDado3=0;
            finTurno=0;

            VectoresACero(turno,lanzamientos);
            jugador1.MaxLanzamiento=0;
            jugador1.Oink=0;
            jugador1.PDV50Trufas=0;
            jugador1.PDV=0;
            jugador1.trufasRonda=0;
            jugador1.trufasTotales=0;
            jugador1.trufasTotalesAux=0;
            jugador2.MaxLanzamiento=0;
            jugador2.Oink=0;
            jugador2.PDV50Trufas=0;
            jugador2.PDV=0;
            jugador2.trufasRonda=0;
            jugador2.trufasTotales=0;
            jugador2.trufasTotalesAux=0;
            jugador1.porky=0;
            jugador2.porky=0;

            system("cls");

            cout<<"-Juego de dados, comienza el jugador que mayor puntaje obtiene-"<<endl<< endl;
            cout<<"Ingresen sus nombres" << endl << endl;
            cout<<"Jugador 1, ¿Cómo te llamas? (Luego de ingresar tu nombre presiona Enter)."<<endl;
            cin >> jugador1.nombre;
            cout<< endl;
            cout<<"Jugador 2, ¿Cómo te llamas? (Luego de ingresar tu nombre presiona Enter)."<<endl;
            cin >> jugador2.nombre;
            system("cls");

            //JUGADA PRELIMINAR

            while (banderainicio==false)
            {
                // Llamada a Funcion Lanzamiento
                cout <<"Es el turno de " << jugador1.nombre << endl;
                lanzamiento(jugador1.dado1,jugador1.dado2,dado3,usarDado3,jugador1.sumaDado);

                cout<<"La suma de los dados de " << jugador1.nombre << " es: ["<<jugador1.sumaDado<<"]"<<endl <<endl;
                system("pause");
                system("cls");

                // Llamada a Funcion Lanzamiento
                cout <<"Es el turno de " << jugador2.nombre << endl;
                lanzamiento(jugador2.dado1,jugador2.dado2,dado3,usarDado3,jugador2.sumaDado);

                cout<<"La suma de los dados de " << jugador2.nombre << " es: ["<<jugador2.sumaDado<<"]"<<endl <<endl;

                //Si las sumas son iguales
                if(jugador1.sumaDado == jugador2.sumaDado)
                {
                    //Si todos los dados son diferentes
                    if(jugador1.dado1 != jugador2.dado1 && jugador1.dado2 != jugador2.dado1)
                    {
                        //Le asigno el valor del dado
                        maximodado=jugador1.dado1;
                        //Identifica que dado es
                        dadomasalto=1;
                        if(jugador1.dado2>maximodado)
                        {
                            dadomasalto=2;
                            maximodado=jugador1.dado2;
                        }
                        if(jugador2.dado1>maximodado)
                        {
                            dadomasalto=3;
                            maximodado=jugador2.dado1;
                        }
                        if(jugador2.dado2>maximodado)
                        {
                            dadomasalto=4;
                            maximodado=jugador2.dado2;
                        }

                        if(dadomasalto==1 || dadomasalto==2)
                        {
                            cout<<"°°°El jugador 1, es decir: " << jugador1.nombre << " gana por sacar el dado mayor y comienza el juego°°°"<<endl<<endl;
                            turno1=jugador1.nombre;
                            turno2=jugador2.nombre;
                        }
                        else
                        {
                            cout <<"°°°El jugador 2, es decir: " << jugador2.nombre << " gana por sacar el dado mayor y comienza el juego°°°" <<endl<<endl;
                            turno1=jugador2.nombre;
                            turno2=jugador1.nombre;
                        }
                        banderainicio=true;
                    }
                    else
                    {
                        cout<<"\n---¡Empate! Vuelven a lanzar ---"<<endl;
                    }
                }
                //Si suma j1 es mayor
                else if (jugador1.sumaDado > jugador2.sumaDado)
                {
                    cout<<"°°°El jugador 1, es decir: " << jugador1.nombre << " gana y comienza el juego°°°"<<endl<<endl;
                    banderainicio=true;
                    turno1=jugador1.nombre;
                    turno2=jugador2.nombre;
                }
                //Si suma j2 es mayor
                else
                {
                    cout <<"°°°El jugador 2, es decir: " << jugador2.nombre << " gana y comienza el juego°°°" <<endl<<endl;
                    banderainicio=true;
                    turno1=jugador2.nombre;
                    turno2=jugador1.nombre;
                }
                system("pause");
                system ("cls");
            }

            //JUGADA PRINCIPAL

            for(int i = 0; i < turno; i++)
            {
                system("title JUEGO EL GRAN CERDO (°@°)~ Ahora sí. Vamos por esas Trufas!");
                //Resto: asigna si es 0 (par,j1) o 1(impar,j2).
                resto = i % 2;
                do
                {
                    tiraDeVuelta = 0;
                    finTurno=0;
                    lanzamientos[i]++;

                    if (resto == 0)
                    {
                        cout <<"Es el turno de : " << turno1 << endl << endl;
                    }
                    else
                    {
                        cout <<"Es el turno de : " << turno2 << endl << endl;
                    }
                    cout <<"Ronda # " << (i/2)+1 << endl; // Para saber en qué ronda está
                    cout <<"Lanzamiento: " <<lanzamientos[i] << endl;

                    /**
                     * @brief [8] Trufas auxiliares (se acumulan por ronda + las anteriores acumuladas, NO las totales porque las puede perder)
                     * usarDado3 Bandera que habilita el dado 3.
                     * flagd3 Bandera que muestra el mensaje de porque se habilito el dado 3.
                     */
                    if ((jugador1.trufasTotalesAux >50 && jugador2.trufasTotalesAux >50) || barro == 1)
                    {
                        usarDado3 = 1;
                        if(flagd3==0)
                        {
                            if(jugador1.trufasTotalesAux >50 && jugador2.trufasTotalesAux >50)
                            {
                                cout <<"Se han seperado las 50 trufas totales, se empieza a jugar con 3 dados!" << endl;
                            }
                            else
                            {
                                cout <<"Un jugador se hundió en el barro, se empieza a jugar con 3 dados!" << endl;
                            }
                            flagd3=1;
                        }
                    }

                    lanzamiento(dado1,dado2,dado3,usarDado3,jugador1.sumaDado);

                    /**
                     * @brief Condiciones con 3 dados
                     */

                    if(usarDado3==1)
                    {

                        //Si todos los dados son diferentes y ninguno es 1.
                        if((dado1!=dado2 || dado2!=dado3)&&dado1!=1&&dado2!=1&&dado3!=1)
                        {
                            trufas=dado1+dado2+dado3;
                            cout<<"La suma de los dados es: ["<<trufas<<"]"<<endl<<endl;
                        }
                        //Si todos son iguales y ninguno es 1.
                        else if(dado1==dado2&&dado2==dado3&&dado1!=1&&dado2!=1&&dado3!=1)
                        {
                            trufas=(dado1+dado2+dado3)*2;
                            cout<<"¡Dados iguales! Puntaje doble, sumas un oink y debes tirar nuevamente. La suma de los dados es: ["<<trufas<<"]"<<endl<<endl;
                            tiraDeVuelta=1;
                            //[7] Contador de Oinks
                            if(resto==0)
                            {
                                jugador1.Oink++;
                            }
                            else
                            {
                                jugador2.Oink++;
                            }
                        }
                        //Si todos los dados son 1
                        else if(dado1==1&&dado2==1&&dado3==1)
                        {
                            cout <<"¡Sacaste triple 1! Perdés todas tus trufas y pasan al otro jugador" << endl;
                            if(resto==0)
                            {
                                jugador2.trufasTotales+=jugador1.trufasTotalesAux; //Al contador de trufas totales del jugador 2, le acumulo las trufas aux del 1 (acumuladas + actual)
                                jugador2.trufasTotalesAux=jugador2.trufasTotales;
                                jugador1.trufasTotales=0;
                                jugador1.trufasTotalesAux=0;
                                jugador1.trufasRonda=0;
                                finTurno=1;
                                trufas=0;
                            }
                            else
                            {
                                jugador1.trufasTotales+=jugador2.trufasTotalesAux;
                                jugador1.trufasTotalesAux=jugador1.trufasTotales;
                                jugador2.trufasTotales=0;
                                jugador2.trufasTotalesAux=0;
                                jugador2.trufasRonda=0;
                                finTurno=1;
                                trufas=0;
                            }
                        }
                        //Si dos dados son 1
                        else if((dado1==1&&dado2==1)||(dado2==1&&dado3==1)||(dado1==1&&dado3==1))
                        {
                            barro=1;
                            trufas=0;
                            cout<<"¡Sacaste doble 1! Caíste en el barro =( Perdes tu turno y empezas nuevamente con cero trufas."<<endl<<endl;
                            if(resto==0)
                            {
                                jugador1.trufasTotales=0;
                                jugador1.trufasTotalesAux=0;
                                jugador1.trufasRonda=0;
                            }
                            else
                            {
                                jugador2.trufasTotales=0;
                                jugador2.trufasTotalesAux=0;
                                jugador2.trufasRonda=0;
                            }
                            finTurno=1;
                        }
                        //Un solo dado es 1
                        else
                        {
                            trufas=0;
                            cout <<"¡Sacaste un 1! Perdés tu turno y las trufas conseguidas en esta ronda."<<endl<<endl;
                            if(resto==0)
                            {
                                //Contador de trufas por ronda, subsisten las acumuladas.
                                jugador1.trufasRonda=0;
                            }
                            else
                            {
                                jugador2.trufasRonda=0;
                            }
                            finTurno=1;
                        }
                    }


                    /**
                     * @brief Validaciones solo con 2 dados.
                     */

                    else
                    {
                        //porky
                        if(dado1+1==dado2 || dado2+1==dado1)
                        {
                            if(banderaporky==false)
                            {
                                if(resto==0)
                                {
                                    jugador1.porky=1;
                                    banderaporky=true;
                                    cout << "El jugador " << turno1 << " obtubo el hito Porky!" << endl;
                                }
                                else
                                {
                                    jugador2.porky=1;
                                    banderaporky=true;
                                    cout << "El jugador " << turno2 << " obtubo el hito Porky!" << endl;
                                }
                            }
                        }
                        //Dados diferentes y niguno es 1
                        if(dado1!=dado2&&dado1!=1&&dado2!=1)
                        {
                            trufas=dado1+dado2;
                            cout<<"La suma de los dados es: ["<<trufas<<"]"<<endl<<endl;
                        }
                        //Dados iguales y niguno es 1
                        else if(dado1==dado2&&dado1!=1&&dado2!=1)
                        {
                            trufas=(dado1+dado2)*2;
                            cout<<"Dados iguales! Puntaje doble, sumas un oink! y debes tirar nuevamente. La suma de los dados es: ["<<trufas<<"]"<<endl<<endl;
                            tiraDeVuelta=1;
                            if(resto==0)
                            {
                                jugador1.Oink++;
                            }
                            else
                            {
                                jugador2.Oink++;
                            }
                        }
                        //Ambos 1
                        else if(dado1==1&&dado2==1)
                        {
                            barro=1;
                            trufas=0;
                            cout<<"Sacaste doble 1! Caíste en el barro =( Perdes tu turno y empezas nuevamente con cero trufas!"<<endl<<endl;
                            if(resto==0)
                            {
                                jugador1.trufasTotales=0;
                                jugador1.trufasTotalesAux=0;
                                jugador1.trufasRonda=0;
                            }
                            else
                            {
                                jugador2.trufasTotales=0;
                                jugador2.trufasTotalesAux=0;
                                jugador2.trufasRonda=0;
                            }
                            finTurno=1;
                        }
                        //Un solo 1
                        else
                        {
                            trufas=0;
                            cout <<"¡Sacaste un 1! Perdes tu turno y perdes las trufas conseguidas en esta ronda."<<endl<<endl;
                            if(resto==0)
                            {
                                jugador1.trufasRonda=0;
                            }
                            else
                            {
                                jugador2.trufasRonda=0;
                            }
                            finTurno=1;
                        }

                    }


                    /**
                     * @brief Información que se muestra luego de cada LANZAMIENTO (While).
                     */
                    cout <<"Sumaste " << trufas << " trufas" << endl;

                    /**
                    * @brief Lo que está en trufas de cada LANZAMIENTO (While), se acumula en el jugador correspondiente.
                    */
                    if(resto==0)
                    {
                        jugador1.trufasRonda+=trufas;
                        jugador1.trufasTotalesAux=jugador1.trufasRonda+jugador1.trufasTotales;
                        cout <<"LLevas " << jugador1.trufasRonda << " trufas acumuladas en esta ronda" << endl;
                    }
                    else
                    {
                        jugador2.trufasRonda+=trufas;
                        jugador2.trufasTotalesAux=jugador2.trufasRonda+jugador2.trufasTotales;
                        cout <<"LLevas " << jugador2.trufasRonda << " trufas acumuladas en esta ronda" << endl;
                    }
                    cout <<"Trufas totales: " << endl;
                    cout << turno1 << ": " << jugador1.trufasTotalesAux << " trufas" <<endl;
                    cout << turno2 << ": " << jugador2.trufasTotalesAux << " trufas" <<endl;

                    /**
                    * @brief Habilita la pregunta de continuar o no, dependiendo las banderas activas.
                    */

                    if(finTurno==0)
                    {
                        if(tiraDeVuelta==0)
                        {
                            do
                            {
                                cout <<"Desea continuar? (Escribir S/N)" << endl;
                                cin >> continua;
                                continua=toupper(continua);
                                banderacontinua=false;
                                system("cls");
                                switch(continua)
                                {
                                case 'S':

                                    banderacontinua=true;
                                    break;

                                case 'N':

                                    banderacontinua=true;
                                    finTurno=1;
                                    break;
                                default:

                                    cout <<"Opción no válida" << endl;
                                }
                            }
                            while(banderacontinua==false);
                        }
                        else
                        {
                            cout <<"Volvé a tirar!"<< endl;
                            system("pause");
                            system("cls");
                        }
                    }
                }

                while(finTurno == 0);

                /**
                * @brief Lo que está en trufas de cada RONDA (For), se acumula en el jugador correspondiente FINAL.
                */

                if(resto==0)
                {
                    jugador1.trufasTotales+=jugador1.trufasRonda;
                    jugador1.trufasRonda=0;
                }
                else
                {
                    jugador2.trufasTotales+=jugador2.trufasRonda;
                    jugador2.trufasRonda=0;
                }
                system("pause");
                system ("cls");
            }

            system("title JUEGO EL GRAN CERDO (°@°)~ Ha sido una Gran Partida donde ganó la Codicia!");
            cout <<"Termino la partida!" << endl << endl;
            system("pause");
            system ("cls");

            /**
            * @brief HITOS
            */
            rlutil::locate(5,2);
            cout <<"GRAN CERDO" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            rlutil::locate(5,5);
            cout <<"HITO: " << endl;
            rlutil::locate(45,5);
            cout << turno1 << endl;
            rlutil::locate(85,5);
            cout << turno2 << endl;
            rlutil::locate(1,6);
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl ;
            rlutil::locate(5,7);
            cout <<"Más trufas en total" << endl;

            //HITO 1: MAYOR CANTIDAD DE TRUFAS (+5PDV /0PDV O 5/5PDV)
            if(jugador1.trufasTotales>jugador2.trufasTotales)
            {
                jugador1.PDV=jugador1.PDV + 5;
                rlutil::locate(45,7);
                cout << "5 PDV (" << jugador1.trufasTotales << " trufas)" << endl;
                rlutil::locate(85,7);
                cout << "0 PDV (" << jugador2.trufasTotales << " trufas)" << endl;
            }
            else if(jugador2.trufasTotales>jugador1.trufasTotales)
            {
                jugador2.PDV=jugador2.PDV + 5;
                rlutil::locate(45,7);
                cout << "0 PDV (" << jugador1.trufasTotales << " trufas)" << endl;
                rlutil::locate(85,7);
                cout << "5 PDV (" << jugador2.trufasTotales << " trufas)" << endl;
            }
            else
            {
                jugador1.PDV=jugador1.PDV + 5;
                jugador2.PDV=jugador2.PDV + 5;
                rlutil::locate(45,7);
                cout << "5 PDV (" << jugador1.trufasTotales << " trufas)" << endl;
                rlutil::locate(85,7);
                cout << "5 PDV (" << jugador2.trufasTotales << " trufas)" << endl;
            }

            //HITO 2: CADA 50 TRUFAS (+1PDV)
            jugador1.PDV50Trufas=jugador1.trufasTotales/50;
            jugador2.PDV50Trufas=jugador2.trufasTotales/50;
            jugador1.PDV+=jugador1.PDV50Trufas;
            jugador2.PDV+=jugador2.PDV50Trufas;

            rlutil::locate(5,8);
            cout << "Cada 50 trufas" << endl;
            rlutil::locate(45,8);
            cout << jugador1.PDV50Trufas << " PDV (" << jugador1.trufasTotales << " trufas)" << endl;
            rlutil::locate(85,8);
            cout << jugador2.PDV50Trufas << " PDV (" << jugador2.trufasTotales << " trufas)" << endl;

            //HITO 3: POR CADA OINK (+2PDV)

            jugador1.PDV+=jugador1.Oink*2;
            jugador2.PDV+=jugador2.Oink*2;

            rlutil::locate(5,9);
            cout << "Oinks" << endl;
            rlutil::locate(45,9);
            cout << jugador1.Oink*2 << " PDV (" << jugador1.Oink << " Oinks)" << endl;
            rlutil::locate(85,9);
            cout <<  jugador2.Oink*2 << " PDV (" << jugador2.Oink << " Oinks)" << endl;

            //HITO 4: MAYOR LANZAMIENTOS EN UNA SOLA RONDA (+3PDV o 3/3)
            rlutil::locate(5,10);
            cout << "Cerdo codicioso" << endl;
            jugador1.MaxLanzamiento=lanzamientos[0];
            jugador2.MaxLanzamiento=lanzamientos[1];
            //Cual fue el mayor lanzamiento de j1
            for(i=2; i<10; i=i+2)
            {
                if(lanzamientos[i]>jugador1.MaxLanzamiento)
                {
                    jugador1.MaxLanzamiento=lanzamientos[i];

                }
            }
            //Cual fue el mayor lanzamiento de j2
            for(i=3; i<10; i=i+2)
            {
                if(lanzamientos[i]>jugador2.MaxLanzamiento)
                {
                    jugador2.MaxLanzamiento=lanzamientos[i];
                }
            }

            //Cual fue el mayor lanzamiento de entre los dos max
            if(jugador1.MaxLanzamiento>jugador2.MaxLanzamiento)
            {
                jugador1.PDV+=3;
                rlutil::locate(45,10);
                cout << "3 PDV (" << jugador1.MaxLanzamiento << " lanzamientos)" << endl;
                rlutil::locate(85,10);
                cout << "0 PDV (" << jugador2.MaxLanzamiento << " lanzamientos)" << endl;

            }
            else if(jugador1.MaxLanzamiento<jugador2.MaxLanzamiento)
            {
                jugador2.PDV+=3;
                rlutil::locate(45,10);
                cout << "0 PDV (" << jugador1.MaxLanzamiento << " lanzamientos)" << endl;
                rlutil::locate(85,10);
                cout << "3 PDV (" << jugador2.MaxLanzamiento << " lanzamientos)" << endl;
            }
            else
            {
                jugador1.PDV+=3;
                jugador2.PDV+=3;
                rlutil::locate(45,10);
                cout << "3 PDV (" << jugador1.MaxLanzamiento << " lanzamientos)" << endl;
                rlutil::locate(85,10);
                cout << "3 PDV (" << jugador2.MaxLanzamiento << " lanzamientos)" << endl;
            }
            rlutil::locate(5,11);
            cout << "porky";
            if(jugador1.porky==1)
            {
                rlutil::locate(45,11);
                cout << "1 PDV";
                jugador1.PDV++;
                if(jugador2.PDV>=1 && jugador2.PDV<=9)
                {
                    jugador2.PDV-=1;
                    rlutil::locate(85,11);
                    cout << "-1 PDV";
                }
                else if(jugador2.PDV>=10 && jugador2.PDV<=15)
                {
                    jugador2.PDV-=2;
                    rlutil::locate(85,11);
                    cout << "-2 PDV";
                }
                else if(jugador2.PDV>15)
                {
                    jugador2.PDV-=3;
                    rlutil::locate(85,11);
                    cout << "-3 PDV";
                }

            }
            else if(jugador2.porky==1)
            {
                rlutil::locate(85,11);
                cout << "1 PDV";
                jugador2.PDV++;
                if(jugador1.PDV>=1 && jugador1.PDV<=9)
                {
                    jugador1.PDV-=1;
                    rlutil::locate(45,11);
                    cout << "-1 PDV";
                }
                else if(jugador1.PDV>=10 && jugador1.PDV<=15)
                {
                    jugador1.PDV-=2;
                    rlutil::locate(45,11);
                    cout << "-2 PDV";
                }
                else if(jugador1.PDV>15)
                {
                    jugador1.PDV-=3;
                    rlutil::locate(45,11);
                    cout << "-3 PDV";
                }


            }
            else
            {
                rlutil::locate(45,11);
                cout << "0 PDV";
                rlutil::locate(85,11);
                cout << "0 PDV";
            }

            rlutil::locate(1,12);
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl ;

            //RESULTADO FINAL:
            rlutil::locate(5,13);
            cout << "TOTAL";
            rlutil::locate(45,13);
            cout << jugador1.PDV << " PDV" << endl;
            rlutil::locate(85,13);
            cout << jugador2.PDV << " PDV" << endl;

            cout << endl << endl;
            if(jugador1.PDV>jugador2.PDV)
            {

                cout <<"GANADOR: " << turno1 << " con " << jugador1.PDV << " puntos de victoria" <<endl;
            }
            else if(jugador2.PDV>jugador1.PDV)
            {

                cout <<"GANADOR: " << turno2 << " con " << jugador2.PDV << " puntos de victoria" <<endl;
            }
            else
            {
                cout <<"Empataron con: " << jugador1.PDV << " puntos de victoria" << endl;
            }

            system("pause");
            system("cls");
            system("title JUEGO EL GRAN CERDO (°@°)~ ");
            break;

        /**
        * @brief Estadísticas
        */

        case 2:
            system("title JUEGO EL GRAN CERDO (°@°)~ Estadísticas");
            system("cls");
            //Define si se jugo una partida o no
            if(banderainfo==true)
            {
                //Unica partida
                if(banderaestadistica==false)
                {
                    if(jugador1.PDV>jugador2.PDV)
                    {
                        puntmax=jugador1.PDV;
                        nombremax=turno1;
                        banderaestadistica=true;
                    }
                    else
                    {
                        puntmax=jugador2.PDV;
                        nombremax=turno2;
                        banderaestadistica=true;
                    }

                    //Varias partidas
                    if(jugador1.PDV>puntmax)
                    {
                        puntmax=jugador1.PDV;
                        nombremax=turno1;
                    }
                    else if(jugador2.PDV>puntmax)
                    {
                        puntmax=jugador2.PDV;
                        nombremax=turno2;
                    }

                }
                cout <<"ESTADISTICAS!!" << endl;
                cout <<"El jugador " << nombremax << " tiene el record de Puntos de Victoria con " << puntmax << " puntos" << endl;
            }
            else
            {
                cout <<"Aún no se jugo ninguna partida" << endl;
            }
            system("pause");
            system("cls");
            system("title JUEGO EL GRAN CERDO (°@°)~ ");
            break;

        /**
        * @brief Cerditos
        */

        case 3:
            system("title JUEGO EL GRAN CERDO (°@°)~ A este Equipo Codicioso lo forman!");
            system("cls");
            cout <<"CERDITOS participantes: " << endl;
            cout <<"Pinto, Carlos Alberto. Legajo: 26920" << endl;
            cout <<"Visconti, Maria Clara. Legajo: 26826" << endl;
            cout <<"Yoppi, Yesica Noemi. Legajo: 26811" << endl;
            cout <<"Clingo, Fernando Daniel. Legajo: 26859" << endl;
            cout <<"Lancieri, Constanza. Legajo: 26929" << endl;
            cout <<"Nombre del equipo: Los gameboy de Clara" << endl;
            system("pause");
            system("cls");
            system("title JUEGO EL GRAN CERDO (°@°)~ ");
            break;

        /**
        * @brief Salir
        */

        case 0:
            cout <<"¿Querés salir? (S/N)" << endl;
            cin >> salir;
            salir=toupper(salir);
            if(salir=='S')
            {
                cout <<"¿Estás seguro?(S/N)"<< endl;
                cin >> salir;
                salir=toupper(salir);
                if(salir=='S')
                {
                    banderasalir=true;
                }
            }
            system("title JUEGO EL GRAN CERDO (°@°)~ ");
            break;
        }
    }
    while(banderasalir==false);


    return 0;
}
