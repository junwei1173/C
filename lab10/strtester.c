#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
// Name: Junwei Chen, Date: 11/27/24, Course: 2107, Lab 10 String Library

// The purpose of this assignment is to implement custom library string of functions with header and library files.


int main() {
    // 1: all_letters
    printf("Test 1: all_letters(\"Hello World\"): %d\n", all_letters("Hello World"));
    printf("Test 1: all_letters(\"He22o World\"): %d\n", all_letters("He22o World"));

    // 2: num_in_range
    printf("Test 2: num_in_range(\"Yellow\", 'f', 'm'): %d\n", num_in_range("Yellow", 'f', 'm'));

    // 3: diff
    printf("Test 3: diff(\"Book\", \"Back\"): %d\n", diff("Book", "Back"));

    // 4: shorten
    char s1[] = "Hello World";
    shorten(s1, 5);
    printf("Test 4: shorten(\"Hello World\", 5): %s\n", s1);
    char s2[] = "Hello World";
    shorten(s2, 20);
    printf("Test 4: shorten(\"Hello World\", 20): %s\n", s2);

    // 5: len_diff
    printf("Test 5: len_diff(\"Philadelphia\", \"Hello\"): %d\n", len_diff("Philadelphia", "Hello"));

    // 6: rm_left_space
    char s3[] = " Hello";
    rm_left_space(s3);
    printf("Test 6: rm_left_space(\" Hello\"): .%s\n", s3);

    // 7: rm_right_space
    char s4[] = "Hello ";
    rm_right_space(s4);
    printf("Test 7: rm_right_space(\"Hello \"): %s.\n", s4);

    // 8: rm_space
    char s5[] = " Hello ";
    rm_space(s5);
    printf("Test 8: rm_space(\" Hello \"): .%s.\n", s5);

    // 9: find
    printf("Test 9: find(\"Hello \", \"l\"): %d\n", find("Hello ", "l"));
    printf("Test 9: find(\"Hello\", \"q\"): %d\n", find("Hello", "q"));

    // 10: ptr_to
    printf("Test 10: ptr_to(\"Hello \", \"l\"): %p\n", ptr_to("Hello ", "l"));
    printf("Test 10: ptr_to(\"Hello\", \"q\"): %p\n", ptr_to("Hello", "q"));

    // 11: is_empty
    printf("Test 11: is_empty(\" \"): %d\n", is_empty(" "));
    printf("Test 11: is_empty(\"Hello\"): %d\n", is_empty("Hello"));

    // 12: str_zip
    char *zip_result = str_zip("Temple", "Hello");
    printf("Test 12: str_zip(\"Temple\", \"Hello\"): %s\n", zip_result);
    free(zip_result);

    // 13: capitalize
    char s6[] = "hello world";
    capitalize(s6);
    printf("Test 13: capitalize(\"hello world\"): %s\n", s6);

    // 14: strcmp_ign_case
    printf("Test 14: strcmp_ign_case(\"hello\", \"goodbye\"): %d\n", strcmp_ign_case("hello", "goodbye"));
    printf("Test 14: strcmp_ign_case(\"Hello\", \"hello\"): %d\n", strcmp_ign_case("Hello", "hello"));

    // 15: take_last
    char s7[] = "hello";
    take_last(s7, 3);
    printf("Test 15: take_last(\"hello\", 3): %s\n", s7);
    char s8[] = "hello";
    take_last(s8, 6);
    printf("Test 15: take_last(\"hello\", 6): %s\n", s8);

    // 16: dedup
    char s[] = "hello";
    char *dedup_result = dedup(s);  // s is modified in-place
    printf("Test 16: dedup(\"hello\"): %s\n", dedup_result);

    // 17: pad
    char *pad_result = pad("hello", 6);
    printf("Test 17: pad(\"hello\", 6): %s.\n", pad_result);
    free(pad_result);
    char *pad_result2 = pad("hello", 5);
    printf("Test 17: pad(\"hello\", 5): %s.\n", pad_result2);
    free(pad_result2);

    // 18: ends_with_ignore_case
    printf("Test 18: ends_with_ignore_case(\"Coding\", \"ing\"): %d\n", ends_with_ignore_case("Coding", "ing"));
    printf("Test 18: ends_with_ignore_case(\"Coding\", \"ed\"): %d\n", ends_with_ignore_case("Coding", "ed"));

    // 19: repeat
    char *repeat_result = repeat("hello", 3, '-');
    printf("Test 19: repeat(\"hello\", 3, '-'): %s\n", repeat_result);
    free(repeat_result);

    // 20: replace
    char *replace_result = replace("Steph is the X", "X", "best");
    printf("Test 20: replace(\"Steph is the X\", \"X\", \"best\"): %s\n", replace_result);
    free(replace_result);

    // 21: str_connect
    char *strs[] = {"Hello", "world", "Hello", "world", NULL};
    char *str_connect_result = str_connect(strs, 4, '-');
    printf("Test 21: str_connect(Hello world Hello world, 4, '-'): %s\n", str_connect_result);
    free(str_connect_result);

    // 22: rm_empties
    char *words[] = {"Hello", "World", " ", " ", "Steph", NULL};
    rm_empties(words);
    printf("Test 22: rm_empties: ");
    for (int i = 0; words[i] != NULL; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    // 23: str_chop_all
    char str[] = "Hello/world/Hello/world";
    char delimiter = '/';
    char **tokens = str_chop_all(str, delimiter);
    printf("Test 23: str_chop_all(Hello/world/Hello/world, '/'): ");
    if (tokens != NULL) {
        for (int i = 0; tokens[i] != NULL; i++) {
            printf("%s ", tokens[i]);
            free(tokens[i]); 
        }
        free(tokens); 
    }
    printf("\n");

    return 0;
}