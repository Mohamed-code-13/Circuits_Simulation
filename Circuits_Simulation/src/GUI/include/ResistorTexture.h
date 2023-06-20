#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "App.h"

class ResistorTexture
{
private:
	std::shared_ptr<AppData> m_data;
	std::vector<sf::Sprite> resistorsSprites;

public:
	ResistorTexture(std::shared_ptr<AppData> m_data);
	void DrawResistors();
	void AddResistor(sf::Sprite resistor);
};

