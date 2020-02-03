#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "brightness.h"
#include "config.h"
#include "errors.h"

int BHT_GetMaxBrightness() {
    FILE *file;
    int maxBrightness = DEFAULT_MAXBRIGHTNESS;

    if(!(file = fopen(FILENAME_MAXBRIGHTNESS, "r")))
        ERR_Fopen(errno);

    if((fscanf(file, "%d", &maxBrightness)) == EOF)
        ERR_Fscanf(errno);

    if((fclose(file)) == EOF)
        ERR_Fclose(errno);

    return maxBrightness;
}

