#include "GameEngine.h"

b2WorldDef worldDef = b2DefaultWorldDef();


void GameEngine::startUp(float userGrav)  
{
	b2SetLengthUnitsPerMeter(30);
	worldDef.gravity = { 0.0f, userGrav };
	worldId = b2CreateWorld(&worldDef);
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
}

void GameEngine::shutDown()
{
	b2DestroyWorld(worldId);
}
