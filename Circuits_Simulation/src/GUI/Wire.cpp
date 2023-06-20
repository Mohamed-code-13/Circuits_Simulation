#include "include/Wire.h"

Wire::Wire(std::shared_ptr<AppData> data)
	: m_data(data)
{
}

Wire::~Wire()
{
	for (int i = 0; i < wiresSprites.size(); ++i)
		delete[] wiresSprites[i];
}


void Wire::DrawWires()
{
	for (int i = 0; i < wiresSprites.size(); ++i)
		m_data->window.draw(wiresSprites[i], 2, sf::Lines);
}

void Wire::AddWires(sf::Vertex* wire)
{
	sf::Vertex* line = new sf::Vertex[2];
	line[0] = sf::Vertex(sf::Vector2f(wire[0].position.x, wire[0].position.y), sf::Color::Black);
	line[1] = sf::Vertex(sf::Vector2f(wire[1].position.x, wire[1].position.y), sf::Color::Black);
	wiresSprites.push_back(line);
}