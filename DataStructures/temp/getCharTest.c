#include "../include/common.h"

// The buffer is an array that will allocate the characters of the user input
// fgets() will read and store the input inside the buffer, if the input is empty or overflow then is NULL
// strtoul -> string to unsigned long int

int main(){
    char buffer[16]; // The buffer reads up to 15 characters

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return 0;
    
    if (strchr(buffer, '\n') == NULL) // This will look for the char '\n' if not then NULL
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    char *endptr = NULL;

    unsigned long int val = strtoul(buffer, &endptr, 10);
    
    if (endptr != buffer && val <= 255) // endptr != buffer checks if endptr has been moved or not
        printf("%lu\n", val);


    printf("\n");
    return 0;
}
