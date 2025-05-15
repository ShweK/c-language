#include <stdio.h>

void* my_memcpy(void *dest, const void *src, size_t n) {
    char *d = (char *)dest;
    const char *s = (const char *)src;

    while (n--) {
        *d++ = *s++;
    }
    return dest;
}
int main(){
char src[10] = "OpenAI";
char dest[10];
my_memcpy(dest, src, 6);
printf("%s\n", dest);  
}