#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;

    for (int i = 0; i < 32; i++) {
        result <<= 1;          // Make space for the next bit
        result |= (n & 1);     // Copy LSB of n into result
        n >>= 1;               // Move to next bit
    }

    return result;
}

int main() {
    uint32_t n = 13;
    uint32_t reversed = reverseBits(n);

    printf("Input: %u\n", n);
    printf("Reversed Bits Output: %x\n", reversed);
    return 0;
}