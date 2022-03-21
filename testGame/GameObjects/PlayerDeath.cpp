#include "PlayerDeath.h"

PlayerDeath::PlayerDeath(IPlayer* player)
{
	m_Player = player;
	m_timeRemain = 3.f;
}

void PlayerDeath::Init()
{
	m_Animation = new Animation1(*DATA->getTexture("explosions/type_B.png"), sf::Vector2i(64, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
}

void PlayerDeath::Update(float deltaTime, sf::RenderWindow& window)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= m_timeRemain) {
		GSM->ChangeState(StateTypes::END);
	}
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PlayerDeath::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PlayerDeath::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}
