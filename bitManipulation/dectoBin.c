#include <stdio.h>
#include <string.h>

void dectoBin(int dec, char *bin, int size)
{
    //edge case
    if(dec == 0)
    {
        strcpy(bin, "0");
        return;
    }

    int index =0;
    char temp[33];
    while(dec>0)
    {
        temp[index] = dec%2 + '0'; // dont forget to add '0' to convert to string
        dec = dec/2;
        index++;
    }

    for(int i =0; i<index; i++)
    {
        bin[i] = temp[index -1 -i];
        printf("bin[%d]:%d \n",i,bin[i]);
    }
    bin[index] = '\0'; // to convert to string

}


int main()
{
    int dec = 10;
    char bin[33];
    dectoBin(dec, bin, sizeof(bin));

    printf("dec convesion of %d to bin is %s",dec,bin);

    return 0;
}