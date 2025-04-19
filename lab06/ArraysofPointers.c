/******************************************************************************

Name: Junwei Chen, Date: 10/06/24, Course: 2107, Lab 06 2D ArrayOfPointersToFunctions

This program allows users to make a 2D array consisting of student grades. They are then able 
to print out the array, find the minimum/maximum grade for a student, and find the average for
each student.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);
int main()
{
    int rows, cols, choice;
    
    puts("Welcome to 2D arrays for student grades.");
    puts("");
    
    printf("How many students (rows)? ");
    scanf("%d", &rows);
    
    printf("How many exams (cols)? ");
    scanf("%d", &cols);
    
    int arrayGrade[rows][cols];
    
    puts("");
    
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("    Enter value for [%d][%d]: ", i, j);
            scanf("%d", &arrayGrade[i][j]);
        }
    }
    
    void (*processGrades[4])(int students, int exams, int grades[students][exams]) = {printArray,minimum,maximum,average};
    do {
        puts("\nEnter a choice:");
        puts("    0   Print the array of grades");
        puts("    1   Find minimum grade");
        puts("    2   Find maximum grade");
        puts("    3   Print the average on all tests for each student");
        puts("    4   End program");
        scanf("%d", &choice);
        if (choice >= 0 && choice < 4) {
            processGrades[choice](rows, cols, arrayGrade);
        }
    } while (choice != 4);
    
    puts("Program ending....");
    return 0;
}
  

// print the entire 2D array of grades for each students
void printArray(int students, int exams, int grades[students][exams]){
    
    puts("The array is:\n");
     printf("%13s", "");
    for (int i = 0; i < exams; i++) {
        printf("[%d]  ", i); 
    }
    
    for (int i = 0; i < students; i++) {
        
        printf("\nStudent %d:", i);
        for (int j = 0; j < exams; j++) {
        
            printf("%5d", grades[i][j]);
        }
    }
    puts("");
    puts("======================================");
}
// prints the minimum grade
void minimum(int students, int exams, int grades[students][exams]){
    int lowGrade = 100; 
    
    for (int i = 0; i < students; ++i) {
        for (int j = 0; j < exams; ++j) {
        
            if (grades[i][j] < lowGrade) {
            
                lowGrade = grades[i][j];
            }
        }
    }

    printf("\nLowest grade: %d\n", lowGrade);
    puts("======================================");
}
// prints the maximum grade
void maximum(int students, int exams, int grades[students][exams]){
    int highGrade = 0; 
    for (int i = 0; i < students; ++i) {
        
        for (int j = 0; j < exams; ++j) {
        
            if (grades[i][j] > highGrade) { 
            
                highGrade = grades[i][j];
            }
        }
    }

    printf("\nHighest grade: %d\n", highGrade);
    puts("======================================");
}
// prints the average grade for each student
void average(int students, int exams, int grades[students][exams]) {
    for (int i = 0; i < students; i++) {
        int total = 0; 

        for (int j = 0; j < exams; j++) {
            total += grades[i][j];
        }
        puts("");
        printf("The average grade for student %d is %.2f\n", i, (double)total / exams);
        
    }
    puts("======================================");
}