#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AutonTiedot {
    char pMerkki[50];
    int iVuosiLuku;
    struct AutonTiedot *pSeuraava;
};

// Aliohjelma tietueen luomiseen ja listaan lisäämiseen
struct AutonTiedot *lisaaAuto(struct AutonTiedot *pAlku, char *pMerkki, int iValmistusVuosi) {
    struct AutonTiedot *pUusiAuto = (struct AutonTiedot *)malloc(sizeof(struct AutonTiedot));
    if (pUusiAuto == NULL) {
        printf("Muistinvaraus epäonnistui.\n");
        return pAlku;
    }
    strcpy(pUusiAuto->pMerkki, pMerkki);
    pUusiAuto->iVuosiLuku = iValmistusVuosi;
    pUusiAuto->pSeuraava = NULL;

    if (pAlku == NULL) {
        return pUusiAuto;
    } else {
        struct AutonTiedot *pTemppi = pAlku;
        while (pTemppi->pSeuraava != NULL) {
            pTemppi = pTemppi->pSeuraava;
        }
        pTemppi->pSeuraava = pUusiAuto;
        return pAlku;
    }
}


void tulostaAutot(struct AutonTiedot *pAlku) {
    if (pAlku == NULL) {
        printf("Ajoneuvoja ei löytynyt.\n");
        return;
    }

    struct AutonTiedot *pTemppi = pAlku;
    int i = 1;
    while (pTemppi != NULL) {
        printf("%d. ajoneuvo: %s vuosimalli %d.\n", i, pTemppi->pMerkki, pTemppi->iVuosiLuku);
        pTemppi = pTemppi->pSeuraava;
        i++;
    }
}

// Aliohjelma vapauttaa varatun muistin
void vapautaMuisti(struct AutonTiedot *pAlku) {
    struct AutonTiedot *pTemppi = pAlku;

    while (pTemppi != NULL) {
        struct AutonTiedot *pSeuraava = pTemppi->pSeuraava;
        free(pTemppi);
        pTemppi = pSeuraava;
    }
}

int main(int argc, char *argv[]) {
    struct AutonTiedot *pAlku = NULL;
    char pMerkki[50];
    int iValmistusVuosi;
    int luettu = 0;

    if (argc < 2) {
        printf("Et antanut tiedoston nimeä.\n");
        return 1;
    }

    char *ptiedostonNimi = argv[1];
    FILE *pTiedosto = fopen(ptiedostonNimi, "r");

    if (pTiedosto == NULL) {
        printf("Tiedoston avaus epäonnistui.\n");
        return 1;
    }


    printf("Luetaan tiedot tiedostosta %s.\n", ptiedostonNimi);

    // Luetaan tiedot tiedostosta ja lisätään ne listaan
    while (fscanf(pTiedosto, "%s %d", pMerkki, &iValmistusVuosi) == 2) {
        pAlku = lisaaAuto(pAlku, pMerkki, iValmistusVuosi);
        luettu = 1;
    }

    fclose(pTiedosto);

    if (luettu) {
        printf("Tiedot luettu linkitettyyn listaan.\n");
        tulostaAutot(pAlku);
        vapautaMuisti(pAlku);
    } else {
        printf("Tiedostossa ei ollut tietoja.\n");
    }

    printf("Kiitos ohjelman käytöstä.\n");

    return 0;
}