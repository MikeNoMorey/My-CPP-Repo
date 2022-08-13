#include<iostream>
#include<time.h>
#include<stdlib.h>
#include <stdio.h>
#include <Windows.h>
using namespace std;

//Displays the clock
void displayClock() {

	//Time vars
	int hour12Digit1 = 1;
	int hour12Digit2 = 2;
	int hour24Digit1 = 0;
	int hour24Digit2 = 0;
	int min1 = 5;
	int min2 = 9;
	int sec1 = 5;
	int sec2 = 9;
	string ampm = "AM";

	cout << "Enter [C] to clear the screen." << endl;

	cout << "**************************\t" << "**************************" << endl;
	cout << "*     12-Hour Clock      *\t" << "*     24-Hour Clock      *" << endl;
	cout << "*     " << hour12Digit1 << hour12Digit2 << ":" << min1 << min2 << ":" << sec1 << sec2 << " " << ampm << "        *\t"
		<< "*     " << hour24Digit1 << hour24Digit2 << ":" << min1 << min2 << ":" << sec1 << sec2 << "           *" << endl;
	cout << "**************************\t" << "**************************" << endl;
	cout << endl;
}

//function to add an hour
void addHour(int& clock12Hour1, int& clock12Hour2, int& clock24Hour1, int& clock24Hour2, string& ampm) {

	//12 hour clock conditional statements
	if (clock12Hour2 < 10) {
		clock12Hour2 = clock12Hour2 + 1;
	}

	if (clock12Hour2 == 10) {
		clock12Hour1 = 1;
		clock12Hour2 = 0;
	}

	//Condition for clock hour exceeding 12
	if (clock12Hour1 == 1 && clock12Hour2 == 3) {
		clock12Hour1 = 0;
		clock12Hour2 = 1;
	}


	//24 hour clock conditional statements
	if (clock24Hour2 < 10) {
		clock24Hour2 = clock24Hour2 + 1;
	}

	if (clock24Hour1 == 1 && clock24Hour2 == 10) {
		clock24Hour1 = 2;
		clock24Hour2 = 0;
	}

	if (clock24Hour2 == 10) {
		clock24Hour2 = 0;
		clock24Hour1 = 1;
	}

	//Condition for clock hour exceeding 23
	if (clock24Hour1 == 2 && clock24Hour2 == 4) {
		clock24Hour1 = 0;
		clock24Hour2 = 0;
	}

}

//function to add a minute
void addMinute(int& minutes1, int& minutes2, int& clock12Hour1, int& clock12Hour2, int& clock24Hour1, int& clock24Hour2, string& ampm) {

	if (minutes2 < 10) {
		minutes2 = minutes2 + 1;
	}

	//Conditional when minutes exceed 59
	if (minutes1 == 5 && minutes2 == 10) {
		minutes1 = 0;
		minutes2 = 0;

		//conditions for new hour when minutes exceed 59
		if (clock12Hour2 < 10) {
			clock12Hour2 = clock12Hour2 + 1;
		}

		if (clock12Hour2 == 10) {
			clock12Hour1 = 1;
			clock12Hour2 = 0;
		}

		if (clock12Hour1 == 1 && clock12Hour2 == 3) {
			clock12Hour1 = 0;
			clock12Hour2 = 1;
		}

		if (clock24Hour2 < 10) {
			clock24Hour2 = clock24Hour2 + 1;
		}

		if (clock24Hour1 == 1 && clock24Hour2 == 10) {
			clock24Hour1 = 2;
			clock24Hour2 = 0;
		}

		if (clock24Hour2 == 10) {
			clock24Hour2 = 0;
			clock24Hour1 = 1;
		}

		if (clock24Hour1 == 2 && clock24Hour2 == 4) {
			clock24Hour1 = 0;
			clock24Hour2 = 0;
		}

	}

	//Condition when minutes exceed 49
	if (minutes1 == 4 && minutes2 == 10) {
		minutes1 = 5;
		minutes2 = 0;
	}

	//Condition when minutes exceed 39
	if (minutes1 == 3 && minutes2 == 10) {
		minutes1 = 4;
		minutes2 = 0;
	}

	//Condition when minutes exceed 29
	if (minutes1 == 2 && minutes2 == 10) {
		minutes1 = 3;
		minutes2 = 0;
	}

	//Condition when minutes exceed 19
	if (minutes1 == 1 && minutes2 == 10) {
		minutes1 = 2;
		minutes2 = 0;
	}

	//Condition when minutes exceed 09
	if (minutes2 == 10) {
		minutes1 = 1;
		minutes2 = 0;
	}


}

