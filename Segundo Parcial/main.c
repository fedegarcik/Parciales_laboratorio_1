#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "EntradaySalida.h"
#include "Concursante.h"

/*
Tema:1
Nombre :Federico Garcik
*/

int main()
{
    LinkedList* pArrayConcursantes;
    LinkedList* pArrayConcursantesGanadoresPrimeraRonda;
    LinkedList* pArrayConcursantesGanadoresTerceraRonda;


    pArrayConcursantes = ll_newLinkedList();
    pArrayConcursantesGanadoresPrimeraRonda = ll_newLinkedList();
    pArrayConcursantesGanadoresTerceraRonda = ll_newLinkedList();


    int opcion;




    int banderaSegundaRonda;
    int banderaTerceraRonda;

    banderaTerceraRonda = 0;
    banderaSegundaRonda = 0;

    do
    {

        system("cls");
        printf("1 Cargar datos\n");
        printf("2 Mostrar datos\n");
        printf("3 Calcular Segunda Ronda\n");
        printf("4 Guardar Datos\n");
        printf("5 Guardar Aprobados mas de 80 primera ronda\n");
        printf("6 Guardar ganadores primera ronda\n");
        printf("7 Listar ganadores tercera Ronda\n");
        printf("8 Obtener ganadores primer ronda\n");
        printf("9 Obtener ganadores tercer ronda\n");
        printf("10 Calcular Tercera Ronda\n");
        printf("11 Listar ganadores primera ronda\n");
        printf("12 Guardar ganadores tercera ronda\n");
        printf("13 Salir\n");
        printf("Ingrese una opcion\n");
        scanf("%d", &opcion);


        switch(opcion)
        {
            case 1:
                controller_loadFromText(pArrayConcursantes);
                AprieteEnter();
                break;
            case 2:
                if(banderaSegundaRonda == 1 && banderaTerceraRonda == 1)
                {
                    controller_ListEmployee(pArrayConcursantes);
                }
                else
                {
                    printf("calcule primero los puntajes de la segunda ronda y tercera ronda\n");
                }
                AprieteEnter();
                break;
            case 3:
                if(ll_isEmpty(pArrayConcursantes) == 0)
                {
                    ll_map(pArrayConcursantes, calcularSegundaRonda);


                    banderaSegundaRonda = 1;
                }
                else
                {
                    printf("cargue primero los datos\n");
                }
                AprieteEnter();
                break;
            case 4:
                if(banderaSegundaRonda == 1 && banderaTerceraRonda == 1)
                {
                    controller_SaveAsText("resultado2doparcial.csv", pArrayConcursantes);
                }
                else
                {
                    printf("calcule primero los puntajes de la segunda ronda y tercera ronda\n");
                }
                AprieteEnter();
                break;
            case 5:
                if(ll_isEmpty(pArrayConcursantes) == 0)
                {
                    controler_saveAproved(pArrayConcursantes);
                }
                else
                {
                    printf("cargue primero los datos\n");
                }
                AprieteEnter();
                break;
            case 6:
                if(ll_isEmpty(pArrayConcursantesGanadoresPrimeraRonda) == 0)
                {

                    controller_SaveWinners(pArrayConcursantesGanadoresPrimeraRonda);
                }
                else
                {
                    printf("primero obtenga a los finalistas de la primera ronda\n");
                }
                AprieteEnter();
                break;
            case 7:
                if(banderaSegundaRonda == 1 && banderaTerceraRonda == 1 && ll_isEmpty(pArrayConcursantesGanadoresTerceraRonda) == 0)
                {

                    controller_ListEmployee(pArrayConcursantesGanadoresTerceraRonda);
                }
                else
                {
                    printf("calcule primero los puntajes de la segunda ronda y tercera ronda y obtenga a los finalistas de la tercera ronda\n");
                }
                AprieteEnter();
                break;
            case 8:
                pArrayConcursantesGanadoresPrimeraRonda = ll_filterV2(pArrayConcursantes, sacarFinalistasPrimeraRonda, sacarGanadorPrimeraRonda);
                AprieteEnter();
                break;
            case 9:
                pArrayConcursantesGanadoresTerceraRonda = ll_filterV2(pArrayConcursantes, sacarFinalistasTerceraRonda, sacarGanadorTerceraRonda);
                AprieteEnter();
                break;
            case 10:
                if(ll_isEmpty(pArrayConcursantes) == 0)
                {
                    ll_map(pArrayConcursantes, calcularTerceraRonda);
                    banderaTerceraRonda = 1;
                }
                AprieteEnter();
                break;
            case 11:
                if(banderaSegundaRonda == 1 && banderaTerceraRonda == 1 && ll_isEmpty(pArrayConcursantesGanadoresPrimeraRonda) == 0)
                {
                    controller_ListEmployee(pArrayConcursantesGanadoresPrimeraRonda);
                }
                else
                {
                    printf("calcule primero los puntajes de la segunda ronda y tercera ronda y obtenga a los finalistas de la primera ronda\n");
                }
                AprieteEnter();
                break;
            case 12:
                if(ll_isEmpty(pArrayConcursantesGanadoresTerceraRonda) == 0)
                {

                    controller_SaveWinners(pArrayConcursantesGanadoresTerceraRonda);
                }
                else
                {
                    printf("Cargue primero los datos\n");
                }
                AprieteEnter();
                break;
            case 13:
                printf("Gracias por usar el programa");
                AprieteEnter();
                break;
            default:
                printf("Esa no es una opcion valida");
                break;

        }
    }while(opcion != 13);


    return 0;
}
