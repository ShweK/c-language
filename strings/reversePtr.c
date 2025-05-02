#include <stdio.h>

int stringLength(char* str)
{
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

void reverse_string(char* str)
{
    int len = stringLength(str);
    int i = 0;
    int j = len - 1;

    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    char str[] = "AUTOSAR";
    printf("Original string: %s\n", str);

    reverse_string(str);

    printf("Reversed string: %s\n", str);

    return 0;
}