#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "App.h"

class Wire
{
private:
	std::shared_ptr<AppData> m_data;
	std::vector<sf::Vertex*> wiresSprites;

public:
	Wire(std::shared_ptr<AppData> m_data);
	~Wire();

	void DrawWires();
	void AddWires(sf::Vertex* wire);
};

