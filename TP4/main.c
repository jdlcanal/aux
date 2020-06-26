#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int menu();

int main()
{
    char seguir='s';
    char confirm;
    int primeraVez=0;

    LinkedList* lista = ll_newLinkedList();
    if(lista == NULL){
        printf("No se pudo asignar memoria\n");
        exit(EXIT_FAILURE);
    }

    do{
        switch(menu())
        {

            case 8:
                printf("Esta seguro que desea salir? s/n: ");
                fflush(stdin);
                scanf("%c",&confirm);
                if(confirm=='s'){
                    seguir='n';
                    printf("Adios!! \n\n");
                }
                break;
            default:
                printf("ERROR!!! INGRESE UNA OPCION VALIDA!!!\n\n");
                break;
        }
        system("pause");
    }while(seguir=='s');
    return 0;
}
/** \brief Menu general del programa
 *
 * \return int
 *
 */

int menu(){
    int opcion;

    system("cls");
    printf("Bienvenido al VideoClub!!!\n");
    printf("1. Cargar las peliculas 'movieDataBase.csv' (modo texto)\n");
    printf("2. Alta de pelicula\n");
    printf("3. Modificar datos de pelicula\n");
    printf("4. Baja de pelicula\n");
    printf("5. Listar peliculas\n");
    printf("6. Ordenar peliculas\n");
    printf("7. Guardar las peliculas en el archivo 'movieDataBase.csv' (modo texto)\n");
    printf("8. Salir\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

