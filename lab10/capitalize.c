#include "string.h"  
#include <stddef.h>
void capitalize(char *s) {
    if (s == NULL) {
        return; 
    }
    int next = 1; 
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
            next = 1;
        } else {
            if (next) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    s[i] -= ('a' - 'A');
                }
                next = 0; 
            } else {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] += ('a' - 'A');
                }
            }
        }
    }
}
