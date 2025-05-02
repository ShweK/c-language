#include <stdio.h>
#include <stdint.h>
typedef union{
    struct {
        unsigned char ready : 1;
        unsigned char error : 1;
        unsigned char busy  : 1;
        unsigned :5;
    };

 int value;
}StatusReg;

/*uint32_t *statusval = (uint32_t*)&status_v;
printf("Status reg values %08x\n", *statusval);
This is undefined behavior, because:

You're casting a struct Status (probably 1 byte) to a uint32_t* (which reads 4 bytes).

So the program prints whatever is in those 4 bytes in memory — including any garbage from padding or stack leftovers.

✅ How to Fix It Properly
To get a clean result and safe behavior, use a union with a backing integer value.
*/

int main()
{
    StatusReg status_v = {0};    // init to 0

    status_v.ready =1;
    status_v.busy = 1;

    printf("Status reg values %d\n", status_v.value);

}