#pragma once
#include"../GameManager/ResourceManager.h"
#include"CollisionManager.h"
#include"sAsteroid.h"
class CreepManager
{
public:
	CreepManager();
	~CreepManager();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	void Spawn();
	std::list<sAsteroid*> m_ListCreep;
	int m_CreepNum;
	float m_TimeSpwanCreep;
	float m_currentTime;
};

