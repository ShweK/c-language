#include <stdio.h>

int countSetBits(int num){
     int count =0;
    while(num>0)
    {
        if(num&1)
        {
            count ++;
        }
        num = num >>1;
    }

    return count;
}


int main()
{
    int num = 7;
    int count =0;

    count = countSetBits(num);
    printf("total set bits in %d:%d \n", num, count);
}