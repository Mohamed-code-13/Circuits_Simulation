#include "include/MainMenuState.h"
#include "include/SimulationState.h"

MainMenuState::MainMenuState(std::shared_ptr<AppData> data)
	: m_data(data)
{
}

void MainMenuState::Init()
{
	this->m_data->assets.LoadTexture("Main Menu BackGround", MAIN_MENU_FILEPATH);
	this->m_data->assets.LoadTexture("Start Button", START_BUTTON_FILEPATH);
	this->m_data->assets.LoadTexture("End Button", END_BUTTON_FILEPATH);

	m_background.setTexture(this->m_data->assets.GetTexture("Main Menu BackGround"));
	m_startButton.setTexture(this->m_data->assets.GetTexture("Start Button"));
	m_endButton.setTexture(this->m_data->assets.GetTexture("End Button"));

	m_startButton.setPosition((SCREEN_WIDTH / 2) - (m_startButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (m_startButton.getGlobalBounds().height / 2));
	m_endButton.setPosition((SCREEN_WIDTH / 2) - (m_endButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (m_endButton.getGlobalBounds().height / 2) + 200);
}

void MainMenuState::HandleInput()
{
	sf::Event e;

	while (this->m_data->window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			this->m_data->window.close();
		
		if (this->m_data->input.IsClicked(m_endButton, sf::Mouse::Left, this->m_data->window))
			this->m_data->window.close();
		else if (this->m_data->input.IsClicked(m_startButton, sf::Mouse::Left, this->m_data->window))
		{
			m_data->machine.changeState(std::make_unique<SimulationState>(m_data));
			break;
		}
	}
}

void MainMenuState::Update(float dt)
{
}

void MainMenuState::Draw(float dt)
{
	this->m_data->window.clear();
	this->m_data->window.draw(m_background);
	this->m_data->window.draw(m_startButton);
	this->m_data->window.draw(m_endButton);
	this->m_data->window.display();
}