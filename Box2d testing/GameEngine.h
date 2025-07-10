#pragma once
#include "raylib.h"
#include "Box.h"
#include "box2d/box2d.h"

#include <vector>
#include <iostream>
#include <string>
#include "assert.h"


const int screenHeight{ 600 };
const int screenWidth{ 600 };
class GameEngine
{
private:
	std::vector<Box> boxes;
	Box box{ Vector2(0, 0) };
public:
	b2WorldId worldId = {};
	b2BodyId groundId = {};
	void startUp(float userGrav);
	void update();
	void render();
	void shutDown();
};

