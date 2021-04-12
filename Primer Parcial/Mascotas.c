#define CANTIDAD_MASCOTAS_HARDCODEO 7
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include <ctype.h>
#include "Mascotas.h"
#include "EntradaySalida.h"


void HardcodearMascotas(eMascota mascotas[])
{

    //Defino los valores que voy a hardcodear
    int idMascota[CANTIDAD_MASCOTAS_HARDCODEO]   = {1, 2, 3, 4, 5, 6, 7};//,6,7,8,9,10};
    int idRaza[CANTIDAD_MASCOTAS_HARDCODEO]      = {1,2,4,2,1,5,6};//0,0,0,0,0};
    int edad[CANTIDAD_MASCOTAS_HARDCODEO]        = {4,3,10,8,7,10,9};//,1,1,1,1,1};
    int sexo[CANTIDAD_MASCOTAS_HARDCODEO]        = {'f','m','f','m','f','m','m'};//,'f','f','f','f'};
    char tipo[CANTIDAD_MASCOTAS_HARDCODEO][30]   = {"gato","gato","perro","gato","perro","perro","perro"};//,"gato","gato","gato","gato","gato"};
    char nombre[CANTIDAD_MASCOTAS_HARDCODEO][30] = {"jorge","jose","antonio","luis","pepe","luis","rodrigo"};//,"gato","gato","gato","gato","gato"};
    int estado[CANTIDAD_MASCOTAS_HARDCODEO]      = {1,1,1,1,1,1,1};
    int peso[CANTIDAD_MASCOTAS_HARDCODEO]        = {20,30,40,50,45,10,15};
    int i;

    //Cargo los valores al array a travez de un for
    for(i=0; i<CANTIDAD_MASCOTAS_HARDCODEO; i++)
    {
        mascotas[i].idMascota = idMascota[i];
        mascotas[i].idRaza    = idRaza[i];
        mascotas[i].edad      = edad[i];
        mascotas[i].peso      = peso[i];
        mascotas[i].sexo      = sexo[i];
        strcpy(mascotas[i].tipo,tipo[i]);
        mascotas[i].estado    = estado[i];
        strcpy(mascotas[i].nombre, nombre[i]);
    }

}

void MostrarMascota(eMascota mascota)
{




    //Pregunto si la mascota esta dada de alta
    if(mascota.estado == 1)
    {
        //Si la mascota es dada de alta la muestro
        printf("%-8d", mascota.idMascota);
        //printf("%-8d", mascota.idRaza);
        printf("%-15s", mascota.nombre);
        printf("%-8c", mascota.sexo);
        printf("%-8d", mascota.edad);
        printf("kg%-8d", mascota.peso);
        printf("%-15s", mascota.tipo);
    }

}

