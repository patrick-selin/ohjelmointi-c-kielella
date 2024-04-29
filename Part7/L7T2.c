
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

void lisaaListanLoppuun(struct Node **pAlku, int iLuku) {
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

void lisaaListanKeskelle(struct Node **pAlku, int iLuku, int iLisaysErotin) {
    struct Node *pUusiNode = luoNode(iLuku);

    if (*pAlku == NULL) {
        *pAlku = pUusiNode;
        return;
    }

    struct Node *pEdellinen = NULL;
    struct Node *pNykyinen = *pAlku;
    int i = 1;

    while (pNykyinen != NULL && i < iLisaysErotin) {
        pEdellinen = pNykyinen;
        pNykyinen = pNykyinen->pSeuraava;
        i++;
    }

    if (pEdellinen == NULL) {
        pUusiNode->pSeuraava = *pAlku;
        *pAlku = pUusiNode;
    } else {
        pUusiNode->pSeuraava = pNykyinen;
        pEdellinen->pSeuraava = pUusiNode;
    }
}

void poistaAlkio(struct Node **pAlku, int iPoistettavaAlkio) {
    struct Node *pEdellinen = NULL;
    struct Node *pNykyinen = *pAlku;

    while (pNykyinen != NULL && pNykyinen->iLuku != iPoistettavaAlkio) {
        pEdellinen = pNykyinen;
        pNykyinen = pNykyinen->pSeuraava;
    }

    if (pNykyinen == NULL) {
        printf("Alkiota %d ei löydy listasta.\n", iPoistettavaAlkio);
        return;
    }

    if (pEdellinen == NULL) {
        *pAlku = pNykyinen->pSeuraava;
    } else {
        pEdellinen->pSeuraava = pNykyinen->pSeuraava;
    }

    free(pNykyinen);
}

void printList(struct Node *pAlku) {
    while (pAlku != NULL) {
        printf("%d ", pAlku->iLuku);
        pAlku = pAlku->pSeuraava;
    }
    printf("\n");
}

void tyhjennaLista(struct Node **pAlku) {
    struct Node *pTemppi;
    while (*pAlku != NULL) {
        pTemppi = *pAlku;
        *pAlku = (*pAlku)->pSeuraava;
        free(pTemppi);
    }
}

int main() {
    struct Node *pAlku = NULL;
    int iValinta; 
    int iListanPituus; 
    int iSeuraavaNumero = 1;
    int iLisaysErotin;
    int iPoistettavaAlkio;

    printf("Tämä ohjelma hallitsee listaa ja sen alkioita.\n");
    do {
        printf("1) Luo lista\n");
        printf("2) Lisää alkio listan loppuun\n");
        printf("3) Lisää alkio listan keskelle\n");
        printf("4) Tyhjennä lista\n");
        printf("5) Poista alkio listasta\n");
        printf("6) Tulosta lista\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &iValinta);

        switch (iValinta) {
            case 1:
                printf("Anna listan pituus: ");
                scanf("%d", &iListanPituus);

                for (int i = 1; i <= iListanPituus; i++) {
                    lisaaListanLoppuun(&pAlku, iSeuraavaNumero);
                    iSeuraavaNumero++;
                }
                
                printList(pAlku);
                break;
            case 2:
                lisaaListanLoppuun(&pAlku, iSeuraavaNumero);
                iSeuraavaNumero++;
                printList(pAlku);
                break;
            case 3:
                printf("Monenneksi solmuksi alkio lisätään: ");
                scanf("%d", &iLisaysErotin);
                lisaaListanKeskelle(&pAlku, iSeuraavaNumero, iLisaysErotin);
                iSeuraavaNumero++;
                printList(pAlku);
                break;
            case 4:
                tyhjennaLista(&pAlku);
                break;
            case 5:
                printf("Anna poistettava alkio: ");
                scanf("%d", &iPoistettavaAlkio);
                poistaAlkio(&pAlku, iPoistettavaAlkio);
                printList(pAlku);
                break;
            case 6:
                printList(pAlku);
                break;
            case 0:
                tyhjennaLista(&pAlku);
                printf("Kiitos ohjelman käytöstä.");
                break;
            default:
                printf("Tuntematon valinta, yritä uudestaan.\n");
                break;
        }
    } while (iValinta != 0);

    return 0;
}
