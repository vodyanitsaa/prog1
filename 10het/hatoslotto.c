#include <stdio.h>

int main() {
    int a, b, c, d, e, f;
    const int osszeg_cel = 90;
    const long szorzat_cel = 996300;

    for (a = 1; a <= 40; ++a) {
        for (b = a + 1; b <= 41; ++b) {
            for (c = b + 1; c <= 42; ++c) {
                for (d = c + 1; d <= 43; ++d) {
                    for (e = d + 1; e <= 44; ++e) {
                        for (f = e + 1; f <= 45; ++f) {
                            if (a + b + c + d + e + f == osszeg_cel) {
                                if ((long)a * b * c * d * e * f == szorzat_cel) {
                                    printf("A nyeroszamok: %d, %d, %d, %d, %d, %d\n", 
                                            a, b, c, d, e, f);
                                    return 0; 
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}