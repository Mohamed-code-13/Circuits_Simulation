#include "include/Resistor.h"

Resistor::Resistor(double val, Node* term1, Node* term2)
	: Component(val, term1, term2)
{
}

double Resistor::getVoltageDrop() const 
{
	return terminal1->getVolt() - terminal2->getVolt();
}

