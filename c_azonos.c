#include <stdio.h>
#include <string.h>
#include <ctype.h>

int valid_C(const char* input) {
    int hossz = strlen(input);
    if (hossz == 0) {
        return 0;
    }

    if (!(isalpha(input[0]) || input[0] == '_')) {
        return 0;
    }

    for (int i = 1; i < hossz; i++) {
        if (!(isalnum(input[i]) || input[i] == '_')) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char szo[101];

    printf("Adj meg sztringeket '*' vegjelig!\n");

    while (1) {
        printf("\nInput: ");
        
        if (scanf("%100s", szo) != 1) {
            break;
        }
        if (strcmp(szo, "*") == 0) {
            break;
        }

        if (valid_c(szo)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
