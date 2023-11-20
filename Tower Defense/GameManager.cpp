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
|   Following are the methods corresponding to the GameManager Class  |
-----------------------------------------------------------------------
*/

void GameManager::CloseWindow()
{
    oWindow.close();
}

void GameManager::CreateTower()
{
    Tower* tTempTower = new Tower(vLocalPosition.x-25.f, vLocalPosition.y-37.5f, 50.f, 75.f, sf::Color::White, "img/tower2.png");

    tTowers.push_back(tTempTower);

    cCases[iCaseIndex]->bIsFull = true;
}

GameManager::GameManager() : oWindow(sf::VideoMode(1920, 1080), "Casse-Brique") // Calling RenderWindow constructor for our game window
{
    bWon = false;
    bLost = false;
    bCanPlace = false;
    iRemainingBalls = 80;

    CreateCases();
}

void GameManager::CheckWin()
{
    bWon = true;
}

void GameManager::CheckLose()
{
    if (iRemainingBalls == 0)
    {
        bLost = true;
    }
}

void GameManager::CreateCases()
{
    Case* cTempCase = new Case(100.f, 100.f, 100.f, 100.f, sf::Color::Red);

    cCases.push_back(cTempCase);

    Case* cTempCase2 = new Case(100.f, 600.f, 100.f, 100.f, sf::Color::Red);

    cCases.push_back(cTempCase2);

}

void GameManager::CheckInsideCases()
{
    for (int r = 0; r < cCases.size(); r++)
    {
        if (cCases[r]->OverLap(vLocalPosition.x, vLocalPosition.y))
        {
            if (cCases[r]->bIsFull == false)
            {
                bCanPlace = true;
                iCaseIndex = r;
            }
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
    while (oWindow.isOpen() && bWon == false && bLost == false)
    {
        CheckInsideCases();

        //EVENT
        EventManager::Get()->Update(&oWindow, bCanPlace);

        vLocalPosition = sf::Mouse::getPosition(oWindow);

        //DRAW
        oWindow.clear();

        for (int q = 0; q < cCases.size(); q++)
        {
            cCases[q]->Draw(&oWindow);
        }

        if (tTowers.size() != 0)
        {
            for (int o = 0; o < tTowers.size(); o++)
            {
                tTowers[o]->Draw(&oWindow);
            }
        }

        oWindow.display();
        fDeltaTime = oClock.restart().asSeconds();
        if (fDeltaTime < fpsLimit)
        {
            fps = 1.f / (fpsLimit - fDeltaTime);
            sf::sleep(sf::seconds(fpsLimit - fDeltaTime));
            //fDeltaTime += fpsLimit - fDeltaTime;
        }
        cout << cCases.size();
        //cout << "fps :" << fps  << endl;

        //CheckWin();
        CheckLose();

        bCanPlace = false;
    }
}