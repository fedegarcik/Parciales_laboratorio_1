#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size;
    }


    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;



    if(this != NULL && nodeIndex > -1 && nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode;

        for(i=0; i< nodeIndex; i++)
        {
            pNode = pNode->pNextNode;
        }

    }





    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prev;
    Node* next;
    Node* nuevoNodo;



    if(this != NULL && nodeIndex > -1 && nodeIndex <= ll_len(this))
    {
        nuevoNodo = (Node*)malloc(sizeof(Node));

        if(nuevoNodo != NULL)
        {
           if(nodeIndex == 0)
            {
                nuevoNodo->pNextNode = this->pFirstNode;
                this->pFirstNode = nuevoNodo;
            }
            else
            {
                next = getNode(this, nodeIndex);
                nuevoNodo->pNextNode = next;
                prev = getNode(this, nodeIndex-1);
                prev->pNextNode      = nuevoNodo;

            }

            nuevoNodo->pElement = pElement;
            this->size++;
            returnAux = 0;
        }

    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
//    int indice = 0;
//    Node* actual;

    if(this != NULL)
    {
        addNode(this, ll_len(this), pElement);
        returnAux = 0;
    }





    return returnAux;
}
//  ******* OJO CORREGIR *******************
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodoAux;
    if(this != NULL && index > -1 && index < ll_len(this))
    {
        nodoAux  = getNode(this, index);

        if(nodoAux != NULL)
        {
            returnAux = nodoAux->pElement;
        }



    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodoAux;
//    int cantidad;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
        nodoAux  = getNode(this, index);

        if(nodoAux != NULL)
        {
            nodoAux->pElement = pElement;
            returnAux = 0;
        }

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* actual;
    Node* nodoAux;


    //int indice = 0;
    if(this != NULL && index > -1 && index < ll_len(this))
    {
        actual = getNode(this, index);


        if(index != 0)
        {

            nodoAux = getNode(this, index-1);
            nodoAux->pNextNode = actual->pNextNode;


        }
        else
        {
            if(ll_len(this) > 1)
            {

                this->pFirstNode = actual->pNextNode;


            }
            else
            {

                this->pFirstNode = NULL;

            }


        }
        this->size--;
        free(actual);
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
//    Node* nodo;
    int i;
//    int len;



    if(this != NULL)
    {
        for(i = ll_len(this); i > -1; i--)
        {
            ll_remove(this, i);

        }
        returnAux = 0;

    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        free(this);
        returnAux = 0;
    }


    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* nodo;

    if(this != NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            nodo = getNode(this, i);
            if(nodo != NULL && nodo->pElement == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }



    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if( ll_len(this) != 0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux;



    returnAux = addNode(this, index, pElement);


    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* nodoAux;
//    Node* actual;

/*
    if(this != NULL && index > -1 && index < ll_len(this))
    {
        actual =getNode(this, index);

        if(index != 0)
        {
            nodoAux = getNode(this, index-1);
            nodoAux->pNextNode = actual->pNextNode;
        }
        else
        {
            if(index == 0 && ll_len(this) > 1)
            {
                this->pFirstNode = actual->pNextNode;
            }
            else
            {
                    this->pFirstNode = NULL;
            }

        }
        this->size--;
        returnAux = actual->pElement;
    }
    */
    if(index > -1 && index <= ll_len(this))
    {
        nodoAux = getNode(this, index);
        if(nodoAux != NULL)
        {
            returnAux = nodoAux->pElement;
            ll_remove(this, index);
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* nodoAux;


    if(this != NULL)
    {
        returnAux = 0;
        for(i=0; i< ll_len(this); i++)
        {
            nodoAux = getNode(this, i);
            if(nodoAux != NULL)
            {
                if(nodoAux->pElement == pElement)
                {
                    returnAux = 1;
                    break;
                }
            }

        }

    }


    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
   int returnAux = -1;
    int i;
    //Node* nodo;
    void* pElement;


    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;

        for(i=0;i < ll_len(this2); i++)
        {
            //nodo = getNode(this2, i);
            pElement = ll_get(this2, i);
            if(pElement != NULL)
            {
                returnAux = ll_contains(this, pElement);
                if(returnAux == 0)
                {
                    break;
                }

            }
        }
    }


    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement;

    if(this != NULL
       && from >= 0
       && from <= ll_len(this)
       && from <= to
       && to <= ll_len(this))
    {

        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(i=from; i< to; i++)
            {
                pElement = ll_get(this, i);
                if(pElement != NULL)
                {
                    ll_add(cloneArray, pElement);

                }
            }

        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            cloneArray = ll_subList(this, 0, ll_len(this));
        }
    }


    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    Node* pAuxActual;
    Node* pAuxNext;
    void* pAux;
    int len;
    int i;
    int j;
    int criterio;
    len = ll_len(this);

    if(this != NULL
       && pFunc != NULL
       && (order == 0
       || order == 1))
    {
        for(i=0; i < len; i++)
        {
            pAuxActual = getNode(this, i);
            if(pAuxActual != NULL)
            {

                for(j=i+1;j< len; j++)
                {
                    pAuxNext = getNode(this, j);
                    if(pAuxNext != NULL)
                    {
                        criterio = pFunc(pAuxActual->pElement, pAuxNext->pElement);

                        if(criterio == 1
                           && order == 1)
                        {
                            pAux = pAuxActual->pElement;
                            pAuxActual->pElement = pAuxNext->pElement;
                            pAuxNext->pElement = pAux;
                        }
                        else
                        {
                            if(criterio == -1
                                && order == 0)
                            {
                                pAux = pAuxActual->pElement;
                                pAuxActual->pElement = pAuxNext->pElement;
                                pAuxNext->pElement = pAux;
                            }
                        }
                    }
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}



int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux;
    Node* nodeAux;
    int i;

    returnAux = -1;

    if(this  != NULL &&
       pFunc != NULL)
    {
        for(i = 0; i< ll_len(this); i++)
        {
            nodeAux = getNode(this, i);
            if(nodeAux != NULL)
            {
                if(pFunc(nodeAux->pElement) != -1)
                {
                    returnAux = 0;
                }
            }
        }
    }

    return returnAux;
}

int ll_count(LinkedList* this, int (*pFunc)(void*))
{
    Node* nodoAux;
    int i;
    int contadorAprobados;

    contadorAprobados = 0;

    if(this != NULL)
    {
        for(i=0; i< ll_len(this); i++)
        {
            nodoAux = getNode(this, i);

            if(nodoAux != NULL)
            {
                if(pFunc(nodoAux->pElement) == 1)
                {
                    contadorAprobados++;
                }
            }
        }
    }

    return contadorAprobados;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{


    LinkedList* ganadores_ll;
    int i;
    Node* nodeAux;
    ganadores_ll= NULL;


    if(this != NULL && pFunc != NULL)
    {
        ganadores_ll = ll_newLinkedList();
        for(i = 0; i<ll_len(this); i++)
        {
            nodeAux = getNode(this, i);
            if(nodeAux != NULL)
            {
                if(pFunc(nodeAux->pElement) == 1)
                {
                    ll_add(ganadores_ll, nodeAux->pElement);
                }
            }
        }
    }

    return ganadores_ll;
}

LinkedList* ll_filterV2(LinkedList* this, int (*pFuncCriterio)(void*), int (*pFunc)(void*, int))
{


    LinkedList* ganadores_ll;
    int i;
    int criterio;
    Node* nodeAux;
    ganadores_ll= NULL;


    if(this != NULL && pFunc != NULL)
    {
        criterio = pFuncCriterio(this);
        printf("%d", criterio);
        ganadores_ll = ll_newLinkedList();
        for(i = 0; i<ll_len(this); i++)
        {
            nodeAux = getNode(this, i);
            if(nodeAux != NULL)
            {
                if(pFunc(nodeAux->pElement, criterio) == 1)
                {
                    ll_add(ganadores_ll, nodeAux->pElement);
                }
            }
        }
    }

    return ganadores_ll;
}
