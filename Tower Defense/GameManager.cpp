#include "GameManager.h"
#include "Math.h"
#include <iostream>
#include <vector>

using namespace std;
sf::Event pressed;

GameManager* GameManager::pInstance = nullptr;

/*
-----------------------------------------------------------------------
|      Following are the functions used in the EventManager maps      |
-----------------------------------------------------------------------
*/

void EventCloseWindow()
{
    GameManager::Get()->CloseWindow();
}

void EventCreateTower()
{
    GameManager::Get()->CreateTower();
}

/*
-----------------------------------------------------------------------
|  Following are the methods used for creating our different vectors  |
-----------------------------------------------------------------------
*/

void GameManager::CreateCases()
{
    Case* cTempCase = new Case(54.f, 48.f, 150.f, 118.f, sf::Color::Red);

    m_cCases.push_back(cTempCase);

    
    Case* cTempCase2 = new Case(452.f, 158.f, 150.f, 118.f, sf::Color::Red);

	m_cCases.push_back(cTempCase2);


	Case* cTempCase3 = new Case(53.f, 578.f, 150.f, 118.f, sf::Color::Red);

	m_cCases.push_back(cTempCase3);


	Case* cTempCase4 = new Case(147.f, 868.f, 150.f, 118.f, sf::Color::Red);

	m_cCases.push_back(cTempCase4);


	Case* cTempCase5 = new Case(1753.f, 65.f, 150.f, 118.f, sf::Color::Red);

	m_cCases.push_back(cTempCase5);


	Case* cTempCase6 = new Case(1666.f, 358.f, 150.f, 118.f, sf::Color::Red);

	m_cCases.push_back(cTempCase6);


	Case* cTempCase7 = new Case(1666.f, 642.f, 150.f, 118.f, sf::Color::Red);

	m_cCases.push_back(cTempCase7);


	Case* cTempCase8 = new Case(1753.f, 936.f, 150.f, 118.f, sf::Color::Red);

	m_cCases.push_back(cTempCase8);
    

}

void GameManager::CreatePath()
{
    PathCase* cTempPath;

    for (int b = 0; b < 6; b++)
    {
        if (b == 5)
            cTempPath = new PathCase(192.f * b, 325.f, 192.f, 192.f, sf::Color::Blue, 'T');
        else 
            cTempPath = new PathCase(192.f * b, 325.f, 192.f, 192.f, sf::Color::Blue, 'R');
        m_pPath.push_back(cTempPath);
    }

    for (int j = 0; j < 2; j++)
    {
        if (j == 1)
            cTempPath = new PathCase(960.f, 325.f - 90.f - 192.f, 192.f, 192.f, sf::Color::Blue, 'L');
        else
            cTempPath = new PathCase(960.f, 325.f - 90.f, 192.f, 90.f, sf::Color::Blue, 'T');

        m_pPath.push_back(cTempPath);
    }

    for (int p = 0; p < 2; p++)
    {
        if (p == 1)
            cTempPath = new PathCase(960.f - 90.f - 192.f, 38.f, 192.f, 192.f, sf::Color::Blue, 'D');
        else
            cTempPath = new PathCase(960.f - 90.f, 38.f, 90.f, 192.f, sf::Color::Blue, 'L');
        m_pPath.push_back(cTempPath);
    }

    for (int y = 0; y < 7; y++)
    {
        if (y % 2 == 0)
        {
            if (y == 6)
            {
                cTempPath = new PathCase(678.f, 38.f + 192.f * (y+1) - 102.f * (y+1), 192.f, 192.f, sf::Color::Blue, 'L');
            }
            else 
                cTempPath = new PathCase(678.f, 38.f + 192.f * (y + 1) - 90.f * (y + 1), 192.f, 192.f, sf::Color::Blue, 'D');
        }
        else
        {
            cTempPath = new PathCase(678.f, 38.f + 192.f * (y + 1) - 90.f * (y + 1), 90.f, 90.f, sf::Color::Blue, 'D');
        }
        m_pPath.push_back(cTempPath);
    }
}

/*
-----------------------------------------------------------------------
|   Following are the methods corresponding to the GameManager Class  |
-----------------------------------------------------------------------
*/

