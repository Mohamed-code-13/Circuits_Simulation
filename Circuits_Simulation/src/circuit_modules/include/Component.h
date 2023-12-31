#pragma once
#include "Node.h"
#include "../../LinearAlgebra/include/algebra.h"

class Component
{
protected:
	double value;
	Node* terminal1;
	Node* terminal2;

public:
	Component(double val, Node* term1, Node* term2);

	double getValue() const;

	Node* getTerminal1() const;
	Node* getTerminal2() const;

	void setTerminal1(Node* term);
	void setTerminal2(Node* term);

	virtual double getVoltageDrop() const = 0;
	virtual void fillMNA(Vector2D& mat, std::vector<double>& b) const = 0;
};

