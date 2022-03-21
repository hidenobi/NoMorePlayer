#pragma once
#include "../GameManager/ResourceManager.h"
enum TAG
{
	PLAYER,
	ASTERIOD,
};
class HitBox :public sf::RectangleShape {
public:
	HitBox(sf::Vector2i size);
	~HitBox();
	void Init(sf::Vector2f velocity);

	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f velocity);
	TAG getTag() { return m_Tag; };
	void SetTag(TAG tag) { m_Tag = tag; }

	bool isAlive() { return m_isAlive; }
	void setAlive(bool alive) { m_isAlive = alive; }
private:
	sf::Vector2f m_Velocity;
	bool m_isAlive;
	TAG m_Tag;
};