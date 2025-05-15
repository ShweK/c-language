/*Given a stream of uint16_t values, print them in ascending order without duplicates.*/

#include <stdio.h>
#include <stdint.h>

#define MAX_VAL 65536
#define BITSET_SIZE (MAX_VAL / 8)

void print_unique_sorted_records(const uint16_t *records, size_t count) {
    if (!records || count == 0) {
        printf("No valid records found\n");
        return;
    }

    // LOCAL bitset, not static
    uint8_t seen[BITSET_SIZE] = {0};   // create a bitset array of 8192 Bytes

    for (size_t i = 0; i < count; i++) {
        uint16_t val = records[i];
        if (val < MAX_VAL) {
            seen[val / 8] |= 1 << (val % 8);   //set the bit
        }
    }

    printf("sorted unique values:\n");
    for (uint32_t  val = 0; val < MAX_VAL; val++) {
        if (seen[val / 8] & (1 << (val % 8))) {
            printf("%u ", val);
        }
    }
    printf("\n");
}

int main() {
    uint16_t val[] = {200, 700, 100, 600, 500};
    size_t count = sizeof(val) / sizeof(val[0]);

    print_unique_sorted_records(val, count);
    return 0;
}