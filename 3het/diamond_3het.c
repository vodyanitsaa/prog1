#include <stdio.h>
int main(){
    printf("Kérem a magasságot:");
    int h;
    scanf("%d",&h);
    if(h%2==0 || h<0){
        printf("Páratlan, pozitív számot kérek!\n");
    }
    int k=h/2;
    for(int i=0; i<=k; i++){
        for(int j=0;j<k-i;j++){
            printf(" ");
        }
        for(int j=0;j<2*i+1;j++){
            printf("*");
        }
            
            printf("\n");
    }
    for(int i=k-1;i>=0;i--){
        for(int j=0;j<k-i; j++){
            printf(" ");
        }
        for(int j=0;j<2*i+1;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}        

