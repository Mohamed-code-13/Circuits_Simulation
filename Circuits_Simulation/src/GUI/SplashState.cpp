#include "include/SplashState.h"
#include "include/MainMenuState.h"

SplashState::SplashState(std::shared_ptr<AppData> data)
	: m_data(data)
{
}

void SplashState::Init()
{
	this->m_data->assets.LoadTexture("Splash BackGround", SPLASH_BACKGROUND_FILEPATH);

	m_background.setTexture(this->m_data->assets.GetTexture("Splash BackGround"));
}

void SplashState::HandleInput()
{
	sf::Event e;

	while (this->m_data->window.pollEvent(e))
		if (e.type == sf::Event::Closed)
			this->m_data->window.close();
}

void SplashState::Update(float dt)
{
	if (this->m_clock.getElapsedTime().asSeconds() > SPLASH_SCREEN_TIME)
	{
		this->m_data->machine.changeState(std::make_unique<MainMenuState>(this->m_data));
	}
}

void SplashState::Draw(float dt)
{
	this->m_data->window.clear();
	this->m_data->window.draw(m_background);
	this->m_data->window.display();
}