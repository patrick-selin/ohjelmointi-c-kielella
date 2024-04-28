// L6T3: Linkitetty lista aliohjelmilla valikkopohjaisessa ohjelmassa

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int iLuku;
    struct Node *pSeuraava;
};

struct Node *luoNode(int iLuku) {
    struct Node *pUusiNode = NULL;

    if ((pUusiNode = (struct Node *)malloc(sizeof(struct Node))) == NULL) {
        perror("Muistin varaus epäonnistui");
        exit(0);
    }   

    pUusiNode->iLuku = iLuku;
    pUusiNode->pSeuraava = NULL;
    return pUusiNode;
}

void lisaaListaan(struct Node **pAlku, int iLuku) {
    struct Node *pUusiNode = luoNode(iLuku);

    if (*pAlku == NULL) {
        *pAlku = pUusiNode;
        return;
    }

    struct Node *pTemppi = *pAlku;

    while (pTemppi->pSeuraava != NULL) {
        pTemppi = pTemppi->pSeuraava;
    }

    pTemppi->pSeuraava = pUusiNode;
}

void tulostaLuvut(struct Node *pAlku) {
    if (pAlku == NULL) {
        printf("Lista on tyhjä.\n");
        return;
    }
    printf("Listassa on seuraavat luvut:");
    while (pAlku != NULL) {
        printf(" %d", pAlku->iLuku);
        pAlku = pAlku->pSeuraava;
    }
    printf("\n");
}

void vapautaMuisti(struct Node *pAlku) {
    struct Node *pTemppi;
    while (pAlku != NULL) {
        pTemppi = pAlku;
        pAlku = pAlku->pSeuraava;
        free(pTemppi);
    }
}

int main() {
    struct Node *pAlku = NULL;
    int iValinta;
    int iListanPituus;

    do {
        printf("1) Tulosta listan alkiot\n");
        printf("2) Muuta listan pituutta\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &iValinta);

        switch (iValinta) {
            case 1:
                tulostaLuvut(pAlku);
                break;
            case 2:
                printf("Anna listan uusi pituus: ");
                scanf("%d", &iListanPituus);
                if (iListanPituus < 0) {
                    printf("Listan pituus ei voi olla negatiivinen.\n");
                    break;
                }
                vapautaMuisti(pAlku);
                pAlku = NULL;
                for (int i = 0; i < iListanPituus; i++) {
                    int luku = i;
                    lisaaListaan(&pAlku, luku);
                }
                break;
            case 0:
                vapautaMuisti(pAlku);
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