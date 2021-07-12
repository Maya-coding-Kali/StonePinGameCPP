#pragma once

class Grid
{

private:
	const char* PinArray[256];
	int PinArrayVariable = 0;
	int row = 0;
	int column = 0;
	int columns = PinArrayVariable % 16;
	int rows = (PinArrayVariable / 16);
public:
	Grid();
	~Grid();
	void PrintGameboardArray();
	void GamePlayContoles();
	void InitalizeGameBoardArray();

};

