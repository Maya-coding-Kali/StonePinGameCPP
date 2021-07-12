// StoneGameCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include "GRID.h"
using namespace std;
int main()
{
	 char ham ;
	Grid GridObject;
	GridObject.InitalizeGameBoardArray();
	cout << "Game Insructions:\n" << "Use a 'P' Pin to jump over another pin into the 'O' which is an open spot\nYou can only jump one pin at a time and the only way you can move is by jumping a pin\nYour goal is to have one pin left" << endl;
	cout <<"You can only jump horizontal and vertical"<< endl << endl;
	
	while (true)
	{
		GridObject.PrintGameboardArray();
		GridObject.GamePlayContoles();
		
	}
	
	return 0;
	
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
