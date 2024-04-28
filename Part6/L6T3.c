// L6T3: Linkitetty lista aliohjelmilla valikkopohjaisessa ohjelmassa

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Funktio uuden solmun luomiseksi
struct Node *luoNode(int data) {
    struct Node *uusiNode = NULL;

    (struct Node *)malloc(sizeof(struct Node));

    if (uusiNode == NULL) {
        perror("Muistin varaus epäonnistui");
        exit(0);
    }

    uusiNode->data = data;
    uusiNode->next = NULL;
    return uusiNode;
}

void lisaaListaan(struct Node **pAlku, int data) {
    struct Node *uusiNode = luoNode(data);

    if (*pAlku == NULL) {
        *pAlku = uusiNode;
        return;
    }

    struct Node *temp = *pAlku;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = uusiNode;
}

void tulostaLuvut(struct Node *pAlku) {
    if (pAlku == NULL) {
        printf("Lista on tyhjä.\n");
        return;
    }
    printf("Listassa on seuraavat luvut:");
    while (pAlku != NULL) {
        printf(" %d", pAlku->data);
        pAlku = pAlku->next;
    }
    printf("\n");
}

// Funktio vapauttaa varatun muistin
void freeList(struct Node *pAlku) {
    struct Node *temp;
    while (pAlku != NULL) {
        temp = pAlku;
        pAlku = pAlku->next;
        free(temp);
    }
}
// ******* MAIN
int main() {
    struct Node *pAlku = NULL;
    int iValinta; 
    int iListanPituus;

    do {
        printf("1) Tulosta listan alkiot\n");
        printf("2) Lisää luku listalle\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &iValinta);

        switch (iValinta) {
            case 1:
                tulostaLuvut(pAlku);
                break;
            case 2:
                printf("Anna luku: ");
                scanf("%d", &iListanPituus);
                lisaaListaan(&pAlku, iListanPituus);
                break;
            case 0:
                freeList(pAlku);
                printf("Muisti vapautettu.\n");
                break;
            default:
                printf("Tuntematon valinta, yritä uudestaan.\n");
                break;
        }
    } while (iValinta != 0);

    printf("Kiitos ohjelman käytöstä.\n");

    return 0;
}
