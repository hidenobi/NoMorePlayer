#include "sPlayer.h"
#include "PlayerFly.h"
#include "PlayerDeath.h"
sPlayer::sPlayer()
{
	m_nextState = IPState::SNULL;
	m_flyState = new PlayerFly(this);
	m_deathState = new PlayerDeath(this);
	m_currentState = m_flyState;
}

sPlayer::~sPlayer()
{

}

void sPlayer::changeNextState(IPState::STATE nextState)
{
	m_nextState = nextState;
}

void sPlayer::Init()
{
	m_flyState->Init();
	m_deathState->Init();
	m_HitBox = new HitBox(sf::Vector2i(32, 25));
	m_HitBox->setPosition(400, groundY);
	m_HitBox->Init(sf::Vector2f(0, 0));
	m_HitBox->SetTag(PLAYER);
}

void sPlayer::Update(float deltaTime, sf::RenderWindow& window)
{
	performStateChange();
	m_currentState->Update(deltaTime, window);
}

void sPlayer::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
}

HitBox* sPlayer::getHitBox()
{
	return m_HitBox;
}

void sPlayer::performStateChange()
{
	if (m_nextState != IPState::SNULL) {
		switch (m_nextState)
		{
		case IPState::FLY:
			m_currentState = m_flyState;
			break;
		case IPState::DEATH:
			m_currentState = m_deathState;
			break;
		default:
			break;
		}
		m_nextState = IPState::SNULL;
		m_currentState->Reset();
	}
}

