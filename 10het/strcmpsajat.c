#include <stdio.h>
#include <ctype.h>

int strcmpi(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        unsigned char c1 = tolower((unsigned char)*s1);
        unsigned char c2 = tolower((unsigned char)*s2);
        
        if (c1 != c2) {
            return c1 - c2;
        }
        
        s1++;
        s2++;
    }
    
    return (unsigned char)tolower((unsigned char)*s1) - (unsigned char)tolower((unsigned char)*s2);
}

int main() {
    printf("%d\n", strcmpi("ez", "EZ"));
    printf("%d\n", strcmpi("Alma", "alma"));
    printf("%d\n", strcmpi("abc", "ABD"));
    
    return 0;
}