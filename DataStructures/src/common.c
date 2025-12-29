#include "../include/common.h"

uint8_t getInputUint8(){
    char buffer[16];

    if (fgets(buffer, sizeof(buffer), stdin) != NULL){
        return (uint8_t)atoi(buffer);
    }
    return 0;
} 
