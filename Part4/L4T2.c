// L4T2: Matriisien yhteenlasku

#include <stdio.h>

#define RIVI 2
#define SARAKE 2

void kysyMatriisi(int matriisi[RIVI][SARAKE], char nimi[]) {
    printf("Matriisin %s alkiot:\n", nimi);
    for (int i = 0; i < RIVI; i++) {
        for (int j = 0; j < SARAKE; j++) {
            printf("Rivi %d alkio %d: ", i + 1, j + 1);
            scanf("%d", &matriisi[i][j]);
        }
    }
}

void tulostaMatriisi(int matriisi[RIVI][SARAKE], char nimi[]) {
    printf("%s:\n", nimi);
    for (int i = 0; i < RIVI; i++) {
        for (int j = 0; j < SARAKE; j++) {
            printf("%4d ", matriisi[i][j]);
        }
        printf("\n");
    }

}

void laskeSummaMatriisi(int iMatriisi[RIVI][SARAKE], int iMatriisi2[RIVI][SARAKE], int summa[RIVI][SARAKE]) {
    for (int i = 0; i < RIVI; i++) {
        for (int j = 0; j < SARAKE; j++) {
            summa[i][j] = iMatriisi[i][j] + iMatriisi2[i][j];
        }
    }
}

int main() {
    int iMatriisi[RIVI][SARAKE], iMatriisi2[RIVI][SARAKE], summa[RIVI][SARAKE];

    printf("Anna arvot yhteenlaskettaville matriiseille:\n");

    kysyMatriisi(iMatriisi, "1");
    printf("\n");
    tulostaMatriisi(iMatriisi, "Matriisi 1");
    printf("\n");

    kysyMatriisi(iMatriisi2, "2");
    printf("\n");
    tulostaMatriisi(iMatriisi2, "Matriisi 2");
    
    printf("\n");

    laskeSummaMatriisi(iMatriisi, iMatriisi2, summa);

    tulostaMatriisi(summa, "Summamatriisi");

    printf("\nKiitos ohjelman käytöstä.");

    return 0;
}
