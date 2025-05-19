/*You are developing firmware for a microcontroller that manages 32 hardware peripherals, each capable of triggering an interrupt. All interrupt flags are stored in a 4-byte array (32 bits total), where:

Each bit i represents the interrupt flag for device i.

A bit set to 1 means the interrupt has been triggered.

The ISR clears the flag once the interrupt has been serviced.
🧩 Your Task:
// Sets the interrupt flag for the given device (0–31)
void trigger_interrupt(uint8_t *flags, int device_id);

// Clears the interrupt flag for the given device
void clear_interrupt(uint8_t *flags, int device_id);

// Returns 1 if the interrupt is pending for the device, 0 otherwise
int is_interrupt_pending(uint8_t *flags, int device_id);
✅ Constraints:
Do not use arrays with int, uint32_t — use a uint8_t flags[4].

Must use pointer arithmetic and bitwise operators.

Must be efficient and clean — no loops required for individual operations.

*/

void trigger_interrupt(uint8_t *flags, int device_id){
    int byte_index = device_id /8;
    int bit_index = device_id %8;

    *(flags + byte_index) |= (1U << bit_index); 
}

void clear_interrupt(uint8_t *flags, int device_id){
    int byte_index = device_id /8;
    int bit_index = device_id %8;

    *(flags + byte_index) &= ~(1U << bit_index); 
}

int is_interrupt_pending(uint8_t *flags, int device_id){
    int byte_index = device_id /8;
    int bit_index = device_id %8;

    return *(flags + byte_index) & (1U << bit_index); 
}



