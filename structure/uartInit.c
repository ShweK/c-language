#include <stdio.h>
#include <stdint.h>

typedef struct {
    unsigned int baud_rate;
    unsigned char stop_bits;   // 1 or 2
    unsigned char data_bits;   // 8 or 9

    struct {
        unsigned char parity : 2;     // 0=None, 1=Even, 2=Odd
        unsigned char enable_tx : 1;  // 0 = No, 1 = Yes
        unsigned char enable_rx : 1;  // 0 = No, 1 = Yes
        unsigned char reserved : 4;   // Reserved for future use
    };
} UART_Config;

void UART_Init(UART_Config *config) {
    printf("Initializing UART...\n");
    printf("Baud Rate: %u\n", config->baud_rate);
    printf("Parity: %s\n", (config->parity == 0) ? "None" :
                            (config->parity == 1) ? "Even" : "Odd");
    printf("Stop Bits: %u\n", config->stop_bits);
    printf("Data Bits: %u\n", config->data_bits);
    printf("TX Enabled: %s\n", config->enable_tx ? "Yes" : "No");
    printf("RX Enabled: %s\n", config->enable_rx ? "Yes" : "No");

    // Here, you'd normally write to hardware registers based on config.
}

int main() {
    UART_Config my_uart = {
        .baud_rate = 115200,
        .stop_bits = 1,
        .data_bits = 8,
        .parity = 0,
        .enable_tx = 1,
        .enable_rx = 1
    };

    UART_Init(&my_uart);
    return 0;
}