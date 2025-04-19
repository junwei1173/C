#include "string.h"
#include <stddef.h>
#include <ctype.h>

void rm_empties(char **words) {
    if (words == NULL) {
        return; 
    }

    int i = 0, j = 0;
    while (words[i] != NULL) {
        int is_empty = 1;  
        for (int k = 0; words[i][k] != '\0'; k++) {
            if (!isspace(words[i][k])) {  
                is_empty = 0;
                break;
            }
        }

        if (!is_empty) {
            words[j++] = words[i];  
        }
        i++;
    }

    words[j] = NULL; 
}
