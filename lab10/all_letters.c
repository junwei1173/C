#include "string.h"  
#include <stdio.h>
#include <ctype.h> 

int all_letters(char *s) {
    while (*s) {  
        if (*s != ' ' && !isalpha(*s)) { 
            return 0;  
        }
        s++;  
    }
    return 1; 
}