
#include"Block.h"

Block::Block() {
	cellSize = 30;
	rotation_state = 0;
	colors = Get_cellscolor();
	rowOffset = 0;
	columnOffset = 0;

}
 void Block::Draw(int ofsetx,int ofsety) {

	 std::vector<Position>tiles = Get_cellposition();
	 for (Position item : tiles) {

		 DrawRectangle(item.colunm * cellSize + ofsetx, item.row * cellSize + ofsety, cellSize - 1, cellSize - 1, colors[id]);
	 }


}
 void Block::Move(int row, int column) {
	 rowOffset += row;
	 columnOffset += column;

 }
 std::vector<Position>Block::Get_cellposition() {

	 std::vector<Position>tiles = cells[rotation_state];
	 std::vector<Position>MoveTiles;
	 for (Position Item : tiles) {

		 Position newPosition = Position(Item.row + rowOffset, Item.colunm + columnOffset);
		 MoveTiles.push_back(newPosition);

	 }
	 return MoveTiles;




 }
 void Block::Rotate() {

	 rotation_state++;
	 if (rotation_state == (int)cells.size())
		 rotation_state = 0;


 }
 void Block :: UndoRotation() {
	 rotation_state--;
	 if (rotation_state == -1) {

		 rotation_state = cells.size() - 1;
	 }

	  

 }