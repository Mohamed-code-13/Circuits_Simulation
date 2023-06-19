#pragma once
#include <iostream>
#include "../circuit_modules/include/Resistor.h"
#include "../circuit_modules/include/VoltageSource.h"

class Circuit
{
private:
	std::vector<Node*> nodes;
	std::vector<Component*> components;

public:
	~Circuit();

	Node* addNode(int id);
	Resistor* addResistor(double resistance, Node* term1, Node* term2);
	VoltageSource* addVoltageSource(double volt, Node* term1, Node* term2);

	void simulateCircuit();

	void printResult();
};

