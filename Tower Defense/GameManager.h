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

	Enemy* m_eEnemiesList[10];

	std::vector<Enemy*> m_eEnemies;

	std::vector<int> m_iTowerPrice;

	bool m_bWon, m_bLost, m_bCanPlace;

	int m_iBaseLife, m_iCaseIndex, m_iMoney, m_iTowerIndex;

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

    float m_fClosestEnemy;

	int m_iClosestEnemyIndex;

	GameObject* gBackground;

	GameManager();

	void CheckWin();

	void CheckLose();

	void GameLoop();

	void CheckInsideCases();

	void GetPathIndex();

	// Delete Broken Objects

	void CheckDeadEnemy();

	void CheckEmptyProjectiles();

	// Creating Vectors

	void CreateCases();
	
	void CreatePath();

	//Events

	void CloseWindow();

	void CreateTower();

	void ChooseTower1();

	void ChooseTower2();

	void ChooseTower3();
};