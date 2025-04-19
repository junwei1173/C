#include "string.h"  
#include <stdio.h>
void rm_left_space(char *s) {
    int i = 0, j = 0;

    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
        i++;
    }

    while (s[i] != '\0') {
        s[j++] = s[i++];
    }
    s[j] = '\0';
}
