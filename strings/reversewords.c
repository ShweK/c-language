#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void reverse(char *s, int st, int end){

    while(st<end)
    {
        char temp = s[st];
        s[st++] = s[end];
        s[end--]= temp;
    }
}


char *reverseWords(char *s){

    int len = strlen(s);
    //step1 : reverse the entire sting
    reverse(s, 0, len-1);

    //step2 : extract the word and reverse
    int read =0;

    while(read < len)
    {
        while(read < len && s[read] == ' ') read++; //skip the space
        int start = read;
        while(read < len && s[read] != ' ')read++; //extract the word
        reverse(s, start, read-1);  //reverse the word
    }

    //step 3 update the final string by removing extra spaces
    read =0;
    int wrt =0;

    while(read<len)
    {
         while(read < len && s[read] == ' ') read++; //skip the space
         while(read < len && s[read] != ' ')s[wrt++] =s[read++];//write the word
         while(read < len && s[read] == ' ') read++; //skip the space
         if(read <len)s[wrt++]=' '; //add an spae after writing one word
    }
    s[wrt] = '\0';
    return s;
}



// ---------- Helper function for comparison ----------
bool compare(const char* result, const char* expected) {
    return strcmp(result, expected) == 0;
}

// ---------- Test Runner ----------
void runTest(char* input, const char* expected, int testNum) {
    char buffer[1024];
    strcpy(buffer, input); // create a mutable buffer
    char* result = reverseWords(buffer);

    printf("Test %d: %s\n", testNum, compare(result, expected) ? "PASS ✅" : "FAIL ❌");
    if (!compare(result, expected)) {
        printf("  Input:    \"%s\"\n", input);
        printf("  Output:   \"%s\"\n", result);
        printf("  Expected: \"%s\"\n", expected);
    }
}

// ---------- Main Function with Unit Tests ----------
int main() {
    runTest("  the sky is blue  ", "blue is sky the", 1);
    runTest("hello", "hello", 2);
    runTest("  a  good   example ", "example good a", 3);
    runTest("   multiple    spaces  here ", "here spaces multiple", 4);
    runTest("a", "a", 5);
    runTest("   abc  ", "abc", 6);
    return 0;
}