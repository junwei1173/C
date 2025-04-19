#include "string.h"  
#include <stddef.h>
char *ptr_to(char *h, char *n) {
    if (!h || !n || *n == '\0') {
        return NULL; 
    }

    char *h_start = h; 
    while (*h_start != '\0') {
        char *h_iter = h_start;
        char *n_iter = n;

        while (*h_iter != '\0' && *n_iter != '\0' && *h_iter == *n_iter) {
            h_iter++;
            n_iter++;
        }

        if (*n_iter == '\0') { 
            return h_start;
        }

        h_start++; 
    }
    return NULL; 
}
