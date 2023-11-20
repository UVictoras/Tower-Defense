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

	std::vector<Tower*> m_tTowers;

	std::vector<Case*> m_cCases;

	std::vector<PathCase*> m_pPath;

	Enemy* eEnemy;

	bool m_bWon, m_bLost, m_bCanPlace;

	int m_iRemainingBalls, m_iCaseIndex, m_iPathIndex;

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

	void CheckInsideCases();

	void GetPathIndex();

	// Creating Vectors

	void CreateCases();
	
	void CreatePath();

	//Events

	void CloseWindow();

	void CreateTower();
};