// L4T4: Valikkopohjainen ohjelma käyttäjätunnusten ylläpitoon

#include <stdio.h>
#include <string.h>

#define MAX_TUNNUKSET 50
#define MAX_PITUUS 50

typedef struct {
    char aKayttajanimi[MAX_PITUUS];
    char aSalasana[MAX_PITUUS];
    int iId;
} Kayttaja;

int naytaValikko() {
    int iValinta;
  
    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lisää uusi tunnus\n");
    printf("2) Tulosta tunnukset\n");
    printf("0) Lopeta\n");
    printf("Valintasi: ");
    scanf("%d", &iValinta);
    return iValinta;
}

void lisaaTunnus(Kayttaja aKayttajat[], int *iLaskuri) {
    if (*iLaskuri >= MAX_TUNNUKSET) {
        printf("Ei voi lisätä uutta tunnusta, lista täynnä.\n");
        return;
    }

    Kayttaja kayttaja1;
    printf("\nAnna käyttäjätunnus: ");
    scanf("%s", kayttaja1.aKayttajanimi);
    printf("Anna salasana: ");
    scanf("%s", kayttaja1.aSalasana);
    kayttaja1.iId = *iLaskuri;

    aKayttajat[*iLaskuri] = kayttaja1;
    (*iLaskuri)++;

    printf("Tunnus '%s' lisättiin listaan.\n", kayttaja1.aKayttajanimi);
    printf("\n");
}

void tulostaTunnukset(Kayttaja aKayttajat[], int iLaskuri) {
    if (iLaskuri == 0) {
         printf("Listalla ei ole yhtään tunnusta.\n");
    } else {
        printf("\nListalla olevat tunnukset:\n");
    }

    for (int i = 0; i < iLaskuri; i++) {
        printf("%d. tunnus '%s', salasana '%s', ID '%d'.\n", i + 1, aKayttajat[i].aKayttajanimi, aKayttajat[i].aSalasana, aKayttajat[i].iId);
    }
    printf("\n");
}

int main() {
    Kayttaja aKayttajat[MAX_TUNNUKSET];
    int iLaskuri = 0;
    int iValinta;

    printf("Käyttäjätunnusten hallinta.\n");
    
    do {
        iValinta = naytaValikko();

        switch (iValinta) {
            case 1:
                lisaaTunnus(aKayttajat, &iLaskuri);
                break;
            case 2:
                tulostaTunnukset(aKayttajat, iLaskuri);
                break;
            case 0:
                printf("\n");
                printf("Kiitos ohjelman käytöstä.");
                break;
            default:
                printf("Virheellinen iValinta. Yritä uudelleen.\n");
        }
    } while (iValinta != 0);

    return 0;
}