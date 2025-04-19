#include "string.h"
#include <stdio.h>

int strcmp_ign_case(char *s1, char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        char c1 = (*s1 >= 'A' && *s1 <= 'Z') ? *s1 + ('a' - 'A') : *s1;
        char c2 = (*s2 >= 'A' && *s2 <= 'Z') ? *s2 + ('a' - 'A') : *s2;

        if (c1 != c2) {
            return c1 - c2;
        }

        s1++;
        s2++;
    }

    return *s1 - *s2;
}
