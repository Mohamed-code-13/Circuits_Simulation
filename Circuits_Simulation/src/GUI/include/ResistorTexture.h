#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "App.h"

class ComponentTexture
{
private:
	std::shared_ptr<AppData> m_data;
	std::vector<std::vector<sf::Sprite>> resistorsSprites;

public:
	ComponentTexture(std::shared_ptr<AppData> data);
	void DrawResistors();
	void AddComponent(std::vector<sf::Sprite> resistor);
	std::vector<std::vector<sf::Sprite>>& GetResistors();
};

