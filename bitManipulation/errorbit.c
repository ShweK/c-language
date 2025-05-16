/*You are given a system register that stores sensor status bits. Each bit represents whether a sensor has a fault (1) or is healthy (0). Due to a firmware bug, up to 2 bits may flip incorrectly.

You are also given the correct expected pattern, and your task is to:

Compare the current register with the expected pattern.

Return the positions of the flipped bits (if any).

If the number of flipped bits > 2, return -1 to indicate invalid correction.
*/

#include <stdio.h>

// Function to find the index of the least significant set bit (LSB)
int find_lsb_position(unsigned int val) {
    for (int i = 0; i < 32; i++) {
        if ((val >> i) & 1)
            return i;
    }
    return -1;  // shouldn't happen if val != 0
}

int find_error_bits(unsigned int current, unsigned int expected, int result[2]) {
    unsigned int diff = current ^ expected;  //XOR to check the difference at bit level
    int count = 0;

    while (diff && count < 3) {
        int pos = find_lsb_position(diff);
        if (count < 2) {
            result[count] = pos;
        }
        count++;
        diff &= (diff - 1);  // Clear the least significant set bit
    }

    return (count > 2) ? -1 : count;
}

int main() {
    unsigned int current = 0x0D;    // 00001101
    unsigned int expected = 0x08;   // 00001000
    int result[2] = {-1, -1};

    int count = find_error_bits(current, expected, result);

    if (count == -1) {
        printf("Too many flipped bits.\n");
    } else {
        printf("Flipped bits: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    return 0;
}

while(n)
{
    res ^=n&1;
    n = n>>1;
}

return !res;