#include "LinkedList.h"
#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    char genero[128];
    int anio;
}Movie;

Movie* movie_new();
Movie* movie_newParametros(char* idStr,char* nombreStr,char* generoStr,char* anioStr);

int movie_setId(Movie* mov,int id);
int movie_getId(Movie* mov,int* id);

int movie_setNombre(Movie* mov,char* nombre);
int movie_getNombre(Movie* mov,char* nombre);

int movie_setGenero(Movie* mov,char* genero);
int movie_getGenero(Movie* mov,char* genero);

int movie_setAnio(Movie* mov,int anio);
int movie_getAnio(Movie* mov,int* anio);

#endif // PELICULAS_H_INCLUDED
