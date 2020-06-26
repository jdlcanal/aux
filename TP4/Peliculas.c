#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Peliculas.h"

Movie* movie_new(){
    Movie* newMovie=(Movie*) malloc(sizeof(Movie));

    if(newMovie!=NULL)
    {
        newMovie->id=0;
        strcpy(newMovie->genero," ");
        newMovie->anio=0;
        strcpy(newMovie->nombre," ");
    }

    return newMovie;
}
Movie* movie_newParametros(char* idStr,char* nombreStr,char* generoStr,char* anioStr){
    Movie* mov = movie_new();

    if(idStr!=NULL && nombreStr!=NULL && generoStr!=NULL && anioStr!=NULL){
        movie_setId(mov,atoi(idStr));
        movie_setNombre(mov,nombreStr);
        movie_setGenero(mov,atoi(generoStr));
        movie_setAnio(mov,atoi(anioStr));
    }

    return mov;
}

int movie_setId(Movie* mov,int id){
    int todoOk = -1;

    if(mov != NULL && id >-1)
    {
        mov->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int movie_getId(Movie* mov,int* id);

int movie_setNombre(Movie* mov,char* nombre);
int movie_getNombre(Movie* mov,char* nombre);

int movie_setGenero(Movie* mov,char* genero);
int movie_getGenero(Movie* mov,char* genero);

int movie_setAnio(Movie* mov,int anio);
int movie_getAnio(Movie* mov,int* anio);
