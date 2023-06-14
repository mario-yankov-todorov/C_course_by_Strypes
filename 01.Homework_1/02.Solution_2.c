#include<stdio.h>

int main() {

    int num;

    scanf("%d", &num);

    num = num>>31;
    num = num&1;

    if(num){
        printf("NO\n");
    }else{
        printf("YES\n");
    }

    return 0;
}