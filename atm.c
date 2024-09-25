#include <stdlib.h>
#include <stdio.h>

// Name: Junwei Chen, Date: 9/15/24, Course: 2107, Lab 03 ATM machine
// This is a basic ATM program that checks balance, withdraws cash, and deposits cash from an initial value of $5000.

int main()
{
    int pin = 3014, inputPin, retries = 0, totalTrans = 0, amount = 5000, depoLimit = 10000, choice=0, withdrawLimit = 1000, receipt;
    double deposit, withdraw;
    
    printf("Hello, welcome to Junwei\'s ATM: ");
    printf("\nPlease enter your pin: ");

    scanf("%d",&inputPin);
    
    while (inputPin != pin && retries <2) {
        printf("Wrong pin, enter again: ");
        scanf("%d",&inputPin);
        retries +=1;
        
    }
    if (retries > 2) {
        printf("\nYou have entered the wrong PIN three times. Access denied. Program terminating.");
        exit(1);
    }
    while (choice != 4) {
        puts("===========================");
        puts("ATM menu:");
        puts("1. Check Balance");
        puts("2. Withdraw Cash");
        puts("3. Deposit Cash");
        puts("4. Quit");
        puts("===========================");

        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice <= 0 || choice >= 5) {
            puts("Inavlid choice option. Please enter 1, 2, 3, 4.");
            continue;
        }
        if (choice == 1) {
            printf("\nYou currently have a balance of $%d\n", amount);
            continue;
        } else if (choice == 2) {
            printf("Enter withdraw amount (multiples of 20): ");
            scanf("%lf", &withdraw);
            if (withdraw != 20 && (int)withdraw % 20 != 0 || withdraw <= 0 || withdraw != (int)withdraw) {
                puts("Invalid amount, must be multiples of 20.");
                continue;
            }
            int checkWithdrawLim = withdrawLimit - withdraw;
        
            if (withdrawLimit <0 || checkWithdrawLim < 0) {
                printf("You have reached the limit of $1000 withdraws per day.\n");
                printf("Amount available to withdraw: $%d\n", withdrawLimit);
                continue;
            } else {
                amount -= withdraw;
                withdrawLimit -= withdraw;
            }
            
        
            printf("Withdraw Complete. Your new balance is: %d\n", amount);
            totalTrans += 1;
            continue;
        } else if (choice == 3) {
            printf("Enter deposit amount (paper bills only): ");
            scanf("%lf", &deposit);
            if (deposit != (int)deposit || deposit <= 0) {
                printf("Invalid amount. Please use paper bills only (no coins).\n");
                continue; 
            }
            
            int checkDepoLim = depoLimit - deposit;
            
            if (depoLimit < 0 || checkDepoLim < 0) {
                printf("You have reached the limit of $10000 deposits per day.\n");
                printf("Amount available to deposit: $%d\n", depoLimit);
                continue;
            } else {
                amount += deposit;
                depoLimit -= deposit;
            }
            printf("Deposit Complete, your new balance is: %d\n", amount);
            totalTrans += 1;
            continue;
            
        } else {
            printf("Do you want a receipt? 1 for yes, 2 for no: ");
            scanf("%d", &receipt);
            if (receipt == 1) {
                puts("Receipt Printing...");
                printf("You have made %d transactions.\n", totalTrans);
                puts("\nThank you for using Junwei\'s ATM.");
            } else {
                printf("You have made %d transactions.\n", totalTrans);
                puts("\nThank you for using Junwei\'s ATM.");
            }
            
        }
        
        
    }
    exit(0);
    }
    
