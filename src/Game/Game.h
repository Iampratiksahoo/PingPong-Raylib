#pragma once
#include <vector>

class GameObject;
class Paddle;
class Ball;
class Game
{
public:
	enum Player
	{
		ONE,
		TWO
	};

	void Setup();
	void Play();
	void Cleanup();


	static void RecordScore(Player player);
private:
	void Update();
	void Draw();

	void AddGameObject(GameObject* gameObject);

private:
	std::vector<GameObject*> mGameObjects;

	Ball* mBall;
	Paddle* mPlayer1;
	Paddle* mPlayer2;

	static int mPlayer1Score;
	static int mPlayer2Score;
};

