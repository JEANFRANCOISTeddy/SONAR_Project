# Project description :

Radar created using Arduino to detect or not the presence of objects and their distance from our radar in a defined area. Lighting of a led to warn us that an object is present. Implementation of an algorithm to calculate the distance between the object and the radar. All displayed on a C application with a moving sonar.

# Features :

-File management :
Creation of a file storing all signals received by the radar, with time, day and distance.

-Configuration folder :
Change the search angle (enlarge or reduce).

-Object detection :
The Arduino map will detect whether or not there is an object in front of the radar and lights a led.

-Displaying an object on the console :
After the detection of the object, the application will display its position on the graph.

-Object's localisation :
Once detected we will display the coordinates of the latter its distance from the radar as well as the angle at which it is located.

-Sound :
Sound's emission when an object is detected.

-Scanning :
Line's rotation in the circle's arc to detect on the graph where the object is located.

-Serial port data recovery :
From the usb port we retrieve the data sent to us by the arduino card to use them in our program and display them on the radar.

# Librairies :

## [termios.h](http://manpagesfr.free.fr/man/man3/termios.3.html) 
Permet de contrôler les ports séries (pour nous le port USB)

Code d'exemple :

`PORT.c_cflag |= CREAD;` 

*Cela nous permet de vérifier la réception de données (PORT étant define)*

## [fcntl.h](http://manpagesfr.free.fr/man/man2/fcntl.2.html) 
Permet de réaliser des opérations sur le descripteur de fichier

Code d'exemple :

`fd = open(portname, O_RDWR | O_NOCTTY);` 

*Configuration de la lecture de la carte arduino*

## [unistd.h](https://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html) 
Configuration UNIX

## [servo.h](https://github.com/arduino-libraries/Servo) 
Permet à l’arduino de commander des servomoteurs

`for(i=0;i<5;i++){
    myServo.write(i);
 }
`

*Pour faire bouger le servomoteur de i position *

## [SDL2.h]() 
Permet de créer une interface avec des fenêtres de gérer des événement de créer des rendue et des surfaces  , tracer des droites , des rectangle et des points.

Code d'exemple :

`SDL_Window *window = NULL;` 

*Lancement SDL*

## [SDL2_gfxPrimitives.h](http://www.ferzkopp.net/Software/SDL2_gfx/Docs/html/_s_d_l2__gfx_primitives_8h.html) 
Module complémentaire pour SDL2 permettant l’ajout de différentes fonction pour tracer des cercles , des polygon des arc des cercles , et autres figure géométrique.

Code d'exemple :

`if(arcRGBA(renderer,400,500,100,180,360,0,255,0,255) != 0 ){   
    SDL_ExitWithError("Erreur creation arc 1");
  }
` 

*Création d'un arc de cercle*

## [SDL_ttf.h](https://www.libsdl.org/projects/SDL_ttf/docs/SDL_ttf.html) 
Module complémentaire a la SDL2 qui permet l’ajout de texte sur l’interface graphique

## [SDL_mixer.h](https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer.html) 
Module complémentaire a la SDL2 qui permet de gérer le son sur la SDL2.
