#include "string.h"  
#include <stdlib.h>
char *replace(char *s, char *pat, char *rep) {
    
    if (s == NULL || pat == NULL || rep == NULL) {
        return NULL;
    }

    int len_s = 0, len_pat = 0, len_rep = 0;
    
    while (s[len_s] != '\0') len_s++;
    while (pat[len_pat] != '\0') len_pat++;
    while (rep[len_rep] != '\0') len_rep++;

    int count = 0;
    for (int i = 0; i <= len_s - len_pat; i++) {
        int match = 1;
        for (int j = 0; j < len_pat; j++) {
            if (s[i + j] != pat[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            count++;
            i += len_pat - 1; 
        }
    }

    int new_len = len_s + count * (len_rep - len_pat) + 1;

    char *result = (char *)malloc(new_len * sizeof(char));
    if (result == NULL) {
        return NULL;  
    }

    int index = 0;

    for (int i = 0; i < len_s;) {
        int match = 1;
        for (int j = 0; j < len_pat; j++) {
            if (s[i + j] != pat[j]) {
                match = 0;
                break;
            }
        }

        if (match) {
            for (int j = 0; j < len_rep; j++) {
                result[index++] = rep[j];
            }
            i += len_pat;  
        } else {
            result[index++] = s[i++];
        }
    }
    result[index] = '\0';

    return result;  
}
