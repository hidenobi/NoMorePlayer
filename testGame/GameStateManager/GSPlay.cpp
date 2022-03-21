#include "GSPlay.h"
#include<iostream>
GSPlay::GSPlay()
{
	m_currentScore = 0;
	m_currentTime = 0.f;
}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

void GSPlay::Init()
{
	printf("Play game\n");
	m_Player.Init();
	m_CollisionManager.addObj(m_Player.getHitBox());
	m_CreepManager.Init(m_CollisionManager);

	// score
	m_Score.setFont(*DATA->getFont("ABC.otf"));
	m_Score.setCharacterSize(50);
	m_Score.setString("Score: 0");
	m_Score.setFillColor(sf::Color::Black);
	m_Score.setPosition(50, 50);

	// play music
	DATA->playMusic("play_music.wav");
	DATA->getMusic("play_music.wav")->setVolume(50);
}

void GSPlay::Update(float deltaTime,sf::RenderWindow* window)
{
	if (m_Player.getHitBox()->isAlive()) {
		m_currentTime += deltaTime;
		if (m_currentTime >= 0.5f) {
			m_currentScore++;
			m_Score.setString("Score: "+std::to_string(m_currentScore));
			m_currentTime -= 1.f;
		}
	}
	else ScoreManager::GetInstance()->setCurrentScore(m_currentScore);
	m_Player.Update(deltaTime,*window);
	if (m_Player.getHitBox()->isAlive()) {
		m_CreepManager.Update(deltaTime);
		m_CollisionManager.Update();
	}
}

void GSPlay::Render(sf::RenderWindow* window)
{
	window->clear(sf::Color::White);
	m_Player.Render(window);
	m_CreepManager.Render(window);
	window->draw(m_Score);

}
