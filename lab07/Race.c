

// Name: Junwei Chen, Date: 10/13/24, Course: 2107, Lab 07 Race

/*The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
controlled using the sleep() function.*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int hPos,int tPos);

int main(){
    srand((unsigned)time(NULL));

    int hPos =1;						
    int tPos = 1;					

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");	
    puts("\tAND THEY'RE OFF    !!!!");	

    while(hPos != 70 && tPos!=70){
        //sleep(1);						
        hareMove(&hPos);
        tortMove(&tPos);
        printRace(hPos,tPos);
        puts("");
    }
    if (hPos == 70 && tPos == 70) {
        printf("It's a tie!\n");
    } else if (hPos == 70) {
        printf("Hare wins. Yuch.\n");
    } else {
        printf("TORTOISE WINS!!! YAY!!!\n");
    }
    return 0;

}



// prints the position of the H and T
void printRace(int hPos,int tPos){
    // I put it to size 77 because they might crash into each other at position 68 and "OUCH!!!" won't have enough space.
    char placement[77];
    
    for (int i = 0; i < 70; i++) {
        placement[i] = ' ';
    }
    placement[76] = '\0';
    
    if (hPos == tPos) {
        if (hPos - 1 < 70 && hPos - 1 != 69) {
            placement[hPos - 1] = 'O'; // set first character of "OUCH!!!"
            placement[hPos] = 'U';  
            placement[hPos + 1] = 'C';   
            placement[hPos + 2] = 'H';
            placement[hPos + 3] = '!';
            placement[hPos + 4] = '!';
            placement[hPos + 5] = '!';
            
        }
    } else {

        if (hPos - 1 < 70) {
            placement[hPos - 1] = 'H'; // place Hare
        }
        if (tPos - 1 < 70) {
            placement[tPos - 1] = 'T'; // place Tortoise
        }
    }
    printf("%s\n", placement);
    
    

}

// controls the tortoise movement
void tortMove(int *tPtr){
    int move = rand() % 10 + 1;
    if (move <= 5) {
        *tPtr += 3; // fast plod
    } else if (move <= 7) {
        *tPtr -= 6; // slip
    } else {
        *tPtr += 1; // slow plod
    }
    if (*tPtr < 1) *tPtr = 1;
    if (*tPtr > 70) *tPtr = 70;
 
}

// controls the hare movement
void hareMove(int *hPtr){
    int move = rand() % 10 + 1;
    if (move <= 2) {
        *hPtr += 0; // sleep
    } else if (move <= 4) {
        *hPtr += 9; // big hop
    } else if (move <= 5){
        *hPtr -= 12; // big slip
    } else if (move <= 8){
        *hPtr += 1; // small hop
    } else {
        *hPtr -= 2; // small slip
    }
    if (*hPtr < 1) *hPtr = 1;
    if (*hPtr > 70) *hPtr = 70;
    

}

