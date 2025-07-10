#pragma once  
#include "raylib.h"  
#include "box2d/box2d.h"  


#include <vector>
#include <iostream>

class Box  
{  
private:  
   int m_size{ 30 };  
   Vector2 m_pos{ 0 };
   bool m_isCleared{ false };
public:
	b2BodyId bodyId{ 0 };

   Box(Vector2 pos);  
   void handleSpawning(std::vector<Box>& boxes, b2WorldId& worldId);
   void renderBoxes(std::vector<Box>& boxes, b2WorldId& worldId);
};