void CargarMascota(eMascota mascotas[], eRaza razas[], int cantidadMascotas, int cantidadRazas, int indice)
{

    //Array auxiliares para validacion
    char edadAux[CANTIDAD_ARRAY];
    char pesoAux[CANTIDAD_ARRAY];
    char idAux[CANTIDAD_ARRAY];
    int idMaximo;
    int i;

    //Inicializo el id maximo en 0 para evitar errores
    idMaximo = 0;

    //Pregunto si hay espacio libre de no haberlo no se carga la mascota
    if(indice == -1)
    {
        printf("ERROR NO HAY MAS ESPACIO PARA MASCOTAS NUEVAS\n");
    }
    else
    {
        MostrarRazas(razas, cantidadRazas);
        //Ingreso el id de la raza

        IngresarDatoCadenaCaracteres(idAux,"Ingrese el id raza de la mascota");
        mascotas[indice].idRaza = ValidarNumeroEntero(idAux);
        while(mascotas[indice].idRaza < 1 ||
              BuscarRazaPorId(mascotas[indice].idRaza, razas, cantidadRazas) == -1)
        {
            IngresarDatoCadenaCaracteres(idAux,"ERROR, la raza no existe reingrese el id raza de la mascota");
            mascotas[indice].idRaza = ValidarNumeroEntero(idAux);
        }


        //Ingreso el nombre de la mascota
        IngresarDatoCadenaCaracteres(mascotas[indice].nombre,"Ingrese el nombre de la mascota");


        mascotas[indice].sexo = IngresarCaracter("ingrese el sexo de la mascota");
        mascotas[indice].sexo = tolower(mascotas[indice].sexo);
        while(mascotas[indice].sexo != 'm' &&
              mascotas[indice].sexo != 'f')
        {
            mascotas[indice].sexo = IngresarCaracter("ERROR, reingrese el sexo de la mascota");
            mascotas[indice].sexo = tolower(mascotas[indice].sexo);
        }

        //Ingreso la edad de la mascota y la valido
        IngresarDatoCadenaCaracteres(edadAux,"Ingrese la edad de la mascota");
        mascotas[indice].edad = ValidarNumeroEntero(edadAux);

        //Ingreso el peso de la mascota y la valido
        IngresarDatoCadenaCaracteres(pesoAux,"Ingrese el peso de la mascota");
        mascotas[indice].peso = ValidarNumeroEntero(pesoAux);

        //Ingreso el tipo de la mascota
        IngresarDatoCadenaCaracteres(mascotas[indice].tipo,"Ingrese el tipo de mascota,'gato', 'perro' o 'raro'");
        strlwr(mascotas[indice].tipo);
        while(strcmp(mascotas[indice].tipo, "gato")  != 0 &&
              strcmp(mascotas[indice].tipo, "perro") != 0 &&
              strcmp(mascotas[indice].tipo, "raro")  != 0)
        {
            IngresarDatoCadenaCaracteres(mascotas[indice].tipo,"Error, reingrese el tipo , 'gato', 'perro' o 'raro'");
            strlwr(mascotas[indice].tipo);
        }


        //Recorro el array de mascotas buscando el id maximo
        for(i = 0; i<cantidadMascotas; i++)
        {
            if(mascotas[i].idMascota > idMaximo)
            {
                idMaximo = mascotas[i].idMascota;
            }
        }

        //El id de la mascota ingresada va a ser igual al id maximo +1 ej: idMax = 5, nuevoId = 6
        mascotas[indice].idMascota = idMaximo + 1;

        //Doy de alta logica la mascota
        mascotas[indice].estado = 1;
    }

}

void MostrarMascotas(eMascota mascotas[], int cantidad)
{
    int i;


    printf("id     ");
    //printf("id raza   ");
    printf("nombre        ");
    printf("sexo      ");
    printf("edad    ");
    printf("peso      ");
    printf("tipo    \n");

    //Recorro todo el array de las mascotas mostrandolas
    for(i= 0; i < cantidad; i ++)
    {
        //Pregunto si esta dada de alta la mascota antes de mostrar
        if(mascotas[i].estado == 1)
        {
            MostrarMascota(mascotas[i]);
            printf("\n");
        }
    }
}

int BuscarPorId(eMascota mascotas[], int capacidad)
{
    int i;
    int idBusqueda;
    int flagId;
    int retorno;

    retorno = -1;
    flagId = 0;
    //Se pide ingresar el id de la mascota a buscar
    printf("ingrese el id de la mascota a buscar: \n");
    scanf("%d", &idBusqueda);


    //Bucle for que reccore todo el array de mascotas en busca de una coincidencia del id ingresado
    for(i = 0; i<capacidad; i++)
    {
        //En caso de coincidencia se muestra la mascota y se almacena en la variable de retorno el indice de la mascota
        if(idBusqueda == mascotas[i].idMascota)
        {
            flagId = 1;
            retorno = i;
             /*
            Es de observar que la juistificacion esta en negativo ya que en positivo no da el formato deseado, no se sabe el motivo sin embargo funciona
            se supone que justifica en vez de a la derecha hacia la izquierda asi que se toma como solucion
            */
            printf("La mascota encontrada es: \n");
            printf("id     ");
            printf("nombre         ");
            printf("sexo    ");
            printf("edad     ");
            printf("tipo       \n");
            MostrarMascota(mascotas[i]);
            printf("\n");
            break;
       }
    }


    //En caso de no encontrar coincidencia muestra mensaje de error y se retorna -1
    if(flagId == 0)
    {
        printf("Error, no existe el id\n");
    }



    return retorno;
}

