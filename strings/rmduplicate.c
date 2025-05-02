#include <stdio.h>
#include <stdbool.h>

void remove_duplicates(char* str){

    bool seen[256] ={false};
    char *read = str;
    char *write = str; 

    while(*read != '\0')
    {
        if(seen[*read] == false){
        seen[*read] = true;
        *write = *read;
        write++;
        }         
    read++;     
    }
    *write = '\0';
}

int main()
{
    char str[] = "embedded";
    printf("original string %s\n",str);
    remove_duplicates(str);
    printf("modified string %s\n",str);
}

