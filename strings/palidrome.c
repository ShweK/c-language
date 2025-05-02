#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalidrome(char *str){
    int i =0;
    int j = strlen(str) -1;
    while(i < j)
        {
            if(str[i++]!=str[j--]) return false;
        }

    return true;
}


int main(){

    char str[] = "madam";
    printf("Str: %s is a palidrome?- %s\n", str, isPalidrome(str) ? "true": "false");
}