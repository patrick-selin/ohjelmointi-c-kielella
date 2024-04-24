#include <stdio.h>
#include <stdlib.h>

void laskeNelio(int *iLuku) {
    *iLuku *= *iLuku;
}

int main(int iArgs, char *cArgv[]) {
    if (iArgs != 2) {
        printf("Et antanut lukua!\n");
        printf("Kiitos ohjelman käytöstä.");
        return 0;
    }

    int iLuku = atoi(cArgv[1]);

    printf("Luku on %d.\n", iLuku);

    laskeNelio(&iLuku);

    printf("Luvun neliö on %d.\n", iLuku);
    printf("Kiitos ohjelman käytöstä.");

    return 0;
}
