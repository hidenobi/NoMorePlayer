#include "GSEnd.h"

GSEnd::GSEnd()
{
}

GSEnd::~GSEnd()
{
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
{
	printf("Dead\n");
	GameButton* button;
	//menu Button
	button = new GameButton();
	button->Init("home");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->getMusic("ost_menu.wav")->stop();
		DATA->playSound("click.wav");
		DATA->getSound("click.wav")->setVolume(20);
		DATA->playMusic("ost_menu.wav");
		GSM->PopState();
		GSM->PopState();
		ScoreManager::GetInstance()->UpdateHighScore();
		ScoreManager::GetInstance()->writeFile();
		});
	m_ListBtn.push_back(button);

	//replay Button
	button = new GameButton();
	button->Init("restart");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 12, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->getMusic("ost_menu.wav")->stop();
		DATA->playSound("click.wav");
		DATA->getSound("click.wav")->setVolume(20);
		GSM->PopState();
		GSM->ChangeState(StateTypes::PLAY);
		ScoreManager::GetInstance()->UpdateHighScore();
		ScoreManager::GetInstance()->writeFile();
		});
	m_ListBtn.push_back(button);

	//Tile Game
	m_Title.setString("END GAME!");
	m_Title.setFont(*DATA->getFont("ABC.otf"));
	m_Title.setCharacterSize(100);
	m_Title.setPosition(screenWidth / 3, screenHeight / 5);
	m_Title.setFillColor(sf::Color::Black);

	//Best Score
	m_bestScore.setString("BEST SCORE: " + std::to_string(ScoreManager::GetInstance()->getBestScore()));
	m_bestScore.setFont(*DATA->getFont("ABC.otf"));
	m_bestScore.setCharacterSize(50);
	m_bestScore.setFillColor(sf::Color::Black);
	m_bestScore.setPosition(screenWidth / 3 - 20, screenHeight / 2);

	//current Score
	m_currentScore.setString("YOUR SCORE: " + std::to_string(ScoreManager::GetInstance()->getCurrentScore()));
	m_currentScore.setFont(*DATA->getFont("ABC.otf"));
	m_currentScore.setCharacterSize(50);
	m_currentScore.setFillColor(sf::Color::Black);
	m_currentScore.setPosition(screenWidth / 3 - 20, screenHeight / 2 + 50);

	//Playing backround music
	DATA->playMusic("ost_menu.wav");
	DATA->getMusic("ost_menu.wav")->setLoop(true);
	DATA->getMusic("ost_menu.wav")->setVolume(20);
}

void GSEnd::Update(float deltaTime, sf::RenderWindow* window)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSEnd::Render(sf::RenderWindow* window)
{
	//window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_Title);
	window->draw(m_bestScore);
	window->draw(m_currentScore);
}
