#pragma once
#include "GameStateBase.h"
class GSAbout : public GameStateBase {
public:
	GSAbout();
	virtual ~GSAbout();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime, sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void addStory(std::string s1, std::string s2);
private:
	std::list<GameButton*> m_ListBtn;
	float m_currentTime=0;
	std::vector<sf::Sprite> stories;
	std::vector<sf::Text> texts;
	sf::Sprite m_currentSprite;
	sf::Text m_currentText;
	int count = 0;
	int timeClick = 0;
};