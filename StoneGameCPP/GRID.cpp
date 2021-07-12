#include "GRID.h"
#include <iostream>
#include <algorithm>
#include<cctype>
using namespace std;
Grid::Grid()
{
	int row = 0;
	int column = 0;
	int columns = PinArrayVariable % 16;
	int rows = (PinArrayVariable / 16);
	PinArrayVariable = 0;
}

Grid::~Grid()
{
}
void Grid::InitalizeGameBoardArray()//Sets up the Array
{
	row = 8;
	column = 8;
	for (PinArrayVariable = 0; PinArrayVariable <= 255; PinArrayVariable++)//loops to create a grid that prints out where the pins are "P"
	{
		if (PinArrayVariable == (row - 1) * 16 + (column - 1))
		{
			PinArray[PinArrayVariable] = " O";
		}
		else
		{
			PinArray[PinArrayVariable] = " P";
		}
	}
}
void Grid::PrintGameboardArray()// design a grid so that the game board is set the game board is 256/256
{
	int RowCounter = 0;
	int n = sizeof(PinArray) / sizeof(PinArray[256]);
	int PinsLeft = count(PinArray, PinArray + n, " P");
	int PinsCaptured = count(PinArray, PinArray + n, " O");
	PinsCaptured = PinsCaptured - 1;
	cout << "You have captured: " << PinsCaptured << " Pins" << endl;//this gives a count so people know the score and know how many pins they have captured
	cout << "You have: "<< PinsLeft << " Pins left"<<endl;//this gives a count so people know the score
	if (PinsLeft == 1)
	{
		cout << " YOU WON THE GAME!!!!!" << endl;

	}
	cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10 |11 |12 |13 |14 |15 |16 |"<<endl;
	for (PinArrayVariable = 0; PinArrayVariable <= 255; PinArrayVariable++)//loops to create a grid that prints out where the pins are "P"
	{
		
		
		
		if (columns == 0)
		{
			if (PinArrayVariable == 0)//prints first column
			{
				cout << "|"<< PinArray[PinArrayVariable] + columns ;
			}
			else if(PinArrayVariable % 16 != 0)//prints columns 2-16
			{
				
				cout << " |" << PinArray[PinArrayVariable] + columns ;
			}
			else if( PinArrayVariable % 16 == 0)//prints rows in the first column 
			{
				
				RowCounter++;
					cout <<" |"<< RowCounter<< "\n|" <<PinArray[PinArrayVariable] + rows ;
					
			}
			if (PinArrayVariable == 255)// prints the last number for the row '16' 
			{
				RowCounter++;
				cout << " |"<< RowCounter << endl << endl;
			}
		}
	
	}
	//I feel like this loop's order is n. I am now curous if IF statments have order N, n2 squared and so on
	
}
void Grid::GamePlayContoles()// This will allow you to choose which pin you want and where to put the pin
{
	

	cout << "Please Select the row with the pin you would like to use: ";
	cin >> row;
	cout << "Please Select the Column with the pin you would like to use: ";
	cin >> column;
	int PinSelection = (row - 1) * 16 + (column - 1);//this formula allows the user to easly pick the row and column and causes the 1d array to be like a table or 2d array
	if (row > 16 || row <= 0 || column <= 0 || column > 16)
	{
		cout << "Thats not a resonable selection you silly human" << endl;
	}
	else if (PinArray[PinSelection] == " O")//if there is no pin which is "O" the user will get a wrong Selection notification
	{
		cout << "Wrong Selection" << endl;
	}
	else if (PinArray[PinSelection] == " P")//once you pick a pin you will then get to pick where you want to put that pin
	{
		
		cout << "Great Selection!" << endl;
		cout << "Please Select which row would like to place the pin in: ";
		cin >> row;
		cout << "Please Select which Column would like to place the pin in: ";
		cin >> column;
		int holeSelection = (row - 1) * 16 + (column - 1);//this formula allows the user to easly pick the row and column and causes the 1d array to be like a table or 2d array

		if (row > 16 || row <= 0 || column <= 0 || column > 16 )//prevents exception if columns and rows are too big or small
		{
			cout << "Thats not a resonable selection you silly human" << endl << endl;
		}
		else if (PinArray[holeSelection] == " P")
		{
			cout << "There is a pin there, please try again" << endl << endl;
		}
		else if (PinArray[holeSelection] == " O" && PinSelection == (holeSelection + 2) ||PinSelection == (holeSelection - 2) || PinSelection == (holeSelection - 32) || PinSelection == (holeSelection + 32))//This if statment only allows you to move the pin in an open hole and you have to go over another pin
		{
			cout << "You got one!" << endl;
			if (PinSelection == (holeSelection + 2))//
			{
				PinArray[holeSelection] = " P";
				PinArray[PinSelection] = " O";
				holeSelection = holeSelection + 1;
				PinArray[holeSelection] = " O";
			}
			else if (PinSelection == (holeSelection - 2))

			{
				PinArray[holeSelection] = " P";
				PinArray[PinSelection] = " O";
				holeSelection = holeSelection - 1;
				PinArray[holeSelection] = " O";
			}
			else if (PinSelection == (holeSelection - 32))

			{
				PinArray[holeSelection] = " P";
				PinArray[PinSelection] = " O";
				holeSelection = holeSelection - 16;
				PinArray[holeSelection] = " O";
			}
			else if (PinSelection == (holeSelection + 32))

			{
				PinArray[holeSelection] = " P";
				PinArray[PinSelection] = " O";
				holeSelection = holeSelection + 16;
				PinArray[holeSelection] = " O";
			}



		}
		else
		{
			cout << "Not valid"<<endl;
		}
	}
	else
	{
		cout << "Try a differnt number please :():" << endl;
	}

}