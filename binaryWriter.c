#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    FILE *file;

     if ((file = fopen("numbers.bin", "wb")) == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    int i;
    for (i = 0; i < 10; i++) {
        fwrite(&i, sizeof(int), 1, file);
    }
    fclose(file);

    if ((file = fopen("numbers.bin", "rb")) == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    int number;
    while (fread(&number, sizeof(int), 1, file) == 1) {
        printf("%d ", number);
    }
    fclose(file);

    return 0;
}