#pragma once
#include "GameStateBase.h"
class GSHighScore : public GameStateBase {
public:
	GSHighScore();
	virtual ~GSHighScore();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime, sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_Background;
	std::list<GameButton*> m_ListBtn;
	std::list<sf::Text*> m_ListScore;
	sf::Text m_Title;

};