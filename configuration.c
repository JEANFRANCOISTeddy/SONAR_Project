#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuration.h"

void read(Configuration *conf){
    FILE *cf;
    char *search;
    char *new_var;
    char work[255];

    fflush(stdin);
    cf = fopen("C:\\Users\\TEDDY\\Desktop\\file.txt","r"); //à modifier
    if(cf == NULL){
        printf("\nImpossible d'ouvrir le fichier");
        exit(1);
    }else{
        printf("Ouverture OK\n");
    }
    while( fgets(work,sizeof(work),cf) , !feof(cf) ){

        if( MATCH(work,"colorR=",6) == 0){
            search = strchr(work,'=');
            new_var = strcpy(search,search+1);
            conf->colorR = (int)atoi(new_var);
            printf("colorR = %d\n",conf->colorR);
        }

        if( MATCH(work,"colorG=",6) == 0){
            search = strchr(work,'=');
            new_var = strcpy(search,search+1);
            conf->colorG = (int)atoi(new_var);
            printf("colorG = %d\n",conf->colorG);
        }

        if( MATCH(work,"colorB=",6) == 0){
            search = strchr(work,'=');
            new_var = strcpy(search,search+1);
            conf->colorB = (int)atoi(new_var);
            printf("colorB = %d\n",conf->colorB);
        }

        if( MATCH(work,"size_width=",11) == 0){
            search = strchr(work,'=');
            new_var = strcpy(search,search+1);
            conf->size_width = (int)atoi(new_var);
            printf("size_width = %d\n",conf->size_width);
        }

        if( MATCH(work,"size_height",11) == 0){
            search = strchr(work,'=');
            new_var = strcpy(search,search+1);
            conf->size_height = (int)atoi(new_var);
            printf("size_height = %d\n",conf->size_height);
        }

    }

    fclose(cf);
}
