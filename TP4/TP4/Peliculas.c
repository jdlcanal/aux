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
        movie_setGenero(mov,generoStr);
        movie_setAnio(mov,atoi(anioStr));
    }

    return mov;
}

void movie_delete(Movie* mov){
	if(mov!=NULL){
		free(mov);
	}
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
int movie_getId(Movie* mov,int* id){
    int todoOk = -1;

    if(mov != NULL && id != NULL)
    {
        *id=mov->id;
        todoOk = 1;
    }
    return todoOk;
}

int movie_setNombre(Movie* mov,char* nombre){
    int todoOk = -1;

    if(mov != NULL && strlen(nombre) > 0 && strlen(nombre)< 50)
    {
        strcpy(mov->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}
int movie_getNombre(Movie* mov,char* nombre){
    int todoOk = -1;

    if(mov != NULL && strlen(nombre) > 0 && strlen(nombre)< 50)
    {
        strcpy(nombre,mov->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int movie_setGenero(Movie* mov,char* genero){
    int todoOk = -1;

    if(mov != NULL && strlen(genero) > 0 && strlen(genero)< 50)
    {
        strcpy(mov->genero, genero);
        todoOk = 1;
    }
    return todoOk;

}
int movie_getGenero(Movie* mov,char* genero){
    int todoOk = -1;

    if(mov != NULL && strlen(genero) > 0 && strlen(genero)< 50)
    {
        strcpy(genero,mov->genero);
        todoOk = 1;
    }
    return todoOk;
}

int movie_setAnio(Movie* mov,int anio){
    int todoOk = -1;

    if(mov != NULL && anio >-1)
    {
        mov->anio=anio;
        todoOk = 1;
    }
    return todoOk;
}
int movie_getAnio(Movie* mov,int* anio){
    int todoOk = -1;

    if(mov != NULL && anio != NULL)
    {
        *anio=mov->anio;
        todoOk = 1;
    }
    return todoOk;
}

int obtenerId(int* id){
    *id=20;

    FILE* f;
    f=fopen("proximoId.bin", "rb");
    if(f!=NULL){
        fread(id,sizeof(int),1,f);

        fclose(f);
    }
    return *id;
}

int actualizarId(int id){
    id=obtenerId(&id);
    id++;

    FILE* f=fopen("proximoId.bin","wb");
    if(f!=NULL){
        fwrite(&id,sizeof(int),1,f);

        fclose(f);
    }
    return id;
}

int movie_sortNombre(void* movA, void* movB){
    int todoOk=-1;
	Movie* mov1=NULL;
	Movie* mov2=NULL;
	char nombre1[20];
	char nombre2[20];

	if(movA!=NULL && movB!=NULL){
		mov1=(Movie*)movA;
		mov2=(Movie*)movB;
		movie_getNombre(mov1,nombre1);
		movie_getNombre(mov2,nombre2);
		if(stricmp(nombre1,nombre2)>0){
			todoOk=1;
		} else if(stricmp(nombre1,nombre2)<0){
			todoOk=0;
		}
    }
	return todoOk;
}

int movie_sortGenero(void* movA, void* movB){
    int todoOk=-1;
	Movie* mov1=NULL;
	Movie* mov2=NULL;
	char genero1[20];
	char genero2[20];

	if(movA!=NULL && movB!=NULL){
		mov1=(Movie*)movA;
		mov2=(Movie*)movB;
		movie_getGenero(mov1,genero1);
		movie_getGenero(mov2,genero2);
		if(stricmp(genero1,genero2)>0){
			todoOk=1;
		} else if(stricmp(genero1,genero2)<0){
			todoOk=0;
		}
    }
	return todoOk;
}

int movie_sortAnio(void* movA, void* movB){
	int todoOk=-1;
	Movie* mov1=NULL;
	Movie* mov2=NULL;
	int anio1;
	int anio2;

	if(movA!=NULL && movB!=NULL){
		mov1=(Movie*)movA;
		mov2=(Movie*)movB;
		movie_getAnio(mov1,&anio1);
		movie_getAnio(mov2,&anio2);
		if(anio1 > anio2){
			todoOk=1;
		} else if(anio1 < anio2){
			todoOk=0;
		}
	}
	return todoOk;
}
