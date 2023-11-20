#pragma once
#include "EventManager.h"

typedef void(*func)();
using namespace std;

class GameManager
{
private:
	static GameManager* pInstance;

	sf::Vector2i vLocalPosition;

	sf::RenderWindow oWindow;

	std::vector<Tower*> tTowers;

	std::vector<Case*> cCases;

	bool bWon, bLost, bCanPlace;

	int iRemainingBalls, iCaseIndex;

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

	void CreateCases();
	
	void CheckInsideCases();

	//Events

	void CloseWindow();

	void CreateTower();
};