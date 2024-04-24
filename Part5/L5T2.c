// L5T2: Kokonaislukutaulukon dynaaminen hallinta

#include <stdio.h>
#include <stdlib.h>

int tarkistaSyote(char *pParametri) {
    int iTaulukonKoko = atoi(pParametri);

    if (iTaulukonKoko <= 0) {
        printf("Parametri ei ollut positiivinen kokonaisluku.\n");
        printf("Kiitos ohjelman käytöstä.");
        return 0;
    }
    return iTaulukonKoko;
}

int *varaaMuisti(int iTaulukonKoko) {
    int *pTaulukko = (int *)malloc(iTaulukonKoko * sizeof(int));

    if (pTaulukko == NULL) {
        perror("Muistin varaus epäonnistui");
        exit(0);
    }
    return pTaulukko;
}

void taytaTaulukko(int *pTaulukko, int iTaulukonKoko) {
    for (int i = 0; i < iTaulukonKoko; i++) {
        printf("Anna %d. luku: ", i + 1);
        scanf("%d", &pTaulukko[i]);
    }
    printf("Taulukko täytetty.\n");
}

void tulostaTaulukko(int *pTaulukko, int iTaulukonKoko) {
    printf("Taulukossa on luvut:");
    for (int i = 0; i < iTaulukonKoko; i++) {
        printf(" %d", pTaulukko[i]);
    }
    printf(" ");
    printf("\nTaulukko tulostettu.\n");
}

void vapautaMuisti(int *pTaulukko) {
    free(pTaulukko);
    printf("Muisti vapautettu.\n");
}

int main(int iArgs, char *aArgv[]) {
    if (iArgs != 2) {
        printf("Et antanut taulukon kokoa.\n");
        printf("Kiitos ohjelman käytöstä.");

        return 0;
    }

    int iTaulukonKoko = tarkistaSyote(aArgv[1]);

    if (iTaulukonKoko == 0) {
        return 0;
    }

    printf("Muistin varaus onnistui.\n");
    printf("Taulukossa on tilaa %d alkiolle.\n", iTaulukonKoko);

    int *pTaulukko = varaaMuisti(iTaulukonKoko);

    taytaTaulukko(pTaulukko, iTaulukonKoko);
    tulostaTaulukko(pTaulukko, iTaulukonKoko);
    vapautaMuisti(pTaulukko);

    printf("Kiitos ohjelman käytöstä.");

    return 0;
}
