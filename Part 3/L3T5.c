#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMEROIDEN_MAARA 20

int kirjoitaLuvutTiedostoon(const char *aTiedostoNimi, int iLahtoArvo) {
    FILE *tiedosto = fopen(aTiedostoNimi, "wb");
    if (tiedosto == NULL) {
        printf("Tiedoston avaaminen epäonnistui, lopetetaan.\n");
        return 0;
    }

    srand(iLahtoArvo);
    for (int i = 0; i < NUMEROIDEN_MAARA; i++) {
        int number = rand() % 1000;
        fwrite(&number, sizeof(int), 1, tiedosto);
    }

    fclose(tiedosto);
    printf("Tiedoston kirjoitus onnistui.\n");
    return 1;
}

int lueLuvutTiedostosta(const char *aTiedostoNimi) {
    FILE *tiedosto = fopen(aTiedostoNimi, "rb");
   
    if (tiedosto == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    printf("Tiedostossa on seuraavat luvut:\n");
    int number;
    while (fread(&number, sizeof(int), 1, tiedosto)) {
        printf("%d ", number);
    }
    printf("\n");

    fclose(tiedosto);
    printf("Tiedoston lukeminen onnistui.\n");
    return 1;
}

int main() {
    char aTiedostoNimi[100];
    int iLahtoArvo;

    printf("Anna käsiteltävän tiedoston nimi: ");
    scanf("%99s", aTiedostoNimi);

    printf("Anna satunnaisluvuille lähtöarvo: ");
    scanf("%d", &iLahtoArvo);

    if (kirjoitaLuvutTiedostoon(aTiedostoNimi, iLahtoArvo)) {
        if (lueLuvutTiedostosta(aTiedostoNimi)) {
            printf("Kiitos ohjelman käytöstä.\n");
        }
    }

    return 0;
}