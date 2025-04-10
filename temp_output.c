#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *inputFile = "data.tit";        // Bestandsnaam met C-code
    const char *outputFile = "temp_output.c";  // Tijdelijk .c bestand
    const char *executable = "program_exec";   // Naam van de gecompileerde uitvoer

    // Stap 1: Open inputbestand
    FILE *in = fopen(inputFile, "rb");
    if (in == NULL) {
        perror("Fout bij openen van data.tit");
        return 1;
    }

    // Stap 2: Schrijf inhoud naar een tijdelijk .c bestand
    FILE *out = fopen(outputFile, "wb");
    if (out == NULL) {
        perror("Fout bij aanmaken van temp_output.c");
        fclose(in);
        return 1;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);

    // Stap 3: Compileer met gcc
    char compileCommand[256];
    snprintf(compileCommand, sizeof(compileCommand), "gcc %s -o %s", outputFile, executable);
    int compileStatus = system(compileCommand);
    if (compileStatus != 0) {
        fprintf(stderr, "Compilatie mislukt\n");
        return 1;
    }

    // Stap 4: Voer het gecompileerde programma uit
    printf("Uitvoeren van gecompileerde code:\n\n");
    char runCommand[128];
    snprintf(runCommand, sizeof(runCommand), "./%s", executable);
    system(runCommand);

    return 0;
}
