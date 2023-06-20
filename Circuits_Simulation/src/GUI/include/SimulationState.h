#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "App.h"
#include "ResistorTexture.h"

class SimulationState : public State
{
private:
	std::shared_ptr<AppData> m_data;
	sf::Sprite m_background;
	sf::Sprite m_batteryVerticalButton;
	sf::Sprite m_batteryHorizontalButton;
	sf::Sprite m_resistorVerticalButton;
	sf::Sprite m_resistorHorizontalButton;
	ResistorTexture* resistors;
	sf::Sprite* m_mouseTexture;
	bool m_holding;

public:
	SimulationState(std::shared_ptr<AppData> data);
	~SimulationState();

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};

