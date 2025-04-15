#include <stdio.h>
#include <stdbool.h>
//Check number even or odd without % operator

bool isEven(int num)
{

    if((num&1) == 0)
    {
        return true;
    }

    return false;

}

int main(){
    int num;

    printf("enter num: ");
    scanf("%d",&num);

    printf("Number %d is : %s\n", num, isEven(num) ? "even": "odd");
    return 0;

}