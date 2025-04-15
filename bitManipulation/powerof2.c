#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n)
{
    return  n && !(n&(n-1));
}

int main()
{
    int n = 8;
    printf("%d %s power of 2 \n",n,isPowerOfTwo(n)?"is" : "is not");
    n =13;
    printf("%d %s power of 2 \n",n,isPowerOfTwo(n)?"is" : "is not");
    return 0;
}