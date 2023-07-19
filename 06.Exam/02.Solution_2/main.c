#include "books.h"

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