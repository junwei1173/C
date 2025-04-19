#include "string.h"

int find(char *h, char *n) {
    if (!h || !n || *n == '\0') {
        return -1; 
    }
    int i = 0, j, k;

    while (h[i] != '\0') {
        if (h[i] == n[0]) { 
            j = i;
            k = 0;
            while (h[j] != '\0' && n[k] != '\0' && h[j] == n[k]) {
                j++;
                k++;
            }
            if (n[k] == '\0') { 
                return i;
            }
        }
        i++;
    }
    return -1;
}
