#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define EPS 0.001
#define BOOKS 15
#define UPPER 1
#define LOWER 0


typedef struct book {
    char title[101]; // One byte for the null character
    char author[101]; // One byte for the null character
    uint16_t pages;
    double price;
} Book;

typedef int (*comparator_f)(const void*, const void*);

int comparatorTitleAscending (const void* struct1, const void* struct2) {
    Book *book1 = (Book *)struct1;
    Book *book2 = (Book *)struct2;

    return (book1->title[0] - book2->title[0]);
}

int comparatorTitleDescending(const void* struct1, const void* struct2) {
    Book *book1 = (Book *)struct1;
    Book *book2 = (Book *)struct2;

    return (book2->title[0] - book1->title[0]);
}

int comparatorPagesAscending (const void* struct1, const void* struct2) {
    Book *book1 = (Book *)struct1;
    Book *book2 = (Book *)struct2;

    return (book1->pages - book2->pages);
}

int comparatorPagesDescending(const void* struct1, const void* struct2) {
    Book *book1 = (Book *)struct1;
    Book *book2 = (Book *)struct2;

    return (book2->pages - book1->pages);
}

int comparatorPriceAscending (const void* struct1, const void* struct2) {
    Book *book1 = (Book *)struct1;
    Book *book2 = (Book *)struct2;

    // Price is of type double, so EPS is used here!
    if(fabs(book1->price - book2->price) < EPS){
        return 0;
    }
    else if(book2->price < book1->price){
        return 1;
    }
    return -1;
}

int comparatorPriceDescending(const void* struct1, const void* struct2) {
    Book *book1 = (Book *)struct1;
    Book *book2 = (Book *)struct2;

    // Price is of type double, so EPS is used here!
    if(fabs(book1->price - book2->price) < EPS){
        return 0;
    }
    else if(book1->price < book2->price){
        return 1;
    }
    return -1;
}
 
comparator_f getComparator(int n){
    // Create an array witch contains pointers to functions.
    // Each function accepts two parameters of type const void*
    // and return int (0, 1 or -1).
    int (*comps[])(const void*,const void*) = { 
        comparatorTitleAscending, comparatorTitleDescending,
        comparatorPagesAscending, comparatorPagesDescending,
        comparatorPriceAscending, comparatorPriceDescending
    };
    // Define a pointer to assign the result.
    int(*comparatorPointer)(const void*, const void*);
    comparatorPointer = ((n >= 1) && (n <= 6)) ? comps[n - 1] : NULL;

    return comparatorPointer;
}

uint16_t randomRange(uint16_t min, uint16_t max){
    // Generate int value between 0 and (max - min)
    uint16_t range = rand() % (max + 1 - min);
    // Generate number between min and max
    uint16_t number = range + min;
    return number;
}

double randRange(double min, double max){
    // Generate double values between 0 and 1. 
    double random = ((double) rand()) / RAND_MAX;
    // Generate double values between 0 and (max - min). 
    double range = (max - min) * random;
    // Generate double values between min and max.
    double number = range + min;
    // Round to the second digit and return.
    return (roundl(number * 100) / 100);
}

char randLetter(bool isUpper){
    return (isUpper ? 'A' : 'a') + rand() % 26;
}

void randString(char *str, uint16_t min, uint16_t max){
    uint16_t len = randomRange(min, max);
    str[0] = randLetter(UPPER);  // Upper letter
    for (int i = 1; i < len; i++){
        str[i] = randLetter(LOWER);  // Lower letters
    }
    str[len] = '\0';  // Null char
}

void printArr(Book * arr){

    for (size_t i = 0; i < BOOKS; i++)
    {
        printf("Title: %-22s  ", arr[i].title);
        printf("Author: %-24s  ", arr[i].author);
        printf("Pages: %-7d  ", arr[i].pages);
        printf("Price: %-7.2f  ", arr[i].price);
        putchar('\n');
    }
}


int main(){

    srand(time(NULL));

    int n;
    // Get the number from the user that matches a sort function.
    printf("\nHow do you want the array to be sorted:\n");
    printf("1 - Title Ascending  2 - Title Descending\n");
    printf("3 - Pages Ascending  4 - Pages Descending\n");
    printf("5 - Price Ascending  6 - Price Descending\n");
    printf("Your choice: ");
    scanf("%d", &n);
    // Define an array of structures of type Car.
    Book books[BOOKS];

    // Define a pointer to assign the value from the getComparator().
    int(*comparatorPointer)(const void*, const void*);
    // Fill each struct from the array with values!
    putchar('\n');
    for (size_t i = 0; i < BOOKS; i++)
    {
        randString(books[i].title, 11, 21);
        randString(books[i].author, 4, 11);
        strcat(books[i].author, " ");
        randString(books[i].author + strlen(books[i].author), 4, 11); 
        books[i].pages = randomRange(10, 1000);
        books[i].price = randRange(2.00, 100.00);
    }

    // Print the values of each struct before sorting.
    printf("-------BEFORE SORTING-------\n");
    printArr(books);
    putchar('\n');
    // Sort the array by struct member selected by the user.
    comparatorPointer = getComparator(n);
    if(comparatorPointer != NULL){
        qsort(books, BOOKS, sizeof(*books), getComparator(n));
    }else{
        printf("Sorry, you entered the wrong input!\n");
        fprintf(stderr,"Sorting could not be done!\n");
        putchar('\n');
        return EXIT_FAILURE;
    }
    // Print the values of each struct after sorting.
    printf("-------AFTER SORTING-------\n");
    printArr(books);
    putchar('\n');
    

    return EXIT_SUCCESS;
}