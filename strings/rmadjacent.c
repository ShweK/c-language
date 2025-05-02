#include <stdio.h>

void removeAdjacentDuplicates(char *str){

    char *read = str;
    char *write = str;

    while(*read){
        char *start = read;
        while(*read == *(read+1)){
            read++;
        }
        *write = *start;
        read++;
        write++;
    }

    *write = '\0';
}

int main(){
    char str1[] = "abbaca";
    removeAdjacentDuplicates(str1);
    printf("Result: %s\n", str1);

    return 0;
}