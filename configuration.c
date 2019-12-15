#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuration.h"

Configuration read(Configuration *conf){
    Configuration new_struct;

    FILE *cf;
    char *search;
    char *new_var;
    char string[255];

    search = malloc( sizeof(char) * SIZE );
    new_var = malloc( sizeof(char) * SIZE );

    if( search == NULL || new_var == NULL ){
        printf("Probleme d'allocation");
        exit(1);
    }

    cf = fopen("file.txt","r"); //à modifier
    if(cf == NULL){
        printf("\nImpossible d'ouvrir le fichier");
        exit(1);
    }else{
        printf("Ouverture OK\n");
    }
    while( fgets(string,sizeof(string),cf) , !feof(cf) ){

        if( MATCH(string,"colorR=",6) == 0){
            search = strchr(string,'=');
            new_var = strcpy(search,search+1);
            conf->colorR = (int)atoi(new_var);
            printf("colorR = %d\n",conf->colorR);
        }

        if( MATCH(string,"colorG=",6) == 0){
            search = strchr(string,'=');
            new_var = strcpy(search,search+1);
            conf->colorG = (int)atoi(new_var);
            printf("colorG = %d\n",conf->colorG);
        }

        if( MATCH(string,"colorB=",6) == 0){
            search = strchr(string,'=');
            new_var = strcpy(search,search+1);
            conf->colorB = (int)atoi(new_var);
            printf("colorB = %d\n",conf->colorB);
        }

        if( MATCH(string,"size_width=",11) == 0){
            search = strchr(string,'=');
            new_var = strcpy(search,search+1);
            conf->size_width = (int)atoi(new_var);
            printf("size_width = %d\n",conf->size_width);
        }

        if( MATCH(string,"size_height",11) == 0){
            search = strchr(string,'=');
            new_var = strcpy(search,search+1);
            conf->size_height = (int)atoi(new_var);
            printf("size_height = %d\n",conf->size_height);
        }

    }

    return(new_struct);

    fclose(cf);
    free(search);
    free(new_var);
}


