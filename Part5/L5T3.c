// L5T3: Oman tietueen kopiointi ja vertailu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char aEtunimi[30];
    int iIka;
} HENKILO;

void kopioTietue(HENKILO *pTulevaTietue, const HENKILO *pAlkuparainenTietue) {
    strcpy(pTulevaTietue->aEtunimi, pAlkuparainenTietue->aEtunimi);
    pTulevaTietue->iIka = pAlkuparainenTietue->iIka;
}

int vertaaTietueet(const HENKILO *pTietue1, const HENKILO *pTietue2) {
    if (strcmp(pTietue1->aEtunimi, pTietue2->aEtunimi) != 0 || pTietue1->iIka != pTietue2->iIka) {
        return 0;
    }
    return 1;
}

int main() {
    HENKILO pTietue1; 
    HENKILO pTietue2;
    
    printf("Anna ensimmäisen henkilön etunimi: ");
    scanf("%s", pTietue1.aEtunimi);
    printf("Anna ensimmäisen henkilön ikä: ");
    scanf("%d", &pTietue1.iIka);

    printf("Anna toisen henkilön etunimi: ");
    scanf("%s", pTietue2.aEtunimi);
    printf("Anna toisen henkilön ikä: ");
    scanf("%d", &pTietue2.iIka);

    if (vertaaTietueet(&pTietue1, &pTietue2)) {
        printf("Annetut tiedot ovat samoja.\n");
    } else {
        printf("Annetut tiedot eivät ole samoja.\n");
    }

    HENKILO *pTietue3 = (HENKILO *)malloc(sizeof(HENKILO));
    if (pTietue3 == NULL) {
        printf("Muistin varaus epäonnistui.\n");
        return 1;
    }

    kopioTietue(pTietue3, &pTietue1);

    if (vertaaTietueet(&pTietue1, pTietue3)) {
        printf("Kopioinnin jälkeen tietueiden tiedot ovat samoja.\n");
    } else {
        printf("Kopioinnin jälkeen tietueiden tiedot eivät ole samoja.\n");
    }

    if (&pTietue1 == pTietue3) {
        printf("Kopioinnin jälkeen tietueiden osoitteet ovat samoja.\n");
    } else {
        printf("Kopioinnin jälkeen tietueiden osoitteet eivät ole samoja.\n");
    }

    free(pTietue3);
    printf("Muisti vapautettu.\n");
    printf("Kiitos ohjelman käytöstä.");

    return 0;
}
