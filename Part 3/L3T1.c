#include <stdio.h>

int laskePotenssi(int iLuku, int iPotenssi) {
    int iTulos = 0;

    for (int i = 0; i < iPotenssi; i++) {
        iTulos *= iLuku;
    }
    return iTulos;
}

int main() {
    int iLuku;
    int iPotenssi;
    int iVastaus;

    printf("Ohjelma laskee luvun potenssin.\n");
    printf("Anna kokonaisluku, jonka haluat korottaa potenssiin: ");
    scanf("%d", &iLuku);
    printf("Anna potenssi, jonka haluat laskea: ");
    scanf("%d", &iPotenssi);

    iVastaus = laskePotenssi(iLuku, iPotenssi);

    printf("%d ^ %d = %d.\n", iLuku, iPotenssi, iVastaus);
    printf("Kiitos ohjelman käytöstä.");

    return 0;
}
