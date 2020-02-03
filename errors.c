#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "errors.h"

void ERR_Fopen(int errnum) {
    switch(errnum) {
        case EINVAL:
            fprintf(stderr, "The mode provided to fopen(), fdopen(), or freopen() was invalid.\n");
            exit(EXIT_FAILURE);
    }
}

void ERR_Fclose(int errnum) {
    switch(errnum) {
        case EBADF:
            fprintf(stderr, "The file descriptor underlying stream is not valid.\n");
            exit(EXIT_FAILURE);
    }
}

void ERR_Fscanf(int errnum) {
    switch(errnum) {
        case EAGAIN:
            fprintf(stderr, "The file descriptor underlying stream is marked nonblocking, and the read operation would block.\n");
            exit(EXIT_FAILURE);
            break;

        case EBADF:
            fprintf(stderr, "The file descriptor underlying stream is invalid, or not open for reading.\n");
            exit(EXIT_FAILURE);

        case EILSEQ:
            fprintf(stderr, "Input byte sequence does not form a valid character.\n");
            exit(EXIT_FAILURE);

        case EINTR:
            fprintf(stderr, "The read operation was interrupted by a signal\n");
            exit(EXIT_FAILURE);

        case EINVAL:
            fprintf(stderr, "Not enough arguments or format is NULL.\n");
            exit(EXIT_FAILURE);

        case ENOMEM:
            fprintf(stderr, "Out of memory.\n");
            exit(EXIT_FAILURE);

        case ERANGE:
            fprintf(stderr, "The result of an integer conversion would exceed the size that can be stored in the corresponding integer type.\n");
            exit(EXIT_FAILURE);
    }
}

