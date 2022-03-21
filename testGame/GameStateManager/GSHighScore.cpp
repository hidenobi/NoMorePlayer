#include "GSHighScore.h"

GSHighScore::GSHighScore()
{
}

GSHighScore::~GSHighScore()
{
	for (auto it : m_ListBtn) {
		if (it != nullptr) {
			delete it;
		}
	}
	for (auto it : m_ListScore) {
		if (it != nullptr) {
			delete it;
		}
	}
}

void GSHighScore::Exit()
{
}

void GSHighScore::Pause()
{
}

void GSHighScore::Resume()
{
}

void GSHighScore::Init()
{
	printf("HighScore\n");
	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("close");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {
		DATA->getMusic("ost_menu.wav")->stop();
		DATA->playSound("click.wav");
		DATA->getSound("click.wav")->setVolume(20);
		DATA->playMusic("ost_menu.wav");
		GSM->PopState(); });
	m_ListBtn.push_back(button);

	//Tile Game
	m_Title.setString("HIGH SCORE");
	m_Title.setFont(*DATA->getFont("ABC.otf"));
	m_Title.setCharacterSize(100);
	m_Title.setFillColor(sf::Color::Black);
	m_Title.setPosition(screenWidth / 3, screenHeight / 5);
	//ListScore
	for (int i = 0; i < ScoreManager::GetInstance()->getNum(); i++) {
		sf::Text* t = new sf::Text();
		t->setString(std::to_string(ScoreManager::GetInstance()->getHighScore()[i]));
		t->setFont(*DATA->getFont("ABC.otf"));
		t->setCharacterSize(50);
		t->setFillColor(sf::Color::Black);
		t->setPosition(screenWidth / 3, screenHeight / 2 + 30 * i);
		m_ListScore.push_back(t);
	}

	//Playing backround music
	DATA->playMusic("ost_menu.wav");
	DATA->getMusic("ost_menu.wav")->setLoop(true);
	DATA->getMusic("ost_menu.wav")->setVolume(20);
}

void GSHighScore::Update(float deltaTime,  sf::RenderWindow* window)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}

}

void GSHighScore::Render(sf::RenderWindow* window)
{
	//window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	for (auto it : m_ListScore) {
		window->draw(*it);
	}
	window->draw(m_Title);
}
