#pragma once
#include<vector>
#include <raylib.h>
using namespace std;

class Grid
{
public:
	Grid();
	int grid[20][10];
	void initialize();
	void print();
	void Draw();
	bool IsCellOutside(int row1, int column);
	bool IsCellempty(int row, int column);
	int ClearFullRow();


	
private: 
	
	int row;
	int colum;
	int cell_size;
	vector<Color> colors;
	bool IsRowfull(int row);
	void clear_Row(int row);

	void Move_RowDown(int row,int numofRow);

};


