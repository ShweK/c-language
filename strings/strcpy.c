#include <stdio.h>

char* my_strcpy(char *dest, const char *src){
    char *original = dest;  // Save the original starting point

    while(*src)
    {
        *dest =*src;
        dest++;
        src++;
    }

    *dest ='\0';
    return original; // Return start of dest, not the moved pointer
}

int main() {
    char src[] = "embedded";
    char dest[20];  // Ensure enough space for destination

    my_strcpy(dest, src);

    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    return 0;
}