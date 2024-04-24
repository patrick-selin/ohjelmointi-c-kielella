// L2T4: Valikkopohjainen ohjelma switch, vakiot

#include <stdio.h>
#include <math.h>

#define PI 3.142

int main() {
    float fLiukuluku;
    char cValinta;

    printf("Anna liukuluku: ");
    scanf("%f", &fLiukuluku);
    printf("\n");

    printf("Valikko\n");
    printf("1) Kerro piin arvo luvulla %.3f.\n", fLiukuluku);
    printf("2) Jaa piin arvo luvulla %.3f.\n", fLiukuluku);

    printf("Valitse: ");
    scanf(" %c", &cValinta);
    printf("\n");

    switch (cValinta) {
        case '1':
            printf("Pii * %.3f = %.3f.", fLiukuluku, PI * fLiukuluku);
            break;
        case '2':
            if (fLiukuluku != 0) {
                printf("Pii / %.3f = %.3f.", fLiukuluku, PI / fLiukuluku);
            } else {
                printf("Nollalla ei voi jakaa.");
            }
            break;
        default:
            printf("Tuntematon valinta.");
            break;
    }

    return 0;
}