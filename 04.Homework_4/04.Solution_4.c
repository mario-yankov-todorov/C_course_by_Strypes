#include <stdio.h>

#define MAX(x, y, z) ( (x > y && x > z) ? x : ( y > z) ? y : z ) 
#define MIN(x, y, z) ( (x < y && x < z) ? x : ( y < z) ? y : z )

#define SETBIT(mask, bit) mask |= (1ULL << (bit)) 
#define CLEARBIT(mask, bit) mask &= ~(1ULL << (bit)) 
#define INVERSEBIT(mask, bit) mask ^= (1ULL << (bit)) 

#define CHECKBIT(mask, bit) (mask & (1ULL << (bit))) ? 1 : 0 
// Alternative solution for CHECKBIT:
// #define CHECKBIT(mask, bit) !!(mask & (1ULL << (bit))

// SWAP macro implemented only through the XOR operator!
#define SWAP(a, b) {         \
                    a ^= b;  \
                    b ^= a;  \
                    a ^= b; }

int main(){
    

    return 0;
}