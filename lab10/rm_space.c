#include "string.h"
void rm_space(char *s) {
    int start = 0, end = 0;

    while (s[end] != '\0') {
        end++;
    }

    while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n') {
        start++;
    }

    if (s[start] == '\0') {
        s[0] = '\0';
        return;
    }

    end--; 
    while (end >= start && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')) {
        end--;
    }

    int i = 0;
    while (start <= end) {
        s[i++] = s[start++];
    }

    s[i] = '\0';
}
