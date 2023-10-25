#pragma once
#include "Utils/Vector2D.h"

class GameObject
{
public:
	virtual void Draw() = 0;
	virtual void Update() = 0;
};