int RemoverMascota(eMascota mascotas[], int capacidad, int indice)
{

    int confirmacion;
    int retorno;

    //Establezco el retorno en caso de error en 0
    retorno = 0;

    //Pregunto si se pudo encontrar el id
    if(indice != -1)
    {

        //Pido una confirmacion de parte del usuario antes de eliminar la mascota
        confirmacion = IngresarNumeroEntero("Esta seguro que desea borrar a la mascota? 1 para si 0 para no");
        while(confirmacion != 0 &&
              confirmacion != 1)
        {
            //En caso de haber ingresado un numero no valido como confirmacion le pido que reingrese
            confirmacion = IngresarNumeroEntero("ERROR NUMERO NO VALIDO 1 para si 0 para no");
        }


        //Si la confirmacion fue positiva se da la baja logica
        if(confirmacion == 1)
        {
            //Se cambia el retorno a 1
            retorno = 1;
            mascotas[indice].estado = 0;
        }
    }




    return retorno;
}

int inicializarMascotas(eMascota mascotas[], int capacidad)
{

    int i;
    int retorno;



    //Se establece el retorno en caso de error en -1
    retorno = -1;

    //Me fijo que la capacidad de array pasada como parametro no sea mayor a la del array
    if(capacidad <= CANTIDAD_MASCOTAS)
    {

        //Inicializo la variable de estado y los id para no tener valores basuras y que comienzen  todos dados de baja y con su id en 0
        for(i = 0; i < capacidad ; i++)
        {
            mascotas[i].estado = 0;
            mascotas[i].idMascota = 0;
        }
        retorno = 0;
    }
    return retorno;
}



int ObtenerEspacioLibreMascota(eMascota mascotas[], int capacidad)
{
    int i;
    int banderaEspacioLibre;

    banderaEspacioLibre = 0;

    //Busco en el array cual es el espacio libre
    for(i = 0; i<capacidad; i++)
    {
        if(mascotas[i].estado == 0)
        {
            banderaEspacioLibre  = 1;

            break;
        }
    }

    //En caso de no encontrar espacio se devuelve -1 como error
    if(banderaEspacioLibre == 0)
    {
        i = -1;
    }
    return i;
}

int OrdenarPorPeso(eMascota mascotas[], int cantidad)
{
    int i;
    int j;
    eMascota mascotaAux;
    int retorno;

    //Establezco el retorno en caso de error en 0
    retorno = 0;


    //Burbuejo que ordena el peso de mayor a menor
    for(i = 0; i < cantidad; i++)
    {
        for(j = i+1; j < cantidad; j++)
        {
            if(mascotas[i].estado == 1 && mascotas[i].peso < mascotas[j].peso)
            {
                mascotaAux  = mascotas[i];
                mascotas[i] = mascotas[j];
                mascotas[j] = mascotaAux;

                retorno = 1;
            }
        }
    }
    return retorno;
}

int MostarMascotasPorId(int idRaza, eMascota mascotas[], int cantidadMascotas)
{
    int i;
    int retorno;

    //Establezco el retorno en caso de error en -1
    retorno = -1;

    printf("  Id:     ");
    printf("Nombre:       ");
    printf("Sexo:   ");
    printf("Edad:    ");
    printf("Peso:     ");
    printf("Tipo:        \n");

    //Recorro todo el array de mascotas
    for(i=0; i<cantidadMascotas; i++)
    {
        //Pregutno si la mascota esta dada de alta  y si el id de raza coincide con el de la mascota
        if(mascotas[i].estado == 1 && idRaza == mascotas[i].idRaza)
        {
            //En caso de cumplirse la condicion muestro la mascota
            printf("* ");
            MostrarMascota(mascotas[i]);
            printf("\n");
            retorno = 0;
        }
    }

    return retorno;
}

