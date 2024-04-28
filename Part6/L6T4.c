// L6T4: Valikkopohjainen ohjelma listan hallintaan

// L6T1: Linkitetyn listan perusoperaatiot

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int iKokonaisLuku;
    struct Node* pSeuraava;
};

int main() {
    struct Node* pAlku = NULL;
    int iValinta;

    printf("Tämä ohjelma hallitsee listaa ja sen alkioita.\n");

    do {
        printf(" ");
        scanf("%d", &iValinta);

        if (iValinta != 0) {
      
        }
    } while (iValinta != 0);


    printf("Kiitos ohjelman käytöstä.");

    return 0;
}