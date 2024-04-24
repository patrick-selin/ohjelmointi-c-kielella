// L3T2: Valikkopohjainen ohjelma tiedostonkäsittelyyn aliohjelmilla

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NIMEN_PITUUS 50

void kirjoitaTiedostoon(const char *tiedostonimi) {
    char nimi[MAX_NIMEN_PITUUS];
    FILE *tiedosto;

    tiedosto = fopen(tiedostonimi, "a");
    if (tiedosto == NULL) {
        perror("Virhe tiedoston avaamisessa");
        exit(EXIT_FAILURE);
    }

    printf("Anna lisättävä nimi: ");
    if (fgets(nimi, MAX_NIMEN_PITUUS, stdin) == NULL) {
        printf("Virhe nimen lukemisessa\n");
        exit(EXIT_FAILURE);
    }

    fprintf(tiedosto, "%s", nimi);
    fclose(tiedosto);
    printf("Nimi lisätty tiedostoon.\n");
    printf("\n");
}

void lueTiedostosta(const char *tiedostonimi) {
    char nimi[MAX_NIMEN_PITUUS];
    FILE *tiedosto;

    tiedosto = fopen(tiedostonimi, "r");
    if (tiedosto == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    printf("Tiedostossa olevat nimet:\n");
    while (fgets(nimi, MAX_NIMEN_PITUUS, tiedosto) != NULL) {
        printf("%s", nimi);
    }

    fclose(tiedosto);
    printf("Tiedosto luettu ja tulostettu.\n");
    printf("\n");
}

void pyoritaValikkoa(const char *tiedostonimi) {
    int valinta;
    while (1) {
        printf("Valitse alla olevista valinnoista\n");
        printf("1) Lisää uusi nimi\n");
        printf("2) Tulosta nimet\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &valinta);

        if (valinta == 1) {
            getchar();
            kirjoitaTiedostoon(tiedostonimi);
        } else if (valinta == 2) {
            lueTiedostosta(tiedostonimi);
        } else if (valinta == 0) {
            break; 
        } else {
            printf("Tuntematon valinta. Yritä uudelleen.\n");
        }
    }
    printf("Kiitos ohjelman käytöstä.\n");
}

int main() {
    char tiedostonimi[100];

    printf("Tämä ohjelma lisää nimiä tiedostoon ja lukee ne.\n");
    printf("Anna käsiteltävän tiedoston nimi: ");
    scanf("%99s", tiedostonimi);

    pyoritaValikkoa(tiedostonimi);

    return 0;
}