#include "string.h" 
#include <stdlib.h>
char *repeat(char *s, int x, char sep) {
    if (s == NULL || x <= 0) {
        return NULL;
    }
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    int total_len = len * x + (x - 1) + 1; 
    char *result = (char *)malloc(total_len * sizeof(char));

    if (result == NULL) {
        return NULL; 
    }

    int index = 0;
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; s[j] != '\0'; j++) {
            result[index++] = s[j];
        }
        
        if (i < x - 1) {
            result[index++] = sep;
        }
    }

    result[index] = '\0';

    return result; 
}
