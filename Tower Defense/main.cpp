// Tower Defense.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include "GameManager.h"
#include <iostream>

int main()
{
    EventManager::Initialize();
    GameManager::Initialize(); //Initializing GameManager's singleton instance

    GameManager::Get()->GameLoop();

    return 0;
}