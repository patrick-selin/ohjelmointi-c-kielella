// L1T2: Lukujen kysyminen ja tulostaminen

#include <stdio.h>

int main(void) {
    int kokonaisluku;
    float liukuluku;

    printf("Anna kokonaisluku: ");
    scanf("%d", &kokonaisluku);

    printf("Anna liukuluku: ");
    scanf("%f", &liukuluku);

    printf("Annoit luvut %d ", kokonaisluku);
    printf("ja %.2f.", liukuluku);

    return(0);
}