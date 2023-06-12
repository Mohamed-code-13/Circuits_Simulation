#pragma once
#include "Component.h"

class Resistor : public Component
{
public:
	Resistor(double val, Node* term1, Node* term2);

	double getVoltageDrop() const override;
};

