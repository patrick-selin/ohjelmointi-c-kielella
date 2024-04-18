#include <stdio.h>

int main(void) {
    int luku1;
    int luku2;
    int valinta;
    int tulos;
    
    printf("Anna kaksi kokonaislukua: ");
    scanf("%d %d", &luku1, &luku2);
 
    printf("\n");

    printf("Valikko\n");
    printf("1) Summaa luvut yhteen.\n");
    printf("2) Kerro luvut keskenään.\n");

    printf("Valitse: ");
    scanf("%d", &valinta);

    printf("\n");

    if (valinta == 1) {
        tulos = luku1 + luku2;
        printf("Luvut laskettiin yhteen. Tulos = %d.\n", tulos);
    } else if (valinta == 2) {
        tulos = luku1 * luku2;
        printf("Luvut kerrottiin keskenään. Tulos = %d.\n", tulos);
    } else {
        printf("Tuntematon valinta.\n");
    }

    return 0;
}
