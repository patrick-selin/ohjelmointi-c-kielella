#include <stdio.h>

int lueAskeleetListaan(int *pLista, int *iRivienMaara) {
    FILE *pTiedosto;
    char rivi[30];
    int iSumma = 0;

    pTiedosto = fopen("askeldata.txt", "r");
    if (pTiedosto == NULL) {
        perror("Virhe tiedoston avaamisessa");
        return -1;
    }

    int i = 0;
    while (fgets(rivi, sizeof(rivi), pTiedosto) != NULL && i < *iRivienMaara) {
        int iAskelMaara;
        sscanf(rivi, "%*[^:]:%d", &iAskelMaara);
        pLista[i] = iAskelMaara;
        iSumma += iAskelMaara;
        i++;
    }

    *iRivienMaara = i;

    fclose(pTiedosto);

    return iSumma;
}

void tulostaLista(int *pLista, int iRivienMaara) {
    printf("Listan askeleet: ");
    for (int i = 0; i < iRivienMaara; i++) {
        printf("%d ", pLista[i]);
    }

    printf("\n");
}
