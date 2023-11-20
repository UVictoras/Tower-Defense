#pragma once
#include "EventManager.h"
#include "GameObject.h"

typedef void(*func)();
using namespace std;

class GameManager
{
private:
	static GameManager* pInstance;

	sf::Vector2i vLocalPosition;

	sf::RenderWindow oWindow;

	bool bWon, bLost, bCanShoot;

	int iRemainingBalls;

public:

	static void Initialize()
	{
		GameManager::pInstance = new GameManager();
	}

	static GameManager* Get()
	{
		return pInstance;
	}

public:

	GameManager();

	void CheckWin();

	void CheckLose();

	void GameLoop();

	//Events

	void CloseWindow();
};