void GameManager::CloseWindow()
{
    oWindow.close();
}

void GameManager::CreateTower()
{
    Tower* tTempTower = new Tower(m_cCases[m_iCaseIndex]->m_fX + m_cCases[m_iCaseIndex]->m_fSizeW / 4, m_cCases[m_iCaseIndex]->m_fY - m_cCases[m_iCaseIndex]->m_fSizeH / 3, 75.f, 130.f, sf::Color::White, "img/tower2.png", 500.f);

    m_tTowers.push_back(tTempTower);

    m_cCases[m_iCaseIndex]->m_bIsFull = true;
}

GameManager::GameManager() : oWindow(sf::VideoMode(1920, 1080), "Casse-Brique") // Calling RenderWindow constructor for our game window
{
    m_bWon = false;
    m_bLost = false;
    m_bCanPlace = false;
	m_iBaseLife = 10;
    m_fClosestEnemy = 0.f;
    m_iClosestEnemyIndex = 0;

    gBackground = new GameObject(0.f, 0.f, 1920.f, 1080.f, sf::Color::White, "img/map.png");

	m_eEnemies.push_back(new Enemy(-50.f, 390.f, 48.f, 48.f, sf::Color::Yellow));
	m_eEnemies.push_back(new Enemy(-250.f, 390.f, 48.f, 48.f, sf::Color::Yellow));
	m_eEnemies.push_back(new Enemy(-450.f, 390.f, 48.f, 48.f, sf::Color::Yellow));

    CreateCases();
    CreatePath();
}

void GameManager::CheckWin()
{
    if (m_eEnemies.size() == 0)
    {
        m_bWon = true;
    }
}

void GameManager::CheckLose()
{
    if (m_iBaseLife == 0)
    {
        m_bLost = true;
    }
}

void GameManager::CheckInsideCases()
{
    for (int r = 0; r < m_cCases.size(); r++)
    {
        if (m_cCases[r]->OverLap(vLocalPosition.x, vLocalPosition.y))
        {
            if (m_cCases[r]->m_bIsFull == false)
            {
                m_bCanPlace = true;
                m_iCaseIndex = r;
            }
        }
    }
}

void GameManager::CheckDeadEnemy()
{
    for (int s = 0; s < m_eEnemies.size(); s++)
    {
        if (m_eEnemies[s]->m_sGraphism == nullptr)
        {
            m_eEnemies.erase(m_eEnemies.begin() + s);
        }
    }
}

void GameManager::CheckEmptyProjectiles()
{
    for (int a = 0; a < m_tTowers.size(); a++)
    {
        for (int ç = 0; ç < m_tTowers[a]->m_pProjectiles.size(); ç++)
		{
            for (int i = 0; i < m_eEnemies.size(); i++)
            {
                m_eEnemies[i]->Hit(m_tTowers[a]->m_pProjectiles[ç]);
            }
        }
        m_tTowers[a]->DeleteProjectile();
    }
}

void GameManager::GetPathIndex()
{
    for (int $ = 0; $ < m_pPath.size(); $++)
    {
        for (int i = 0; i < m_eEnemies.size(); i++)
        {
            if (m_eEnemies[i]->m_iPathIndex == -1)
            {
                if (m_pPath[$]->OverLap(m_eEnemies[i]->m_fX, m_eEnemies[i]->m_fY) && m_eEnemies[i]->m_fX >= 0)
                {
                    m_eEnemies[i]->m_iPathIndex = $;
                    return;
                }
            }
        }
    }
}

