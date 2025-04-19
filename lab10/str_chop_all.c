#include "string.h"
#include <stdlib.h>
#include <stddef.h>
char **str_chop_all(char *s, char c) {
    int token_count = 1; 
    for (char *ptr = s; *ptr != '\0'; ptr++) {
        if (*ptr == c) {
            token_count++;
        }
    }

    char **result = (char **)malloc((token_count + 1) * sizeof(char *)); 
    if (result == NULL) {
        return NULL; 
    }

    int token_index = 0;
    char *start = s; 
    for (char *ptr = s; ; ptr++) {
        if (*ptr == c || *ptr == '\0') {
            int token_length = ptr - start;
            result[token_index] = (char *)malloc((token_length + 1) * sizeof(char));
            if (result[token_index] == NULL) {
                for (int i = 0; i < token_index; i++) {
                    free(result[i]);
                }
                free(result);
                return NULL;
            }
            for (int i = 0; i < token_length; i++) {
                result[token_index][i] = start[i];
            }
            result[token_index][token_length] = '\0'; 
            token_index++;
            start = ptr + 1;
        }

        if (*ptr == '\0') {
            break; 
        }
    }
    result[token_index] = NULL;

    return result;
}