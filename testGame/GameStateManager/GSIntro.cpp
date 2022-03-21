#include "GSIntro.h"
#include <fstream>

GSIntro::GSIntro()
{
	m_currentTime = 0.f;
}

GSIntro::~GSIntro()
{
}

void GSIntro::Exit()
{
}

void GSIntro::Pause()
{
}

void GSIntro::Resume()
{
}

void GSIntro::Init()
{
	printf("Intro\n");
	sf::Texture* texture = DATA->getTexture("intro.png");
	m_Logo.setTexture(*texture);
	m_Logo.setPosition(screenWidth / 2, screenHeight / 2);
	m_Logo.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	DATA->playMusic("new_intro.wav");
	DATA->getMusic("new_intro.wav")->setVolume(100);
}

void GSIntro::Update(float deltaTime, sf::RenderWindow* window)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= 5.f) {
		DATA->getMusic("new_intro.wav")->stop();
		GameStateMachine::GetInstance()->ChangeState(StateTypes::MENU);
	}
}

void GSIntro::Render(sf::RenderWindow* window)
{
	window->draw(m_Logo);
}
