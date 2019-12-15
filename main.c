#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuration.h"

int main(int argc, char **argv)
{
    Configuration config;
    read(&config);

    printf("size_width : %d\n",config.size_width);
    printf("colorG : %d",config.colorG);

    return 0;
}
