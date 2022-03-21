#include "GSSetCharacter.h"

GSSetCharacter::GSSetCharacter()
{
}

GSSetCharacter::~GSSetCharacter()
{
}

void GSSetCharacter::Exit()
{
}

void GSSetCharacter::Pause()
{
}

void GSSetCharacter::Resume()
{
}

void GSSetCharacter::Init()
{
	printf("SetCharacter\n");
	// set character 1
	sf::Texture* text1 = DATA->getTexture("character_1.png");
	m1_Character.setTexture(*text1);
	m1_Character.setPosition(screenWidth / 2 - screenWidth / 3, screenHeight / 3);

	// about character 1
	m1_about.setString("Nhan vat: Phan Thach\nDac diem: Idol D20\nChua te hoc bong\nKe huy diet PTIT");
	m1_about.setFont(*DATA->getFont("ABC.otf"));
	m1_about.setPosition(screenWidth / 2 - screenWidth / 3, screenHeight / 3 + 175);
	m1_about.setFillColor(sf::Color::Black);
	m1_about.setCharacterSize(35);
	// set character 2
	sf::Texture* text2 = DATA->getTexture("character_2.png");
	m2_Character.setTexture(*text2);
	m2_Character.setPosition(screenWidth / 2 + screenWidth / 5, screenHeight / 3);

	// about character 2
	m2_about.setString("Nhan vat: Vo Tuan\nDac diem: Sinh Vien D20\nChua te qua mon\nKe huy diet diem F");
	m2_about.setFont(*DATA->getFont("ABC.otf"));
	m2_about.setPosition(screenWidth / 2 + screenWidth / 5, screenHeight / 3 + 175);
	m2_about.setFillColor(sf::Color::Black);
	m2_about.setCharacterSize(35);

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

	//choose character 1
	button = new GameButton();
	button->Init("tick_1");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 - screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->playSound("click.wav");
		DATA->getSound("click.wav")->setVolume(20);
		DATA->setAllowCharacter(true); });
	m_ListBtn.push_back(button);

	//choose character 2
	button = new GameButton();
	button->Init("tick_2");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(100, 100));
	button->setPosition(screenWidth / 2 + screenWidth / 4, screenHeight - screenHeight / 8);
	button->setOnClick([]() {
		DATA->playSound("click.wav");
		DATA->getSound("click.wav")->setVolume(20);
		DATA->setAllowCharacter(false); });
	m_ListBtn.push_back(button);

	//Tile Game
	m_Title.setString("Choose character");
	m_Title.setFont(*DATA->getFont("ABC.otf"));
	m_Title.setCharacterSize(100);
	m_Title.setPosition(screenWidth / 3 - screenWidth / 9, screenHeight / 8);
	m_Title.setFillColor(sf::Color::Black);

	//Playing backround music
	DATA->playMusic("ost_menu.wav");
	DATA->getMusic("ost_menu.wav")->setLoop(true);
	DATA->getMusic("ost_menu.wav")->setVolume(20);
}

void GSSetCharacter::Update(float deltaTime, sf::RenderWindow* window)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSSetCharacter::Render(sf::RenderWindow* window)
{
	window->draw(m_Title);
	window->draw(m1_about);
	window->draw(m2_about);
	window->draw(m1_Character);
	window->draw(m2_Character);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}
