#pragma once
#include "Component.h"

class VoltageSource : public Component
{
public:
	VoltageSource(double val, Node* term1 = nullptr, Node* term2 = nullptr);

	double getVoltageDrop() const override;
};

