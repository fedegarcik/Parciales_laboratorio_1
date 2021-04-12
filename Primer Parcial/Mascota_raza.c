
#include <stdlib.h>
#include <stdio.h>
#include "EntradaySalida.h"
#include "Mascotas.h"
#include "Raza.h"
#include "Pais.h"
#include "Mascota_raza.h"
#include "Pais_mascota.h"
#include <ctype.h>

 //Funcion que devuelva la raza


void MostrarRazaConMascotas(eRaza razas[], eMascota mascotas[], int cantidadMascotas, int cantidadRazas)
{
    int i;


    //For para recorrer el array de razas
    for(i=0; i<cantidadRazas; i++)
    {
        if(razas[i].estado == 1)
        {
            printf("===================== RAZA ==========================\n");
            printf("Descripcion:   ");
            printf("Tamanio:        ");
            printf("Origen:\n");
            //Muestro la raza
            MostrarRaza(razas[i]);
            printf("\n");

            printf("-----------------------------------------------------\n");
            //Muestro todas las mascotas correspondientes a la raza
            MostarMascotasPorId(razas[i].idRaza, mascotas, cantidadMascotas);
            //printf("\n");
            printf("\n");

        }

    }
}


void MostrarMascotaConRaza(eRaza razas[], eMascota mascotas[], int cantidadMascotas, int cantidadRazas)
{
    int i;
    int j;
    printf("Id:    ");
    printf("Nombre:        ");
    printf("Sexo:   ");
    printf("Edad:    ");
    printf("Peso:     ");
    printf("Tipo:        ");
    printf("Descripcion:          ");
    printf("Origen:\n");

    for(i=0; i<cantidadMascotas; i++)
    {

        MostrarMascota(mascotas[i]);


        j = BuscarRazaPorId(mascotas[i].idRaza ,razas, cantidadRazas);
        if(j != -1)
        {
            printf("%-15s      ", razas[j].descripcion);
            printf("%-15s\n", razas[j].origen);
            //MostrarRaza(razas[j]);
        }

    }
}


void Menu(eMascota mascotas[], eRaza razas[], ePaisAux paisAux[], ePais paises[], int cantidadMascotas, int cantidadRazas, int cantidadPaises)
{
    char subOpcion;
    char opcionAux[CANTIDAD_ARRAY];
    int opcion;
    int indice;
    int indiceId;

    inicializarMascotas(mascotas, cantidadMascotas);
    inciliazarRazas(razas, cantidadRazas);
    HardcodearPais(paises);
    HardcodearMascotas(mascotas);
    HardcodearRazas(razas);



    do
    {


        //Limpio la pantalla
        system("cls");

        //Muestro primeras opciones
        printf("1_Cargar mascota\n");
        printf("2_Modificar mascota\n");
        printf("3_Dar de baja mascota\n");
        printf("4_Informar\n");
        printf("5_Cargar raza\n");
        printf("6_Salir\n");

        //Ingreso la opcion y valido que sea un numero
        IngresarDatoCadenaCaracteres(opcionAux, "Ingrese una opcion por favor: \n");
        opcion = ValidarNumeroEntero(opcionAux);

        switch(opcion)
        {
            case 1:
                indice = ObtenerEspacioLibreMascota(mascotas, cantidadMascotas);
                CargarMascota(mascotas, razas, cantidadMascotas, cantidadRazas, indice);
                AprieteEnter();
                break;
            case 2:
                indiceId = BuscarPorId(mascotas, cantidadMascotas);
                if(indiceId == -1)
                {
                    printf("ERROR, no se encontro el id");
                    AprieteEnter();
                }
                else
                {
                    ModificarMascota(mascotas, razas, cantidadRazas, indiceId);
                    //ModificarEmpleado(empleados, CANTIDAD_EMPLEADOS, indiceId);
                }
                break;
            case 3:
                //case remover


                indiceId = BuscarPorId(mascotas, cantidadMascotas);
                if(indiceId == -1)
                {
                    AprieteEnter();
                }
                else
                {
                    RemoverMascota(mascotas, cantidadMascotas, indiceId);
                    AprieteEnter();
                }

                break;
            case 4:
                //Sub menu para elegir de que manera listar las mascotas
                printf("A_Listar Mascotas\n");
                printf("B_Listar Razas\n");
                printf("C_Listar Mascota con Raza y Paises de Origen\n");
                printf("D_Listar Raza con Mascota\n");
                printf("E_Listar Ordenadas por Peso\n");
                printf("F_Mostrar pais con mas mascotas\n");
                printf("G_Listar raza con pais\n");
                printf("H_Ordenar por numero de zona\n");

                printf("Ingrese una opcion por favor: \n");
                fflush(stdin);
                scanf("%c", &subOpcion);

                subOpcion = toupper(subOpcion);

                switch(subOpcion)
                {
                    case 'A':
                        MostrarMascotas(mascotas, cantidadMascotas);
                        AprieteEnter();
                        break;
                    case 'B':
                        MostrarRazas(razas, cantidadRazas);
                        AprieteEnter();
                        break;
                    case 'C':
                        MostrarMascotaConRaza(razas, mascotas, cantidadMascotas, cantidadRazas);
                        AprieteEnter();
                        break;
                    case 'D':
                        MostrarRazaConMascotas(razas, mascotas, cantidadMascotas, cantidadRazas);
                        AprieteEnter();
                        break;
                    case 'E':
                        OrdenarPorPeso(mascotas, cantidadMascotas);
                        MostrarMascotas(mascotas, cantidadMascotas);
                        AprieteEnter();
                        break;
                    case 'F':
                        ObtenerPaisMaximo(mascotas, razas, paisAux, cantidadMascotas, cantidadRazas);
                        AprieteEnter();
                        break;
                    case 'G':
                        ListarRazaConPais(paises, razas, cantidadRazas, cantidadPaises);
                        AprieteEnter();
                        break;
                    case 'H':
                        OrdenarPorTel(paises,razas,mascotas,cantidadMascotas,cantidadRazas,cantidadPaises);
                        AprieteEnter();
                        break;
                    //Caso en el que no se ingresa opcion valida
                    default:
                        printf("ERROR eso no es una opcion valida\n");
                        AprieteEnter();
                        break;

                }
                break;
            case 5:
                indice = ObtenerEspacioLibreRaza(razas, CANTIDAD_RAZAS);
                CargarRaza(razas, CANTIDAD_RAZAS, indice, paises, CANTIDAD_HARDCODEO_PAIS);
                AprieteEnter();
                break;
            //Caso en el que no se ingresa una opcion valida
            case 6:
                printf("Gracias por usar el programa!\n");
                AprieteEnter();
                break;
            default:
            printf("ERROR esa no es una opcion valida:\n");
            AprieteEnter();
            break;
        }
    }while(opcion != 6);
}

