#include "CreepManager.h"

CreepManager::CreepManager()
{
	m_CreepNum = 100;
	m_TimeSpwanCreep = 0.1f;
	m_currentTime = 0.f;
}

CreepManager::~CreepManager()
{
	for (auto it : m_ListCreep) {
		if (it != nullptr) delete it;
	}
	m_ListCreep.clear();
}

void CreepManager::Init(CollisionManager& collisionManager)
{
	for (int i = 0; i < m_CreepNum; i++) {
		sAsteroid* creepR = new sAsteroid();
		creepR->Init(rand()%screenWidth,rand()%screenHeight);
		creepR->getHitBox()->setAlive(false);
		m_ListCreep.push_back(creepR);
		collisionManager.addObj(creepR->getHitBox());
	}
}

void CreepManager::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime > m_TimeSpwanCreep) {
		Spawn();
		m_currentTime = 0.f;
	}
	for (auto creep : m_ListCreep) {
		creep->Update(deltaTime);
	}
}

void CreepManager::Render(sf::RenderWindow* window)
{
	for (auto creep : m_ListCreep) {
		creep->Render(window);
	}
}

void CreepManager::Spawn()
{
	Creep* creep = nullptr;
	for (auto it : m_ListCreep) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	float x = rand() % screenWidth;
	float y = rand() % screenHeight;
	if (x > 50 && x < screenWidth - 50) {
		if (abs(x - 50) > abs(x - (screenWidth - 50))) x = screenWidth - 50;
		else x = 50;
	}
	if (y > 50 && y < screenHeight - 50) {
		if (abs(y - 50) > abs(y - (screenHeight - 50))) y = screenHeight - 50;
		else y = 50;
	}
	creep->setStartPoint(sf::Vector2f(x, y));
	creep->getHitBox()->setVelocity(sf::Vector2f(rand() % 200 - 4, rand() % 200 - 4));
	creep->Reset();
}
