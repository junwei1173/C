/*
 * Name: Junwei Chen
 * Section:	2
 * Lab:  	CIS2107_Lab08_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[], int size);
void endsWithed(char *string[], int size);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    int size = sizeof(series) / sizeof(series[0]);
    startsWithB(series,size);

    //test for endsWithed
    endsWithed(series,size);

}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char * s) {
    char upper[100];
    char lower[100];

    for (int i = 0; s[i] != '\0'; i++) {
        upper[i] = toupper(s[i]);
        lower[i] = tolower(s[i]);
    }
    
    upper[strlen(s)] = '\0';
    lower[strlen(s)] = '\0';

    printf("Uppercase: %s\n", upper);
    printf("Lowercase: %s", lower);
    
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    int num1 = atoi(s1);
    int num2 = atoi(s2);
    int num3 = atoi(s3);
    int num4 = atoi(s4);

    return num1 + num2 + num3 + num4;
}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    float num1 = atof(s1);
    float num2 = atof(s2);
    float num3 = atof(s3);
    float num4 = atof(s4);

    return num1 + num2 + num3 + num4;
}

//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
    int compare = strcmp(s1,s2);
    if (compare > 0) {
        printf("\n\n%s > %s", s1,s2);
    } else {
        printf("\n\n%s < %s", s1,s2);
    }
    

}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
   int compare = strncmp(s1,s2,n);
   if (compare == 0) {
        printf("\n\nComparison of first 4 chars: %s = %s", s1,s2);
   }

}

//6.(Random Sentences) 
void randomize(void) {
   char *article[] = {"the", "a", "one", "some","any"};
   char *noun[] = {"boy", "girl", "dog", "town", "car"};
   char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
   char *preposition[] = {"to", "from", "over", "under", "on"};
   
   puts("\n");
   for (int i = 0; i<20;i++) {
       char sentence[100] = "";
       int ranArt = (rand() % 5) + 0;
       strcat(sentence, article[ranArt]);
       strcat(sentence, " ");

       int ranNoun = (rand() % 5) + 0;
       strcat(sentence, noun[ranNoun]);
       strcat(sentence, " ");

       int ranVerb = (rand() % 5) + 0;
       strcat(sentence, verb[ranVerb]);
       strcat(sentence, " ");

       int ranPrep = (rand() % 5) + 0;
       strcat(sentence, preposition[ranPrep]);
       strcat(sentence, " ");

       int ranArt2 = (rand() % 5) + 0;
       strcat(sentence, article[ranArt2]);
       strcat(sentence, " ");

       int ranNoun2 = (rand() % 5) + 0;
       strcat(sentence, noun[ranNoun2]);
       
       strcat(sentence, ". ");

       sentence[0] = toupper(sentence[0]);
       printf("\n%s", sentence);
    }
}

//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
    puts("\n");
    while (*num != '\0' ) {
        if (*num != '(' && *num != ')' && *num !='-') {
            printf("%c", *num);
        }
        num++;
    }
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    char *str1 = strtok(text, " ");
    char *str2 = strtok(NULL, " ");
    
    printf("\n\n%s %s", str2,str1);

}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
    int count = 0;
    char *ptr = line;
    while ((ptr = strstr(ptr,sub)) != NULL) {
        count++;
        ptr++;
    }
    return count;
  
  
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
    int count = 0;
    char *ptr = line;
    while ((ptr = strchr(ptr,c)) != NULL) {
        count++;
        ptr++;
    }
    return count;
  
  
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
    int counts[26] = {0};

    for (char letter = 'a'; letter <= 'z'; letter++) {
        counts[letter - 'a'] = countChar(string, letter); 
        counts[letter - 'a'] += countChar(string, letter - 32);
    }
    puts("");
    for (int i = 0; i < 26; i++) {
        printf("%c,%c | %d\n", 'A' + i, 'a' + i, counts[i]);
    }
 
 
}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
    int count = 0;
    
   char *str = strtok(string, " ");
   while (str != NULL) {
       count++;
       str = strtok(NULL, " ");
   }
   return count;
   
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[], int size) {
    puts("");
    for (int i = 0; i<size;i++) {
        if (string[i][0] == 'b' || string[i][0] == 'B') {
            putchar(tolower(string[i][0])); 
            printf("%s ", string[i]+1);
        }
    }

 

}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[], int size) {
    puts("\n");
    for (int i = 0; i < size; i++) {
        int len = strlen(string[i]);
        if (string[i][len - 2] == 'e' && string[i][len - 1] == 'd') {
            printf("%s ", string[i]);
        }
    }
}