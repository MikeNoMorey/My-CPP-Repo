/*
* Project II:
* 
*   Pseudocode:
* 
*                   Reports.h File: (
* 
* Create a Report class {
*   Add public interest reports functionality for both with and without deposit functions
*   Add private vars for initdeposit, monthlydeposit, interest, and years
* }
* 
* )
* 
* 
*                   InterestReports.cpp File: (
* 
* Call class and assign new variables to the variables passed from main(). (Construtor)
* 
* Call Reports Class : Creates Reports function without monthly deposits() {
*   Assigns vars for a loop
*   Assigns vars for the year being equal to 1
* 
*   Prints Report screen
*   
*   While loop if the current year is less then or equal to year provided by user {
*       Apply algorithm for interest rates 
*       Print the current year, a year end balance, and the interest earned
* 
*       increment the current year by 1 to kill loop
*   }
* }
* 
* Calls Reports Class : Creates Reports function with monthly deposits() {
*   Assign vars for a loop
*   Assign vars for the current year being equal to 1
* 
*   Print reports screen 
*   
*   While loop if the current year is less than or equal to year provided by user {
*       Assign vars for a loop 
*       Assign vars for the current month being equal to 1
*       Assign double for the interest earned and the month end balance being equal to the year end balance
* 
*       While loop if the current month is less than or equal to 12 {
*           Apply algorithm for interest rates each month
*           
*           increment the current month by 1 to kill loop
* 
*       }
* 
*   Convert month back to years assigning the end month balance to years end balance
*   Print the current year, year end balance, and the interest earned
* 
*   increment the year by 1 to kill loop
* 
* }
* 
* )
* 
*                   Source File: (
* 
* Main Function() {
* Call reports header file to acess the obj
* 
* While loop true {
*   Assign variables for investment, years, interest, and deposits
* 
*   Display the Banking Appliction Menu 
* 
*   Request user input for Investment - assign to var
*   Request user input for Monthly deposit - assign to var
*   Request user input for Annual interest - assign to var
*   Request user input for Number of years - assign to var
* 
*   Pass the vars as parameters to the obj class
* 
*   Call reports function without mothly deposits
* 
*   If monthly deposit is more than 0 {
*       Call reports function with monthly deposits
*       }
* 
*   End program with input validation
*   If the user enters Y or y {
*       Call the main function 
*       }
* 
*   Else {
*       Call the exit function to kill loop
*       }
* 
*   }
* 
*   Return data
* 
* }
* 
* )
* 
*/

//Access the reports header file
#include "reports.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

int main() {

    //Assign vars
    double investment, monthlyDeposit, interestRate;
    int years;

    //Loop while true. (Start the program)
    while (1) {
         
        //Displays what will be requested from the user
        cout << "***********************************" << endl;
        cout << "*          Banking App            *" << endl;
        cout << "***********************************" << endl;
        cout << "* Initial Investment:             *" << endl;
        cout << "* Monthly Deposit:                *" << endl;
        cout << "* Annual Interest:                *" << endl;
        cout << "* Number of Years in Account:     *" << endl;
        cout << "***********************************" << endl;
        cout << endl;

        //User input display
        cout << "***********************************" << endl;
        cout << "*       Please Input Data         *" << endl;
        cout << "***********************************" << endl;
        cout << endl;

        //Request then assign user input to vars
        cout << "Initial Investment Amount: $";
        cin >> investment;

        cout << "Monthly Deposit: $";
        cin >> monthlyDeposit;

        cout << "Annual Interest: % ";
        cin >> interestRate;

        cout << "Number of years: ";
        cin >> years;

        //Use Reports class with savings object using the user supplied data vars
        Reports savings = Reports(investment, monthlyDeposit, interestRate, years);
        cout << endl;

        //Call reports function without monthly deposits
        savings.reportNoMonthlyDeposits();
        cout << endl;

        //Calls reports function with monthly deposits so long as it exceeds 0 (conditional)
        if (monthlyDeposit > 0) {
            savings.reportMonthlyDeposits();

        }

        //Request if the user wants to start over (conditional)
        string choice;
        cout << endl << "Would you like to start over? Y/N: ";
        cin >> choice;

        //input validation
        if (choice == "y" || choice == "Y") {
            //Call main to start over
            cout << "Restarting ..." << endl;
            Sleep(2000);
            main();

        }

        //Exit message
        else {
            cout << "Thanks for using the app!" << endl;
            //Call system exit true
            exit(1);

        }

        cout << endl;

    }

    return 0;

}