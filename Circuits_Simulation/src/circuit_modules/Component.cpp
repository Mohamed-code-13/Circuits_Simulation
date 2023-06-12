#include "include/Component.h"

Component::Component(double val, Node* term1, Node* term2)
	: value(val), terminal1(term1), terminal2(term2)
{
}

double Component::getValue() const
{
	return value;
}

Node* Component::getTerminal1() const
{
	return terminal1;
}

Node* Component::getTerminal2() const
{
	return terminal2;
}

void Component::setTerminal1(Node* term)
{
	this->terminal1 = term;
}

void Component::setTerminal2(Node* term)
{
	this->terminal2 = term;
}