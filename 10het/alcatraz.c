#include <stdio.h>
#include <stdbool.h>

int main() {
    int cellak[601];
    int i, j;

    for (i = 1; i <= 600; i++) {
        cellak[i] = 0;
    }

    for (i = 1; i <= 600; i++) {
        for (j = i; j <= 600; j += i) {
            cellak[j] = !cellak[j];
        }
    }

    printf("Szabadon tavozhatnak a kovetkezo cellakbol:\n");
    int db = 0;
    for (i = 1; i <= 600; i++) {
        if (cellak[i] == 1) {
            printf("%d ", i);
            db++;
        }
    }

    printf("\n\nOsszesen szabadult: %d fo.\n", db);

    return 0;
}