#include "Box.h"

Box::Box(Vector2 pos)
: m_pos(pos)
{
}

void Box::handleSpawning(std::vector<Box>& boxes, b2WorldId& worldId)
{
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		Box p{ GetMousePosition() };

		b2BodyDef bodyDef = b2DefaultBodyDef();
		bodyDef.type = b2_dynamicBody;
		bodyDef.position = { p.m_pos.x / 30, p.m_pos.y / 30 };

		p.bodyId = b2CreateBody(worldId, &bodyDef);
		
		b2Polygon dynamicBox = b2MakeBox(0.5f, 0.5f);
		b2ShapeDef shapeDef = b2DefaultShapeDef();
		shapeDef.density = 1.0f;
		shapeDef.material.friction = 0.3f;

		b2CreatePolygonShape(p.bodyId, &shapeDef, &dynamicBox);

		boxes.push_back(p);
	}
	if (IsKeyPressed(KEY_C))
	{
		boxes.clear();
	}
}

void Box::renderBoxes(std::vector<Box>& boxes, b2WorldId& worldId)
{
	for (auto& square : boxes)
	{
		b2Vec2 position = b2Body_GetPosition(square.bodyId);
		b2Rot rotation = b2Body_GetRotation(square.bodyId);
		float angleRadians = atan2f(rotation.s, rotation.c);

		float angleDegrees = angleRadians * (180.0f / 3.14159265f);

		float x = position.x * 30;
		float y = position.y * 30;
		square.m_pos.x = x;
		square.m_pos.y = y;
		Rectangle squareRec{ square.m_pos.x, square.m_pos.y, square.m_size, square.m_size };
		DrawRectanglePro(squareRec, Vector2(square.m_size / 2, square.m_size / 2), angleDegrees, RAYWHITE);
	}
}
