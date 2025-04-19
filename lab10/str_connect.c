#include "string.h" 
#include <stdlib.h>
char *str_connect(char **strs, int n, char c) {
    if (strs == NULL || n <= 0) {
        return NULL;
    }

    int total_length = 0;
    for (int i = 0; i < n; i++) {
        if (strs[i] == NULL) {
            return NULL; 
        }
        int len = 0;
        while (strs[i][len] != '\0') {
            len++;
        }
        total_length += len;
        
        if (i < n - 1) {
            total_length++; 
        }
    }

    char *result = (char *)malloc((total_length + 1) * sizeof(char)); 
    if (result == NULL) {
        return NULL; 
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (strs[i][j] != '\0') {
            result[index++] = strs[i][j++];
        }
        
        if (i < n - 1) {
            result[index++] = c;
        }
    }

    result[index] = '\0';

    return result;
}
