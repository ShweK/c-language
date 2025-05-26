/*Problem Statement:
You are given a block of memory represented as a uint8_t* pointer (byte array). Each bit in this memory represents the status of a device (0 = OFF, 1 = ON). Write a function to:

Set the Nth device ON (i.e., set the Nth bit).

Clear the Nth device (set it OFF).

Check whether the Nth device is ON or OFF.

Assume the memory block is large enough to hold up to 1024 devices.*/


uint8_t memory[128] = {0};  // 128 bytes → 1024 bits → 1024 devices

set_device_status(memory, 17);    // turns ON device #17
clear_device_status(memory, 17);  // turns OFF device #17
is_device_on(memory, 17);         // returns 0



void set_device_status(uint8_t *ptr, int bit){
//Step1 : calculate byte index 
    int byte_index = bit/8; //remeber this 
    int bit_index = bit%8;
    *(ptr + byte_index) |= (1U << bit_index);
}

void clear_device_status(uint8_t *ptr, int bit){
//Step1 : calculate byte index 
    int byte_index = bit/8;
    int bit_index = bit%8;
    *(ptr + byte_index) &= ~(1U << bit_index);
}

int is_device_on(uint8_t *ptr, int bit)
{
    //Step1 : calculate byte index 
    int byte_index = bit/8;
    int bit_index = bit%8;
    return (*(ptr + byte_index) & (1U << bit_index));
}
