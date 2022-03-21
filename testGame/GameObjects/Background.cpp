#include "Background.h"

void Background::Init(std::string name)
{
	sf::Texture* text = DATA->getTexture(name);
	m_Image.setTexture(*text);
	m_Size = (sf::Vector2i)text->getSize();
	m_Image.setPosition(sf::Vector2f(screenWidth / 2, screenHeight - text->getSize().y / 2));
	m_Image.setOrigin((sf::Vector2f)m_Size * 0.5f);
}

void Background::Render(sf::RenderWindow* window)
{
	window->draw(m_Image);
}
