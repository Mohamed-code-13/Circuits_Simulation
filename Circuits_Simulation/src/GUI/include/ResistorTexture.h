#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "App.h"

class ResistorTexture
{
private:
	std::shared_ptr<AppData> m_data;
	std::vector<std::vector<sf::Sprite>> resistorsSprites;

public:
	ResistorTexture(std::shared_ptr<AppData> data);
	void DrawResistors();
	void AddResistor(std::vector<sf::Sprite> resistor);
	std::vector<std::vector<sf::Sprite>>& GetResistors();
};

