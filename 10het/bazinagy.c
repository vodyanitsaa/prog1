#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int f = *((int*)a);
    int s = *((int*)b);
    if (f > s) return 1;
    if (f < s) return -1;
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Használat: %s <fájlnév>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror("Hiba a fájl megnyitásakor");
        return 1;
    }

    int max_db = 10000000;
    int *szamok = malloc(max_db * sizeof(int));
    
    if (szamok == NULL) {
        fprintf(stderr, "Nincs elég memória!\n");
        fclose(f);
        return 1;
    }

    int db = 0;
    while (db < max_db && fscanf(f, "%d", &szamok[db]) == 1) {
        db++;
    }

    fclose(f);

    if (db > 0) {
        qsort(szamok, db, sizeof(int), compare);

        for (int i = 0; i < db; i++) {
            printf("%d\n", szamok[i]);
        }
    }

    free(szamok);

    return 0;
}
