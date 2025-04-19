#include "string.h"  
#include <stdlib.h>

char* pad(char *s, int d) {
    if (s == NULL || d <= 0) {
        return NULL;
    }

    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    
    if (len % d == 0) {
        char* copy = (char*) malloc(len + 1); 
        if (copy == NULL) {
            return NULL;
        }
        for (int i = 0; i < len; i++) {
            copy[i] = s[i];
        }
        copy[len] = '\0';
        return copy; 
    }

    int padding = d - (len % d);  
    int new_len = len + padding;

    char *new_str = (char*) malloc(new_len + 1);  

    if (new_str == NULL) {
        return NULL;  
    }


    for (int i = 0; i < len; i++) {
        new_str[i] = s[i];
    }

   
    for (int i = len; i < new_len; i++) {
        new_str[i] = ' ';
    }

    new_str[new_len] = '\0';

    return new_str; 
}