//function to add a second
void addSecond(int& seconds1, int& seconds2, int& minutes1, int& minutes2, int& clock12Hour1, int& clock12Hour2, int& clock24Hour1, int& clock24Hour2,
	string& ampm) {

	if (seconds2 < 10) {
		seconds2 = seconds2 + 1;
	}

	//Condition if seconds exceed 59
	if (seconds1 == 5 && seconds2 == 10) {
		seconds1 = 0;
		seconds2 = 0;

		//Condition will add a minute
		if (minutes2 < 10) {
			minutes2 = minutes2 + 1;
		}

		//Condition if seconds exceed 59 but minutes do as well
		if (minutes1 == 5 && minutes2 == 10) {
			minutes1 = 0;
			minutes2 = 0;

			//Conditions will add an hour
			if (clock12Hour2 < 10) {
				clock12Hour2 = clock12Hour2 + 1;
			}

			if (clock12Hour2 == 10) {
				clock12Hour1 = 1;
				clock12Hour2 = 0;
			}

			if (clock12Hour1 == 1 && clock12Hour2 == 3) {
				clock12Hour1 = 0;
				clock12Hour2 = 1;
			}


			//Condition will add an hour
			if (clock24Hour2 < 10) {
				clock24Hour2 = clock24Hour2 + 1;
			}

			if (clock24Hour1 == 1 && clock24Hour2 == 10) {
				clock24Hour1 = 2;
				clock24Hour2 = 0;
			}

			if (clock24Hour2 == 10) {
				clock24Hour2 = 0;
				clock24Hour1 = 1;
			}

			if (clock24Hour1 == 2 && clock24Hour2 == 4) {
				clock24Hour1 = 0;
				clock24Hour2 = 0;
			}

		}

		//Condition if minutes exceed 49
		if (minutes1 == 4 && minutes2 == 10) {
			minutes1 = 5;
			minutes2 = 0;
		}

		//Condition if minutes exceed 39
		if (minutes1 == 3 && minutes2 == 10) {
			minutes1 = 4;
			minutes2 = 0;
		}

		//Condition if minutes exceeds 29
		if (minutes1 == 2 && minutes2 == 10) {
			minutes1 = 3;
			minutes2 = 0;
		}

		//Condition if minutes exceed 19
		if (minutes1 == 1 && minutes2 == 10) {
			minutes1 = 2;
			minutes2 = 0;
		}

		//Condition if minutes exceed 09
		if (minutes2 == 10) {
			minutes1 = 1;
			minutes2 = 0;
		}

	}

	//COndition if seconds exceed 49
	if (seconds1 == 4 && seconds2 == 10) {
		seconds1 = 5;
		seconds2 = 0;
	}

	//Condition if seconds exceed 39
	if (seconds1 == 3 && seconds2 == 10) {
		seconds1 = 4;
		seconds2 = 0;
	}

	//Condition if seconds exceed 29
	if (seconds1 == 2 && seconds2 == 10) {
		seconds1 = 3;
		seconds2 = 0;
	}

	//Condition if seconds exceed 19
	if (seconds1 == 1 && seconds2 == 10) {
		seconds1 = 2;
		seconds2 = 0;
	}

	//Condition if seconds exceed 09
	if (seconds2 == 10) {
		seconds1 = 1;
		seconds2 = 0;
	}


}

