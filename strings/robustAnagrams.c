#include <stdio.h>
#include <stdbool.h>
int string_length(const char *str);
bool are_anagrams(const char* str1, const char* str2);


bool isAlphanumberic(char c){
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));

}

char convert_tolower(char c){
    return (c >= 'A' && c<= 'Z') ? (c + 32) : c;
    }

    
bool are_clean_anagrams(const char* str1, const char* str2) {

    int freq[26] = {0};

    const char *p1 = str1;
    const char *p2 = str2;

    while (*p1) {
        if(isAlphanumberic(*p1)){
            freq[convert_tolower(*p1) -'a']++;
        }
        p1++;
    }

    while (*p2) {
        if(isAlphanumberic(*p2)){
            freq[convert_tolower(*p2) -'a']--;
        }
        p2++;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) return false;
    }

    return true;
}

int main() {
    const char* tests[][2] = {
        {"Dormitory", "Dirty room!"},
        {"The eyes", "They see"},
        {"Astronomer", "Moon starer"},
        {"Hello", "World"},
        {"A decimal point", "I'm a dot in place"},
        {"School master", "The classroom"},
        {"", ""},
        {"A", "a"},
        {"abc123", "cba"},
        {"Not", "an Anagram"}
    };

    for (int i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        printf("Test %d: \"%s\" vs \"%s\" → %s\n",
            i + 1,
            tests[i][0],
            tests[i][1],
            are_clean_anagrams(tests[i][0], tests[i][1]) ? "Anagram" : "Not Anagram");
    }

    return 0;
}