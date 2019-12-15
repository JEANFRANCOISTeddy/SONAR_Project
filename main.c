#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuration.h"

int main(int argc, char **argv)
{
    int a;

    Configuration config;
    read(&config);

    //a = config.size_width;
    printf("%d",config.size_width);

    return 0;
}




