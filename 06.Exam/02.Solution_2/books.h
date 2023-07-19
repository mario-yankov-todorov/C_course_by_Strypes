#ifndef BOOKS_H
#define BOOKS_H

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

int comparatorTitleAscending (const void* struct1, const void* struct2);

int comparatorTitleDescending(const void* struct1, const void* struct2);

int comparatorPagesAscending (const void* struct1, const void* struct2);

int comparatorPagesDescending(const void* struct1, const void* struct2);

int comparatorPriceAscending (const void* struct1, const void* struct2);

int comparatorPriceDescending(const void* , const void* ); 

comparator_f getComparator(int);

uint16_t randomRange(uint16_t , uint16_t );

double randRange(double , double );

char randLetter(bool );

void randString(char *str, uint16_t , uint16_t );

void printArr(Book * arr);


#endif