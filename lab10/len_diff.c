#include "string.h"
#include <stdio.h>

int len_diff(char *s1, char *s2) {
    int len1 = 0, len2 = 0;

    while (*s1) {
        s1++;
        len1++;
    }
    while (*s2) {
        s2++;
        len2++;
    }
    return len1 - len2;
}