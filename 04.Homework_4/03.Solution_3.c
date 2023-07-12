#include <stdio.h>
#include <stdlib.h>


void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int)){

    int sum = f(arr, n);  
    printf("The sum of the array elements is = %d\n", sum);
}

int sum(int* arr, int n){

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;   
}


int main() {

    size_t n;

    printf("Please enter the number of elements you want the array to contain:\n");
    scanf("%ld", &n);
    if (n < 2){
        fprintf(stderr, "An array must contain at least two elements!\n");
        return EXIT_FAILURE;
    }

    int arr[n];

    printf("Please enter %ld int numbers, separated by a space:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // Use function arrayEvaluate to print 
    // the sum of the array elements!
    arrayEvaluate(arr, n, sum);
  
    return EXIT_SUCCESS;
}