void displayOptionsMenu() {
	//Main menu display
	cout << "\t\t**************************" << endl;
	cout << "\t\t*  1-Add One Hour        *" << endl;
	cout << "\t\t*  2-Add One Minute      *" << endl;
	cout << "\t\t*  3-Add One Second      *" << endl;
	cout << "\t\t*  4-Exit Program        *" << endl;
	cout << "\t\t**************************" << endl;
}

int main() {

	//Clock vars
	int clock12Hour1 = 1;
	int clock12Hour2 = 2;
	int clock24Hour1 = 0;
	int clock24Hour2 = 0;
	int mins1 = 5;
	int mins2 = 9;
	int sec1 = 5;
	int sec2 = 9;
	string ampm = "AM";

	//Menu vars
	int menuInput;
	bool mainLoop = true;
	string clearScreen;

	//Display the clock
	displayClock();


	while (mainLoop) {

		cin >> clearScreen;

		if (clearScreen == "c" || clearScreen == "C") {

			//Call display options menu
			displayOptionsMenu();

			//switch statement to execute main menu
			cin >> menuInput;

			switch (menuInput) {
			case 1:
				//call function to add hours
				addHour(clock12Hour1, clock12Hour2, clock24Hour1, clock24Hour2, ampm);
				system("CLS");
				cout << "Enter [C] to clear the screen." << endl;
				cout << "**************************\t" << "**************************" << endl;
				cout << "*     12-Hour Clock      *\t" << "*     24-Hour Clock      *" << endl;
				cout << "*     " << clock12Hour1 << clock12Hour2 << ":" << mins1 << mins2 << ":" << sec1 << sec2 << " "
					<< ampm << "        *\t"
					<< "*     " << clock24Hour1 << clock24Hour2 << ":" << mins1 << mins2 << ":" << sec1 << sec2 << "           *"
					<< endl;
				cout << "**************************\t" << "**************************" << endl;
				cout << endl;
				break;
			case 2:
				//call function to add minutes
				addMinute(mins1, mins2, clock12Hour1, clock12Hour2, clock24Hour1, clock24Hour2, ampm);
				system("CLS");
				cout << "Enter [C] to clear the screen." << endl;
				cout << "**************************\t" << "**************************" << endl;
				cout << "*     12-Hour Clock      *\t" << "*     24-Hour Clock      *" << endl;
				cout << "*     " << clock12Hour1 << clock12Hour2 << ":" << mins1 << mins2 << ":" << sec1 << sec2 << " "
					<< ampm << "        *\t"
					<< "*     " << clock24Hour1 << clock24Hour2 << ":" << mins1 << mins2 << ":" << sec1 << sec2 << "           *"
					<< endl;
				cout << "**************************\t" << "**************************" << endl;
				cout << endl;
				break;
			case 3:
				//call function to add seconds
				addSecond(sec1, sec2, mins1, mins2, clock12Hour1, clock12Hour2, clock24Hour1, clock24Hour2, ampm);
				system("CLS");
				cout << "Enter [C] to clear the screen." << endl;
				cout << "**************************\t" << "**************************" << endl;
				cout << "*     12-Hour Clock      *\t" << "*     24-Hour Clock      *" << endl;
				cout << "*     " << clock12Hour1 << clock12Hour2 << ":" << mins1 << mins2 << ":" << sec1 << sec2 << " "
					<< ampm << "        *\t"
					<< "*     " << clock24Hour1 << clock24Hour2 << ":" << mins1 << mins2 << ":" << sec1 << sec2 << "           *"
					<< endl;
				cout << "**************************\t" << "**************************" << endl;
				cout << endl;
				break;
			case 4:
				//exits program
				cout << "Exiting program. . ." << endl;
				return EXIT_SUCCESS;
				break;
				//input validation
			default:
				cout << "Invalid Entry. . ." << endl;
				cout << "Type [C] to reload menu." << endl;
				if (clearScreen != "c" || clearScreen != "C") {
					break;

				}


			}


		}


		//Input validation
		else {
			cout << "Invalid Entry, try again..." << endl;
			Sleep(1500);
			main();

		}

	}

	return 0;

}