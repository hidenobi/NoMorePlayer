#pragma once
#include"IPlayer.h"
#include"IPState.h"
class PlayerFly :public IPState
{
public:
	PlayerFly(IPlayer* player);
	void Init();
	void Update(float deltaTime, sf::RenderWindow& window);
	void Render(sf::RenderWindow* window);
	void Reset();
private:
	IPlayer* m_player;
	Animation1* m_Animation;
};

