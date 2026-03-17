#include <stdio.h>

void line(char c, int length){
    for (int i = 0; i < length; ++i){
        putchar(c);
    }
    printf("\n");
}

int rfind_char(char s[], char c){
    int length = 0;
    while (s[length] != '\0'){
        ++length;
    }
    
    for (int i = length - 1; i >= 0; --i){
        if(s[i] == c){
            return i;
        }
    }
    return -1;
    
}

int char_count(char s[], char c){
    int length = 0;
    while (s[length] != '\0'){
        length = length +=;
    }
    int counter = 0;
    for (int i = 0; i <= length; ++i){
        if(s[i] == c){
            counter += 1;
        }
    }
    return counter;
    
}



int main (){
//1.feladat
    printf("Hello\n");
    line('-',5);
    printf("World\n");
//2.feladat
    printf("Kérem a szót és a keresendő betűt:");
    char s[100], c;
    scanf(" %s %c", s, &c);
    int eredmeny = rfind_char(s, c);
    printf("Utolsó előfordulás: %s ----> %d\n", s, eredmeny);
//3.feladat
    int e = char_count(s, c);
    printf("Összes előfordulás: %s ----> %d\n", s, e);
}