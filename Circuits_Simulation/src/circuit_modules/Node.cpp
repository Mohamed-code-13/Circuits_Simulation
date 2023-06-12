#include "include/Node.h"

Node::Node(int id)
	: id(id)
{
	this->volt = 0;
}

int Node::getId() const
{
	return id;
}

void Node::addComponent(Component* component)
{
	connectedComponents.push_back(component);
}

const std::vector<Component*>& Node::getComponent() const
{
	return connectedComponents;
}

int Node::getVolt() const
{
	return volt;
}

void Node::setVolt(int volt)
{
	this->volt = volt;
}
