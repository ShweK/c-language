#include <stdio.h>
#include <stdbool.h>
int string_length(const char *str);
bool are_anagrams(const char* str1, const char* str2);

int string_length(const char *str){

    int len =0;
    while(*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}

bool are_anagrams(const char* str1, const char* str2) {
    if (string_length(str1) != string_length(str2)) {
        return false;
    }

    int freq[26] = {0};

    while (*str1 != '\0' && *str2 != '\0') {
        freq[*str1 - 'a']++;
        freq[*str2 - 'a']--;
        str1++;
        str2++;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) return false;
    }

    return true;
}

int main(){

    printf("Anagram test (listen/silent): %s\n", are_anagrams("listen", "silent") ? "Yes" : "No");
    printf("Anagram test (hello/world): %s\n", are_anagrams("hello", "world") ? "Yes" : "No");
    
}