#include <stdio.h>

void set_pin(unsigned int *port, int pin);      // Sets a pin HIGH
void clear_pin(unsigned int *port, int pin);    // Sets a pin LOW
int read_pin(unsigned int port, int pin);       // Returns pin state (0 or 1)
void toggle_pin(unsigned int *port, int pin);   // Toggles the state of a pin
unsigned int make_mask(int pos, int width);     //Write a function that creates a bitmask of width w starting at bit position pos.
void set_field(unsigned int *reg, int val, int pos, int width); //Write a function to set a value val inside a field starting at position pos with width width
void toggle_alternate_bits(unsigned int *reg);                 //Write a function that toggles every alternate bit in a 32-bit register, starting from the Least Significant Bit (bit 0).
void update_gpio(unsigned int *reg);//WAF :  toggle the state of all even-numbered pins (0, 2, 4...) and clear all odd-numbered pins (1, 3, 5...).

void set_pin(unsigned int *port, int pin){
    *port = *port|(1U<<pin);                //The U suffix ensures the shift doesn’t cause signed overflow.
}

void clear_pin(unsigned int *port, int pin){
    *port = *port&(~(1U<<pin));
}

void toggle_pin(unsigned int *port, int pin){
    *port = *port^(1U<<pin);
}

int read_pin(unsigned int port, int pin){
    return (port&(1U<<pin)) !=0;            //This avoids the shift and directly returns a boolean-like 0 or 1.
}

unsigned int make_mask(int pos, int width){

    unsigned int mask = 0x00;
    int count = 1;
    while(count<=width)
    {
        mask = mask|(1U<<pos);
        pos++;
        count ++;
    }
    return mask;

    /*another easy way without while loop*/
    //return (1U<<width)-1)<<pos; 
}

void set_field(unsigned int *reg, int val, int pos, int width){
    unsigned int mask = 0x0;

    mask = ((1U<<width)-1)<<pos;
    *reg = *reg&~mask; // imp : clear the required fields
    *reg = *reg|((((1U<<width)-1)&val)<<pos);
}

void toggle_alternate_bits(unsigned int *reg){
    //unsigned int odd_mask = 0xAAAAAAAA;
    unsigned int evn_mask = 0x55555555;
    *reg= *reg^evn_mask;
}

void update_gpio(unsigned int *reg)
{
    unsigned int even_mask = 0x55555555, odd_mask = 0xAAAAAAAA;

    *reg = *reg^even_mask;
    *reg = *reg&~odd_mask;
}

int main(){
    unsigned int port = 0;

    set_pin(&port, 3);       // Sets pin 3
    set_pin(&port, 5);       // Sets pin 5
    clear_pin(&port, 3);     // Clears pin 3
    toggle_pin(&port, 5);    // Toggles pin 5 (should go LOW)
    printf("%d\n", read_pin(port, 3));  // Output: 0
    printf("%d\n", read_pin(port, 5));  // Output: 0

    printf("%x\n",make_mask(4,3));
    printf("%x\n",make_mask(0, 5));

    unsigned int reg = 0xFFFF0000;
    set_field(&reg, 5, 4, 3);
    printf("%x\n",reg); // set bits 4-6 to binary 101

    unsigned int reg1 = 0XAAAAAAAA;
    toggle_alternate_bits(&reg1);
    printf("%x\n",reg1);

    reg1 = 0xFFFFFFFF;
    update_gpio(&reg1);
    printf("%x\n",reg1);
    return 0;
}