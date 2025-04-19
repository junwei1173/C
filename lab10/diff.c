#include "string.h" 
#include <stdio.h>
int diff(char *s1, char *s2) {
    int diff_count = 0;

    while (*s1 && *s2) {
        if (*s1 != *s2) {
            diff_count++;  
        }
        s1++;
        s2++;
    }

    while (*s1) {
        diff_count++;
        s1++;
    }
    while (*s2) {
        diff_count++;
        s2++;
    }

    return diff_count;
}
