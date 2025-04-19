#include "string.h" 
#include <stddef.h>
char *dedup(char *s) { 
    if (s == NULL) {
        return NULL;  
    }

    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    int index = 0; 
    for (int i = 0; i < len; i++) {
        int j;
        for (j = 0; j < index; j++) {
            if (s[j] == s[i]) {
                break;  
            }
        }

        if (j == index) {
            s[index++] = s[i];
        }
    }

    s[index] = '\0'; 
    return s; 
}