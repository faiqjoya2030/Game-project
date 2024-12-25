
# include<raylib.h>
# include"Game.h"
# include"color.h"
# include <iostream>


double LastUpdateTime = 0;
bool EventTriggert(double interval) {

	double currentTime = GetTime();
	if (currentTime - LastUpdateTime >= interval) {
		LastUpdateTime = currentTime;
		return true;
	}
	return false;

}


int main() {
	
	
	InitWindow(500, 620, "Tetris Game");
	SetTargetFPS(60);

	Font font = LoadFontEx("Font/myfont.ttf", 64, 0, 0);
	Game game = Game();

	

	while (WindowShouldClose() == false)
	{
		
		if (EventTriggert(0.4)) {
			game.MoveBlockDown();
		}
		game.HandleInput();
		BeginDrawing();
		ClearBackground(darkblue);
		if (game.gameover) {
			DrawTextEx(font, "GameOver", { 320,450 }, 35, 2, WHITE);
		}
		DrawTextEx(font, "Score", { 365,15 }, 38, 2, WHITE);
		DrawTextEx(font, "Next", { 370,175 }, 38, 2, WHITE);
		DrawRectangleRounded({ 320,55,170,60 }, 0.4, 6, lightblue);

		char scoretext[10];
		sprintf_s(scoretext, "%d", game.score);
		Vector2 textsize = MeasureTextEx(font, scoretext, 38, 2);
		DrawTextEx(font, scoretext,{( 320+ (170-textsize.x)/2),65 }, 38, 2, WHITE);

		DrawRectangleRounded({ 320,215,170,180 }, 0.2, 6, lightblue);
		game.Draw();
		

		EndDrawing();
	}


	CloseWindow();
}