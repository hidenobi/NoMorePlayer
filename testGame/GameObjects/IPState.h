#pragma once
#include "../GameManager/ResourceManager.h"

class IPState {
public:
	enum STATE
	{
		FLY,
		DEATH,
		SNULL,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime, sf::RenderWindow& window) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;
};