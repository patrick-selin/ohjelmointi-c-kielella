#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct henkilo {
    char aNimi[30];
    int iIka;
} HENKILO;

void muuta(HENKILO *pHlo) {
    printf("Anna nimi: ");
    scanf("%s", pHlo->aNimi);
    getchar();
    printf("Anna ikä: ");
    scanf("%d", &pHlo->iIka);
    getchar();
    return;
}

void tulosta(HENKILO hlo) {
    printf("Nimi on '%s' ja ikä on %d.\n", hlo.aNimi, hlo.iIka);
    return;
}

int main(int argc, char *argv[]) {
    HENKILO aHlot[MAX];
    int iLkm, i;

    if (argc != 2) {
        printf("Ohjelman käyttö: ./E4_9 <muutettavien tietojen määrä>\n");
        printf("Komentoriviparametrinä tulee antaa ohjelman nimen\n");
        printf("lisäksi muutettavien henkilötietojen määrä, lopetetaan.\n");
        exit(0);
    }
    iLkm=atoi(argv[1]);

    for (i=0; i < iLkm; i++)
        muuta(&aHlot[i]);
        
    i = 0;
    while (i < iLkm)
        tulosta(aHlot[i++]);
    
    return(0);
}