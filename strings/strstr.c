/*Implement strStr(haystack, needle) manually.
Meaning:
You are given two strings:
    haystack: the big string (like a book)
    needle: the small string you want to search (like a word)
Return the index of the first occurrence of needle in haystack.
If needle is not found, return -1.
If needle is an empty string, return 0 (by LeetCode convention).*/

#include <stdio.h>

int strStr(const char *haystack, const char *needle) {

    if(*needle == '\0') return 0; //needle empty return 0

    /*create two pointers*/
    const char *p1 = haystack;
    const char *p2 = needle;

    while(*p1){
        const char *start = p1;

        while(*p1 && *p2 && *p1==*p2){
            p1++;
            p2++;
        }

        if(*p2 == '\0')
        {
            return start -haystack;
        }
        p1 = start +1;
    }
   return -1;
}

int main() {
    const char *haystack = "hello";
    const char *needle = "ll";
    
    printf("First occurrence is at index: %d\n", strStr(haystack, needle));
}

/*How it Works:
p1 moves along haystack
start saves the position where the current attempt started
Try matching character-by-character.
If complete needle is matched (*p2 == '\0'), return the difference (start - haystack)
If mismatch, move p1 one character ahead and try again.*/