#include <stdio.h>

// A function to add all the digits that
// compose the numbers contained in an array!
unsigned sumArrayDigits(const int *arr, size_t n){

    unsigned sum = 0;
    int temp = 0;
 
    for (int i = 0; i < n; ++i) {
        temp = arr[i];
  
        while (temp != 0) {
            sum += temp % 10;
            temp /= 10;
        }
    }

    return sum;
}

void printArrayValues(int arr[], int n){

    printf("\nFor array with values: ");
    for (int i = 0; i < n; ++i) {

        printf("%d ", arr[i]);
    }
}

int reverseNum(int n){

    int reverse = 0;
    int remainder = 0;

    while (n != 0) {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n /= 10;
    }
    return reverse;
}

void printSumDigitByDigit(int arr[], int n){

    int temp = 0;
    int isLastDigit = 0;

    printf("\nSum of the digits = ");
    for (int i = 0; i < n; ++i) {
        temp = arr[i];
        temp = reverseNum(temp);
        isLastDigit = temp;

        while (temp != 0) {
            isLastDigit /= 10;
            // Check if the next digit is the last digit.
            // If so, print without the + sign after the number.
            if((i == n-1) && (isLastDigit == 0)){
                printf("%d", (temp % 10));
            }else{
                printf("%d + ", (temp % 10));
            }
            temp /= 10;
        }     
    }
}

int main() {

    int arr[] = { 22, 17, 35, 81, 16 };
    int temp = 0;

    // Size of the array.
    size_t n = sizeof(arr) / sizeof(arr[0]);

    printArrayValues(arr, n);
    printSumDigitByDigit(arr, n);
    // Use function sumArrayDigits to calculate
    // the sum of the digits and print it!
    printf("\nTotal sum = %d\n\n", sumArrayDigits(arr, n));
  
    return 0;
 
}