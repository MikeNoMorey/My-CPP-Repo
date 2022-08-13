//Access the reports header file
#include "reports.h"
#include <iomanip>
#include <iostream>
using namespace std;

//Calls class (Constructor)
Reports::Reports(double investment, double monthDeposit, double rate, int years) {

	//Assign the vars associated with the passed by the user, and assign those vars using "this" to differentiate values
	this->initialDeposit = investment;
	this->monthlyDeposit = monthDeposit;
	this->interestRate = rate;
	this->numYears = years;

}

//destructor
Reports::~Reports() {}

//Prints report without additional monthly deposits
void Reports::reportNoMonthlyDeposits() {

	//Assign vars for loop
	int currentYear = 1;
	double yearEndBalance = this->initialDeposit;

	//Prints report table
	cout << "	Balance & interest without additional monthly deposits" << endl;
	cout << "******************************************************************************" << endl;
	cout << "*       " << "Year" << "         " << "Year end balance" << "               " << "Year end earned interest *" << endl;
	cout << "******************************************************************************" << endl;

	//Loop if the number of years is more than 1
	while (currentYear <= this->numYears) {

		//Algorithm without additional monthly deposits
		double interestEarned = yearEndBalance * this->interestRate / 100;

		//Output information
		cout << right << setw(10) << currentYear << fixed << setprecision(2) << setw(20) << yearEndBalance << setw(35) << interestEarned << endl;
		
		//Increment the year by 1 to end the loop
		currentYear++;

	}

}

//Prints report with additional monthly deposits
void Reports::reportMonthlyDeposits() {

	//Assign vars for loop
	int currentYear = 1;
	double yearEndBalance = this->initialDeposit;

	//Print report table
	cout << "	Balance & interest with additional monthly deposits" << endl;
	cout << "******************************************************************************" << endl;
	cout << "*       " << "Year" << "         " << "Year end balance" << "               " << "Year end earned interest *" << endl;
	cout << "******************************************************************************" << endl;

	//Loop if the number of years is more than 1
	while (currentYear <= this->numYears) {

		//Assign vars to calculate interest
		int month = 1;
		double interestEarned = 0.0;
		double monthEndBalance = yearEndBalance;

		//Loop through each month
		while (month <= 12) {

			//Algorithm with additional monthly deposits
			monthEndBalance += this->monthlyDeposit;
			double monthlyInterest = monthEndBalance * this->interestRate / (100 * 12);
			interestEarned += monthlyInterest;
			monthEndBalance += monthlyInterest;

			//Increment the month by 1 to end the loop
			month++;

		}

		//Convert months to years
		yearEndBalance = monthEndBalance;

		//Output information
		cout << right << setw(10) << currentYear << fixed << setprecision(2) << setw(20) << yearEndBalance << setw(35) << interestEarned << endl;
		
		//Increment the year by 1 to end the loop
		currentYear++;

	}

}