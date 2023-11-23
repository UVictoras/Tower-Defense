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

void EventChooseTower1()
{
    GameManager::Get()->ChooseTower1();
}

void EventChooseTower2()
{
    GameManager::Get()->ChooseTower2();
}

void EventChooseTower3()
{
    GameManager::Get()->ChooseTower3();
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

    m_pPath.push_back(new PathCase(0, 325.f, 10.f, 192.f, sf::Color::Blue, 'R'));
    m_pPath.push_back(new PathCase(1046.f, 325.f, 10.f, 192.f, sf::Color::Red, 'T'));
    m_pPath.push_back(new PathCase(930.f, 139.f, 192.f, 10.f, sf::Color::Green, 'L'));
    m_pPath.push_back(new PathCase(730.f, 38.f, 10.f, 192.f, sf::Color::Blue, 'D'));
    m_pPath.push_back(new PathCase(678.f, 928.f, 192.f, 10.f, sf::Color::Red, 'L'));
    m_pPath.push_back(new PathCase(398.f, 838.f, 10.f, 192.f, sf::Color::Red, 'T'));
    m_pPath.push_back(new PathCase(358.f, 638.f, 192.f, 10.f, sf::Color::Red, 'R'));
    m_pPath.push_back(new PathCase(1308.f, 608.f, 10.f, 192.f, sf::Color::Red, 'T'));
    m_pPath.push_back(new PathCase(1258.f, 188.f, 192.f, 10.f, sf::Color::Red, 'R'));
    m_pPath.push_back(new PathCase(1518.f, 148.f, 10.f, 192.f, sf::Color::Red, 'D'));
    m_pPath.push_back(new PathCase(1438.f, 868.f, 192.f, 10.f, sf::Color::Red, 'L'));
    m_pPath.push_back(new PathCase(988.f, 838.f, 10.f, 192.f, sf::Color::Red, 'D'));
    //m_pPath.push_back(new PathCase(960.f - 90.f - 192.f, 38.f, 192.f, 192.f, sf::Color::Blue, 'D'));

    /*for (int j = 0; j < 2; j++)
    {
        if (j == 1)
            cTempPath = new PathCase(960.f, 325.f - 90.f - 192.f, 192.f, 192.f, sf::Color::Blue, 'L');
        else
            cTempPath = new PathCase(960.f, 325.f - 90.f, 192.f, 90.f, sf::Color::Blue, 'T');

        m_pPath.push_back(cTempPath);
    }*/
    /*
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
    }*/
}

/*
-----------------------------------------------------------------------
|   Following are the methods corresponding to the GameManager Class  |
-----------------------------------------------------------------------
*/

void GameManager::ChooseTower1()
{
    m_iTowerIndex = 0;
}

void GameManager::ChooseTower2()
{
    m_iTowerIndex = 1;
}

void GameManager::ChooseTower3()
{
    m_iTowerIndex = 2;
}

void GameManager::CloseWindow()
{
    oWindow.close();
}

void GameManager::CreateTower()
{
    if (m_iMoney >= m_iTowerPrice[m_iTowerIndex])
    {
        if (m_iTowerIndex == 0)
        {
            Tower* tTempTower = new Tower(m_cCases[m_iCaseIndex]->m_fX + m_cCases[m_iCaseIndex]->m_fSizeW / 4, m_cCases[m_iCaseIndex]->m_fY - m_cCases[m_iCaseIndex]->m_fSizeH / 3, 75.f, 130.f, sf::Color::White, "img/tower1.png", 400.f, 1, 0.35f);
            m_tTowers.push_back(tTempTower);
            m_cCases[m_iCaseIndex]->m_bIsFull = true;
        }
        else if(m_iTowerIndex == 1)
        {
            Tower* tTempTower = new Tower(m_cCases[m_iCaseIndex]->m_fX + m_cCases[m_iCaseIndex]->m_fSizeW / 4, m_cCases[m_iCaseIndex]->m_fY - m_cCases[m_iCaseIndex]->m_fSizeH / 3, 75.f, 130.f, sf::Color::White, "img/tower2.png", 300.f, 3, 0.65f);
            m_tTowers.push_back(tTempTower);
            m_cCases[m_iCaseIndex]->m_bIsFull = true;
        }
        else if (m_iTowerIndex == 2)
        {
            Tower* tTempTower = new Tower(m_cCases[m_iCaseIndex]->m_fX + m_cCases[m_iCaseIndex]->m_fSizeW / 4, m_cCases[m_iCaseIndex]->m_fY - m_cCases[m_iCaseIndex]->m_fSizeH / 3, 75.f, 130.f, sf::Color::White, "img/tower3.png", 9999.f, 10, 1.5f);
            m_tTowers.push_back(tTempTower);
            m_cCases[m_iCaseIndex]->m_bIsFull = true;
        }


        m_iMoney -= m_iTowerPrice[m_iTowerIndex];
    }
}

