#include <stdio.h>
#include <stdlib.h>


//hallo 


int main() {
    const char *filename = "data.tit";
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Reading contents of '%s':\n\n", filename);

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
    return 0;
}
