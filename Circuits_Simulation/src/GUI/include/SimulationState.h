#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "App.h"
#include "ResistorTexture.h"
#include "Wire.h"
#include "../../include/Circuit.h"

class SimulationState : public State
{
private:
	Circuit circuit;
	int numNodes;
	std::vector<Component*> m_components;
	Node* n1;
	Node* n2;

	std::shared_ptr<AppData> m_data;
	sf::Sprite m_background;
	sf::Sprite m_batteryVerticalButton;
	sf::Sprite m_batteryHorizontalButton;
	sf::Sprite m_resistorVerticalButton;
	sf::Sprite m_resistorHorizontalButton;
	sf::Sprite m_Node;
	sf::Sprite m_simulate;
	ComponentTexture* m_compsText;
	std::vector<sf::Text> m_valuesTextures;
	Wire* m_wires;
	sf::Vertex wire[2];
	sf::Sprite* m_mouseTexture;
	bool m_holding;
	bool m_isHorizontal;
	bool m_isResistor;
	bool m_isWire;

public:
	SimulationState(std::shared_ptr<AppData> data);
	~SimulationState();

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};

