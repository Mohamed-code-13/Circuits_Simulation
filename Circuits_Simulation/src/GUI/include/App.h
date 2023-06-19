#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "DEFINITION.h"

struct AppData
{
	sf::RenderWindow window;
	AssetManager assets;
	InputManager input;
	StateMachine machine;
};

class App
{
public:
	App(int width, int height, std::string title);
	void Run();

private:
	const float dt = 1.0f / 60.0f;
	sf::Clock m_clock;

	std::shared_ptr<AppData> m_data = std::make_shared<AppData>();
};

