#pragma once
#include"gh.h"
#include "Blocks.cpp"
class Game {

public:
	Game();
	
	
	std::vector<Block> GetAllBlock();
	void Draw();
	void HandleInput();
	void MoveBlockDown();
	bool IsBlockOutSide();
	void RotateBlock();
	Grid grid;
	bool gameover;
	int score;
	Music music;



private:


	Block GetrandomBlock();
	void MoveBlockLeft();
	void MoveBlockRight();
	std::vector<Block>blocks;
	Block current_block;
	Block next_block;
	void LockBlock();
	void Reset();
	bool Blockfit();
	void updateScore(int lineClear, int moveDownPoint);
	Sound rotatesound;
	Sound clearsound;

};