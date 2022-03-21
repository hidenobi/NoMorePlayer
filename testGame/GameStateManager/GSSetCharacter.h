#pragma once
#include "GameStateBase.h"
class GSSetCharacter : public GameStateBase {
public:
	GSSetCharacter();
	virtual ~GSSetCharacter();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime, sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m1_Character,m2_Character;
	sf::Text m_Title,m1_about,m2_about;
	std::list<GameButton*> m_ListBtn;

};