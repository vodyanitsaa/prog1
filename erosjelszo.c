#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shuffle(int n, char tomb[]) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char seged = tomb[i];
        tomb[i] = tomb[j];
        tomb[j] = seged;
    }
}

int main() {
    srand(time(NULL));

    char kisbetuk[] = "abcdefghijklmnopqrstuvwxyz";
    char nagybetuk[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char szamok[] = "0123456789";
    char specialis[] = ".,;'";
    char osszes[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,;'";

    int hossz = 8 + rand() % 5; 
    char jelszo[13];

    jelszo[0] = kisbetuk[rand() % strlen(kisbetuk)];
    jelszo[1] = nagybetuk[rand() % strlen(nagybetuk)];
    jelszo[2] = szamok[rand() % strlen(szamok)];
    jelszo[3] = specialis[rand() % strlen(specialis)];

    for (int i = 4; i < hossz; i++) {
        jelszo[i] = osszes[rand() % strlen(osszes)];
    }

    shuffle(hossz, jelszo);

    jelszo[hossz] = '\0';

    printf("%s\n", jelszo);

    return 0;
}