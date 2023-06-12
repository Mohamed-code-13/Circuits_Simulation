#include <iostream>

#include "include/Circuit.h"

int main()
{
	Circuit circuit;

	Node* node1 = new Node(1);
	Node* node2 = new Node(2);

	VoltageSource* voltageSource = new VoltageSource(5.0, node1, node2);
	Resistor* resistor = new Resistor(1000.0, node1, node2);

	circuit.addComponent(voltageSource);
	circuit.addComponent(resistor);

	circuit.addNode(node1);
	circuit.addNode(node2);

	return 0;
}