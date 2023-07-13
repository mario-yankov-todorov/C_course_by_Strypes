#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>


// Alternative solutions that look more elegant are added to some functions,
// at a later stage of the C course!  

bool isEmpty(uint64_t set){
    // Check if there are any ones in the set.
    if (set){
        return false;
    }else{
        return true;
    }
    // Alternative solution:
    // uint64_t temp = 0xffffffffffffffff;
    // set = !(set & temp);   
    // return set;
}

uint64_t add(uint64_t set, char index){
    // Use a temporary variable to set the required index.
    uint64_t temp = 1;
    temp = (temp << (63 - index));
    // Use Bitwise OR to add the element to the set according to the given index.
    set = set | temp;
    
    return set;
    // Alternative solution:
    // set |= (1ULL << (63 - index));  
    // return set;
}

uint64_t removee(uint64_t set, char index){
    // Use a temporary variable to set the required index.
    uint64_t temp = 1;
    temp = (temp << (63 - index));
    // Check if the element is present in the set.
    if(set & temp){
        // Use Bitwise XOR to remove the element 
        // of the set according to the given index.
        set = set ^ temp;
    }   
    return set;
    // Alternative solution:
    // set &= ~(1ULL << (63 - index));  
    // return set;
}

bool isFull(uint64_t set){
    uint64_t temp = 0xffffffffffffffff;
    // Check if there are any zeros in the set.
    if(set ^ temp){
        return false;
    }else{
        return true;
    }
}

bool isSubset(uint64_t setA, uint64_t setB){
    // Check if intersection of setA and setB is equal to setB.
    // Check if union of setA and setB is equal to setA.
    if(((setA & setB) == setB) && ((setA | setB) == setA)){
        return true;
    }else{
        return false;
    }
}

uint64_t unionn(uint64_t setA, uint64_t setB){
    // Return the union of the given sets.
    return (setA | setB);
}

uint64_t intersect(uint64_t setA, uint64_t setB){
    // Return the intersect of the given sets.
    return (setA & setB);
}

uint64_t difference(uint64_t setA, uint64_t setB){
    // Return the difference of the given sets.
    return (setA ^ setB);
}

char numElements(uint64_t set){
    // Check if the set has zero elements.
    if (set == 0) {
        return 0;
    }
    // Return recursively!
    return (set & 1) + numElements(set >> 1);
}

int main() {    

    // For convenience, the vectors of various sets are represented in hexadecimal 
    // number system. Above each variable, its binary value is presented as a comment!

    // setA: 0b1111000011110000111100001111000011110000111100001111000011110000;
    uint64_t setA = 0xf0f0f0f0f0f0f0f0;
    // setB: 0b0000111100001111000011110000111100001111000011110000111100001111;
    uint64_t setB = 0x0f0f0f0f0f0f0f0f;
    // setC: 0b1100110011001100110011001100110011001100110011001100110011001100;
    uint64_t setC = 0xcccccccccccccccc;
    // setD: 0b0011001100110011001100110011001100110011001100110011001100110011;
    uint64_t setD = 0x3333333333333333; 
    // setE: 0b0000000000000000000000000000000000000000000011110000111100001111;
    uint64_t setE = 0x00000000000f0f0f;
    // setF: 0b1111000011110000111100000000000000000000000000000000000000000000;
    uint64_t setF = 0xf0f0f00000000000; 
    // setG: 0b0000000000000000000000000000000000000000000011001100110011001100;
    uint64_t setG = 0x00000000000ccccc;
    // setH: 0b1111111111111111111111111111111111111111111111111111111111111111;
    uint64_t setH = 0xffffffffffffffff;
    // setI: 0b0000000000000000000000000000000000000000000000000000000000000000;
    uint64_t setI = 0x0000000000000000;


    printf("\nFunction isEmpty, with argument %016lx return: %d", setA, isEmpty(setA));
    printf("\nFunction isEmpty, with argument %016lx return: %d\n", setI, isEmpty(setI));

    printf("\nFunction add, with arguments %016lx and %d return: %lx", setA, 55, add(setA, 55));
    printf("\nFunction add, with arguments %016lx and %d return: %lx\n", setA, 52, add(setA, 52));

    printf("\nFunction removee, with arguments %016lx and %d return: %lx", setA, 56, removee(setA, 56));
    printf("\nFunction removee, with arguments %016lx and %d return: %lx\n", setA, 59, removee(setA, 59));

    printf("\nFunction isFull, with argument %016lx return: %d", setA, isFull(setA));
    printf("\nFunction isFull, with argument %016lx return: %d\n", setH, isFull(setH));

    printf("\nFunction isSubset, with arguments %016lx and %016lx return: %d", setB, setE, isSubset(setB, setE));
    printf("\nFunction isSubset, with arguments %016lx and %016lx return: %d\n", setB, setC, isSubset(setB, setC));

    printf("\nFunction unionn, with arguments %016lx and %016lx return: %016lx", setF, setG, unionn(setF, setG));
    printf("\nFunction unionn, with arguments %016lx and %016lx return: %016lx\n", setA, setD, unionn(setA, setD));

    printf("\nFunction intersect, with arguments %016lx and %016lx return: %016lx", setA, setB, intersect(setA, setB));
    printf("\nFunction intersect, with arguments %016lx and %016lx return: %016lx\n", setB, setE, intersect(setB, setE));

    printf("\nFunction difference, with arguments %016lx and %016lx return: %016lx", setB, setE, difference(setB, setE));
    printf("\nFunction difference, with arguments %016lx and %016lx return: %016lx\n", setH, setG, difference(setH, setG));

    printf("\nFunction numElements, with argument %016lx return: %d", setH, numElements(setH));
    printf("\nFunction numElements, with argument %016lx return: %d\n", setG, numElements(setG));

    printf("\n");


    return 0;
}
