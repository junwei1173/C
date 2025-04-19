#include "string.h" 
#include <stddef.h>
int ends_with_ignore_case(char *s, char *suff) {
    if (s == NULL || suff == NULL) {
        return 0;  
    }

    int s_len = 0;
    int suff_len = 0;

    while (s[s_len] != '\0') {
        s_len++;
    }

    while (suff[suff_len] != '\0') {
        suff_len++;
    }

    if (suff_len > s_len) {
        return 0;
    }

    for (int i = 0; i < suff_len; i++) {
        char s_char = s[s_len - suff_len + i];
        char suff_char = suff[i];

        if (s_char >= 'A' && s_char <= 'Z') {
            s_char += 'a' - 'A';  
        }

        if (suff_char >= 'A' && suff_char <= 'Z') {
            suff_char += 'a' - 'A'; 
        }

        if (s_char != suff_char) {
            return 0; 
        }
    }

    return 1;  
}
