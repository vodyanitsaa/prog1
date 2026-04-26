#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Hiba! Adja meg egy szöveges állomány nevét!\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        fprintf(stderr, "Hiba! A %s nevű file-t nem sikerült megnyitni!\n", argv[1]);
        return 2;
    }

    int sorok_szama = 0;
    int c;

    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            sorok_szama++;
        }
    }

    fclose(f);

    printf("%d\n", sorok_szama);

    return 0;
}