void ModificarMascota(eMascota mascotas[], eRaza razas[], int cantidadRazas, int indice)
{
    char edadAux[CANTIDAD_ARRAY];
    char pesoAux[CANTIDAD_ARRAY];
    char idAux[CANTIDAD_ARRAY];
    char nombreAux[CANTIDAD_ARRAY];

/*
    confirmacion = IngresarNumeroEntero("Esta seguro que desea modificar a la mascota? 1 para si 0 para no");
    while(confirmacion != 0 &&
          confirmacion != 1)
    {
        //En caso de haber ingresado un numero no valido como confirmacion le pido que reingrese
        confirmacion = IngresarNumeroEntero("ERROR NUMERO NO VALIDO 1 para si 0 para no");
    }
    */

    MostrarRazas(razas, cantidadRazas);


    IngresarDatoCadenaCaracteres(idAux,"Ingrese el id raza de la mascota");
    mascotas[indice].idRaza = ValidarNumeroEntero(idAux);
    while(mascotas[indice].idRaza < 1 ||
          BuscarRazaPorId(mascotas[indice].idRaza, razas, cantidadRazas) == -1)
    {
        IngresarDatoCadenaCaracteres(idAux,"ERROR, la raza no existe reingrese el id raza de la mascota");
        mascotas[indice].idRaza = ValidarNumeroEntero(idAux);
    }


    printf("Id: %-8d\n", mascotas[indice].idMascota);

    printf("Nombre : %-15s\n", mascotas[indice].nombre);
    IngresarDatoCadenaCaracteres(nombreAux,"Ingrese el nuevo nombre de la mascota o enter para mantener el antiguo");
    if(strcmp(nombreAux, "") != 0)
    {
        strcpy(mascotas[indice].nombre, nombreAux);
    }


    printf("Sexo: %-8c\n", mascotas[indice].sexo);
    mascotas[indice].sexo = IngresarCaracter("ingrese el sexo de la mascota");
    mascotas[indice].sexo = tolower(mascotas[indice].sexo);
    while(mascotas[indice].sexo != 'm' &&
          mascotas[indice].sexo != 'f')
    {
        mascotas[indice].sexo = IngresarCaracter("ERROR, reingrese el sexo de la mascota");
        mascotas[indice].sexo = tolower(mascotas[indice].sexo);
    }

    printf("Edad: %-8d\n", mascotas[indice].edad);
    IngresarDatoCadenaCaracteres(edadAux,"Ingrese la edad de la mascota");
    mascotas[indice].edad = ValidarNumeroEntero(edadAux);

    printf("Peso : kg%-8d\n", mascotas[indice].peso);
    IngresarDatoCadenaCaracteres(pesoAux,"Ingrese el peso de la mascota");
    mascotas[indice].peso = ValidarNumeroEntero(pesoAux);

    printf("Tipo : %-15s\n", mascotas[indice].tipo);
    IngresarDatoCadenaCaracteres(mascotas[indice].tipo,"Ingrese el tipo de mascota,'gato', 'perro' o 'raro'");
    strlwr(mascotas[indice].tipo);
    while(strcmp(mascotas[indice].tipo, "gato")  != 0 &&
          strcmp(mascotas[indice].tipo, "perro") != 0 &&
          strcmp(mascotas[indice].tipo, "raro")  != 0)
    {
        IngresarDatoCadenaCaracteres(mascotas[indice].tipo,"Error, reingrese el tipo , 'gato', 'perro' o 'raro'");
        strlwr(mascotas[indice].tipo);
    }




}


