#include <stdio.h>

unsigned long long laskeFibonacciRekursiivisesti(int iNumero) {
    if (iNumero <= 1) {
        return iNumero;
    } else {
        return laskeFibonacciRekursiivisesti(iNumero - 1) + laskeFibonacciRekursiivisesti(iNumero - 2);
    }
}

int main() {
    int iNumero;
    printf("Anna luku, jolle lasketaan Fibonaccin luku: ");
    scanf("%d", &iNumero);

    unsigned long long lVastaus = laskeFibonacciRekursiivisesti(iNumero);

    printf("Luvun %d Fibonaccin luku on %llu.\n", iNumero, lVastaus);
    printf("Kiitos ohjelman käytöstä.");

    return 0;
}
