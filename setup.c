#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "setup.h"
#include "version.h"

void STP_Usage(int maxBrightness)
{
    printf("Usage : backlight [OPTION]\n\nOptions:\n");
    printf(" -h, --help\t\tShow help\n");
    printf(" -g, --get, .\t\tGet the current backlight\n");
    printf(" -i, --increase, +\tIncrease 1 the backlight (max %d)\n", maxBrightness);
    printf(" -d, --decrease, -\tDecrease 1 the backlight (min 0)\n");
    printf(" -s, --set\t\tSet the backlight (integer bewtween range [0, %d])\n", maxBrightness);

    exit(EXIT_FAILURE);
}

void STP_Setup(int argc, char *argv[], int *mode, int maxBrightness) {
    if(argc < 2 || argc > 3)
        STP_Usage(maxBrightness);

    if(argc == 2 && (!strcmp(argv[1], "-i") || !strcmp(argv[1], "--increase") || !strcmp(argv[1], "+")))
        *mode = 1;
    else if(argc == 2 && (!strcmp(argv[1], "-d") || !strcmp(argv[1], "--decrease") || !strcmp(argv[1], "-")))
        *mode = 2;
    else if(argc == 3 && (!strcmp(argv[1], "-s") || !strcmp(argv[1], "--set")))
        *mode = 3;
    else if(argc == 2 && (!strcmp(argv[1], "-g") || !strcmp(argv[1], "--get") || !strcmp(argv[1], ".")))
        *mode = 4;
    else if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
        STP_Usage(maxBrightness);
    else if(!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version"))
        VRS_Print();
    else
        STP_Usage(maxBrightness);
}

