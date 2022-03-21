#include "Creep.h"

Creep::Creep()
{
	m_stop = true;
	m_soundDeadisPlay = false;
}

Creep::~Creep()
{
	m_currentAni = nullptr;
	if (m_runAni != nullptr) {
		delete m_runAni;
	}
	if (m_HitBox != nullptr) {
		delete m_HitBox;
	}
}

void Creep::Init(float x, float y)
{
}

void Creep::Update(float deltaTime)
{
	if (m_stop == true) return;
	if (m_HitBox->isAlive()) {
		m_HitBox->move(m_HitBox->getVelocity() * deltaTime);
		if (m_HitBox->getPosition().x < 0) {
			m_HitBox->setPosition(screenWidth, m_HitBox->getPosition().y);
		}
		else if (m_HitBox->getPosition().x > screenWidth) {
			m_HitBox->setPosition(0, m_HitBox->getPosition().y);
		}
		else if (m_HitBox->getPosition().y > screenHeight) {
			m_HitBox->setPosition(m_HitBox->getPosition().x, 0);
		}
		else if (m_HitBox->getPosition().y < 0) {
			m_HitBox->setPosition(m_HitBox->getPosition().x, screenHeight);
		}
		m_currentAni->Update(deltaTime);
		m_currentAni->setPosition(getHitBox()->getPosition());
		m_currentAni->setRotation(getHitBox()->getRotation());
	}
}

void Creep::Render(sf::RenderWindow* window)
{
	if (m_stop) return;
	window->draw(*m_currentAni);
}

void Creep::Reset()
{
	m_stop = false;
	m_runAni->Reset();
	m_currentAni = m_runAni;
	m_HitBox->setPosition(m_startPoint);
	m_soundDeadisPlay = false;
}
