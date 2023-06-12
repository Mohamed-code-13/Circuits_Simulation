#pragma once
#include "Component.h"

class VoltageSource : public Component
{
public:
	VoltageSource(double val, Node* term1, Node* term2);

	double getVoltageDrop() const override;
};

