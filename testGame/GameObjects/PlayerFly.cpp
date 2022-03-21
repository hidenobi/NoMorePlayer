#include "PlayerFly.h"

PlayerFly::PlayerFly(IPlayer* player)
{
	m_player = player;
}

void PlayerFly::Init()
{
	
	if(DATA->getAllowCharacter()==true) m_Animation = new Animation1(*DATA->getTexture("image_1.png"),sf::Vector2i(1,1),0.1f);
	else m_Animation = new Animation1(*DATA->getTexture("image_2.png"), sf::Vector2i(1, 1), 0.1f);
	
}

void PlayerFly::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PlayerFly::Reset()
{
	m_Animation->Reset();
}

void PlayerFly::Update(float deltaTime, sf::RenderWindow& window)
{
	m_Animation->Update(deltaTime);
	if (!m_player->getHitBox()->isAlive()|| sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_player->getHitBox()->setAlive(false);
		DATA->getMusic("play_music.wav")->stop();
		DATA->playSound("exploision.wav");
		DATA->getSound("exploision.wav")->setVolume(10);
		m_player->changeNextState(IPState::DEATH);
	}
	if (sf::Mouse::getPosition(window).x < 0) m_player->getHitBox()->setPosition(0, sf::Mouse::getPosition(window).y);
	
	else if (sf::Mouse::getPosition(window).x > screenWidth) m_player->getHitBox()->setPosition(screenWidth, sf::Mouse::getPosition(window).y);
	else if (sf::Mouse::getPosition(window).y < 0) m_player->getHitBox()->setPosition(sf::Mouse::getPosition(window).x, 0);
	else if (sf::Mouse::getPosition(window).y > screenHeight) m_player->getHitBox()->setPosition(sf::Mouse::getPosition(window).x, screenHeight);
	else {
		m_player->getHitBox()->setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	}
	m_Animation->setPosition(m_player->getHitBox()->getPosition());
}
