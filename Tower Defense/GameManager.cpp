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

    /*
    Case* cTempCase2 = new Case(100.f, 600.f, 100.f, 100.f, sf::Color::Red);

    cCases.push_back(cTempCase2);
    */

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
    Tower* tTempTower = new Tower(m_cCases[m_iCaseIndex]->m_fX + m_cCases[m_iCaseIndex]->m_fSizeW / 4, m_cCases[m_iCaseIndex]->m_fY, 50.f, 75.f, sf::Color::White, "img/tower2.png");

    m_tTowers.push_back(tTempTower);

    m_cCases[m_iCaseIndex]->m_bIsFull = true;
}

GameManager::GameManager() : oWindow(sf::VideoMode(1920, 1080), "Casse-Brique") // Calling RenderWindow constructor for our game window
{
    m_bWon = false;
    m_bLost = false;
    m_bCanPlace = false;
    m_iRemainingBalls = 80;

    eEnemy = new Enemy(0.f, 661.f, 50.f, 50.f, sf::Color::Yellow);

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

void GameManager::GetPathIndex()
{
    for (int $ = 0; $ < m_pPath.size(); $++)
    {
        if (m_pPath[$]->OverLap(eEnemy->m_fX, eEnemy->m_fY))
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
    float fpsLimit = 1 / 120;
    float fps = 120;

    EventManager::Get()->AddComponent(sf::Event::EventType::KeyPressed, sf::Keyboard::Key::Escape, &EventCloseWindow);
    EventManager::Get()->AddComponent(sf::Event::EventType::MouseButtonPressed, sf::Mouse::Left, &EventCreateTower);

    //GameLoop
    while (oWindow.isOpen() && m_bWon == false && m_bLost == false)
    {
        GetPathIndex();
        CheckInsideCases();

        eEnemy->MoveAlongPath(m_pPath[m_iPathIndex], fDeltaTime);

        //EVENT
        EventManager::Get()->Update(&oWindow, m_bCanPlace);

        vLocalPosition = sf::Mouse::getPosition(oWindow);

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

        eEnemy->Draw(&oWindow);

        oWindow.display();
        fDeltaTime = oClock.restart().asSeconds();
        if (fDeltaTime < fpsLimit)
        {
            fps = 1.f / (fpsLimit - fDeltaTime);
            sf::sleep(sf::seconds(fpsLimit - fDeltaTime));
            fDeltaTime += fpsLimit - fDeltaTime;
        }

        //cout << "fps :" << fps  << endl;

        //CheckWin();
        CheckLose();

        m_bCanPlace = false;
    }
}