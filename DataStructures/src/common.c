#include "../include/common.h"

uint8_t getInputUint8(){
    char buffer[16];

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return 0;

    if (strchr(buffer, '\n') == NULL){
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    char *endptr = NULL;
    unsigned long val = strtoul(buffer, &endptr, 10);

    if (endptr != buffer && val <= 255){
        return (uint8_t)val;
    }

    return 0;
}
