#pragma once
#include "Component.h"

class Resistor : public Component
{
public:
	Resistor(double val, Node* term1 = nullptr, Node* term2 = nullptr);

	double getVoltageDrop() const override;
	double getCurrent() const;
};

