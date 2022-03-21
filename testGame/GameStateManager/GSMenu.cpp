#include "GSMenu.h"

GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	printf("Menu\n");
	//Tile Game
	m_Title.setString("NO MORE PLAYER");
	m_Title.setFont(*DATA->getFont("ABC.otf"));
	m_Title.setCharacterSize(100);
	m_Title.setPosition(screenWidth / 3 - 50, screenHeight / 5);
	m_Title.setFillColor(sf::Color::Black);
	GameButton* button;
	//PlayButton
	button = new GameButton();
	button->Init("play");
	button->setOnClick([]() {
		DATA->playSound("click.wav");
		DATA->getSound("click.wav")->setVolume(20); 
		DATA->getMusic("ost_menu.wav")->stop();
		GSM->ChangeState(StateTypes::PLAY); });
	button->setPosition(screenWidth / 2 - 20, screenHeight / 2 + screenHeight/10);
	button->setSize(sf::Vector2f(100, 100));
	button->setOrigin(button->getSize() / 2.f);
	m_ListBtn.push_back(button);
	//Exit Button
	button = new GameButton();
	button->Init("exit");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 + 2 * screenWidth / 7, screenHeight - screenHeight / 8);
	button->setOnClick([]() {WConnect->getWindow()->close(); });
	m_ListBtn.push_back(button);

	//Setting Button
	button = new GameButton();
	button->Init("settings");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - 2 * screenWidth / 7, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->getMusic("ost_menu.wav")->stop();
		DATA->playSound("click.wav");
		DATA->getSound("click.wav")->setVolume(20);
		GSM->ChangeState(StateTypes::SETTING); });
	m_ListBtn.push_back(button);

	//Choose character
	button = new GameButton();
	button->Init("character");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - screenWidth / 7, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->getMusic("ost_menu.wav")->stop();
		DATA->playSound("click.wav");
		DATA->getSound("click.wav")->setVolume(20);
		GSM->ChangeState(StateTypes::SETCHARACTER); });
	m_ListBtn.push_back(button);

	//about Button
	button = new GameButton();
	button->Init("about");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 + screenWidth / 7, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->getMusic("ost_menu.wav")->stop();
		DATA->playSound("click.wav");
		DATA->getSound("click.wav")->setVolume(20);
		GSM->ChangeState(StateTypes::ABOUT); });
	m_ListBtn.push_back(button);

	//HighScore Button
	button = new GameButton();
	button->Init("prize");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 , screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->getMusic("ost_menu.wav")->stop();
		DATA->playSound("click.wav");
		DATA->getSound("click.wav")->setVolume(20);
		GSM->ChangeState(StateTypes::HIGHSCORE); });
	m_ListBtn.push_back(button);

	//Playing backround music
	DATA->playMusic("ost_menu.wav");
	DATA->getMusic("ost_menu.wav")->setLoop(true);
	DATA->getMusic("ost_menu.wav")->setVolume(20);
	

}

void GSMenu::Update(float deltaTime, sf::RenderWindow* window)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->draw(m_Title);
	//window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}
