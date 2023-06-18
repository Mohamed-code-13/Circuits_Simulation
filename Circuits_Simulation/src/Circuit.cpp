#include "include/Circuit.h"

Circuit::~Circuit()
{
	for (int i = 0; i < nodes.size(); ++i)
		delete nodes[i];

	for (int i = 0; i < components.size(); ++i)
		delete components[i];
}

Node* Circuit::addNode(int id)
{
	Node* node = new Node(id);
	nodes.push_back(node);
	return node;
}

Resistor* Circuit::addResistor(double resistance, Node* term1, Node* term2)
{
	Resistor* res = new Resistor(resistance, term1, term2);
	components.push_back(res);
	return res;
}

VoltageSource* Circuit::addVoltageSource(double volt, Node* term1, Node* term2)
{
	VoltageSource* source = new VoltageSource(volt, term1, term2);
	components.push_back(source);
	return source;
}

void Circuit::simulateCircuit()
{
	int numNodes = nodes.size();

	Vector2D mat(numNodes, numNodes);
	std::vector<double> b(numNodes);

	for (Component* comp : components)
		comp->fillMNA(mat, b);

	mat.solveEquations(b);
	//std::vector<double> x = mat.solveLinearEquations(mat.matrix, b);

	for (int i = 0; i < numNodes; ++i)
		nodes[i]->setVolt(b[i]);
}