#include <stdio.h>
#include <stdlib.h>


int comparator(const void* num1, const void* num2){
    int n1 = *(int*)num1;
    int n2 = *(int*)num2;
    if ((n1 - n2) == 0){
        return 0;
    } else if (n1 < n2){
        return 1;
    }
    return -1;
}

void secondMax(int* arr, size_t n, int* secondMaxNum){
    qsort(arr, n, sizeof(int), comparator);
    *secondMaxNum = arr[1];
}


int main(){

    size_t n;
    int secondMaxNum;

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

    for (int i = 0; i < (n - 1); i++){
        if (arr[i] == arr[i + 1]){
            fprintf(stderr, "All values in the array are equal!\n");
            return EXIT_FAILURE;
        }
    }

    secondMax(arr, n, &secondMaxNum);
   
    printf("The second largest element of the array is:\n");
    printf("%d\n", secondMaxNum);

    return EXIT_SUCCESS;
}