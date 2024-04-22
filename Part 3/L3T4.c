#include <stdio.h>
#define MAX_PITUUS 30

int laskePituus(const char *aMerkkijono) {
    int iMerkkijononPituus = 0;
    while (aMerkkijono[iMerkkijononPituus] != '\0') {
        iMerkkijononPituus++;
    }
    
    return iMerkkijononPituus;
}

char* kopioMerkkijono(const char *aMerkkijono, char *aKopioituMerkkijono) {
    int i = 0;
    while (aMerkkijono[i] != '\0') {
        aKopioituMerkkijono[i] = aMerkkijono[i];
        i++;
    }
    aKopioituMerkkijono[i] = '\0';

    return aKopioituMerkkijono;
}

int main() {
    char aAnnettuMerkkijono[MAX_PITUUS];
    char aKopioituMerkkijono[MAX_PITUUS];

    printf("Anna kopioitava merkkijono: ");
    fgets(aAnnettuMerkkijono, MAX_PITUUS, stdin);

    if (aAnnettuMerkkijono[laskePituus(aAnnettuMerkkijono) - 1] == '\n') {
        aAnnettuMerkkijono[laskePituus(aAnnettuMerkkijono) - 1] = '\0';
    }

    kopioMerkkijono(aAnnettuMerkkijono, aKopioituMerkkijono);

    printf("Merkkijono 1 on '%s'.\n", aAnnettuMerkkijono);
    printf("Merkkijono 2 on '%s'.\n", aKopioituMerkkijono);
    printf("Kiitos ohjelman käytöstä.\n");

    return 0;
}
