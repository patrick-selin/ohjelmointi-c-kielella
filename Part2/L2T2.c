// L2T2: Toistorakenne for, virheenkäsittely

#include <stdio.h>

int main() {
    int iLuku;
    int iSumma = 0;

    printf("Anna jokin luku väliltä 10 - 200: ");
    scanf("%d", &iLuku);

    if (iLuku < 10 || iLuku > 200) {
        printf("Antamasi luku ei ole annetulla välillä.\n");
    } else {
        for (int i = 0; i <= iLuku; i++) {
            iSumma += i;
        }
        
        printf("Lukujen 0 - %d summa on %d.", iLuku, iSumma);
    }

    return 0;
}