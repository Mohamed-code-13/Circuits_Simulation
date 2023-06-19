#pragma once
#include <SFML/Graphics.hpp>

class InputManager
{
public:
	bool IsClicked(sf::Sprite obj, sf::Mouse::Button button, sf::RenderWindow& window);
	sf::Vector2i GetMousePosition(sf::RenderWindow& window);
};

