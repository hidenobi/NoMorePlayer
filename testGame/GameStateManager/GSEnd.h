#pragma once
#include "GameStateBase.h"
class GSEnd : public GameStateBase {
public:
	GSEnd();
	virtual ~GSEnd();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime, sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_Background;
	std::list<GameButton*> m_ListBtn;
	sf::Text m_Title;
	sf::Text m_currentScore;
	sf::Text m_bestScore;
};