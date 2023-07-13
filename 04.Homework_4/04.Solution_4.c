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
    int testBitwiseMacro = 0;
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

    // Test SETBIT
    testBitwiseMacro = 0xeeeeeeee;
    SETBIT(testBitwiseMacro, 0);
    printf("Test SETBIT: %x\n", testBitwiseMacro);
    testBitwiseMacro = 0xeeeeeeee;
    SETBIT(testBitwiseMacro, 4);
    printf("Test SETBIT: %x\n", testBitwiseMacro);
    putchar('\n');

    // Test CLEARBIT
    testBitwiseMacro = 0xffffffff;
    CLEARBIT(testBitwiseMacro, 0);
    printf("Test CLEARBIT: %x\n", testBitwiseMacro);
    testBitwiseMacro = 0xffffffff;
    CLEARBIT(testBitwiseMacro, 4);
    printf("Test CLEARBIT: %x\n", testBitwiseMacro);
    putchar('\n');

    // Test INVERSEBIT
    testBitwiseMacro = 0xf0f0f0f0;
    INVERSEBIT(testBitwiseMacro, 8);
    printf("Test INVERSEBIT: %x\n", testBitwiseMacro);
    testBitwiseMacro = 0xf0f0f0f0;
    INVERSEBIT(testBitwiseMacro, 12);
    printf("Test INVERSEBIT: %x\n", testBitwiseMacro);
    putchar('\n');

    // Test CHECKBIT
    testBitwiseMacro = 0xf0f0f0f0;
    testBitwiseMacro = CHECKBIT(testBitwiseMacro, 8);
    printf("Test CHECKBIT: %x\n", testBitwiseMacro);
    testBitwiseMacro = 0xf0f0f0f0;
    testBitwiseMacro = CHECKBIT(testBitwiseMacro, 12);
    printf("Test CHECKBIT: %x\n", testBitwiseMacro);
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
