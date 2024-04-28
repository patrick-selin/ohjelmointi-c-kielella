// L6T4: Valikkopohjainen ohjelma listan hallintaan

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int iLuku;
    struct Node *pSeuraava;
};

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

void lisaaListaan(struct Node **pAlku, int iLuku) {
    struct Node *pUusiNode = luoNode(iLuku);

    if (*pAlku == NULL) {
        *pAlku = pUusiNode;
        return;
    }

    struct Node *pTemppi = *pAlku;
    while (pTemppi->pSeuraava != NULL) {
        pTemppi = pTemppi->pSeuraava;
    }

    pTemppi->pSeuraava = pUusiNode;
}

void printList(struct Node *pAlku) {
    int iTulostinApuri = 1;
    
    while (pAlku != NULL) {
        printf("%d ", iTulostinApuri);
        iTulostinApuri++;
        pAlku = pAlku->pSeuraava;
    }
    printf("\n");
}

void tyhjennaLista(struct Node **pAlku) {
    struct Node *pTemppi;
    while (*pAlku != NULL) {
        pTemppi = *pAlku;
        *pAlku = (*pAlku)->pSeuraava;
        free(pTemppi);
    }
}

int main() {
    struct Node *pAlku = NULL;
    int iValinta; 
    int iListanPituus; 
    int iLuku;

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
                    lisaaListaan(&pAlku, i);
                }
                printList(pAlku);
                break;
            case 2:
                
                printf("Anna lisättävä luku: ");
                scanf("%d", &iLuku);

                if (iLuku == 0){
                    tyhjennaLista(&pAlku);
                    printf("Kiitos ohjelman käytöstä.");
                     exit(0);
                }

                lisaaListaan(&pAlku, iLuku);
                printList(pAlku);
                break;
            case 3:
                printf("TOO.\n");
                break;
            case 4:
                tyhjennaLista(&pAlku);
                break;
            case 5:
                printf("TODO.\n");
                break;
            case 6:
                printList(pAlku);
                break;
            case 0:
                tyhjennaLista(&pAlku);
                printf("Kiitos ohjelman käytöstä.\n");
                break;
            default:
                printf("Tuntematon valinta, yritä uudestaan.\n");
                break;
        }
    } while (iValinta != 0);

    return 0;
}
