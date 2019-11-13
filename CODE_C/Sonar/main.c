#include <stdio.h>
#include <sys/fcntl.h>  // Contrôle de fichiers
#include <termios.h> // Configuration du terminal de contrôle
#include <unistd.h> // Configuration UNIX
#include <errno.h>  // Gestion des erreurs

#define BAUDRATE B9600
#define BITS 100

/* c_iflag --> INPUT | c_oflag --> OUTPUT | c_cflag --> CONTROL */
/* 1 bit = 1 caracter */

int main(int argc,char **argv)
{
    int octet = 50;
    char read_buffer[BITS];
    int bytes_read = 0;
    int fd; // File Descriptor
    char *portname = "/dev/ttyACM0";

    fd = open(portname, O_RDWR | O_NOCTTY); //Configuration de la lecture de la carte arduino

    if(fd == -1)
        printf("Opening : FAIL");
    else
        printf("Opening : OK\n");

    /* Configuration de la structure Termios */

    struct termios PORT;

    tcgetattr(fd, &PORT); //Récupérer la configuration de base du port série
    cfsetispeed(&PORT, BAUDRATE); // Vitesse de lecture indication --> "i"
    PORT.c_cflag &= ~PARENB; // Pas de parité
    PORT.c_cflag &= ~CSTOPB; // Bit de stop
    PORT.c_cflag &= ~CSIZE;
    PORT.c_cflag |= CS8; // Set

    //Configuration Communication RTS/CTS --> alerte pour vérifier l'envoi et la reception
    PORT.c_cflag &= ~CRTSCTS; // CRT/CTS Interruption sur le receveur pour l'alerter de l'envoi de données
    PORT.c_cflag |= CREAD | CLOCAL; // Valider la reception | Ignorer les signaux du modem
    PORT.c_iflag &= ~(IXON | IXOFF | IXANY); // XON/XOFF Validation sortie | entrée | redémrrage
    PORT.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG); // Mode canoni0que

    /* Configuration du temps de lecture */
    PORT.c_cc[VMIN] = 10;
    PORT.c_cc[VTIME] = 0; // Attente indéfinit pour la reception de caractères

    /* Changement de configuration */
    if( tcsetattr(fd,TCSANOW,&PORT) == -1) // Appliquer les nouvelles modification au terminale
        printf("Fail to save the configuration");
    else
        printf("Configuration correctly save\n");

    usleep(1000 * 1000); //Reset de l'arduino
    tcflush(fd, TCIFLUSH); // Efface les données reçue mais non lues
    bytes_read = read(fd,&read_buffer,octet); // Read --> nombre d'octets lus par le port série
    printf("%i bytes got read ..\n", bytes_read);
    printf("Arduino program :\n %s", read_buffer);

    return 0;
}
