#ifndef CONFIGURATION_H_INCLUDED
#define CONFIGURATION_H_INCLUDED
#define MATCH(a,b,n) strncmp(a,b,n)
#define SIZE 15

typedef struct Configuration{
    int colorR;
    int colorG;
    int colorB;
    int size_width;
    int size_height;
} Configuration;

Configuration read(Configuration*);

#endif // CONFIGURATION_H_INCLUDED
