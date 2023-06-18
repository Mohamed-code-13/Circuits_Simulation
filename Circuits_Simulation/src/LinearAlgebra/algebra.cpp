#include "include/algebra.h"

Vector2D::Vector2D(int r, int c)
	: rows(r), cols(c)
{
	matrix = std::vector<std::vector<double>>(r, std::vector<double>(c, 0));
}

double Vector2D::get(int i, int j) const
{
	return matrix[i][j];
}

void Vector2D::set(int i, int j, double val)
{
	matrix[i][j] = val;
}

std::vector<double> Vector2D::solveEquations(std::vector<double>& b)
{
	forwardElimination(b);
	backwardSubstitution(b);

	return b;
}

void Vector2D::forwardElimination(std::vector<double>& b)
{
	for (int i = 0; i < rows; ++i)
	{
		makePivotOne(b, i);
		elimination(b, i);
	}
}

void Vector2D::backwardSubstitution(std::vector<double>& b)
{
	for (int i = rows - 1; i >= 0; --i)
		for (int j = i + 1; j < cols; ++j)
			b[i] -= matrix[i][j] * b[j];
}

void Vector2D::makePivotOne(std::vector<double>& b, int r)
{
	double div = matrix[r][r];
	for (int j = r; j < cols; ++j)
		matrix[r][j] /= div;
	b[r] /= div;
}

void Vector2D::elimination(std::vector<double>& b, int r)
{
	for (int i = r + 1; i < rows; ++i)
	{
		double factor = matrix[i][r];
		for (int j = r; j < cols; ++j)
			matrix[i][j] -= factor * matrix[r][j];
		b[i] -= factor * b[r];
	}
}