#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "App.h"


class MainMenuState : public State
{
private:
	std::shared_ptr<AppData> m_data;
	sf::Sprite m_background;
	sf::Sprite m_startButton;
	sf::Sprite m_endButton;

public:
	MainMenuState(std::shared_ptr<AppData> data);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};
