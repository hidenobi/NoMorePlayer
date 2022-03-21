#pragma once
#include "IPState.h"
#include "IPlayer.h"
#include "../GameStateManager/GameStateMachine.h"

class PlayerDeath :public IPState {
public:
	PlayerDeath(IPlayer* player);
	void Init();
	void Update(float deltaTime, sf::RenderWindow& window);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IPlayer* m_Player;
	Animation1* m_Animation;
	float m_currentTime;
	float m_timeRemain;

};