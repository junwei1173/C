#include <time.h>
#include <stdio.h>
#include <stdlib.h>  

#define RAND_MIN 0
#define MY_RAND_MAX 100

// Name: Junwei Chen, Date: 9/22/24, Course: 2107, Lab 04 1D Arrays

/* This program makes a function that fill up an array with 40 random elements ranging from 0 to 100, then uses various functions that
finds biggest element with indexes, reverses the array, reverses with selected range, and finds a specific sequence via user input. */

// function prototypes
void fillArray(int arr[], int size, int rand_min, int rand_max);
int findWithRange(int arr[], int low, int high);
void reverseArray(int arr[], int size);
void reverseSelectedRangeWithinArray(int arr[], int low, int high);
int findSequence(int arr[], int size, int tom, int jerry);
int main()
{
    int array[40];  
    int lowRange, highRange, lowRangeRev, highRangeRev, tom, jerry;
    srand(time(NULL));  
    
    printf("Welcome to the 1D array demo! Let's make an array of 40 random elements from 0 to 100:\n");
    
    fillArray(array, 40, RAND_MIN, MY_RAND_MAX);
    
    
    for (int i = 0; i < 40; i++) {
        printf("%3d ", array[i]);
        if ((i + 1) % 10 == 0) {
            puts("");
        }
    }
    printf("\n");
    
    puts("Now, let's search the largest element between two indexes of the array.");
    printf("Enter your low index: ");
    scanf("%d",&lowRange);
    printf("Enter your high index: ");
    scanf("%d",&highRange);
    while (lowRange < 0 || highRange > 39 || lowRange > highRange) {
        puts("Invalid input, please enter between 0 to 39 (ascending).");
        printf("Enter your low index: ");
        scanf("%d",&lowRange);
        printf("Enter your high index: ");
        scanf("%d",&highRange);
    }
    
    printf("\nMax = %d\n", findWithRange(array, lowRange, highRange));
    
    puts("\nThis is the array reversed: ");
    
    reverseArray(array, 40);
    for (int i = 0; i < 40; i++) {
        printf("%3d ", array[i]);
        if ((i + 1) % 10 == 0) {
            puts("");
        }
    }
    printf("\n");
    
    puts("Now, let's reverse the elements between two indexes of the array.");
    printf("Enter your start index: ");
    scanf("%d",&lowRangeRev);
    printf("Enter your end index: ");
    scanf("%d",&highRangeRev);
    while (lowRangeRev < 0 || highRangeRev > 39 || lowRangeRev > highRangeRev) {
        puts("Invalid input, please enter between 0 to 39 (ascending).");
        printf("Enter your start index: ");
        scanf("%d",&lowRangeRev);
        printf("Enter your end index: ");
        scanf("%d",&highRangeRev);
    }
    
    reverseArray(array, 40); // reverse the array back to original
    
    printf("\nThis is the original array reversed within %d and %d: \n", lowRangeRev, highRangeRev);
    
    reverseSelectedRangeWithinArray(array, lowRangeRev, highRangeRev);
    for (int i = 0; i < 40; i++) {
        printf("%3d ", array[i]);
        if ((i + 1) % 10 == 0) {
            puts("");
        }
    }
    
    puts("\nLet's see if we can find Tom and Jerry with two consecutive elements.");
    printf("Enter first number: ");
    scanf("%d", &tom);
    printf("Enter second number: ");
    scanf("%d", &jerry);
    if (findSequence(array, 40, tom, jerry) != -1) {
        printf("\nSequence found at index %d\n", findSequence(array, 40, tom, jerry));
    } else {
        printf("\nSequence was not found.\n");
    }
    
    printf("\nEnd of program, thanks for using!");

    exit(0);
}
// fills an array with 40 random elements (numbers) ranging from 0 to 100.
void fillArray(int arr[], int size, int rand_min, int rand_max) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand_min + rand() % (rand_max - rand_min + 1);  
    }
}

// finds the biggest element between two indexes from user input
int findWithRange(int arr[], int low, int high) {
    
    int big = -1;
    
    for (int i = low; i <= high; i++) {
        if (arr[i] > big) {
            big = arr[i];
        }
    }
    return big;
}

// reverses the entire array
void reverseArray(int arr[], int size) {
    
    for (int i = 0; i < size/2; i++) {
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
    
}

// reverses a specific range of the array between two indexes
void reverseSelectedRangeWithinArray(int arr[], int low, int high) {
    
    while (low < high) {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        
        low++;
        high--;
    }
}

// find if there is a two consecutive number sequence from user input
int findSequence(int arr[], int size, int tom, int jerry) {
    for (int i = 0; i < size-1; i++) {
        if (arr[i] == tom && arr[i+1] == jerry) {
            return i;
        }
    }
    return -1;
    
}


