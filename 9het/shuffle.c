#include <stdlib.h>
// Durstenfeld's shuffle algorithm
// helyben módosít
void shuffle(int n, int tomb[]) {
    if (n < 2) {
        return;
    }

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        int seged = tomb[i];
        tomb[i] = tomb[j];
        tomb[j] = seged;
    }
}