#include "include/App.h"
#include "include/SplashState.h"

App::App(int width, int height, std::string title)
{
	m_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	m_data->machine.changeState(std::make_unique<SplashState>(m_data));

	m_data->window.setFramerateLimit(60);
}

void App::Run()
{

	float newTime, frameTime, interpolation;
	float currTime = this->m_clock.getElapsedTime().asSeconds();

	float accumelator = 0.0f;
	while (this->m_data->window.isOpen())
	{
		this->m_data->machine.ProcessStateChanges();

		newTime = this->m_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currTime;
		if (frameTime > 0.25f)
			frameTime = 0.25f;

		currTime = newTime;
		accumelator += frameTime;

		while (accumelator >= dt)
		{
			this->m_data->machine.GetState()->HandleInput();
			this->m_data->machine.GetState()->Update(dt);
			accumelator -= dt;
		}

		interpolation = accumelator / dt;
		this->m_data->machine.GetState()->Draw(interpolation);
	}
}