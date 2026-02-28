#include <stdio.h>
int fibo(int n){
    int i=0;
    int a=0;
    int b=1;
    int eredmeny;
    printf("%d\n%d\n",a,b);
    for(i=3;i<=n;i++){
        eredmeny=a+b;
        a=b;
        b=eredmeny;
        printf("%d\n",eredmeny);
    }
}

int main(){
    int n=100;
    fibo(n);
}