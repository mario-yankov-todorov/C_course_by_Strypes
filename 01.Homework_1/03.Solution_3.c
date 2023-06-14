#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {

    double num;
    double diff;

    scanf("%lf", &num);

    diff = 3.14159 - num;

    if(fabs(diff) < 0.00001){
        printf("YES\n");
    }else{
        printf("NO\n");
    }


    return 0;
}