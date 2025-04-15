/* CoderPad C Cheat Sheet for Embedded Security Assessment */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

/***** 1. Pointer and Memory Manipulation *****/

struct Node {
    int data;
    struct Node* next;
};

void reverseLinkedList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

bool detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

void* my_memcpy(void* dest, const void* src, size_t n) {
    char* d = (char*)dest;
    const char* s = (const char*)src;
    for (size_t i = 0; i < n; i++)
        d[i] = s[i];
    return dest;
}

/***** 2. Bit Manipulation *****/

int countSetBits(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

bool isPowerOfTwo(unsigned int n) {
    return n && !(n & (n - 1));
}

unsigned int reverseBits(unsigned int n) {
    unsigned int result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}

void reverse_and_count(uint32_t input, uint32_t* reversed, int* set_bits) {
    *reversed = 0;
    *set_bits = 0;
    for (int i = 0; i < 32; i++) {
        *reversed <<= 1;
        if (input & 1) {
            *reversed |= 1;
            (*set_bits)++;
        }
        input >>= 1;
    }
}

/***** 3. Secure String Handling *****/

void safe_str_copy(char* dest, const char* src, size_t dest_size) {
    if (dest_size == 0) return;
    strncpy(dest, src, dest_size - 1);
    dest[dest_size - 1] = '\0';
}

/***** 4. Endianness Check *****/

bool isLittleEndian() {
    uint16_t num = 1;
    return (*(uint8_t*)&num == 1);
}

uint32_t swapEndian(uint32_t num) {
    return ((num >> 24) & 0xFF) |
           ((num << 8) & 0xFF0000) |
           ((num >> 8) & 0xFF00) |
           ((num << 24) & 0xFF000000);
}

/***** 5. Volatile & Const Example *****/

volatile int sensor_data; // Might be updated by interrupt/ISR
const int threshold = 100; // Read-only constant

/***** 6. Secure Input Handling *****/

void readInput(char* buffer, size_t size) {
    if (fgets(buffer, size, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // remove newline
    }
}

/***** 7. Detect Integer Overflow *****/

bool safe_add(int a, int b, int* result) {
    if ((b > 0 && a > INT_MAX - b) ||
        (b < 0 && a < INT_MIN - b)) {
        return false;
    }
    *result = a + b;
    return true;
}

/***** 8. Ring Buffer Skeleton *****/

#define RING_SIZE 8
char ring[RING_SIZE];
int head = 0, tail = 0;

bool ring_push(char c) {
    int next = (head + 1) % RING_SIZE;
    if (next == tail) return false; // buffer full
    ring[head] = c;
    head = next;
    return true;
}

bool ring_pop(char* c) {
    if (head == tail) return false; // buffer empty
    *c = ring[tail];
    tail = (tail + 1) % RING_SIZE;
    return true;
}

/***** 9. CRC-16 Checksum (Polynomial 0x8005) *****/

uint16_t crc16(const uint8_t* data, size_t len) {
    uint16_t crc = 0xFFFF;
    for (size_t i = 0; i < len; i++) {
        crc ^= data[i] << 8;
        for (int j = 0; j < 8; j++) {
            if (crc & 0x8000)
                crc = (crc << 1) ^ 0x8005;
            else
                crc <<= 1;
        }
    }
    return crc;
}

/***** 10. Mini Assessment Questions *****/

// Q2: Memory corruption detection with guard
#define GUARD 0xDEADBEEF

typedef struct {
    char data[48];
    uint32_t guard;
} SafeBlock;

bool write_to_block(SafeBlock* blk, const char* input) {
    strncpy(blk->data, input, sizeof(blk->data) - 1);
    blk->data[sizeof(blk->data) - 1] = '\0';
    blk->guard = GUARD;
    return true;
}

bool check_guard(SafeBlock* blk) {
    return blk->guard == GUARD;
}

// Q3: Simulated Race Condition
volatile int shared_counter = 0;

void increment_no_lock() {
    for (int i = 0; i < 10000; i++) {
        shared_counter++;
    }
}

void increment_with_lock(int* counter) {
    for (int i = 0; i < 10000; i++) {
        __sync_fetch_and_add(counter, 1); // atomic increment
    }
}

/***** Main for Testing *****/

int main() {
    printf("Endianness: %s\n", isLittleEndian() ? "Little" : "Big");
    printf("Reverse Bits of 9: %u\n", reverseBits(9));
    printf("Set Bits in 15: %d\n", countSetBits(15));

    char buffer[20];
    printf("Enter a string: ");
    readInput(buffer, sizeof(buffer));
    printf("You entered: %s\n", buffer);

    const uint8_t crc_data[] = {0x12, 0x34, 0x56, 0x78};
    printf("CRC16: 0x%X\n", crc16(crc_data, sizeof(crc_data)));

    // Test reverse_and_count
    uint32_t input = 0xF0F0F0F0, reversed;
    int bits;
    reverse_and_count(input, &reversed, &bits);
    printf("Original: 0x%X, Reversed: 0x%X, Set Bits: %d\n", input, reversed, bits);

    // Test SafeBlock
    SafeBlock blk;
    write_to_block(&blk, "Safe write");
    printf("Block Guard Check: %s\n", check_guard(&blk) ? "PASS" : "FAIL");

    // Test Race Simulation
    shared_counter = 0;
    increment_no_lock();
    increment_no_lock();
    printf("Without Lock: %d\n", shared_counter);

    int atomic_counter = 0;
    increment_with_lock(&atomic_counter);
    increment_with_lock(&atomic_counter);
    printf("With Atomic: %d\n", atomic_counter);

    return 0;
}
