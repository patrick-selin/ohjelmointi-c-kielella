// L1T3: Laskutoimituksia kokonaisluvuilla

#include <stdio.h>

int main(void) {
    int luku1;
    int luku2;

    printf("Anna ensimmäinen kokonaisluku: ");
    scanf("%d", &luku1);

    printf("Anna toinen kokonaisluku: ");
    scanf("%d", &luku2);

    printf("(%d + %d) * 2 = %d\n", luku1, luku2, (luku1 + luku2) * 2);
    printf("(%d / %d) - 3 = %d\n", luku1, luku2, (luku1 / luku2) - 3);
    printf("%d %% %d = %d\n", luku1 + 1, luku2 - 1, (luku1 + 1) % (luku2 - 1));

    return(0);
}