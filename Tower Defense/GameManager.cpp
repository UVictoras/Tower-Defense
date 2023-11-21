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
    Case* cTempCase = new Case(100.f, 100.f, 100.f, 100.f, sf::Color::Red);

    m_cCases.push_back(cTempCase);

    
    Case* cTempCase2 = new Case(200.f, 500.f, 100.f, 100.f, sf::Color::Red);

    m_cCases.push_back(cTempCase2);
    

}

void GameManager::CreatePath()
{
    PathCase* cTempPath;

    for (int b = 0; b < 4; b++)
    {
        if (b == 3)
            cTempPath = new PathCase(192.f * b, 600.f, 192.f, 192.f, sf::Color::Blue, 'T');
        else 
            cTempPath = new PathCase(192.f * b, 600.f, 192.f, 192.f, sf::Color::Blue, 'R');
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
    Tower* tTempTower = new Tower(m_cCases[m_iCaseIndex]->m_fX + m_cCases[m_iCaseIndex]->m_fSizeW / 8, m_cCases[m_iCaseIndex]->m_fY - m_cCases[m_iCaseIndex]->m_fSizeH / 2, 75.f, 130.f, sf::Color::White, "img/tower2.png");

    m_tTowers.push_back(tTempTower);

    m_cCases[m_iCaseIndex]->m_bIsFull = true;
}

GameManager::GameManager() : oWindow(sf::VideoMode(1920, 1080), "Casse-Brique") // Calling RenderWindow constructor for our game window
{
    m_bWon = false;
    m_bLost = false;
    m_bCanPlace = false;
    m_iRemainingBalls = 80;

    m_eEnemies.push_back(new Enemy(0.f, 661.f, 48.f, 48.f, sf::Color::Yellow));

    CreateCases();
    CreatePath();
}

void GameManager::CheckWin()
{
    m_bWon = true;
}

void GameManager::CheckLose()
{
    if (m_iRemainingBalls == 0)
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
    if (m_eEnemies[0]->m_sGraphism == nullptr)
    {
        return;
    }
}

void GameManager::CheckEmptyProjectiles()
{
    for (int a = 0; a < m_tTowers.size(); a++)
    {
        for (int ç = 0; ç < m_tTowers[a]->m_pProjectiles.size(); ç++)
        {
            m_eEnemies[0]->Hit(m_tTowers[a]->m_pProjectiles[ç]);
        }
        m_tTowers[a]->DeleteProjectile();
    }
}

void GameManager::GetPathIndex()
{
    for (int $ = 0; $ < m_pPath.size(); $++)
    {
        if (m_pPath[$]->OverLap(m_eEnemies[0]->m_fX, m_eEnemies[0]->m_fY))
        {
            m_iPathIndex = $;
            return;
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

        if (m_eEnemies[0]->m_sGraphism != nullptr)
        {
            m_eEnemies[0]->MoveAlongPath(m_pPath[m_iPathIndex], fDeltaTime);
            m_eEnemies[0]->Die();
        }

        //EVENT
        EventManager::Get()->Update(&oWindow, m_bCanPlace);

        CheckEmptyProjectiles();

        vLocalPosition = sf::Mouse::getPosition(oWindow);
        for (int ù = 0; ù < m_tTowers.size(); ù++)
        {
			m_tTowers[ù]->fTimeElapsed += fDeltaTime;

            if (m_tTowers[ù]->fTimeElapsed >= m_tTowers[ù]->fDelay){

				m_tTowers[ù]->fTimeElapsed = 0;
                if (m_eEnemies[0]->m_sGraphism != nullptr)
                    m_tTowers[ù]->Shoot(m_eEnemies[0]->m_fX + m_eEnemies[0]->m_fSizeW, m_eEnemies[0]->m_fY + m_eEnemies[0]->m_fSizeH);
            }

            if (m_tTowers[ù]->m_pProjectiles.size() != 0)
            {
                for (int µ = 0; µ < m_tTowers[ù]->m_pProjectiles.size(); µ++)
                {
                    m_tTowers[ù]->m_pProjectiles[µ]->Move(fDeltaTime, m_eEnemies[0]->m_fX, m_eEnemies[0]->m_fY);
                }
            }
        }

        //DRAW
        oWindow.clear();

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
        
        if (m_eEnemies[0]->m_sGraphism != nullptr)
            m_eEnemies[0]->Draw(&oWindow);

        oWindow.display();
        fDeltaTime = oClock.restart().asSeconds();

        //CheckWin();
        CheckLose();

        m_bCanPlace = false;
        cout << m_eEnemies[0]->m_iHP << endl;
    }
}