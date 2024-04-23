#include <stdio.h>

int main() {
    int iKierrosmaara;
    int iKierros = 1;

    printf("Anna jokin kokonaisluku väliltä 1-10: ");
    scanf("%d", &iKierrosmaara);

    if (iKierrosmaara < 1 || iKierrosmaara > 10) {
        printf("Antamasi luku ei ole välillä 1-10.\n");
    } else {
        while (iKierros <= iKierrosmaara) {
            printf("%d kierros.\n", iKierros);

            iKierros++;  
        }
    }

    return 0;
}