GameManager::GameManager() : oWindow(sf::VideoMode(1920, 1080), "Casse-Brique") // Calling RenderWindow constructor for our game window
{
    m_bWon = false;
    m_bLost = false;
    m_bCanPlace = false;
	m_iBaseLife = 10;
    m_fClosestEnemy = 0.f;
    m_iClosestEnemyIndex = 0;
    m_iMoney = 100;
    m_iTowerIndex = 0;
    m_iTowerPrice.push_back(100);
    m_iTowerPrice.push_back(150);
    m_iTowerPrice.push_back(250);

    gBackground = new GameObject(0.f, 0.f, 1920.f, 1080.f, sf::Color::White, "img/map.png");

	m_eEnemies.push_back(new Enemy(-50.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
	m_eEnemies.push_back(new Enemy(-250.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
	m_eEnemies.push_back(new Enemy(-450.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-650.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-850.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-1050.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-1250.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-1450.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-1650.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-1850.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-2050.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-2250.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-2450.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-2650.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/necromancer.png", 15));
    m_eEnemies.push_back(new Enemy(-2850.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-3050.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-3250.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/necromancer.png", 15));
    m_eEnemies.push_back(new Enemy(-3450.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/necromancer.png", 15));
    m_eEnemies.push_back(new Enemy(-3650.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-3850.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/necromancer.png", 15));
    m_eEnemies.push_back(new Enemy(-4050.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-4250.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-4450.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/necromancer.png", 15));
    m_eEnemies.push_back(new Enemy(-4650.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/necromancer.png", 15));
    m_eEnemies.push_back(new Enemy(-4850.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/witch.png", 5));
    m_eEnemies.push_back(new Enemy(-5050.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/necromancer.png", 15));
    m_eEnemies.push_back(new Enemy(-5250.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/necromancer.png", 15));
    m_eEnemies.push_back(new Enemy(-5850.f, 390.f, 48.f, 48.f, sf::Color::Yellow, "img/warlock.png", 100));

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
            for (int i = 0; i < m_tTowers.size(); i++)
            {
                for (int j = 0; j < m_tTowers[i]->m_pProjectiles.size(); j++)
                {
                    if (m_tTowers[i]->m_pProjectiles[j]->m_iEnemyIndex == s)
                    {
                        m_tTowers[i]->m_pProjectiles.erase(m_tTowers[i]->m_pProjectiles.begin() + s);
                    }
                }
            }
            m_eEnemies.erase(m_eEnemies.begin() + s);
            m_iMoney += 25;
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
                m_eEnemies[i]->Hit(m_tTowers[a]->m_pProjectiles[ç], m_tTowers[a]->m_iDamage);
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
            if (true)
            {
                if (m_pPath[$]->OverLap(m_eEnemies[i]->m_fX, m_eEnemies[i]->m_fY) && m_eEnemies[i]->m_fX >= 0)
                {
                    if ($ == m_eEnemies[i]->m_iPathIndex + 1)
                    {
                        m_eEnemies[i]->m_iPathIndex += 1;
                        return;
                    }
                }
            }
        }
    }
}

void GameManager::GameLoop()
{
    oWindow.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("font/DePixelBreitFett.ttf")) {

    }

    sf::Text texteArgent;
    texteArgent.setFont(font);
    texteArgent.setCharacterSize(16);
    texteArgent.setFillColor(sf::Color::Yellow);

    sf::Clock oClock;
    float fDeltaTime = oClock.restart().asSeconds();
    sf::Clock clock;

    EventManager::Get()->AddComponent(sf::Event::EventType::KeyPressed, sf::Keyboard::Key::Escape, &EventCloseWindow);
    EventManager::Get()->AddComponent(sf::Event::EventType::KeyPressed, sf::Keyboard::Key::Num1, &EventChooseTower1);
    EventManager::Get()->AddComponent(sf::Event::EventType::KeyPressed, sf::Keyboard::Key::Num2, &EventChooseTower2);
    EventManager::Get()->AddComponent(sf::Event::EventType::KeyPressed, sf::Keyboard::Key::Num3, &EventChooseTower3);
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
                m_eEnemies[i]->Move(fDeltaTime);
                m_eEnemies[i]->Die();
                if (m_eEnemies[i]->HitCastle())
                {
                    m_iBaseLife -= 1;
                }
            }
            if (m_eEnemies[i]->m_fX < 0)
                m_eEnemies[i]->StartMove(fDeltaTime);
        }


        //EVENT
        EventManager::Get()->Update(&oWindow, m_bCanPlace);

        CheckDeadEnemy();
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

        texteArgent.setString("Argent : " + std::to_string(m_iMoney));

        gBackground->Draw(&oWindow);

        /*for (int q = 0; q < m_cCases.size(); q++)
        {
            m_cCases[q]->Draw(&oWindow);
        }

        if (m_pPath.size() != 0)
        {
            for (int w = 0; w < m_pPath.size(); w++)
            {
                m_pPath[w]->Draw(&oWindow);
            }
        }*/

        if (m_tTowers.size() != 0)
        {
            for (int o = 0; o < m_tTowers.size(); o++)
            {
                m_tTowers[o]->Draw(&oWindow);
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

        oWindow.draw(texteArgent);

        oWindow.display();
        fDeltaTime = oClock.restart().asSeconds();

        //CheckWin();
        CheckLose();

        m_bCanPlace = false;
    }
}