# Project description :

Radar created using Arduino to detect or not the presence of objects and their distance from our radar in a defined area. Lighting of a led to warn us that an object is present. Implementation of an algorithm to calculate the distance between the object and the radar. All displayed on a C application with a moving sonar.

# Features :

-File management :
Creation of a file storing all signals received by the radar, with time, day and distance.

-Configuration folder :
Change the search angle (enlarge or reduce).

-Object's detection :
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

Libraries used for the realization of our project

## [termios.h](http://manpagesfr.free.fr/man/man3/termios.3.html) 
The termios functions establish a general interface in the form of a terminal, allowing control of the asynchronous communication ports.

Example code :

`PORT.c_cflag |= CREAD;` 

*This allows us to check the reception of data (PORT being defined)*

## [fcntl.h](http://manpagesfr.free.fr/man/man2/fcntl.2.html) 
Allows you to perform operations on the file descriptor

Example code :

`fd = open(portname, O_RDWR | O_NOCTTY);` 

*Configuration de lecture de la carte arduino*

## [unistd.h](https://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html) 
UNIX Configuration

## [servo.h](https://github.com/arduino-libraries/Servo) 
Allows the arduino to control servomotors.

`for(i=0;i<5;i++){
    myServo.write(i);
 }
`

*To move the actuator from i position*

## [SDL2.h]() 
Allows to create an interface with windows to manage events, create renderings and surfaces, draw lines, rectangles and points.

Example code :

`SDL_Window *window = NULL;` 

*Launch SDL*

## [SDL2_gfxPrimitives.h](http://www.ferzkopp.net/Software/SDL2_gfx/Docs/html/_s_d_l2__gfx_primitives_8h.html) 
Add-on module for SDL2 allowing the addition of different functions to draw circles, polygons, arcs, circles, and other geometric shapes.

Example code :

`if(arcRGBA(renderer,400,500,100,180,360,0,255,0,255) != 0 ){   
    SDL_ExitWithError("Erreur creation arc 1");
  }
` 

*Creating an arc of a circle*

## [SDL_ttf.h](https://www.libsdl.org/projects/SDL_ttf/docs/SDL_ttf.html) 
Add-on module to SDL2 that allows text to be added to the graphical interface.

## [SDL_mixer.h](https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer.html) 
Complementary module to SDL2 which allows to manage the sound on SDL2.
