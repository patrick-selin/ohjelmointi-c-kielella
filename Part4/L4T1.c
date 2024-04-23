#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NIMEN_PITUUS 50

struct Kirja {
    char aNimi[MAX_NIMEN_PITUUS + 1];
    int iPainovuosi;
    int iHyllypaikka;
};

int main() {
    struct Kirja kirja1;

    printf("Anna kirjan nimi: ");
    fgets(kirja1.aNimi, sizeof(kirja1.aNimi), stdin);
    if (kirja1.aNimi[strlen(kirja1.aNimi) - 1] == '\n') {
        kirja1.aNimi[strlen(kirja1.aNimi) - 1] = '\0';
    }

    printf("Anna kirjan painovuosi: ");
    scanf("%d", &kirja1.iPainovuosi);

    printf("Anna kirjan hyllypaikka: ");
    scanf("%d", &kirja1.iHyllypaikka);

    printf("Kirjan nimi on '%s', painovuosi %d ja hyllypaikka %d.\n", kirja1.aNimi, kirja1.iPainovuosi, kirja1.iHyllypaikka);
    printf("Kiitos ohjelman käytöstä.\n");

    return 0;
}
