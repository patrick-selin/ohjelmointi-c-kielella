#include "L7T2_lista.h"
#include <stdio.h>
#include <stdlib.h>

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
