#pragma once
#include <vector>
#include "Component.h"

class Component;

class Node
{
private:
	int id;
	int volt;
	std::vector<Component*> connectedComponents;

public:
	Node(int id);

	int getId() const;

	void addComponent(Component* component);

	const std::vector<Component*>& getComponent() const;

	int getVolt() const;
	void setVolt(int volt);
};

