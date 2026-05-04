#include <stdio.h>

void kiir_mellekatlo(int matrix[6][6]) {
    printf("A mellekatlo elemei: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", matrix[i][5 - i]);
    }
    printf("\n");
}

int main() {
    int matrix[6][6] = {
        {11, 12, 13, 14, 15, 16},
        {21, 22, 23, 24, 25, 26},
        {31, 32, 33, 34, 35, 36},
        {41, 42, 43, 44, 45, 46},
        {51, 52, 53, 54, 55, 56},
        {61, 62, 63, 64, 65, 66}
    };

    kiir_mellekatlo(matrix);

    return 0;
}