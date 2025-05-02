/* Question: Create a buffer of 10 Packets. Access the 5th one and update payload using pointer arithmetic.*/
#include <stdio.h>


#define PACKET_BUFFER 10
struct Packet {
    char header;
    char payload[4];
    char checksum;
};

int main()
{
    struct Packet packets[PACKET_BUFFER] ={0};

    struct Packet *ptr = packets;
    (ptr + 5)->checksum =4;
    (ptr + 5)->payload[0] =5;
    (ptr + 5)->payload[1] =6;
    printf("Access the 5th packet checksum %d\n", (ptr + 5)->checksum);
    printf("Access the 5th packet checksum %d\n", (ptr + 5)->payload[0]);

    return 0;
}