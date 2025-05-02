#include <stdio.h>
#include <stdint.h>

struct GPIO{

    unsigned int pin0 : 1;
    unsigned int pin1 : 1;
    unsigned int pin2 : 1;
    unsigned int pin3 : 1;
    unsigned int pin4 : 1;
    unsigned int pin5 : 1;
    unsigned int pin6 : 1;
    unsigned int pin7 : 1;
    unsigned int reserved : 31;
};

int main(){

    struct GPIO gpio_reg = {0};

    gpio_reg.pin0 =1;
    gpio_reg.pin2 = 1;

    uint32_t *regval = (uint32_t*)&gpio_reg;
    printf("GPIO register value : 0x%08x\n", *regval);
}