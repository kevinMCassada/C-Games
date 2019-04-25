/*
    Sinking Ship Grame source: 
	http://pastebin.com/atfSSUef
	
	//Expanded by Dr. Tyson McMillan on 4-5-2014,10-24-2015
	//Expanded by: Type Teamates Names
	//3-21-19
	//Kevin Cassada and Fahim Sunka
	//Big Show Hint on Line 104
	
	Objective:
	1) Make this game more fun, visual (color), and validate input of the two integers. 
	2) In a mult-line comment below the program, state how this program works. 
	3) Expand upon the ways that you improved the grame. 
	4 How does the 10 by 10 matrix work
	5) How does one attack a ship in the 10 by 10 matrix? That is what characters represent what? 
	
	Added input validation
	Added color for ships destroyed - changes to a 2 and outputs in green
	Made the grid start at 1 and end at 10 instead of 0 to 9 (user friendly)
	Made input prompt easier to understand
	Added input validation for out of bounds attack
	Added number change for miss to a 5 and outputs in red
	Ships hidden from user
	Changed 0's to be blue
	Showing the real game board when the game ends
	
*/
#include <iostream>
#include <ctime>
#include <time.h>
#include <stdlib.h>  
#include "Input_Validation_Extended.h"
#include "Color_in_CPP.h"
using namespace std;

const int rows = 10;
const int elements = 10;

int maxships = 10;

int matrix[rows][elements];

void Clear()
{
	for(int i=0; i < rows; i++)
	{
		for(int j=0; j < elements; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Show()
{
	for(int i=0; i < rows; i++) //rows
	{
		for(int j=0; j < elements; j++) //columns
		{
			if(matrix[i][j] == 2) //hit
			{
				changeColor(10);
				cout << matrix[i][j] << " ";
				changeColor(7);
			}
			else if(matrix[i][j] == 1) // hide ships from user
			{
				changeColor(9);
				cout << "0 ";	
				changeColor(7);		
			}
			else if(matrix[i][j] == 5) //miss
			{
				changeColor(12);
				cout << matrix[i][j] << " ";
				changeColor(7);
			}
			else
			{
				changeColor(9);
				cout << matrix[i][j] << " ";
				changeColor(7);
			}
			
		}
		cout << endl;
	}
}

void ShowEndBoard() //show the ships at the end of the game / results
{
	for(int i=0; i < rows; i++) //rows
	{
		for(int j=0; j < elements; j++) //columns
		{
			if(matrix[i][j] == 2) //hit
			{
				changeColor(10);
				cout << matrix[i][j] << " ";
				changeColor(7);
			}
			else if(matrix[i][j] == 1)
			{
				changeColor(14);
				cout << matrix[i][j] << " ";
				changeColor(7);		
			}
			else if(matrix[i][j] == 5) //miss
			{
				changeColor(12);
				cout << matrix[i][j] << " ";
				changeColor(7);
			}
			else
			{
				changeColor(9);
				cout << matrix[i][j] << " ";
				changeColor(7);
			}
			
		}
		cout << endl;
	}
}

int NumberOfShips() //Ship counter
{
	int c = 0;

	for(int i=0; i < rows; i++)
	{
		for(int j=0; j < elements; j++)
		{
			if(matrix[i][j] == 1)
				c++;
		}
	}

	return c;
}

void SetShips() //Ship locations
{
	int s = 0;
	while(s < maxships)
	{
		int x = rand() % rows;
		int y = rand() % elements;
		if(matrix[x][y] != 1)
		{
			s++;
			matrix[x][y] = 1;
		}
	}
}

bool Attack(int x,int y)
{
	if(matrix[x][y] == 1)
	{
		matrix[x][y] = 2;
		return true;
	}
	else if(matrix[x][y] == 0)
	{
		matrix[x][y] = 5;
	}
	return false;
}

int main()
{
	srand(time(NULL));
	Clear();
	SetShips();
	int pos1,pos2;
	char prompt;
	while(1)
	{
		
		//Show the Board
		Show(); 
		
		
		cout << "Please input row choice: ";
		pos1 = (validateInt(pos1)-1);
		while(pos1 < 0 || pos1 >= 10)
		{
			changeColor(12);
			cout << "Out of bounds!" << endl;
			changeColor(7);
			cout << "Please input row choice: ";
			pos1 = (validateInt(pos1)-1);
		}
		
		cout << "Please input column choice: ";
		pos2 = (validateInt(pos2)-1);
		while(pos2 < 0|| pos2 >= 10)
		{
			changeColor(12);
			cout << "Out of bounds!" << endl;
			changeColor(7);
			cout << "Please input column choice: ";
			pos2 = (validateInt(pos2)-1);
		}
		
				
		if(Attack(pos1,pos2))
			cout << "You got me! :)" << endl;
		else
			cout << "Sorry no ship at that position!" << endl;
		cout << "Number of ships left: " << NumberOfShips() << endl;
		cout << "Do you want to surrender (y/n)? ";
		prompt = validateChar(prompt);
		if(prompt == 'y')
			break;
	}
	changeColor(10);
	cout << "\n\nGame over!\n" << endl;
	changeColor(7);
	ShowEndBoard();
	
	return 0;
}

/*

A 10x10 matrix (array of integers) is created and populated with 0s.
Then 10 random ships are placed as 1's but still showing as 0s (our changes)
When there is a hit, the number changes to a 2. When there is a miss, the number changes to a 5.
We attack by selecting two numbers - a row and a column in the matrix.
The ships are shown at the end of the game.

*/
