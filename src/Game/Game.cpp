#include "Game.h"
#include "raylib/raylib.h"
#include "GameObject.h"
#include "Ball.h"
#include "Paddle.h"
#include "Definations.h"
#include <iostream>

int Game::mPlayer1Score = 0;
int Game::mPlayer2Score = 0;

void Game::Setup()
{
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ping!Pong");
	SetTargetFPS(FRAME_RATE);
	
	// Create GameObjects
	mBall = new Ball(Vector2D(400, 300), 20);
	mPlayer1 = new Paddle(Vector2D(10, SCREEN_HEIGHT / 2 - 60), Vector2D(25, 120), true);
	mPlayer2 = new Paddle(Vector2D(SCREEN_WIDTH - 25 - 10, SCREEN_HEIGHT/2 - 60), Vector2D(25, 120), false);

	// Add Gameobjects
	AddGameObject(mBall);
	AddGameObject(mPlayer1);
	AddGameObject(mPlayer2);
}

void Game::Play()
{
	while (!WindowShouldClose())
	{
		// Update
		Update();

		//Draw
		BeginDrawing();
		Draw();
		EndDrawing();
	}
}

void Game::Cleanup()
{
	CloseWindow();
}

void Game::RecordScore(Player player)
{
	if (player == ONE)
	{
		mPlayer1Score++;
	}
	else
	{
		mPlayer2Score++;
	}
}

void Game::Update()
{
	// Check for ball collision
	if (mPlayer1->GetRectangle() && CheckCollisionCircleRec(Vector2(mBall->GetPosition().GetX(), mBall->GetPosition().GetY()), mBall->GetRadius(), *mPlayer1->GetRectangle()))
	{
		mBall->OnCollidedWithPaddle(mPlayer1);
	}

	if (mPlayer2->GetRectangle() && CheckCollisionCircleRec(Vector2(mBall->GetPosition().GetX(), mBall->GetPosition().GetY()), mBall->GetRadius(), *mPlayer2->GetRectangle()))
	{
		mBall->OnCollidedWithPaddle(mPlayer2);
	}

	for (GameObject* gameObject : mGameObjects)
	{
		gameObject->Update();
	}

}

void Game::Draw()
{
	// Set the background color
	ClearBackground(Color{DARK_GREEN});

	// Add a line in the middle of the screen
	DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE);

	// Stylize the Game
	DrawRectangle(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, Color{ GREEN });
	DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 150, Color{ LIGHT_GREEN });

	// Draw the player Scores
	DrawText(TextFormat("%i", mPlayer1Score), SCREEN_WIDTH / 4 - 20, 20, 80, WHITE);
	DrawText(TextFormat("%i", mPlayer2Score), 3 * SCREEN_WIDTH / 4 - 20, 20, 80, WHITE);

	// Draw all gameobjects
	for (GameObject* gameObject : mGameObjects)
	{
		gameObject->Draw();
	}
}

void Game::AddGameObject(GameObject* gameObject)
{
	mGameObjects.push_back(gameObject);
}

