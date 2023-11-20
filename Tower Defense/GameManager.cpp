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

/*
-----------------------------------------------------------------------
|   Following are the methods corresponding to the GameManager Class  |
-----------------------------------------------------------------------
*/

void GameManager::CloseWindow()
{
    oWindow.close();
}

GameManager::GameManager() : oWindow(sf::VideoMode(1920, 1080), "Casse-Brique") // Calling RenderWindow constructor for our game window
{
    bWon = false;
    bLost = false;
    bCanShoot = true;
    iRemainingBalls = 80;
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

void GameManager::GameLoop()
{
    sf::Clock oClock;
    float fDeltaTime = oClock.restart().asSeconds();
    sf::Clock clock;
    float fpsLimit = 1 / 120;
    float fps = 0;

    EventManager::Get()->AddComponent(sf::Event::EventType::KeyPressed, sf::Keyboard::Key::Escape, &EventCloseWindow);

    //GameLoop
    while (oWindow.isOpen() && bWon == false && bLost == false)
    {

        //EVENT
        EventManager::Get()->Update(&oWindow, bCanShoot);

        vLocalPosition = sf::Mouse::getPosition(oWindow);

        //DRAW
        oWindow.clear();

        oWindow.display();
        fDeltaTime = oClock.restart().asSeconds();
        if (fDeltaTime < fpsLimit)
        {
            sf::sleep(sf::seconds(fpsLimit - fDeltaTime));
            fDeltaTime += fpsLimit - fDeltaTime;
        }
        fps = 1.f / fDeltaTime;
        cout << "fps :" << fps << endl;

        CheckWin();
        CheckLose();

        bCanShoot = false;
    }
}