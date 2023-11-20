#include "EventManager.h"

EventManager* EventManager::eInstance = nullptr;

/*
-----------------------------------------------------------------------
|  Following are the methods corresponding to the EventManager Class  |
-----------------------------------------------------------------------
*/

void EventManager::AddComponent(sf::Event::EventType eventType, sf::Mouse::Button mouseEvent, func event)
{
    m_cMouseMap[eventType][mouseEvent] = *event;
}

void EventManager::AddComponent(sf::Event::EventType eventType, sf::Keyboard::Key keyEvent, func event)
{
    m_cKeyboardMap[eventType][keyEvent] = *event;
}

EventManager::EventManager()
{

}

EventManager::EventManager(func* event)
{
    AddComponent(sf::Event::EventType::MouseButtonPressed, sf::Mouse::Left, *event);
}

void EventManager::Update(sf::RenderWindow* oWindow, bool bCanPlace)
{
    //EVENT
    sf::Event oEvent;
    while (oWindow->pollEvent(oEvent))
    {
        if (oEvent.type == sf::Event::Closed)
            oWindow->close();

        if (bCanPlace)
        {
            ManageEvent(oEvent.type, oEvent.mouseButton.button);
        }     

        ManageEvent(oEvent.type, oEvent.key.code);
    }
}

void EventManager::ManageEvent(sf::Event::EventType eType, sf::Mouse::Button mousePressed)
{
    auto itType = m_cMouseMap.find(eType);
    if (itType == m_cMouseMap.end())
        return;

    auto itMouse = itType->second.find(mousePressed);
    if (itMouse == itType->second.end())
        return;

    itMouse->second();
}

void EventManager::ManageEvent(sf::Event::EventType eType, sf::Keyboard::Key keyPressed)
{
    auto itType = m_cKeyboardMap.find(eType);
    if (itType == m_cKeyboardMap.end())
        return;

    auto itKey = itType->second.find(keyPressed);
    if (itKey == itType->second.end())
        return;

    itKey->second();
}