#include <stdio.h>
#define MAX_PITUUS 200

int main() {
    char merkkijono[MAX_PITUUS];
    int pituus = 0;
    char valinta;

    printf("\n");

    do {
        printf("Valikko\n");
        printf("1) Lisää uusi merkki\n");
        printf("2) Tyhjennä merkkijono\n");
        printf("3) Tulosta merkkijono\n");
        printf("0) Lopeta\n");
        printf("Valintasi: ");
        scanf(" %c", &valinta);
        printf("\n");

        switch (valinta) {
            case '1':
                if (pituus < MAX_PITUUS) {
                    printf("Anna jokin merkki: ");
                    scanf(" %c", &merkkijono[pituus]);

                    pituus++;
                } else {
                    printf("Merkkijonoon ei mahdu enempää merkkejä.\n");
                }
                printf("\n");

                break;
            case '2':
                if (pituus == 0) {
                    printf("Merkkijono on jo tyhjä.\n");
                } else {
                    for (int i = 0; i < pituus; i++) {
                        merkkijono[i] = ' ';
                    }
                    pituus = 0;

                    printf("Merkkijono on tyhjennetty.\n");
                }
                printf("\n");

                break;
            case '3':
                if (pituus == 0) {
                    printf("Merkkijono on tyhjä.\n");
                } else {
                    printf("Merkkijono: ");
                    for (int i = 0; i < pituus; i++) {
                        printf("%c", merkkijono[i]);
                    }
                    printf("\n");
                }
                printf("\n");

                break;
            case '0':
                printf("Ohjelman lopetus.\n");
                break;
            default:
                printf("Tuntematon valinta.\n");
                printf("\n");
                break;
        }
    } while (valinta != '0');

    return 0;
}