#pragma once
#include "GameObject.h"

struct Rectangle;
class Paddle :
    public GameObject
{
public:
	Paddle(Vector2D position, Vector2D size, bool isPlayer);

	inline void SetSpeed(int speed) { mSpeed.SetX(speed); mSpeed.SetY(speed); }
	inline void SetIsPlayer(bool isPlayer) { mIsPlayer = isPlayer; }

	inline int GetSpeed() const { return mSpeed.GetX(); }
	inline bool GetIsPlayer() const { return mIsPlayer; }
	inline Rectangle* GetRectangle() { return mRectangle; }

	// Inherited via GameObject
	void Draw() override;
	void Update() override;

private:
	Rectangle* mRectangle;
	Vector2D mPosition;
	Vector2D mSize;
	Vector2D mSpeed;
	bool mIsPlayer;
};

