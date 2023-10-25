#include "Paddle.h"
#include "raylib/raylib.h"

Paddle::Paddle(Vector2D position, Vector2D size, bool isPlayer) : 
	mPosition(position),
	mSize(size),
	mIsPlayer(isPlayer)
{
	SetSpeed(10);
}

void Paddle::Draw()
{
	mRectangle = new Rectangle();
	mRectangle->x = mPosition.GetX();
	mRectangle->y = mPosition.GetY();
	mRectangle->width = mSize.GetX();
	mRectangle->height = mSize.GetY();
	DrawRectangleRounded(*mRectangle, 5, 0, WHITE);
}

void Paddle::Update()
{
	if ((mIsPlayer && IsKeyDown(KEY_W)) || (!mIsPlayer && IsKeyDown(KEY_UP)))
	{
		mPosition.SetY(mPosition.GetY() - GetSpeed());
	}
	if ((mIsPlayer && IsKeyDown(KEY_S)) || (!mIsPlayer && IsKeyDown(KEY_DOWN)))
	{
		mPosition.SetY(mPosition.GetY() + GetSpeed());
	}

	if (mPosition.GetY() <= 0)
	{
		mPosition.SetY(0);
	}
	if (mPosition.GetY() + mSize.GetY() >= GetScreenHeight())
	{
		mPosition.SetY(GetScreenHeight() - mSize.GetY());
	}
}
