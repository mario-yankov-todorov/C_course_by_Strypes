#include "books.h"


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
