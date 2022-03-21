#include "sAsteroid.h"

void sAsteroid::Init(float x, float y)
{
	if (x > 50 && x < screenWidth - 50) {
		if (abs(x - 50) > abs(x - (screenWidth - 50))) x = screenWidth - 50;
		else x = 50;
	}
	if (y > 50 && y < screenHeight - 50) {
		if (abs(y - 50) > abs(y - (screenHeight - 50))) y = screenHeight - 50;
		else y = 50;
	}
	m_HitBox = new HitBox(sf::Vector2i(25, 25));
	m_HitBox->Init(sf::Vector2f(0, 0));
	setStartPoint(sf::Vector2f(x, y));
	m_HitBox->setPosition(x, y);
	m_HitBox->setRotation(rand()%360);
	m_runAni = new Animation1(*DATA->getTexture("F_1.png"), sf::Vector2i(1, 1), 0.1f);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(ASTERIOD);
}
