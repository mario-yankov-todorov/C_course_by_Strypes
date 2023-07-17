#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define EPS 0.001

typedef struct car {
    char model[20];
    uint16_t maxspeed;
    double price;
}Car;
 
int comparatorModelAscending (const void* struct1, const void* struct2) {
    Car *car1 = (Car *)struct1;
    Car *car2 = (Car *)struct2;

    return (car1->model[0] - car2->model[0]);
}

int comparatorModelDescending(const void* struct1, const void* struct2) {
    Car *car1 = (Car *)struct1;
    Car *car2 = (Car *)struct2;

    return (car2->model[0] - car1->model[0]);
}

int comparatorMaxspeedAscending (const void* struct1, const void* struct2) {
    Car *car1 = (Car *)struct1;
    Car *car2 = (Car *)struct2;

    return (car1->maxspeed - car2->maxspeed);
}

int comparatorMaxspeedDescending(const void* struct1, const void* struct2) {
    Car *car1 = (Car *)struct1;
    Car *car2 = (Car *)struct2;

    return (car2->maxspeed - car1->maxspeed);
}

int comparatorPriceAscending (const void* struct1, const void* struct2) {
    Car *car1 = (Car *)struct1;
    Car *car2 = (Car *)struct2;

    // Price is of type double, so EPS is used here!
    if(fabs(car1->price - car2->price) < EPS){
        return 0;
    }
    else if(car2->price < car1->price){
        return 1;
    }
    return -1;
}

int comparatorPriceDescending(const void* struct1, const void* struct2) {
    Car *car1 = (Car *)struct1;
    Car *car2 = (Car *)struct2;

    // Price is of type double, so EPS is used here!
    if(fabs(car1->price - car2->price) < EPS){
        return 0;
    }
    else if(car1->price < car2->price){
        return 1;
    }
    return -1;
}

int (*getComparator(int n))(const void*, const void*){
    // Create an array witch contains pointers to functions.
    // Each function accepts two parameters of type const void*
    // and return int (0, 1 or -1).
    int (*comps[])(const void*,const void*) = { 
        comparatorModelAscending, comparatorModelDescending,
        comparatorMaxspeedAscending, comparatorMaxspeedDescending,
        comparatorPriceAscending, comparatorPriceDescending
    };
    // Define a pointer to assign the result.
    int(*comparatorPointer)(const void*, const void*);
    comparatorPointer = ((n >= 1) && (n <= 6)) ? comps[n - 1] : NULL;

    return comparatorPointer;
}

char randChar(char str[], int lenght){
    // Generate random char from the given string
    // This would work with any encoding system
    // (including EBCDIC, ASCII, UTF-8, ISO-Latin-1).
    char randLetter = str[random() % lenght];
    return randLetter;
}

int16_t randomRange(int16_t min, int16_t max){
    // Generate int16_t value between 0 and (max - min).
    int16_t range = rand() % (max + 1 - min);
    // Generate number between min and max.
    int16_t number = range + min;
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


int main(){

    // If the function below is uncommented, rand() will get 
    // a new seed each time the program is started.
    // srand(time(NULL));

    int n;
    // Get the sort function from the user.
    printf("\nPlease select a member to sort :\n1-Model Asc  3-Maxspeed Asc  5-Price Asc\n");
    printf("2-Model Des  4-Maxspeed Des  6-Price Des\n");
    printf("Your choice: ");
    scanf("%d", &n); 
    // Define an array of structures of type Car.
    Car cars[10];
    // Initialize an array of chars with the alphabet to pass to randChar().
    // Instead of randChar() and array of chars, the expression 'A' + (random() % 26)
    // can be used, but this will not work with every encoding (ASCII and UTF-8 will work).
    char alphabetUpper[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alphabetLower[26] = "abcdefghijklmnopqrstuvwxyz";
    // Define a pointer to assign the value from the getComparator().
    int(*comparatorPointer)(const void*, const void*);

    putchar('\n');
    for (size_t i = 0; i < 10; i++)
    {
        cars[i].model[0] = randChar(alphabetUpper, 26);
        for (size_t j = 1; j < 5; j++)
        {
            cars[i].model[j] = randChar(alphabetLower, 26);
        }
        cars[i].maxspeed = randomRange(100, 300);
        cars[i].price = randRange(1000.00, 100000.00);
    }

    // Print struct values before sorting.
    printf("-------BEFORE SORTING-------\n");
    for (size_t i = 0; i < 10; i++)
    {
        printf("Model: %s  ", cars[i].model);
        printf("Maxspeed: %d  ", cars[i].maxspeed);
        printf("Price: %.2f  ", cars[i].price);
    putchar('\n');
    }
    putchar('\n');

    // Sort the structure by member selected by the user.
    comparatorPointer = getComparator(n);
    if(comparatorPointer != NULL){
        qsort(cars, 10, sizeof(Car), getComparator(n));
    }else{
        printf("Sorry, you entered the wrong input!\n");
        printf("Sorting could not be done!\n");
        putchar('\n');
        return EXIT_FAILURE;
    }

    // Print struct values after sorting.
    printf("-------AFTER SORTING-------\n");
    for (size_t i = 0; i < 10; i++)
    {
        printf("Model: %s  ", cars[i].model);
        printf("Maxspeed: %d  ", cars[i].maxspeed);
        printf("Price: %.2f  ", cars[i].price);
    putchar('\n');
    }
    putchar('\n');
    

    return EXIT_SUCCESS;
}