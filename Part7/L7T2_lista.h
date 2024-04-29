struct Node {
    int iLuku;
    struct Node *pSeuraava;
};

void lisaaListanLoppuun(struct Node **pAlku, int iLuku);
void lisaaListanKeskelle(struct Node **pAlku, int iLuku, int iLisaysErotin);
void poistaAlkio(struct Node **pAlku, int iPoistettavaAlkio);
void printList(struct Node *pAlku);
void tyhjennaLista(struct Node **pAlku);