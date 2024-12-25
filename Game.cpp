#include"Game.h"
#include<random>
Game::Game() {
	grid = Grid();
	blocks = GetAllBlock();
	current_block = GetrandomBlock();
	next_block = GetrandomBlock();
	gameover = false;
	score = 0;
	
}



Block Game::GetrandomBlock() {
	if (blocks.empty()) {
		blocks = GetAllBlock();

	}

	int RandomIndex = rand() % blocks.size();
	Block block = blocks[RandomIndex];
	blocks.erase(blocks.begin() + RandomIndex);
	return block;


}
std::vector<Block>Game::GetAllBlock() {

	return{ lBlock(), IBlock(), JBlock(), SBlock(), ZBlock(),OBlock(), TBlock() };

}
void Game::Draw() {


	grid.Draw();
	current_block.Draw(11,11);

	switch (next_block.id)
	{
	case 3:next_block.Draw(255, 290);
		break;
	case 4:next_block.Draw(255, 280);
		break;
	default:next_block.Draw(270, 270);
		break;
	}


}

void Game::HandleInput()
{
	int keyPressed = GetKeyPressed();
	if (gameover && keyPressed != 0) {

		gameover = false;
		Reset();
	}

	switch (keyPressed)
	{
	case KEY_LEFT:
		MoveBlockLeft();
		break;
	case KEY_RIGHT:
		MoveBlockRight();
		break;
	case KEY_DOWN:
		MoveBlockDown();
		updateScore(0, 1);
		break;
	case KEY_UP:
		RotateBlock();
		break;
	}


}
void Game::MoveBlockLeft() {
	if (!gameover) {
		current_block.Move(0, -1);
		if (IsBlockOutSide() || Blockfit() == false) {
			current_block.Move(0, 1);
		}
	}
}
void Game::MoveBlockRight() {
	if (!gameover) {
		current_block.Move(0, 1);
		if (IsBlockOutSide() || Blockfit() == false) {
			current_block.Move(0, -1);
		}
	}
}
void Game::MoveBlockDown() {
	if (!gameover) {
		current_block.Move(1, 0);
		if (IsBlockOutSide() || Blockfit() == false) {
			current_block.Move(-1, 0);
			LockBlock();
		}
	}
}

bool Game::IsBlockOutSide() {

	std::vector<Position>tiles = current_block.Get_cellposition();
	for (Position item : tiles) {
		if (grid.IsCellOutside(item.row, item.colunm))
			return true;

	}
	return false;

}
void Game::RotateBlock() {

	if (!gameover) {
		current_block.Rotate();
		if (IsBlockOutSide()) {

			current_block.UndoRotation();
		}
		
	}
}

void Game::LockBlock() {
	std::vector<Position>tiles = current_block.Get_cellposition();
	for (Position item : tiles) {

		grid.grid[item.row][item.colunm] = current_block.id;
	
	}
	current_block = next_block;

	if (Blockfit() == false) {

		gameover = true;
	}

	next_block = GetrandomBlock();
	int rowsClear =grid.ClearFullRow();
	updateScore(rowsClear, 0);
	

}

bool Game::Blockfit() {


	std::vector<Position>tiles = current_block.Get_cellposition();
	for(Position item :tiles){
		if (grid.IsCellempty(item.row, item.colunm) == false)
			return false;

	
	}

	return true;
}

void Game::Reset() {
	
 grid.initialize();
 blocks = GetAllBlock();
 current_block = GetrandomBlock();
 next_block = GetrandomBlock();
 score = 0;

}
void Game::updateScore(int lineClear, int moveDownPoint)
{
	switch (lineClear)
	{
	case 1:
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	}

	score += moveDownPoint;

}