

#include <stdio.h>

unsigned int extract_device_id(unsigned int reg);
void set_device_id(unsigned int *reg, unsigned int id);


unsigned int extract_device_id(unsigned int reg){
    int width =8, pos =8;
    unsigned int mask =0;
    mask = ((1U<<width)-1)<<pos;
    return (reg&mask)>>pos; 
}

void set_device_id(unsigned int *reg, unsigned int id)
{
    int width =8, pos =8;
    unsigned int mask =((1U<<width)-1)<<pos;
    *reg = *reg &~mask; //clear the device Id
    *reg = *reg | ((id&((1U<<width)-1))<<width);
}



int main(){
    unsigned int reg = 0x12345678;

    unsigned int device_id = extract_device_id(reg);
    printf("Extracted Device ID: 0x%X (%u)\n", device_id, device_id);  // Expect: 0x56 (86)

    set_device_id(&reg, 0xAB);  // Set new device ID
    printf("Updated Register: 0x%X\n", reg);  // Expect: 0x1234AB78

    return 0;
}