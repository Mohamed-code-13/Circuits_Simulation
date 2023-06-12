#include "include/Circuit.h"

void Circuit::addNode(Node* node)
{
	if (!hasNode(node))
		nodes.push_back(node);
}

void Circuit::addComponent(Component* component)
{
	Node* term1 = component->getTerminal1();
	Node* term2 = component->getTerminal2();

	this->components.push_back(component);

	if (!hasNode(term1))
		nodes.push_back(term1);

	if (!hasNode(term2))
		nodes.push_back(term2);
}

bool Circuit::hasNode(Node* node)
{
	for (Node* n : nodes)
		if (node->getId() == n->getId())
			return true;
	return false;
}