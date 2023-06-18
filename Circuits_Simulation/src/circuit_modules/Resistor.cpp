#include "include/Resistor.h"

Resistor::Resistor(double val, Node* term1, Node* term2)
	: Component(val, term1, term2)
{
}

double Resistor::getVoltageDrop() const 
{
	return terminal1->getVolt() - terminal2->getVolt();
}

double Resistor::getCurrent() const
{
	return getVoltageDrop() / getValue();
}

void Resistor::fillMNA(Vector2D& mat, std::vector<double>& b) const
{
	int r = terminal1->getId();
	int c = terminal2->getId();

	double conductance = 1.0 / value;

	mat.set(r, r, mat.get(r, r) + conductance);
	mat.set(c, c, mat.get(c, c) + conductance);
	mat.set(r, c, mat.get(r, c) - conductance);
	mat.set(c, r, mat.get(c, r) - conductance);
}