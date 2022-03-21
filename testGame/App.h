#pragma once
#include "GameStateManager/GameStateMachine.h"
#include "GameManager/ResourceManager.h"

class App {
public:
	void Run();
	~App();
private:
	void Init();
	void Update(float deltaTime);
	void Render();
private:
	sf::RenderWindow* m_window;
	sf::Sprite m_background;
};