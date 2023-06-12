#include "include/VoltageSource.h"

VoltageSource::VoltageSource(double val, Node* term1, Node* term2)
	: Component(val, term1, term2)
{
}

double VoltageSource::getVoltageDrop() const
{
	return value;
}