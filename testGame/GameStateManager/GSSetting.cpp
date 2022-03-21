#include "GSSetting.h"

GSSetting::GSSetting()
{
}

GSSetting::~GSSetting()
{
}

void GSSetting::Exit()
{
}

void GSSetting::Pause()
{
}

void GSSetting::Resume()
{
}

void GSSetting::Init()
{
	printf("settings\n");
	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("close");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {
		DATA->playSound("click.wav");
		DATA->getSound("click.wav")->setVolume(20);
		DATA->playMusic("ost_menu.wav");
		GSM->PopState(); });
	m_ListBtn.push_back(button);
	//turn on music
	button = new GameButton();
	button->Init("music_on");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->setAllowSound(true); 
		DATA->playMusic("ost_menu.wav");
	});
	m_ListBtn.push_back(button);

	//turn off music
	button = new GameButton();
	button->Init("music_off");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->setAllowSound(false);
		DATA->getMusic("ost_menu.wav")->stop();
	});
	m_ListBtn.push_back(button);

	//Tile Game
	m_Title.setString("SETTINGS");
	m_Title.setFont(*DATA->getFont("ABC.otf"));
	m_Title.setCharacterSize(100);
	m_Title.setPosition(screenWidth / 3, screenHeight / 5);
	m_Title.setFillColor(sf::Color::Black);

	//Playing backround music
	DATA->playMusic("ost_menu.wav");
	DATA->getMusic("ost_menu.wav")->setLoop(true);
	DATA->getMusic("ost_menu.wav")->setVolume(20);
}

void GSSetting::Update(float deltaTime, sf::RenderWindow* window)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSSetting::Render(sf::RenderWindow* window)
{
	//window->draw(m_Background);
	window->draw(m_Title);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}
