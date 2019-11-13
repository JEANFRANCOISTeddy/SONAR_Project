# Descriptif du projet :

Radar créer à l’aide d’Arduino permettant de détecter ou non la présence d’objet et leur distance par rapport à notre radar dans une zone définie.
Allumage d’une led pour nous avertir qu’un objet est présent.
Mise en place d’algorithme permettant de calculer la distance entre l’objet et le radar.
Le tout affiché sur une application en C avec un sonar en mouvement.

# Fonctionnalités :

-Gestion de fichiers :
Création d’un fichier stockant toutes les signaux captés par le radar, avec l’heure, le jour et la distance.

-Fichier de configuration :
Changer l’angle de recherche (agrandir ou diminuer)

-Détection d’objets :
La carte Arduino va détecter si il y a ou non un objet en face du radar et allume une led

-Affichage d'un objet sur la console :
Suite à la détection de l'objet l’application va afficher sur le graphique sa position.

-Localisation de l’objet :
Une fois détecté nous allons afficher les coordonnées de celui-ci sa distance par rapport au radar ainsi qu’à quelle angle il est situé

-Son :
Emission d’un son lors de la détection d’un objet

-Balayage :
Rotation d’une droite dans l’arc de cercle permettant de détecter sur le graphique où se trouve l’objet

-Récupération des données du port série :
Depuis le port usb nous récupérons les données qui nous sont envoyées par la carte arduino pour ainsi les exploiter dans notre programme et les afficher sur le radar

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

# Quelques schémas :

Affichage du sonar :

![Sonar](https://imgur.com/lI3RK1U)

Branchement des composants :

![Arduino schéma](https://hackster.imgix.net/uploads/attachments/208605/radar.jpg?auto=compress%2Cformat&w=900&h=675&fit=min)
