#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "config.h"
#include "errors.h"
#include "setup.h"
#include "brightness.h"

int main(int argc, char *argv[]) {
    FILE *file;
    int brightness, maxBrightness, pbg, mode;

    maxBrightness = BHT_GetMaxBrightness();
    
    if(!(file = fopen(FILENAME_BRIGHTNESS, "r")))
        ERR_Fopen(errno);

    if((fscanf(file, "%d", &brightness) == EOF))
        ERR_Fscanf(errno);

    if((fclose(file)) == EOF)
        ERR_Fclose(errno);

    pbg = brightness;

    STP_Setup(argc, argv, &mode, maxBrightness);

    switch(mode) {
        case 1:
            if(brightness >= 0 && brightness < maxBrightness)
                brightness++;
            else
                fprintf(stderr, "Max backlight\n");

            break;

        case 2:
            if(brightness > 0 && brightness <= maxBrightness)
                brightness--;
            else
                fprintf(stderr, "Min backlight\n");

            break;

        case 3:
            if(!strcmp(argv[2], "0"))
                brightness = 0;
            else if(atoi(argv[2]) != 0 && (atoi(argv[2]) > 0 && atoi(argv[2]) <= maxBrightness))
                brightness = atoi(argv[2]);
            else
                fprintf(stderr, "Wrong range\n");

            break;

        case 4:
            printf("%d\n", brightness);
            break;
    }

    if(pbg != brightness) {
        if(!(file = fopen(FILENAME_BRIGHTNESS, "w")))
            ERR_Fopen(errno);

        fprintf(file, "%d", brightness);

        if((fclose(file)) == EOF)
            ERR_Fclose(errno);
    }

    return EXIT_SUCCESS;
}

