#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Peliculas.h"
#include "parser.h"

/** \brief Listar una sola pelicula
 *
 * \param Movie* mov
 *
 */
void controller_ListOneMovie(Movie* mov){
    if(mov!= NULL){
        printf("%4d   %18s %15s %6d\n",mov->id,mov->nombre,mov->genero,mov->anio);
    }
}

/** \brief Listar pelicula
 *
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int controller_ListMovie(LinkedList* pArrayListMovie)
{
    int todoOk=-1;
    Movie* mov;

    if(pArrayListMovie!=NULL){
        todoOk=1;
        system("cls");
        printf("   ID              NOMBRE          GENERO   ANIO\n");
        for(int i=0; i<ll_len(pArrayListMovie);i++){
            mov=(Movie*)ll_get(pArrayListMovie,i);
            controller_ListOneMovie(mov);
        }
    }

    return todoOk;
}

int controller_loadFromText(char* path , LinkedList* pArrayListMovie){
    int todoOk=-1;

    FILE* f;
    if(path!=NULL && pArrayListMovie!=NULL){
        f=fopen(path,"r");
        if(f!=NULL){
            if(parser_MovieFromText(f,pArrayListMovie)){
                printf("Datos cargados con Exito!!!\n\n");
                fclose(f);
                todoOk=1;
            }
            else{
                printf("Hubo un error al cargar!!!\n\n");
            }
        }
    }

    return todoOk;
}

int controller_addMovie(LinkedList* pArrayListMovie)
{
    int todoOk=-1;
    Movie* mov=movie_new();
    char nombre[20];
    char genero[20];
    int anio;
    int id=0;

    system("cls");
    printf("Alta de Pelicula\n\n");
    printf("Ingrese Nombre: ");
    fflush(stdin);
    gets(nombre);
    printf("Ingrese el Genero: ");
    fflush(stdin);
    gets(genero);
    printf("Ingrese Anio: ");
    scanf("%d",&anio);
    id=actualizarId(id);

    if(movie_setId(mov,id) && movie_setNombre(mov,nombre) && movie_setGenero(mov,genero) && movie_setAnio(mov,anio)){
        if(ll_add(pArrayListMovie,mov)==0){
            printf("Pelicula Cargada con Exito!\n\n");
            todoOk=1;
        }
        else{
            printf("ERROR!!! La pelicula no fue cargada!\n\n");
        }
    }

    return todoOk;
}

int controller_editMovie(LinkedList* pArrayListMovie)
{
    int todoOk=-1;
    int id;
    char confirm;
    char opcion;
    char nombre[20];
    char genero[20];
    int anio;

    Movie* mov;

    system("cls");
    printf("Modificar datos de Pelicula\n\n");
    controller_ListMovie(pArrayListMovie);
    printf("\nIngrese el Id de la Pelicula que desea modificar: ");
    scanf("%d",&id);
        for(int i=0; i<ll_len(pArrayListMovie); i++){
        mov=(Movie*)ll_get(pArrayListMovie,i);
            if(id==mov->id){
            system("cls");
            controller_ListOneMovie(mov);
            printf("\nContinuar con la modificacion? s/n: ");
            fflush(stdin);
            scanf("%c",&confirm);
            if(confirm=='s'){
                do{
                    todoOk=1;
                    printf("\nQue desea modificar?: \n\na.Nombre\nb.Genero\nc.Anio\n");
                    fflush(stdin);
                    scanf("%c",&opcion);
                    switch(opcion){
                case 'a':
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(nombre);
                    if(movie_setNombre(mov,nombre)){
                       controller_ListOneMovie(mov);
                    }
                    printf("Continuar modificando? s/n: ");
                    fflush(stdin);
                    scanf("%c",&confirm);
                    break;
                case 'b':
                    printf("Ingrese nuevo genero: ");
                    fflush(stdin);
                    gets(genero);
                    if(movie_setGenero(mov,genero)){
                       controller_ListOneMovie(mov);
                    }
                    printf("Continuar modificando? s/n: ");
                    fflush(stdin);
                    scanf("%c",&confirm);
                    break;
                case 'c':
                    printf("Ingrese nuevo anio: ");
                    scanf("%d",&anio);
                    if(movie_setAnio(mov,anio)){
                       controller_ListOneMovie(mov);
                    }
                    printf("Continuar modificando? s/n: ");
                    fflush(stdin);
                    scanf("%c",&confirm);
                    break;
                default:
                    break;
                    }
                }while(confirm=='s');
            }
        }

    }

    return todoOk;
}

int controller_removeMovie(LinkedList* pArrayListMovie)
{
    int todoOk=-1;
    int id;
    char confirm;

    Movie* mov;

    system("cls");
    printf("Baja de pelicula\n\n");
    controller_ListMovie(pArrayListMovie);
    printf("\nIngrese el Id de la pelicula que desea dar de baja: ");
    scanf("%d",&id);
        for(int i=0; i<ll_len(pArrayListMovie); i++){
            mov=(Movie*)ll_get(pArrayListMovie,i);
            if(id==mov->id){
                system("cls");
                controller_ListOneMovie(mov);
                printf("\nContinuar con la baja? s/n: ");
                fflush(stdin);
                scanf("%c",&confirm);
                if(confirm=='s'){
                    if(ll_remove(pArrayListMovie,i)==0){
                        movie_delete(mov);
                        printf("\nBaja Exitosa!!!\n\n");
                        todoOk=1;
                    }
                }
            }
        }


    return todoOk;
}

int controller_sortMovie(LinkedList* pArrayListMovie)
{
    int todoOk=-1;
    char opcion;
    char confirm;
	if(pArrayListMovie!=NULL){
		if(ll_len(pArrayListMovie)>0){
			do{
                system("cls");
                printf("Ordenar Peliculas\n\na.Por Nombre\nb.Por Genero\nc.Por Anio\n\nSelecciona una opcion: ");
                fflush(stdin);
                scanf("%c",&opcion);
				switch(opcion){
                case 'a':
						ll_sort(pArrayListMovie,movie_sortNombre,1);
					break;

                case 'b':
						ll_sort(pArrayListMovie,movie_sortGenero,1);
					break;

                case 'c':
						ll_sort(pArrayListMovie,movie_sortAnio,1);
                    break;
                default:
                    break;
				}
				printf("El Ordenamiento fue exitoso!!! Desea volver a hacerlo con otra categoria? s/n: ");
				fflush(stdin);
				scanf("%c",&confirm);


			}while(confirm=='s');
		}   todoOk=1;
    }
    return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListMovie)
{
    FILE* f;
    Movie* mov;
    int len=-1;
    int id;
    int anio;
    char genero[20];
    char nombre[20];
    int todoOk=-1;
    int i;

    if(path!=NULL && pArrayListMovie!=NULL){
        len=ll_len(pArrayListMovie);
        if(len>0){
            f=fopen(path,"w");
            if(f!=NULL){
                fprintf(f,"ID,NOMBRE,GENERO,ANIO\n");
                for(i=0;i<len;i++){
                    mov=(Movie*)ll_get(pArrayListMovie,i);
                    movie_getId(mov,&id);
                    movie_getNombre(mov,nombre);
                    movie_getGenero(mov,genero);
                    movie_getAnio(mov,&anio);
                    fprintf(f,"%d,%s,%s,%d\n",id,nombre,genero,anio);
                }
                fclose(f);
                if(i==len){
                    todoOk=1;
                }
            }
        }
    }
    if(todoOk == 1){
        printf("Datos guardados correctamente!!!\n\n");
    } else{
        if(len==0){
            printf("ERROR!!! No hay datos para guardar!!!\n\n");
        } else{
            printf("ERROR!!! No se pudo guardar los datos!!!\n\n");
        }
    }

    return todoOk;
}
