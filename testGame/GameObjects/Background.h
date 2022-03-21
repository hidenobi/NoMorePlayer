#pragma once
#include"../GameManager/ResourceManager.h"
#include<string>
class Background
{
public:
	Background(){};
	void Init(std:: string name);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_Image;
	sf::Vector2i m_Size;
};

