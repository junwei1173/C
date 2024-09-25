#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Name: Junwei Chen, Date: 9/8/24, Course: 2107, Lab 02 Revenue
// This program calculates the revenue from sale based on the price and quantity of a product from user input.

int main()
{
    float itemprice, quantity, discount=0;
    float cost, discountamount, total;
    double intpart, fracpart;
    
    
    
    printf("Welcome to \"Temple\" store\n\n");
    
    printf("   Enter item price: ");
    scanf("%f", &itemprice);
    
    if (itemprice<=0){
        printf("\n   This is not a valid price.\n");
        printf("   Please run the program again.\n");
        printf("\nThank you for using \"Temple\" store");
        exit (1);
    }
    
    printf("   Enter quantity: ");
    scanf("%f", &quantity);
    
    fracpart=modf(quantity,&intpart);
    
    if (fracpart!=0 || quantity<=0){
        printf("\n   This is not a valid quantity order.\n");
        printf("   Please run the program again.\n");
        printf("\nThank you for using \"Temple\" store\n");
        exit (1);
    }
    
    if (quantity<=49){
        discount=0;
    } else if (quantity>=50 && quantity<100) {
        discount=0.1;
    } else if (quantity>=100 && quantity<150) {
        discount=0.15;
    } else {
        discount=0.25;
    }
    
    cost= quantity*itemprice;
    
    discountamount= discount*cost;
    
    total= cost-discountamount;
    
    printf("\n   The item price is: $%.2f\n", itemprice);
    printf("   The order is: %d item(s) \n", (int)quantity);
    printf("   The cost is: $%.2f\n", cost);
    printf("   The discount is: %.1f%%\n", discount*100);  
    printf("   The discount amount is: $%.1f\n", discountamount);
    printf("   The total is: $%.2f\n", total);
    
    printf("\nThank you for using \"Temple\" store\n");
    exit (0);
    
    
}
