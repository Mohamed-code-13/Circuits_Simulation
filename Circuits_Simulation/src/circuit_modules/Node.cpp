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

double Node::getVolt() const
{
	return volt;
}

void Node::setVolt(double volt)
{
	this->volt = volt;
}
