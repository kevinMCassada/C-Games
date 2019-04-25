/*
Using Dr_T's Color in CPP as a Header //filename: Color_in_CPP.h in my solution folder
*/
#ifndef COLOR_IN_CPP_H
#define COLOR_IN_CPP_H

#include<iostream>
#include<ctime> //to perform date/time calculations
#include<cstdlib>//for system("pause") and system("cls")
#include<windows.h>//for using various dos commands
#include<conio.h>//for using color and/or "sleep" command

string changeColor(int colorValue)  //function definition
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //use of SetConsoleTextAtrribute()
	SetConsoleTextAttribute(console,colorValue); //set the color of the text to user value 1-255
	return "";
}
#endif
