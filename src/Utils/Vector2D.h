#pragma once
class Vector2D
{
public:
	Vector2D();
	Vector2D(const Vector2D& vec);
	Vector2D(int x, int y);

	inline int GetX() const { return mX; }
	inline int GetY() const { return mY; }

	inline void SetX(int x) { mX = x; }
	inline void SetY(int y) { mY = y; }

	inline static Vector2D Zero() { return Vector2D(0, 0); };
private:
	int mX;
	int mY;
};

