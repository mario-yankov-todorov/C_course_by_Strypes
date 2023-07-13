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
    
    int testMacro_1 = 0;
    int testMacro_2 = 0;
    int testBitwiseMacro_1 = 0;
    long testBitwiseMacro_2 = 0;
    putchar('\n');

    // Test MAX
    testMacro_1 = MAX(3, 5, 7);
    printf("Test MAX: %d\n", testMacro_1);
    testMacro_1 = MAX(1, 0, 177);
    printf("Test MAX: %d\n", testMacro_1);
    putchar('\n');

    // Test MIN
    testMacro_2 = MIN(3, 5, 7);
    printf("Test MIN: %d\n", testMacro_2);
    testMacro_2 = MIN(1, 0, 100);
    printf("Test MIN: %d\n", testMacro_2);
    putchar('\n');

    // Test SETBIT / with int and long /
    testBitwiseMacro_1 = 0xeeeeeeee;
    SETBIT(testBitwiseMacro_1, 0);
    printf("Test SETBIT: %x\n", testBitwiseMacro_1);
    testBitwiseMacro_2 = 0xeeeeeeeeeeeeeeee;
    SETBIT(testBitwiseMacro_2, 4);
    printf("Test SETBIT: %lx\n", testBitwiseMacro_2);
    putchar('\n');

    // Test CLEARBIT / with int and long /
    testBitwiseMacro_1 = 0xffffffff;
    CLEARBIT(testBitwiseMacro_1, 0);
    printf("Test CLEARBIT: %x\n", testBitwiseMacro_1);
    testBitwiseMacro_2 = 0xffffffffffffffff;
    CLEARBIT(testBitwiseMacro_2, 4);
    printf("Test CLEARBIT: %lx\n", testBitwiseMacro_2);
    putchar('\n');

    // Test INVERSEBIT / with int and long /
    testBitwiseMacro_1 = 0xf0f0f0f0;
    INVERSEBIT(testBitwiseMacro_1, 8);
    printf("Test INVERSEBIT: %x\n", testBitwiseMacro_1);
    testBitwiseMacro_2 = 0xf0f0f0f0f0f0f0f0;
    INVERSEBIT(testBitwiseMacro_2, 12);
    printf("Test INVERSEBIT: %lx\n", testBitwiseMacro_2);
    putchar('\n');

    // Test CHECKBIT / with int and long /
    testBitwiseMacro_1 = 0xf0f0f0f0;
    testBitwiseMacro_1 = CHECKBIT(testBitwiseMacro_1, 8);
    printf("Test CHECKBIT: %x\n", testBitwiseMacro_1);
    testBitwiseMacro_2 = 0xf0f0f0f0f0f0f0f0;
    testBitwiseMacro_2 = CHECKBIT(testBitwiseMacro_2, 12);
    printf("Test CHECKBIT: %lx\n", testBitwiseMacro_2);
    putchar('\n');

    // Test SWAP
    testMacro_1 = 0;
    testMacro_2 = 1;
    SWAP(testMacro_1, testMacro_2);
    printf("Test SWAP: %d %d\n", testMacro_1, testMacro_2);
    testMacro_1 = 576;
    testMacro_2 = 100;
    SWAP(testMacro_1, testMacro_2);
    printf("Test SWAP: %d %d\n", testMacro_1, testMacro_2);

    putchar('\n');
    
    return 0;
}
