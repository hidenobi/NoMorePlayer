#include "GSAbout.h"

GSAbout::GSAbout()
{
}

GSAbout::~GSAbout()
{
}

void GSAbout::Exit()
{
}

void GSAbout::Pause()
{
}

void GSAbout::Resume()
{
}

void GSAbout::Init()
{
	printf("About\n");
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
		GSM->PopState();
		DATA->playMusic("ost_menu.wav");
	});
	m_ListBtn.push_back(button);

	//setStories
	addStory("huy", "Chao mung ban den voi truong PTIT");
	addStory("thach", "Minh la Thach,\nMinh la tan sinh vien PTIT");
	addStory("tuan", "Oh, minh cung là tan sinh vien ne, minh là Tuan");
	addStory("huy", "Chuc mung 2 ban da dau truong PTIT,\nHom nay minh se giai dap cac thac mac \nVe cac van de cho ban");
	addStory("thach", "Minh nghe noi truong minh rat de nhan \nhoc bong. Co phai nhu the khong ban?");
	addStory("tuan", "Oh, minh cung nghe bao the!");
	addStory("huy", "Um dung roi, rat de\nNhung la de truot mon!!!");
	addStory("huy", "Nhung chi can cac ban co gang \nThi se co co hoi nhan hoc bong day");
	addStory("thach", "Vay minh phai co gang hoc tap\nDe nhan hoc bong thoi\nChao 2 bro nhe");
	addStory("tuan", "Uay hoc phai chac kho lay roi\nCo gang qua mon thoi\nChao 2 cau, minh di");
	addStory("huy", "Cac tam chieu moi da vao truong roi\nCac ban hay giup do Thach va Tuan\ntranh nhung con diem F de dat duoc muc tieu nhe");
}

void GSAbout::Update(float deltaTime, sf::RenderWindow* window)
{	
	
	m_currentTime += deltaTime;
	if (m_currentTime >= 2.f||sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			timeClick++;
			m_currentTime = 0;
			DATA->playSound("click.wav");
		}
		if (m_currentTime >= 2.f || timeClick > 3) {
			DATA->playSound("click.wav");
			if(count < stories.size() - 1) count++;
			m_currentTime = 0;
			timeClick = 0;
		}
		
	}
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
	if (count < stories.size() - 1) {
		m_currentSprite = stories[count];
		m_currentText = texts[count];
	}
	else {
		m_currentSprite = stories[count];
		m_currentText = texts[count];
		DATA->getSound("clock.wav")->stop();
	}
}

void GSAbout::Render(sf::RenderWindow* window)
{
	window->draw(m_currentSprite);
	window->draw(m_currentText);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	
	
}

void GSAbout::addStory(std::string s1, std::string s2)
{
	sf::Sprite m_Background;
	sf::Texture* texture = DATA->getTexture(s1+".png");
	m_Background.setTexture(*texture);
	m_Background.setPosition(screenWidth / 2, screenHeight / 2);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	stories.push_back(m_Background);
	sf::Text m_text;
	m_text.setString(s2);
	m_text.setPosition(screenWidth / 12, 3 * screenHeight / 4 + 30);
	m_text.setFont(*DATA->getFont("XYZ.ttf"));
	m_text.setCharacterSize(35);
	m_text.setFillColor(sf::Color::Black);
	texts.push_back(m_text);
}
