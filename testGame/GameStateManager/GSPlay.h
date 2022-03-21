#pragma once
#include "GameStateBase.h"
#include "../GameObjects/sPlayer.h"
#include "../GameObjects/CollisionManager.h"
#include "../GameObjects/CreepManager.h"

class GSPlay : public GameStateBase {
public:
	GSPlay();
	virtual ~GSPlay();
	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime, sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
private:
	sPlayer m_Player;
	CollisionManager m_CollisionManager;
	CreepManager m_CreepManager;

	int m_currentScore;
	float m_currentTime;
	sf::Text m_Score;
};