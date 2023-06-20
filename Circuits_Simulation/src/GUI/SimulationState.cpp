#include "include/SimulationState.h"
#include <iostream>

SimulationState::SimulationState(std::shared_ptr<AppData> data)
	: m_data(data)
{
	numNodes = 0;
	m_holding = false;
	m_isWire = false;
	m_isHorizontal = false;
	m_isResistor = false;
	m_mouseTexture = nullptr;
	m_wires = nullptr;
	m_compsText = nullptr;
}

SimulationState::~SimulationState()
{
	delete m_compsText;
	delete m_mouseTexture;
}

void SimulationState::Init()
{
	this->m_data->assets.LoadFont(FONT_FILEPATH);

	this->m_data->assets.LoadTexture("Simulation BackGround", SIMULATION_BACKGROUND_FILEPATH);
	this->m_data->assets.LoadTexture("Battery Vertical Button", BATTERY_VERTICAL_BUTTON_FILEPATH);
	this->m_data->assets.LoadTexture("Battery Horizontal Button", BATTERY_HORIZONTAL_BUTTON_FILEPATH);
	this->m_data->assets.LoadTexture("Battery Vertical", BATTERY_VERTICAL_FILEPATH);
	this->m_data->assets.LoadTexture("Battery Horizontal", BATTERY_HORIZONTAL_FILEPATH);
	this->m_data->assets.LoadTexture("Resistor Vertical Button", RESISTOR_VERTICAL_BUTTON_FILEPATH);
	this->m_data->assets.LoadTexture("Resistor Horizontal Button", RESISTOR_HORIZONTAL_BUTTON_FILEPATH);
	this->m_data->assets.LoadTexture("Resistor Vertical", RESISTOR_VERTICAL_FILEPATH);
	this->m_data->assets.LoadTexture("Resistor Horizontal", RESISTOR_HORIZONTAL_FILEPATH);
	this->m_data->assets.LoadTexture("Node", NODE_FILEPATH);
	this->m_data->assets.LoadTexture("Simulate", SIMULATE_BUTTON_FILEPATH);

	m_background.setTexture(this->m_data->assets.GetTexture("Simulation BackGround"));
	m_batteryVerticalButton.setTexture(this->m_data->assets.GetTexture("Battery Vertical Button"));
	m_batteryHorizontalButton.setTexture(this->m_data->assets.GetTexture("Battery Horizontal Button"));
	m_resistorVerticalButton.setTexture(this->m_data->assets.GetTexture("Resistor Vertical Button"));
	m_resistorHorizontalButton.setTexture(this->m_data->assets.GetTexture("Resistor Horizontal Button"));
	m_simulate.setTexture(this->m_data->assets.GetTexture("Simulate"));

	m_batteryVerticalButton.setPosition(20, 100);
	m_batteryHorizontalButton.setPosition(140, 100);
	m_resistorVerticalButton.setPosition(20, 400);
	m_resistorHorizontalButton.setPosition(20, 270);
	m_simulate.setPosition(20, 650);

	m_compsText = new ComponentTexture(m_data);
	m_wires = new Wire(m_data);
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
			m_isResistor = true;
			m_isHorizontal = true;

			delete m_mouseTexture;

			m_mouseTexture = new sf::Sprite();
			m_mouseTexture->setTexture(m_data->assets.GetTexture("Resistor Horizontal"));
		}
		else if (this->m_data->input.IsClicked(m_resistorVerticalButton, sf::Mouse::Left, this->m_data->window))
		{
			m_holding = true;
			m_isResistor = true;
			m_isHorizontal = false;

			delete m_mouseTexture;

			m_mouseTexture = new sf::Sprite();
			m_mouseTexture->setTexture(m_data->assets.GetTexture("Resistor Vertical"));
		}
		else if (this->m_data->input.IsClicked(m_batteryHorizontalButton, sf::Mouse::Left, this->m_data->window))
		{
			m_holding = true;
			m_isResistor = false;
			m_isHorizontal = true;

			delete m_mouseTexture;

			m_mouseTexture = new sf::Sprite();
			m_mouseTexture->setTexture(m_data->assets.GetTexture("Battery Horizontal"));
		}
		else if (this->m_data->input.IsClicked(m_batteryVerticalButton, sf::Mouse::Left, this->m_data->window))
		{
			m_holding = true;
			m_isResistor = false;
			m_isHorizontal = false;

			delete m_mouseTexture;

			m_mouseTexture = new sf::Sprite();
			m_mouseTexture->setTexture(m_data->assets.GetTexture("Battery Vertical"));
		}
		else if (this->m_data->input.IsClicked(m_simulate, sf::Mouse::Left, this->m_data->window))
		{
			circuit.simulateCircuit();
			circuit.printResult();
		}
		else if (m_holding && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			m_holding = false;

			sf::Text valueText;
			valueText.setFont(m_data->assets.GetFont());
			valueText.setCharacterSize(22);
			valueText.setFillColor(sf::Color::Black);
			// valueText.setOrigin(valueText.getGlobalBounds().width / 2, valueText.getGlobalBounds().height/ 2);

			sf::Sprite node1, node2;
			node1.setTexture(m_data->assets.GetTexture("Node"));
			node2.setTexture(m_data->assets.GetTexture("Node"));

			float x = m_mouseTexture->getPosition().x;
			float y = m_mouseTexture->getPosition().y;
			float w = m_mouseTexture->getGlobalBounds().width;
			float h = m_mouseTexture->getGlobalBounds().height;
			if (m_isHorizontal)
			{
				node1.setPosition(x + w, y + h / 2 - node1.getGlobalBounds().height / 2);
				node2.setPosition(x, y + h / 2 - node1.getGlobalBounds().height / 2);

				valueText.setPosition(x + w / 2, y - h / 2);
			}
			else
			{
				node1.setPosition(x + w / 2 - node1.getGlobalBounds().width / 2, y);
				node2.setPosition(x + w / 2 - node1.getGlobalBounds().width / 2, y + h);

				valueText.setPosition(x + w + valueText.getGlobalBounds().width, y + h / 2);
			}
			
			if (m_isResistor)
			{
				double value;
				std::cout << "Enter the Resistance in ohm: ";
				std::cin >> value;
				
				Node* node1 = circuit.addNode(numNodes++);
				Node* node2 = circuit.addNode(numNodes++);
				Resistor* resistor = circuit.addResistor(value, node1, node2);
				m_components.push_back(resistor);

				valueText.setString(std::to_string(value / 1000.0).substr(0, 4) + " k");
			}
			else
			{
				double value;
				std::cout << "Enter the Voltage in volt: ";
				std::cin >> value;

				Node* node1 = circuit.addNode(numNodes++);
				Node* node2 = circuit.addNode(numNodes++);
				VoltageSource* source = circuit.addVoltageSource(value, node1, node2);
				m_components.push_back(source);

				valueText.setString(std::to_string(value).substr(0, 4) + " V");
			}

			m_valuesTextures.push_back(valueText);
			m_compsText->AddComponent({ *m_mouseTexture, node1, node2 });
		}
		else if (!m_holding && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			std::vector<std::vector<sf::Sprite>> comps = m_compsText->GetResistors();
			for (int i = 0; i < comps.size(); ++i)
			{
				for (int j = 1; j < comps[i].size(); ++j)
				{
					if (m_data->input.IsClicked(comps[i][j], sf::Mouse::Left, m_data->window))
					{
						float x = m_data->input.GetMousePosition(m_data->window).x;
						float y = m_data->input.GetMousePosition(m_data->window).y;

						if (m_isWire)
						{
							wire[1] = sf::Vertex(sf::Vector2f(x, y), sf::Color::Black);
							m_isWire = false;
							m_wires->AddWires(wire);

							if (j == 1)
								n2 = m_components[i]->getTerminal1();
							else
								n2 = m_components[i]->getTerminal2();

							Node* temp;
							if (n1->getId() < n2->getId())
								temp = n1;
							else
								temp = n2;

							for (Component* comp : m_components)
							{
								if (comp->getTerminal1() == n1 || comp->getTerminal1() == n2)
									comp->setTerminal1(temp);

								if (comp->getTerminal2() == n1 || comp->getTerminal2() == n2)
									comp->setTerminal2(temp);
							}
						}
						else
						{
							wire[0] = sf::Vertex(sf::Vector2f(x, y), sf::Color::Black);
							m_isWire = true;

							if (j == 1)
								n1 = m_components[i]->getTerminal1();
							else
								n1 = m_components[i]->getTerminal2();
						}
						break;
					}
				}
			}
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
	this->m_data->window.draw(m_simulate);

	if (this->m_compsText)
		this->m_compsText->DrawResistors();
	if (this->m_wires)
		this->m_wires->DrawWires();

	if (m_holding)
		this->m_data->window.draw(*m_mouseTexture);

	for (sf::Text& t : m_valuesTextures)
		this->m_data->window.draw(t);

	this->m_data->window.display();
}