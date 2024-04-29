// Valikkopohjainen ohjelma listan hallintaan useassa tiedostossa

#include "L7T2_lista.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct Node *pAlku = NULL;
    int iValinta; 
    int iListanPituus; 
    int iSeuraavaNumero = 1;
    int iLisaysErotin;
    int iPoistettavaAlkio;

    printf("Tämä ohjelma hallitsee listaa ja sen alkioita.\n");
    do {
        printf("1) Luo lista\n");
        printf("2) Lisää alkio listan loppuun\n");
        printf("3) Lisää alkio listan keskelle\n");
        printf("4) Tyhjennä lista\n");
        printf("5) Poista alkio listasta\n");
        printf("6) Tulosta lista\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &iValinta);

        switch (iValinta) {
            case 1:
                printf("Anna listan pituus: ");
                scanf("%d", &iListanPituus);

                for (int i = 1; i <= iListanPituus; i++) {
                    lisaaListanLoppuun(&pAlku, iSeuraavaNumero);
                    iSeuraavaNumero++;
                }
                
                printList(pAlku);
                break;
            case 2:
                lisaaListanLoppuun(&pAlku, iSeuraavaNumero);
                iSeuraavaNumero++;
                printList(pAlku);
                break;
            case 3:
                printf("Monenneksi solmuksi alkio lisätään: ");
                scanf("%d", &iLisaysErotin);
                lisaaListanKeskelle(&pAlku, iSeuraavaNumero, iLisaysErotin);
                iSeuraavaNumero++;
                printList(pAlku);
                break;
            case 4:
                tyhjennaLista(&pAlku);
                break;
            case 5:
                printf("Anna poistettava alkio: ");
                scanf("%d", &iPoistettavaAlkio);
                poistaAlkio(&pAlku, iPoistettavaAlkio);
                printList(pAlku);
                break;
            case 6:
                printList(pAlku);
                break;
            case 0:
                tyhjennaLista(&pAlku);
                printf("Kiitos ohjelman käytöstä.");
                break;
            default:
                printf("Tuntematon valinta, yritä uudestaan.\n");
                break;
        }
    } while (iValinta != 0);

    return 0;
}
