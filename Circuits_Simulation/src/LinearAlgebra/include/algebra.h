#pragma once
#include <vector>

class Vector2D
{
private:
	int rows, cols;
	std::vector<std::vector<double>> matrix;

public:
	Vector2D(int r, int c);

	double get(int i, int j) const;
	void set(int i, int j, double val);

	void solveEquations(std::vector<double>& b);

private:
	void forwardElimination(std::vector<double>& b);
	void backwardSubstitution(std::vector<double>& b);
	void makePivotOne(std::vector<double>& b, int r);
	void elimination(std::vector<double>& b, int r);
};