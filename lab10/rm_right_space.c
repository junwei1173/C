#include "string.h"  
#include <stdio.h>
void rm_right_space(char *s) {
    int end = 0;

    while (s[end] != '\0') {
        end++;
    }

    end--; 
    while (end >= 0 && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')) {
        end--;
    }
    s[end + 1] = '\0';
}
