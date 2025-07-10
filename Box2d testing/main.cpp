#include "raylib.h"
#include "GameEngine.h"

GameEngine game;
int main()
{
	std::cout << "Enter a gravity amount: ";
	float userGrav;
	std::cin >> userGrav;

	InitWindow(screenWidth, screenHeight, "Box2d test");
	SetTargetFPS(60);

	game.startUp(userGrav);
	while (!WindowShouldClose())
	{
		game.update();
		BeginDrawing(); 
		game.render();
		EndDrawing();
	}
	game.shutDown();
	CloseWindow();
	return 0;
}
