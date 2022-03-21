#include "Layer.h"

void Layer::Init(std::string name, float speed)
{
	sf::Texture* texture = DATA->getTexture(name);
	m_Image1.setTexture(*texture);
	m_Image2.setTexture(*texture);

	m_Speed = speed;

	m_SizeImage = (sf::Vector2i)texture->getSize();
	m_Image1.setPosition(sf::Vector2f(screenWidth / 2, screenHeight - m_SizeImage.y / 2));
	m_Image2.setPosition(m_SizeImage.x * 1.5f, m_Image1.getPosition().y);

	m_Image1.setOrigin((sf::Vector2f)m_SizeImage * 0.5f);
	m_Image2.setOrigin((sf::Vector2f)m_SizeImage * 0.5f);
}

void Layer::Update(float deltaTime)
{
	m_Image1.move(-m_Speed * deltaTime, 0);
	m_Image2.move(-m_Speed * deltaTime, 0);

	if (m_Image2.getPosition().x <= (float)screenWidth / 2) {
		m_Image1.setPosition(sf::Vector2f(screenWidth / 2, screenHeight - m_SizeImage.y / 2));
		m_Image2.setPosition(m_SizeImage.x * 1.5f, m_Image1.getPosition().y);
	}

}

void Layer::Render(sf::RenderWindow* window)
{
	window->draw(m_Image1);
	window->draw(m_Image2);
}

void Layer::setPosition(sf::Vector2i pos)
{
	m_Image1.setPosition((sf::Vector2f)pos);
	m_Image2.setPosition(pos.x + m_SizeImage.x, pos.y);
}
