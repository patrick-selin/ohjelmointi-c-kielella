// L6T2: Linkitetty lista aliohjelmilla

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AutoNode {
    char pMerkki[50];
    int iVuosiLuku;
    struct AutoNode *pSeuraava;
};

struct AutoNode *lisaaAuto(struct AutoNode *pAlku, char *pMerkki, int iValmistusVuosi) {
    struct AutoNode *pUusiAuto = NULL;
    
    if ((pUusiAuto = (struct AutoNode *)malloc(sizeof(struct AutoNode))) == NULL) {
        perror("Muistin varaus epäonnistui");
        exit(0);
    }

    strcpy(pUusiAuto->pMerkki, pMerkki);
    pUusiAuto->iVuosiLuku = iValmistusVuosi;
    pUusiAuto->pSeuraava = NULL;

    if (pAlku == NULL) {
        return pUusiAuto;
    } else {
        struct AutoNode *pTemppi = pAlku;
        while (pTemppi->pSeuraava != NULL) {
            pTemppi = pTemppi->pSeuraava;
        }
        pTemppi->pSeuraava = pUusiAuto;
        return pAlku;
    }
}

void tulostaAutot(struct AutoNode *pAlku) {
    if (pAlku == NULL) {
        printf("Ajoneuvoja ei löytynyt.\n");
        return;
    }

    struct AutoNode *pTemppi = pAlku;
    int iTulosteNumero = 1;

    while (pTemppi != NULL) {
        printf("%d. ajoneuvo: %s vuosimalli %d.\n", iTulosteNumero, pTemppi->pMerkki, pTemppi->iVuosiLuku);
        pTemppi = pTemppi->pSeuraava;
        iTulosteNumero++;
    }
}

void vapautaMuisti(struct AutoNode *pAlku) {
    struct AutoNode *pTemppi = pAlku;

    while (pTemppi != NULL) {
        struct AutoNode *pSeuraava = pTemppi->pSeuraava;
        free(pTemppi);
        pTemppi = pSeuraava;
    }
    printf("Muisti vapautettu.\n");
}

// ******* MAIN
int main(int argc, char *argv[]) {
    struct AutoNode *pAlku = NULL;
    char pMerkki[50];
    int iValmistusVuosi;
    int iOnLuettu = 0;

    if (argc < 2) {
        printf("Et antanut tiedoston nimeä.\n");
        printf("Kiitos ohjelman käytöstä.");
        return 0;
    }

    char *ptiedostonNimi = argv[1];

    FILE *pTiedosto = fopen(ptiedostonNimi, "r");
    printf("Luetaan tiedot tiedostosta %s.\n", ptiedostonNimi);

    if (pTiedosto == NULL) {
        printf("Tiedoston avaus epäonnistui.\n");
        printf("Kiitos ohjelman käytöstä.");
        return 0;
    }

    while (fscanf(pTiedosto, "%s %d", pMerkki, &iValmistusVuosi) == 2) {
        pAlku = lisaaAuto(pAlku, pMerkki, iValmistusVuosi);
        iOnLuettu = 1;
    }
    fclose(pTiedosto);

    printf("Tiedot luettu linkitettyyn listaan.\n");
    tulostaAutot(pAlku);
    vapautaMuisti(pAlku);

    printf("Kiitos ohjelman käytöstä.");

    return 0;
}