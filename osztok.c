#include <stdio.h>
int osztas(int n){
    int eredmeny;
    for(int i=1;i<n;i++){
        if(n%i==0 && i!=n){
            eredmeny=i;
        }else{
            continue;
        }
    }
    printf("%d\n", eredmeny);
}
int main(){
    for(int i=1;i<=50;i++){
        osztas(i);
    }
    return 0;
}