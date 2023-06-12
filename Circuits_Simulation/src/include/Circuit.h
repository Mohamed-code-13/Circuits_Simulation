#pragma once
#include "../circuit_modules/include/Resistor.h"
#include "../circuit_modules/include/VoltageSource.h"

class Circuit
{
private:
	std::vector<Node*> nodes;
	std::vector<Component*> components;

public:
	void addNode(Node* node);
	void addComponent(Component* component);

	bool hasNode(Node* node);
};

