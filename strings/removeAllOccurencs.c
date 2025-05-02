#include <stdio.h>
#include <string.h>

void removeOccurence(char *str, const char *ch){

    
    char *read = str;
    char *write = str;
    const char *p2 = ch;

    while(*read){
        char *start = read;
         // Check if substring matches here
        while(*start && *p2 && *start == *p2){
            // Match found: skip over substring
            start++;
            p2++; 
        }
        if(*p2 =='\0')
        {
            read = start;
        }
        else{
            // No match: copy character
        *write = *read;
        read++;
        write++;
        }
    }
    *write = '\0';
}

int main() {
     char str[] = "abccabcc";
     char *ch = "abc";
    removeOccurence(str, ch);
    printf("after removal of occurance: %s\n", str);
}