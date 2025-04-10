#include "declare.h"
#include "stdio.h"

void WaveOut(char* X, char* Y)
{
    char* endptr;
    long val = strtol(Y, &endptr, 10);
    if (*endptr == '\0' && Y[0] != '\0') {
        //int
        printf("%s%d", Y);
    } else {
        //not int
        printf("%s%s", X);
    }
}

void Write(char* Txt, char* Path)
{

}
