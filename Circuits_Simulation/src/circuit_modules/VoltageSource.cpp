#include "include/VoltageSource.h"

VoltageSource::VoltageSource(double val, Node* term1, Node* term2)
	: Component(val, term1, term2)
{
}

double VoltageSource::getVoltageDrop() const
{
	return value;
}

void VoltageSource::fillMNA(Vector2D& mat, std::vector<double>& b) const
{
	int r = terminal1->getId();
	int c = terminal2->getId();

	mat.set(r, r, mat.get(r, r) + 1);
	mat.set(c, c, mat.get(c, c) + 1);
	mat.set(r, c, mat.get(r, c) - 1);
	mat.set(c, r, mat.get(c, r) - 1);

	b[r] += value;
	b[c] -= value;
}