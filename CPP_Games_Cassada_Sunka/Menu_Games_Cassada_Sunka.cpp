//3-21-19
// Spring 2019 COSC 1437-58000
// Dr. McMillan
//Kevin Cassada and Fahim Sunka


#include <iostream>
#include <stdlib.h>  
#include <windows.h>
#include "Input_Validation_Extended.h"
#include "Color_in_CPP.h"
using namespace std;

void printMulti(int, char);
string primeChecker(double);
int numberReverse(int);
void getMinMax(double, double, double);
void showMenu();

int main()
{
	int decision = 0;
	//Repeat menu until exit condition with do-while loop
	do{
		changeColor(10);
		cout << "\nMenu Games" << endl;
		changeColor(15);
		cout << "\nOPTION \tGAME" << endl;
		changeColor(11);
		cout << "1\tBattleship" << endl;
		changeColor(14);
		cout << "2\tTic-Tac-Toe" << endl;
		changeColor(12);
		cout << "3\tExit Program" << endl;
		changeColor(10);
		cout <<"\n___________________________________\n" << endl;
		cout <<"Please select an option from above: ";
		changeColor(10);
		decision = validateInt(decision);
		changeColor(7); 
		
		if(decision == 1) //make triangle rows of a character
		{
			system("cls");
			system("ship_game.exe");
			changeColor(14);
			cout << "\nReturning to Menu - please wait";
			changeColor(7);
			Sleep(3000);
			system("cls");
		}
		else if(decision == 2) //check if prime number
		{
			system("cls");
			system("Tic_Tac_Toe_Wow.exe");
			changeColor(14);
			cout << "\nReturning to Menu - please wait";
			changeColor(7);
			Sleep(3000);
			system("cls");
		}
		else if(decision == 3)
		{
			system("cls");
			changeColor(10);
			cout << "Thanks for playing our games, goodbye!" << endl;
			changeColor(7);
		}
		else
		{
			changeColor(12);
			cout << "Invalid entry. Try again.\n" << endl;
			changeColor(7);
		}
	}while(decision != 3);
	return 0;
}


