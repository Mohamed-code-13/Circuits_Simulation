#include "include/SimulationState.h"
#include <iostream>

SimulationState::SimulationState(std::shared_ptr<AppData> data)
	: m_data(data)
{
	m_holding = false;
}

SimulationState::~SimulationState()
{
	delete resistors;
	delete m_mouseTexture;
}

void SimulationState::Init()
{
	this->m_data->assets.LoadTexture("Simulation BackGround", SIMULATION_BACKGROUND_FILEPATH);
	this->m_data->assets.LoadTexture("Battery Vertical Button", BATTERY_VERTICAL_BUTTON_FILEPATH);
	this->m_data->assets.LoadTexture("Battery Horizontal Button", BATTERY_HORIZONTAL_BUTTON_FILEPATH);
	this->m_data->assets.LoadTexture("Battery Vertical", BATTERY_VERTICAL_FILEPATH);
	this->m_data->assets.LoadTexture("Battery Horizontal", BATTERY_HORIZONTAL_FILEPATH);
	this->m_data->assets.LoadTexture("Resistor Vertical Button", RESISTOR_VERTICAL_BUTTON_FILEPATH);
	this->m_data->assets.LoadTexture("Resistor Horizontal Button", RESISTOR_HORIZONTAL_BUTTON_FILEPATH);
	this->m_data->assets.LoadTexture("Resistor Vertical", RESISTOR_VERTICAL_FILEPATH);
	this->m_data->assets.LoadTexture("Resistor Horizontal", RESISTOR_HORIZONTAL_FILEPATH);

	m_background.setTexture(this->m_data->assets.GetTexture("Simulation BackGround"));
	m_batteryVerticalButton.setTexture(this->m_data->assets.GetTexture("Battery Vertical Button"));
	m_batteryHorizontalButton.setTexture(this->m_data->assets.GetTexture("Battery Horizontal Button"));
	m_resistorVerticalButton.setTexture(this->m_data->assets.GetTexture("Resistor Vertical Button"));
	m_resistorHorizontalButton.setTexture(this->m_data->assets.GetTexture("Resistor Horizontal Button"));

	m_batteryVerticalButton.setPosition(20, 100);
	m_batteryHorizontalButton.setPosition(140, 100);
	m_resistorVerticalButton.setPosition(20, 580);
	m_resistorHorizontalButton.setPosition(20, 450);

	resistors = new ResistorTexture(m_data);
	m_holding = false;
}

void SimulationState::HandleInput()
{
	sf::Event e;

	while (this->m_data->window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			this->m_data->window.close();

		if (this->m_data->input.IsClicked(m_resistorHorizontalButton, sf::Mouse::Left, this->m_data->window))
		{
			m_holding = true;

			delete m_mouseTexture;

			m_mouseTexture = new sf::Sprite();
			m_mouseTexture->setTexture(m_data->assets.GetTexture("Resistor Horizontal"));
		}
		else if (this->m_data->input.IsClicked(m_resistorVerticalButton, sf::Mouse::Left, this->m_data->window))
		{
			m_holding = true;

			delete m_mouseTexture;

			m_mouseTexture = new sf::Sprite();
			m_mouseTexture->setTexture(m_data->assets.GetTexture("Resistor Vertical"));
		}
		else if (this->m_data->input.IsClicked(m_batteryHorizontalButton, sf::Mouse::Left, this->m_data->window))
		{
			m_holding = true;

			delete m_mouseTexture;

			m_mouseTexture = new sf::Sprite();
			m_mouseTexture->setTexture(m_data->assets.GetTexture("Battery Horizontal"));
		}
		else if (this->m_data->input.IsClicked(m_batteryVerticalButton, sf::Mouse::Left, this->m_data->window))
		{
			m_holding = true;

			delete m_mouseTexture;

			m_mouseTexture = new sf::Sprite();
			m_mouseTexture->setTexture(m_data->assets.GetTexture("Battery Vertical"));
		}
		else if (m_holding && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			m_holding = false;
			resistors->AddResistor(*m_mouseTexture);
		}
	}
}

void SimulationState::Update(float dt)
{
	if (m_holding)
	{
		float x = m_data->input.GetMousePosition(m_data->window).x;
		float y = m_data->input.GetMousePosition(m_data->window).y;
		
		m_mouseTexture->setPosition(x, y);
	}
}

void SimulationState::Draw(float dt)
{
	this->m_data->window.clear();
	
	this->m_data->window.draw(m_background);
	this->m_data->window.draw(m_batteryVerticalButton);
	this->m_data->window.draw(m_batteryHorizontalButton);
	this->m_data->window.draw(m_resistorVerticalButton);
	this->m_data->window.draw(m_resistorHorizontalButton);

	if (this->resistors)
		this->resistors->DrawResistors();

	if (m_holding)
		this->m_data->window.draw(*m_mouseTexture);


	this->m_data->window.display();
}