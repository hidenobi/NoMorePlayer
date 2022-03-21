#pragma once
#include "GameStateBase.h"
class GSSetting : public GameStateBase {
public:
	GSSetting();
	virtual ~GSSetting();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime, sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_Background;
	sf::Text m_Title;
	std::list<GameButton*> m_ListBtn;

};