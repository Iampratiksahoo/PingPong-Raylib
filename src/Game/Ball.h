#pragma once
#include "GameObject.h"

class Paddle;
class Ball : public GameObject
{
public:
	Ball(Vector2D position, float radius);

	inline void SetSpeed(int speed) { mSpeed.SetX(speed); mSpeed.SetY(speed); }

	inline float GetRadius() const { return mRadius; }
	inline Vector2D GetPosition() const{ return mPosition; }
	inline int GetSpeed() const { return mSpeed.GetX(); }

	// Inherited via GameObject
	void Draw() override;
	void Update() override;

	void OnCollidedWithPaddle(Paddle* paddle);


private:
	void ResetBall();

private:
	Vector2D mPosition;
	Vector2D mSpeed;
	float mRadius;
};

