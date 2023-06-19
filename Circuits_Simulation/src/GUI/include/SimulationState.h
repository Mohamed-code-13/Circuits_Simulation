#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "App.h"

class SimulationState : public State
{
private:
	std::shared_ptr<AppData> m_data;
	sf::Sprite m_background;

public:
	SimulationState(std::shared_ptr<AppData> data);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};

