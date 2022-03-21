#pragma once
#include "IPlayer.h"

class sPlayer : public IPlayer
{
public:
	sPlayer();
	~sPlayer();
	void changeNextState(IPState::STATE nextState);

	void Init();
	void Update(float deltaTime,sf::RenderWindow& window);
	void Render(sf::RenderWindow* window);

	HitBox* getHitBox();

private:
	void performStateChange();
	HitBox* m_HitBox;
	IPState::STATE m_nextState;
	IPState* m_currentState;
	IPState* m_flyState;
	IPState* m_deathState;
};