void GameManager::GameLoop()
{
    sf::Clock oClock;
    float fDeltaTime = oClock.restart().asSeconds();
    sf::Clock clock;

    EventManager::Get()->AddComponent(sf::Event::EventType::KeyPressed, sf::Keyboard::Key::Escape, &EventCloseWindow);
    EventManager::Get()->AddComponent(sf::Event::EventType::MouseButtonPressed, sf::Mouse::Left, &EventCreateTower);

    //GameLoop
    while (oWindow.isOpen() && m_bWon == false && m_bLost == false)
    {
        GetPathIndex();
        CheckInsideCases();

        for (int i = 0; i < m_eEnemies.size(); i++)
        {
            if (m_eEnemies[i]->m_sGraphism != nullptr && m_eEnemies[i]->m_iPathIndex != -1)
            {
                m_eEnemies[i]->MoveAlongPath(m_pPath[m_eEnemies[i]->m_iPathIndex], fDeltaTime);
                m_eEnemies[i]->Die();
                if (m_eEnemies[i]->HitCastle())
                {
                    m_iBaseLife -= 1;
                }
            }
            if (m_eEnemies[i]->m_fX < 0)
                m_eEnemies[i]->StartMove(fDeltaTime);
        }

        CheckDeadEnemy();

        //EVENT
        EventManager::Get()->Update(&oWindow, m_bCanPlace);

        CheckEmptyProjectiles();
        
        vLocalPosition = sf::Mouse::getPosition(oWindow);
        for (int ù = 0; ù < m_tTowers.size(); ù++)
        {
			m_tTowers[ù]->m_fTimeElapsed += fDeltaTime;
            
            if (m_tTowers[ù]->m_fTimeElapsed >= m_tTowers[ù]->m_fDelay)
			{
				m_iClosestEnemyIndex = -1;
                m_tTowers[ù]->m_fTimeElapsed = 0; 
                for (int i = 0; i < m_eEnemies.size(); i++)
                {
                    if (m_eEnemies[i]->m_sGraphism != nullptr && Math::IsInsideRange(m_tTowers[ù]->m_fX + m_tTowers[ù]->m_fSizeW/2, m_tTowers[ù]->m_fY - m_tTowers[ù]->m_fSizeH / 2, m_eEnemies[i]->m_fX + m_eEnemies[i]->m_fSizeW/2, m_eEnemies[i]->m_fY - m_eEnemies[i]->m_fSizeH/2, m_tTowers[ù]->m_fRadius))
                    {
						m_iClosestEnemyIndex = i;
                        break;
                    }
                }
                if (m_iClosestEnemyIndex != -1)
                {
                    m_tTowers[ù]->Shoot(m_eEnemies[m_iClosestEnemyIndex]->m_fX + m_eEnemies[m_iClosestEnemyIndex]->m_fSizeW, m_eEnemies[m_iClosestEnemyIndex]->m_fY + m_eEnemies[m_iClosestEnemyIndex]->m_fSizeH, m_iClosestEnemyIndex);
                }
            }

            if (m_tTowers[ù]->m_pProjectiles.size() != 0)
            {
                for (int µ = 0; µ < m_tTowers[ù]->m_pProjectiles.size(); µ++)
                {
                    m_tTowers[ù]->m_pProjectiles[µ]->Move(fDeltaTime, sf::Vector2f{ m_eEnemies[m_tTowers[ù]->m_pProjectiles[µ]->m_iEnemyIndex]->m_fX, m_eEnemies[m_tTowers[ù]->m_pProjectiles[µ]->m_iEnemyIndex]->m_fY });
                }
            }
        }
        
        //DRAW
        oWindow.clear();

        gBackground->Draw(&oWindow);

        for (int q = 0; q < m_cCases.size(); q++)
        {
            m_cCases[q]->Draw(&oWindow);
        }

        if (m_tTowers.size() != 0)
        {
            for (int o = 0; o < m_tTowers.size(); o++)
            {
                m_tTowers[o]->Draw(&oWindow);
            }
        }

        if (m_pPath.size() != 0)
        {
            for (int w = 0; w < m_pPath.size(); w++)
            {
                m_pPath[w]->Draw(&oWindow);
            }
        }
        
        for (int à = 0; à < m_tTowers.size(); à++)
		{
            for (int è = 0; è < m_tTowers[à]->m_pProjectiles.size(); è++)
            {
				m_tTowers[à]->m_pProjectiles[è]->Draw(&oWindow);
            }
		}
        for (int i = 0; i < m_eEnemies.size(); i++)
        {
            if (m_eEnemies[i]->m_sGraphism != nullptr)
                m_eEnemies[i]->Draw(&oWindow);
        }

        oWindow.display();
        fDeltaTime = oClock.restart().asSeconds();

        //CheckWin();
        CheckLose();

        m_bCanPlace = false;
    }
}