#include <stdlib.h>

int choice(const int n, const int tomb[]) {
    int random_index = rand() % n;
    return tomb[random_index];
}