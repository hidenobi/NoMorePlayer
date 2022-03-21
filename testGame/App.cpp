#include "App.h"
#include "GameStateManager/GameStateBase.h"
#include<iostream>
#include"../testGame/GameObjects/Background.h"
App::~App()
{
    if (m_window != nullptr) delete m_window;
}

void App::Init()
{
    m_window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), titleGame, sf::Style::Close);
    m_window->setFramerateLimit(60);
    m_window->setVerticalSyncEnabled(false);
    GameStateMachine::GetInstance()->ChangeState(StateTypes::INTRO);
    WConnect->setWindow(m_window);
    srand(time(NULL));
    sf::Texture* text = DATA->getTexture("bk.jpeg");
    m_background.setTexture(*text);
    m_background.setScale(static_cast<float>(m_window->getSize().x) / text->getSize().x,
        static_cast<float>(m_window->getSize().y) / text->getSize().y);
    m_background.setPosition(0, 0);
}

void App::Run()
{
    Init();
    sf::Clock clock;
    float deltaTime = 0.75f;
    while (m_window->isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }
        Update(deltaTime);
        Render();
    }
}

void App::Update(float deltaTime)
{
    if (GameStateMachine::GetInstance()->NeedToChangeState()) {
        GameStateMachine::GetInstance()->PerformStateChange();
    }
    GameStateMachine::GetInstance()->currentState()->Update(deltaTime,m_window);
}

void App::Render()
{
    m_window->clear(sf::Color::White);
    m_window->draw(m_background);
    GameStateMachine::GetInstance()->currentState()->Render(m_window);
    m_window->display();
}
