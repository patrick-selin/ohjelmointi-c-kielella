#include <stdio.h>
#include <string.h>

void vertaile(int iLuku1, int iLuku2) {
    if (iLuku1 < iLuku2) {
        printf("Luku %d on suurempi ja %d pienempi.\n", iLuku2, iLuku1);
    } else if (iLuku1 > iLuku2) {
        printf("Luku %d on suurempi ja %d pienempi.\n", iLuku1, iLuku2);
    } else {
        printf("Luvut %d ja %d ovat yhtä suuria.\n", iLuku1, iLuku2);
    }
}

void vertaile_desimaalit(double iLuku1, double iLuku2) {
    if (iLuku1 < iLuku2) {
        printf("Luku %5.2f on suurempi ja %5.2f pienempi.\n", iLuku2, iLuku1);
    } else if (iLuku1 > iLuku2) {
        printf("Luku %5.2f on suurempi ja %5.2f pienempi.\n", iLuku1, iLuku2);
    } else {
        printf("Luvut %5.2f ja %5.2f ovat yhtä suuria.\n", iLuku1, iLuku2);
    }
}

void vertaile_merkit(char aNimi1[], char aNimi2[]) {
    int vertailu = strcmp(aNimi1, aNimi2);
    if (vertailu < 0) {
        printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", aNimi2, aNimi1);
    } else if (vertailu > 0) {
        printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", aNimi1, aNimi2);
    } else {
        printf("Merkkijonona '%s' ja '%s' ovat yhtä suuria.\n", aNimi1, aNimi2);
    }
}

int main(void) {
    int iKokonaisluku1, iKokonaisluku2;
    double iDesimaaliluku1, fDesimaaliluku2;
    char aNimi1[20], aNimi2[20];

    printf("Anna kaksi kokonaislukua:\n");
    printf("Luku 1: ");
    scanf("%d", &iKokonaisluku1);
    printf("Luku 2: ");
    scanf("%d", &iKokonaisluku2);
    vertaile(iKokonaisluku1, iKokonaisluku2);

    printf("Anna kaksi desimaalilukua:\n");
    printf("Luku 1: ");
    scanf("%lf", &iDesimaaliluku1);
    printf("Luku 2: ");
    scanf("%lf", &fDesimaaliluku2);
    vertaile_desimaalit(iDesimaaliluku1, fDesimaaliluku2);

    printf("Anna kaksi nimeä:\n");
    printf("Nimi 1: ");
    scanf("%s", aNimi1);
    printf("Nimi 2: ");
    scanf("%s", aNimi2);
    vertaile_merkit(aNimi1, aNimi2);

    printf("Kiitos ohjelman käytöstä.\n");

    return 0;
}
