/*
    GNU/Linux
        > gcc main.c $(sdl2-config --cflags --libs) -lSDL2_gfx -lSDL2_ttf -lSDL2_mixer -o prog

*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>

void SDL_ExitWithError(const char *message);



int main(int argc, char **argv)

{
    SDL_Window *window = NULL;

    SDL_Renderer *renderer = NULL;

    SDL_Surface *sfont = NULL;

    SDL_Texture *tfont = NULL;

    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)

        SDL_ExitWithError("Initialisation SDL");

    if(TTF_Init() !=0)

        SDL_ExitWithError("Erreur Init TTF");

    //Création fenêtre
    window = SDL_CreateWindow("Sonar",
                                SDL_WINDOWPOS_CENTERED, // pos x
                                SDL_WINDOWPOS_CENTERED, //y
                                810, //width
                                600, //height
                                0); //mode fenetre avec bordure sans etc

    if(window == NULL){
        SDL_ExitWithError("Creation fenetre echouee");}

    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_TARGETTEXTURE); // -1 driver pour affichage

    if(renderer == NULL){
        SDL_ExitWithError("Creation rendue echouee");}

    /*------------------------------------------------------------*/


    if(SDL_SetRenderDrawColor(renderer,0,255,0,SDL_ALPHA_OPAQUE) !=0 ){

      SDL_ExitWithError("Erreur de changement de couleur");}


    if(SDL_RenderDrawLine(renderer,1,500,400,500) != 0 ){

       SDL_ExitWithError("Erreur de creation ligne");}

//5pi/6

    if(SDL_RenderDrawLine(renderer,(400*-(sqrt(3)/2)+400),500/2,400,500) != 0 )

       SDL_ExitWithError("Erreur de creation ligne");

//2pi/3

    if(SDL_RenderDrawLine(renderer,(-200)+400,500-(500*(sqrt(3)/2)),400,500) != 0 )

        SDL_ExitWithError("Erreur de creation ligne");

        //pi/2

    if(SDL_RenderDrawLine(renderer,400,40,400,500) != 0 )

        SDL_ExitWithError("Erreur de creation ligne");
//pi/3

    if(SDL_RenderDrawLine(renderer,(200+400),500-(500*(sqrt(3)/2)),400,500) != 0 )

        SDL_ExitWithError("Erreur de creation ligne");

//pi/6

    if(SDL_RenderDrawLine(renderer,(400*(sqrt(3)/2)+400),500/2,400,500) != 0 )

      SDL_ExitWithError("Erreur de creation ligne");

//2pi

    if(SDL_RenderDrawLine(renderer,800,500,400,500) != 0 )

       SDL_ExitWithError("Erreur de creation ligne");

    if( arcRGBA(renderer,400,500,100,180,360,0,255,0,255) != 0 ){   //arc1

        SDL_ExitWithError("Erreur creation arc 1");
    }

    if( arcRGBA(renderer,400,500,200,180,360,0,255,0,255) != 0 ){  //arc2

        SDL_ExitWithError("Erreur creation arc 2");
    }

    if( arcRGBA(renderer,400,500,300,180,360,0,255,0,255) != 0 ){  //arc3

        SDL_ExitWithError("Erreur creation arc 3");
    }

    if( arcRGBA(renderer,400,500,400,180,360,0,255,0,255) != 0 ){  //arc4

        SDL_ExitWithError("Erreur creation arc 4");
    }


    SDL_Color text_color = {0,255,0};

    SDL_Rect rfont = {10,500, 250,50};

    TTF_Font * font = TTF_OpenFont("font/font1.ttf",12);

    sfont = TTF_RenderText_Solid(font,"Distance :",text_color);
    tfont = SDL_CreateTextureFromSurface(renderer,sfont);

    SDL_FreeSurface(sfont);
// SDL_QueryTexture(tfont,NULL,NULL,&rfont.w,&rfont.h);

    SDL_RenderCopy(renderer,tfont,NULL,&rfont);
 //afficher le rendue mettre a jour

    SDL_RenderPresent(renderer);

   /*------------------------------------------------- Fermer fenetre avec evenement prog tourne en boucle infinie*/

    SDL_bool program_lanched = SDL_TRUE;

    while(program_lanched)
    {

        SDL_Event event;

        while(SDL_PollEvent(&event) ) //recup n'importe quel evenement sans bloquer le prog
        {
            switch(event.type) //changer le type de event

            {
                case SDL_QUIT:  //pour associer le type a l'action

                    program_lanched = SDL_FALSE;
                    break;

                default:
                    break;

            }
        }
    }

/*----------------------------------------------------------*/

 /*   SDL_RenderClear(renderer);

   if(SDL_RenderClear(renderer) != 0)
        SDL_ExitWithError("Effacement echouee"); pour effacer */
    /*------------------------------------------------------------*/

    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}

void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError()); // pour eviter d'ecrire a chaque fois les log Erreur : ecran , init etc
    SDL_Quit();
    exit(EXIT_FAILURE);
}
