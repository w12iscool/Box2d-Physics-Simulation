#include "GameEngine.h"

b2WorldDef worldDef = b2DefaultWorldDef();
b2BodyDef groundBodyDef = b2DefaultBodyDef();

void GameEngine::startUp(float userGrav)  
{
	b2SetLengthUnitsPerMeter(30);
	worldDef.gravity = { 0.0f, userGrav };
	worldId = b2CreateWorld(&worldDef);

	groundBodyDef.position = { 0.0f, screenHeight / 30 };
	groundId = b2CreateBody(worldId, &groundBodyDef);
	b2Polygon groundBox = b2MakeBox(screenWidth / 2, 0.1);
	b2ShapeDef groundShapeDef = b2DefaultShapeDef();
	b2CreatePolygonShape(groundId, &groundShapeDef, &groundBox);
}


float timeStep = 1.0f / 60.0f;
int subStepCount = 4;
void GameEngine::update()
{
	b2World_Step(worldId, timeStep, subStepCount);
	box.handleSpawning(boxes, worldId);
}

void GameEngine::render()  
{  
   ClearBackground(BLACK);  
   box.renderBoxes(boxes, worldId);  

   std::string temp = std::to_string(boxes.size());
   const char* text = temp.c_str();
   DrawText(text, 20, 20, 20, RAYWHITE);

   std::string tempFps = std::to_string(GetFPS());
   const char* fpsText = tempFps.c_str();
   DrawText(fpsText, 20, 50, 20, YELLOW);
}

void GameEngine::shutDown()
{
	b2DestroyWorld(worldId);
}
