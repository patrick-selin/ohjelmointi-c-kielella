// L4T3: Komentorivilaskin virheenkäsittelyllä

#include <stdio.h>
#include <stdlib.h>

int main(int iArch, char *argv[]) {
    if (iArch < 4) {
        printf("Et antanut syötteitä.\n");
        printf("Kiitos ohjelman käytöstä.");
        return 1;
    }

    float fNumero1 = atof(argv[1]);
    char cOperand = argv[2][0];
    float fNumero2 = atof(argv[3]);

    if (cOperand != '+' && cOperand != '-' && cOperand != 'x' && cOperand != '/') {
        printf("Virheellinen syöte.\n");
        printf("Kiitos ohjelman käytöstä.");
        return 0;
    }


    printf("%.1f %c %.1f = ", fNumero1, cOperand, fNumero2);

    switch (cOperand) {
        case '+':
            printf("%.2f\n", fNumero1 + fNumero2);
            break;
        case '-':
            printf("%.2f\n", fNumero1 - fNumero2);
            break;
        case 'x':
            printf("%.2f\n", fNumero1 * fNumero2);
            break;
        case '/':
            if (fNumero2 != 0) {
                printf("%.2f\n", fNumero1 / fNumero2);
            } else {
                printf("Virheellinen syöte.\n");
                return 1;
            }
            break;
        default:
            printf("Virheellinen syöte.\n");
            return 1;
    }
    printf("Kiitos ohjelman käytöstä.");

    return 0;
}