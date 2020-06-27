#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Peliculas.h"
#include "parser.h"
#include "Controller.h"

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
            case 1:
                if(primeraVez==1){
                    printf("ERROR!!! Ya cargaste los datos!!!\n\n");
                }
                else{
                controller_loadFromText("movieDataBase.csv",lista);
                primeraVez=1;
                }
                break;
            case 2:
                if(primeraVez==0){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{
                controller_addMovie(lista);
                }
                break;
            case 3:
                if(primeraVez==0){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{
                controller_editMovie(lista);
                }
                break;
            case 4:
                if(primeraVez==0){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{
                controller_removeMovie(lista);
                }
                break;
            case 5:
                if(primeraVez==0){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{
                controller_ListMovie(lista);
                }
                break;
            case 6:
                if(primeraVez==0){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{
                controller_sortMovie(lista);
                }
                break;
            case 7:
                if(primeraVez==0){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{
                controller_saveAsText("movieDataBase.csv",lista);
                }
                break;
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

