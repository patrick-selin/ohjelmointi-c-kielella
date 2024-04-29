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

    struct Node *pNykyinen = *pAlku;
    while (pNykyinen->pSeuraava != NULL) {
        pNykyinen = pNykyinen->pSeuraava;
    }

    pNykyinen->pSeuraava = pUusiNode;
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

void poistaAlkio(struct Node **pAlku, int indeksi) {
    if (*pAlku == NULL) {
        return;
    }

    struct Node *poistettava = NULL;
    struct Node *edellinen = NULL;
    struct Node *nykyinen = *pAlku;
    int iLaskuri = 1;

    while (nykyinen != NULL && iLaskuri < indeksi) {
        edellinen = nykyinen;
        nykyinen = nykyinen->pSeuraava;
        iLaskuri++;
    }

    if (nykyinen == NULL) {
        return;
    }

    if (edellinen == NULL) {
        *pAlku = nykyinen->pSeuraava;
    } else {
        edellinen->pSeuraava = nykyinen->pSeuraava;
    }

    free(nykyinen);
}

void printList(struct Node *pAlku) {
    while (pAlku != NULL) {
        printf("%d ", pAlku->iLuku);
        pAlku = pAlku->pSeuraava;
    }
    printf("\n");
}

void tyhjennaLista(struct Node **pAlku) {
    struct Node *pNykyinen;
    while (*pAlku != NULL) {
        pNykyinen = *pAlku;
        *pAlku = (*pAlku)->pSeuraava;
        free(pNykyinen);
    }
}
