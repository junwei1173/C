#include "string.h" 
#include <stdio.h>
void shorten(char *s, int new_len) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (i == new_len) {
            s[i] = '\0';  
            break;
        }
    }
}
