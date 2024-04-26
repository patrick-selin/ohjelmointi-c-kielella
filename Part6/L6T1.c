// L6T1: Linkitetyn listan perusoperaatiot

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int iKokonaisLuku;
    struct Node* pSeuraava;
};

int main() {
    struct Node* pAlku = NULL;
    struct Node* pLoppu = NULL;
    struct Node* pUusi = NULL;
    int iValinta;

    printf("Anna listan luvut.\n");

    do {
        printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
        scanf("%d", &iValinta);

        if (iValinta != 0) {
            if ((pUusi = (struct Node*)malloc(sizeof(struct Node))) == NULL) {
                perror("Muistin varaus epäonnistui");
                exit(0);
            }

            // luo uusi node
            pUusi->iKokonaisLuku = iValinta;
            pUusi->pSeuraava = NULL;

            if (pAlku == NULL) {
                pAlku = pUusi;
                pLoppu = pUusi;
            } else {
                pLoppu->pSeuraava = pUusi;
                pLoppu = pUusi;
            }
        }
    } while (iValinta != 0);

    printf("Listassa on seuraavat luvut: ");
    struct Node* pTemp = pAlku;
    while (pTemp != NULL) {
        printf("%d ", pTemp->iKokonaisLuku);
        pTemp = pTemp->pSeuraava;
    }
    printf("\n");

    while (pAlku != NULL) {
        struct Node* pTemp = pAlku;
        pAlku = pAlku->pSeuraava;

        free(pTemp);
    }

    printf("Kiitos ohjelman käytöstä.");

    return 0;
}