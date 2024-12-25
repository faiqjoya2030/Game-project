
#include"gh.h"
#include<iostream>
#include"color.h"
using namespace std;

Grid::Grid() {
	row = 20;
	colum = 10;
	cell_size = 30;
	initialize();
	colors = Get_cellscolor();

}
void Grid::initialize() {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < colum; j++) {

			grid[i][j] = 0;

		}
	}


}
void Grid::print() {

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < colum; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}


}

 void Grid::Draw() {

	 for (int i = 0; i < row; i++)
	 {
		 for (int j = 0; j < colum; j++) {
			 int cell_value = grid[i][j];

			 DrawRectangle(j * cell_size+11, i * cell_size+11, cell_size-1, cell_size-1, colors[cell_value]);
		 }
	 }

 }

 bool Grid::IsCellOutside(int row1, int column)
 {

	 if (row1 >= 0 && row1 < row && column >= 0 && column < colum) {
		 return false;
	 }
	 return true;
 }

 bool Grid::IsCellempty(int row, int column)
 {
	 if (grid[row][column] == 0) {

		 return true;

	 }
	 return false;
	 
 }

 

 bool Grid::IsRowfull(int row)  {

	 for (int i= 0 ; i < colum; i++) {

		 if (grid[row][i] == 0) {
			 return false;
		 }

	 }

	 return true;
 }
 void Grid::clear_Row(int row) {

	 for (int i = 0; i < colum; i++) {

		 grid[row][i] = 0;
	 }

  }

 void Grid::Move_RowDown(int row,int numofRow) {


	 for (int i= 0; i < colum; i++) {
		 grid[row + numofRow][i] = grid[row][i];
		 grid[row][i] = 0;

	 }


 }
 int Grid::ClearFullRow()
 {
	 int completed = 0;
	 for (int i = row - 1; i >= 0; i--) {

		 if (IsRowfull(i)) {
			 clear_Row(i);
			 completed++;


		 }
		 else if (completed > 0)
			 Move_RowDown(i,completed);

	 }


	 return completed;
	
 }