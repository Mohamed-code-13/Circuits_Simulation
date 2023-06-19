#include "include/SimulationState.h"

SimulationState::SimulationState(std::shared_ptr<AppData> data)
	: m_data(data)
{
}

void SimulationState::Init()
{
	this->m_data->assets.LoadTexture("Simulation BackGround", SIMULATION_BACKGROUND_FILEPATH);

	m_background.setTexture(this->m_data->assets.GetTexture("Simulation BackGround"));
}

void SimulationState::HandleInput()
{
	sf::Event e;

	while (this->m_data->window.pollEvent(e))
		if (e.type == sf::Event::Closed)
			this->m_data->window.close();
}

void SimulationState::Update(float dt)
{
}

void SimulationState::Draw(float dt)
{
	this->m_data->window.clear();
	this->m_data->window.draw(m_background);
	this->m_data->window.display();
}