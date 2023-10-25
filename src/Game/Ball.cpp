#include "Ball.h"
#include "Utils/Vector2D.h"
#include "Definations.h"
#include "Game.h"

#include <typeinfo>
#include "Paddle.h"
#include "raylib/raylib.h"

Ball::Ball(Vector2D position, float radius) :
	mPosition(position),
	mRadius(radius),
	mSpeed(10, 10)
{
}

void Ball::Draw()
{
	mPosition.SetX(mPosition.GetX() + mSpeed.GetX());
	mPosition.SetY(mPosition.GetY() + mSpeed.GetY());
	DrawCircle(mPosition.GetX(), mPosition.GetY(), mRadius, Color{YELLOW});
}

void Ball::Update()
{
	if (mPosition.GetX() + mRadius >= SCREEN_WIDTH)
	{
		Game::RecordScore(Game::Player::TWO);
		ResetBall();
	}
	if (mPosition.GetX() - mRadius <= 0)
	{
		Game::RecordScore(Game::Player::ONE);
		ResetBall();
	}

	if (mPosition.GetY() + mRadius >= SCREEN_HEIGHT || mPosition.GetY() - mRadius <= 0)
	{
		mSpeed.SetY(mSpeed.GetY() * -1);
	}

	
}

void Ball::OnCollidedWithPaddle(Paddle* paddle)
{
	mSpeed.SetX(mSpeed.GetX() * -1);
}

void Ball::ResetBall()
{
	mPosition.SetX(SCREEN_WIDTH / 2);
	mPosition.SetY(SCREEN_HEIGHT / 2);

	int speedChoices[2] = { -1, 1 };
	mSpeed.SetX(mSpeed.GetX() * speedChoices[GetRandomValue(0, 1)]);
	mSpeed.SetY(mSpeed.GetY() * speedChoices[GetRandomValue(0, 1)]);
}

