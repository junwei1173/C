#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

// Name: Junwei Chen, Date: 9/8/24, Course: 2107, Lab 02 Paycheck
// This program checks the paycheck of a Temple employee based on their hourly salary and time worked weekly.

int main() {


    printf("Welcome to \"Temple Human Resources\"\n\n");
    
    double hourlySalary, weeklyTime, regularPay, overtimePay;
    
    double employeeInput, fracpart, intpart;
    
    int employeeNumber;
    
    double netpay = 0;
    
    
    
    printf("Enter Employee Number:");
    scanf("%lf",&employeeInput);
    
    fracpart = modf(employeeInput, &intpart);
    employeeNumber = (int)intpart;
    
    
    if (fracpart != 0 || employeeNumber<=0) {
        printf("\nThis is not a valid employee number.\n");
        printf("Please run the program again.\n\n");
        printf("Thank you for using \"Temple Human Resources\"\n");
        exit(1);
    }
    printf("Enter Hourly Salary:");
    scanf("%lf",&hourlySalary);
    
    if (hourlySalary<=0) {
        printf("\nThis is not a valid hourly salary amount.\n");
        printf("Please run the program again.\n\n");
        printf("Thank you for using \"Temple Human Resources\"\n");
        exit(1);
    }
    printf("Enter Weekly Time:");
    scanf("%lf",&weeklyTime);
    
    if (weeklyTime<=0) {
        printf("\nThis is not a weekly time.\n");
        printf("Please run the program again.\n\n");
        printf("Thank you for using \"Temple Human Resources\"\n");
        exit(1);
    }
    
    if (weeklyTime>40) {
        regularPay = 40 * hourlySalary;
        overtimePay = (weeklyTime - 40) * (hourlySalary * 1.5);
        netpay = regularPay + overtimePay;
    } else {
        regularPay = weeklyTime*hourlySalary;
        netpay = regularPay;
        overtimePay = 0;
    }
    printf("==========================================\n");
    printf("Employee #: %d\n", employeeNumber);
    printf("Hourly Salary: $%.2f\n", hourlySalary); 
    printf("Weekly Time: %.2f\n", weeklyTime); 
    printf("Regular Pay: $%.2f\n", regularPay); 
    printf("Overtime Pay: $%.2f\n", overtimePay);
    printf("Net Pay: $%.2f\n", netpay);
    printf("==========================================\n");
    
    printf("Thank you for using \"Temple Human Resources\"\n");

    exit(0);
    }
