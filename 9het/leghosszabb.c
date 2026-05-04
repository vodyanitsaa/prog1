#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Használat: %s <sorok száma> <min hossz> <max hossz>\n", argv[0]);
        return 1;
    }

    int sorok_szama = atoi(argv[1]);
    int min_hossz = atoi(argv[2]);
    int max_hossz = atoi(argv[3]);

    srand(time(NULL));

    char abc[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int abc_hossza = sizeof(abc) - 1;

    for (int i = 0; i < sorok_szama; i++) {
        int aktualis_hossz = min_hossz + rand() % (max_hossz - min_hossz + 1);
        
        for (int j = 0; j < aktualis_hossz; j++) {
            putchar(abc[rand() % abc_hossza]);
        }
        putchar('\n');
    }

    return 0;
}