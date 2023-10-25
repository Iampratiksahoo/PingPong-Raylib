#include "Vector2D.h"

Vector2D::Vector2D() : 
	Vector2D(0, 0)
{
}

Vector2D::Vector2D(const Vector2D& vec) : 
	Vector2D(vec.GetX(), vec.GetY())
{
}

Vector2D::Vector2D(int x, int y) : 
	mX(x),
	mY(y)
{
}
