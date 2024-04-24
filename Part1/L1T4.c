// L1T4: Merkin ja merkkijonon lukeminen ja tulostaminen

#include <stdio.h>

int main(void) {
    char merkki1;
    char merkki2[21];
    
    printf("Anna merkki: ");
    scanf(" %c", &merkki1);
    printf("Annoit merkin '%c'.\n", merkki1);

    printf("Anna korkeintaan 20 merkkiä pitkä merkkijono: ");
    scanf("%20s", merkki2);
    printf("Annoit merkkijonon '%s'.", merkki2);
    
    return(0);
}
