// L5T4: Valikkopohjainen ohjelma kokonaislukutaulukon käsittelyyn

#include <stdio.h>
#include <stdlib.h>

void tulostaTaulukko(int *pTaulukko, int iKoko) {
    // printf("huu %d ::", iKoko);
    if (iKoko <= 0 || pTaulukko == NULL) {
        printf("Taulukko on tyhjä.\n");
        return;
    }
    printf("Taulukon alkiot ovat:");
    for (int i = 0; i < iKoko; i++) {
        printf(" %d", pTaulukko[i]);
    }
    printf(" ");
    printf("\n");
}

int *muutaTaulukonKokoa(int *pTaulukko, int iAlkuperainenKoko, int iTulevaKoko) {
    if (iTulevaKoko < 0) {
        printf("Taulukon koko ei voi olla negatiivinen.\n");
        return 0;
    }
    int *uusiTaulukko = (int *)malloc(iTulevaKoko * sizeof(int));

    if (uusiTaulukko == NULL) {
        printf("Muistin varaus epäonnistui.\n");
        return 0;
    }
    for (int i = 0; i < iTulevaKoko; i++) {
        if (i < iAlkuperainenKoko) {
            uusiTaulukko[i] = pTaulukko[i];
        } else {
            uusiTaulukko[i] = i;
        }
    }
    free(pTaulukko);

    return uusiTaulukko;
}

int main() {
    int *pTaulukko = NULL;
    int iTaulukonkoko = 0;
    int iValinta;

    do {
        printf("1) Tulosta taulukon alkiot\n");
        printf("2) Muuta taulukon kokoa\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &iValinta);

        switch (iValinta) {
            case 1:
                tulostaTaulukko(pTaulukko, iTaulukonkoko);
                break;
            case 2:
                {
                    int iTulevaKoko;

                    printf("Anna taulukon uusi koko: ");
                    scanf("%d", &iTulevaKoko);
                    pTaulukko = muutaTaulukonKokoa(pTaulukko, iTaulukonkoko, iTulevaKoko);

                    iTaulukonkoko = iTulevaKoko;
                }
                break;
            case 0:
                free(pTaulukko);

                printf("Muisti vapautettu.\n");
                break;
            default:
                printf("Tuntematon valinta, yritä uudestaan.\n");
                break;
        }
    } while (iValinta != 0);

    printf("Kiitos ohjelman käytöstä.\n");

    return 0;
}
