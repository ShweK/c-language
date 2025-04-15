#include <stdio.h>
#include <string.h>

int bin2dec(char *bin){

    int ans = 0;
    int len = strlen(bin); // critical error, dont use sizeof rather strlen

    for(int i = 0; i < len; i++)
    {
        if(bin[i] == '1')
        {
            ans = ans*2 +1;
        }
        else if(bin[i] == '0')
        {
            ans = ans*2;
        }
        else
        {
            printf("invalid character");
            return -1;
        }
    }

    return ans;
}

int main(){
    char *bin = "1010";
    if(bin2dec(bin) !=-1)
    {
        printf("bin conversion of %s to decimal is %d",bin, bin2dec(bin));
    }
}