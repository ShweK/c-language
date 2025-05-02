#include <stdio.h>
#include <ctype.h>  // for isdigit()


void sanitize_logs(char *log) {
    char *read = log;
    char *write = log;

    while (*read) {
        // Check for start of "Patient ID:"
        if (*read == 'P' && 
            *(read + 1) == 'a' && 
            *(read + 2) == 't' && 
            *(read + 3) == 'i' && 
            *(read + 4) == 'e' && 
            *(read + 5) == 'n' && 
            *(read + 6) == 't' && 
            *(read + 7) == ' ' && 
            *(read + 8) == 'I' && 
            *(read + 9) == 'D' && 
            *(read + 10) == ':') 
        {
            // Skip "Patient ID:" (11 characters)
            read += 11;

            // Now skip all digits following "Patient ID:"
            while (isdigit(*read)) {
                read++;
            }
        } 
        else {
            // Normal character, copy
            *write++ = *read++;
        }
    }
    *write = '\0';  // Null terminate the sanitized string
}

int main() {
    char log[] = 
    "LOG: Patient ID:12345\n"
    "LOG: Heartbeat: 70 bpm\n"
    "LOG: Patient ID:67890\n";

    printf("Original Log:\n%s\n", log);

    sanitize_logs(log);

    printf("\nSanitized Log:\n%s\n", log);

    return 0;
}