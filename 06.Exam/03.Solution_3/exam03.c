#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdint.h>
#include <time.h>

bool isNumber(char number[])
{
    int i = 0;
    // Check for negative numbers
    if (number[0] == '-'){
        return false;
    }
    // Check if every symbol is a digit
    while(number[i]){
        if (!isdigit(number[i])){
            return false;
        }            
        i++;
     }
    return true;
}

double randRange(double min, double max){
    // Generate double value between 0 and 1 
    double random = ((double) rand()) / RAND_MAX;
    // Generate double value between 0 and (max - min) 
    double range = (max - min) * random;
    // Generate double value between min and max
    double number = range + min;
    // Round to the second digit and return
    return (roundl(number * 100) / 100);
}

int main(int argc, char **argv){

    srand(time(NULL));

    uint32_t n;
    uint32_t m;
    uint32_t p;

    if((argc == 4) && isNumber(argv[1]) && isNumber(argv[2]) && isNumber(argv[3])){
        printf("\n");
        n = atoi(argv[1]);
        m = atoi(argv[2]);
        p = atoi(argv[3]);

        double *numbers = malloc(n * sizeof(double));
        if (numbers == NULL){
            fprintf(stderr, "Malloc problem!\n");
            return EXIT_FAILURE;
        }
        for (int i = 0; i < n; i++){
            *(numbers + i) = randRange(0.0, 1.0);  // 0,0 - 1.0
        }

        numbers = reallocarray(numbers, (n + m), sizeof(double));
        if (numbers == NULL){
            fprintf(stderr, "Realloc problem!\n");
            return EXIT_FAILURE;
        }
        for (int i = n; i < (n + m); i++){
            *(numbers + i) = randRange(1.0, 2.0);  // 1,0 - 2.0
        }

        numbers = reallocarray(numbers, (n + m + p), sizeof(double));
        if (numbers == NULL){
            fprintf(stderr, "Realloc problem!\n");
            return EXIT_FAILURE;
        }
        for (int i = n + m; i < (n + m + p); i++){
            *(numbers + i) = randRange(2.0, 3.0);  // 2,0 - 3.0
        }
        //         printf("%-7s %-12s%s", carDealership[i].color, carDealership[i].brand,
        // (i + 1) % 3 ? "   " : "\n");
        for (int i = 0; i < (n + m + p); i++){
            if(i == n || i == (n + m)){
                putchar('\n');
            }
            printf("%.2f ", *(numbers + i));
        }
        putchar('\n');
        free(numbers);

        numbers = calloc((n + m + p), sizeof(double));
        if (numbers == NULL){
            fprintf(stderr, "Calloc problem!\n");
            return EXIT_FAILURE;
        }
        printf("Memory free:\n");
        for (int i = 0; i < (n + m + p); i++){
            if(i == n || i == (n + m)){
                putchar('\n');
            }
            printf("%.2f ", *(numbers + i));
        }
        putchar('\n');
        putchar('\n');
            
    }
    else{
        fprintf(stderr,"\nSorry, you entered the wrong input!\n");
        fprintf(stderr,"Please enter three arguments /positive integers/ after the program name!\n");
        putchar('\n');
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}