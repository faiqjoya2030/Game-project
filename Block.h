
#pragma once
#include<vector>
#include<map>
#include"Position.h"
#include"color.h"

class Block {
public:
	Block();
	void Draw(int ofsetx,int ofsety);
	void Move(int row, int column);
	std::vector<Position> Get_cellposition();
	void Rotate();
	void UndoRotation();
	int id;
	std::map<int, std::vector<Position>>cells;
	

private:

	int cellSize;
	int rotation_state;
	int rowOffset;
	int columnOffset;
	
	std::vector<Color>colors;
};
 