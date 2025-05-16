/*You are given a list of 32-bit unsigned integers representing hardware interrupt registers from different cores. 
Each bit set in a register indicates that an interrupt occurred at that bit index. You need to:

✅ Task:
Return the total number of unique interrupt lines (bit positions) that are active across all cores.*/


#include <stdio.h>
#include <stdint.h>

int find_lsb_position(uint32_t n)
{
    if(n==0) return -1;
    int pos =0;
    while((n&1)==0)
    {
        pos++;
        n = n>>1;
    }
    return pos;
}


void print_active_interrupt_lines(uint32_t regs[], int n) {
    uint32_t combined = 0;

    for (int i = 0; i < n; i++) {
        combined |= regs[i];
    }

    while (combined) {
        int pos = find_lsb_position(combined);
        printf("Interrupt line active at bit: %d\n", pos);
        combined &= (combined - 1);  // Clear that LSB
    }
}

int main() {
    uint32_t regs[] = {0b00010010, 0b00000010, 0b01000000};
    int n = sizeof(regs)/sizeof(regs[0]);

    print_active_interrupt_lines(regs, n);
    return 0;
}