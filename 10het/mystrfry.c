#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void my_strfry(char *s) {
    if (s == NULL) return;

    int n = strlen(s);
    if (n < 2) return;

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    srand(time(NULL));

    char teszt_sztring[] = "Programozas";

    printf("Eredeti: %s\n", teszt_sztring);

    my_strfry(teszt_sztring);
    printf("Kevert 1: %s\n", teszt_sztring);

    my_strfry(teszt_sztring);
    printf("Kevert 2: %s\n", teszt_sztring);

    return 0;
}