#pragma once
#include "Component.h"

class Resistor : public Component
{
public:
	Resistor(double val, Node* term1 = nullptr, Node* term2 = nullptr);

	double getVoltageDrop() const override;
	double getCurrent() const;

	void fillMNA(Vector2D& mat, std::vector<double>& b) const override;
};

