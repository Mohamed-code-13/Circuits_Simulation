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

void Vector2D::solveEquations(std::vector<double>& b)
{
	forwardElimination(b);
	backwardSubstitution(b);
}

void Vector2D::forwardElimination(std::vector<double>& b)
{
	for (int i = 0; i < rows; ++i)
	{
		/*int pivotRow = i;
		for (int j = i + 1; j < rows; ++j)
			if (std::abs(matrix[j][i]) > std::abs(matrix[pivotRow][i]))
				pivotRow = j;


		std::swap(matrix[i], matrix[pivotRow]);
		std::swap(b[i], b[pivotRow]);
        */

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
    if (std::abs(div) > 1e-8) {
        for (int j = r; j < cols; ++j)
            matrix[r][j] /= div;
        b[r] /= div;
    }
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

std::vector<double> Vector2D::solveLinearEquations(std::vector<std::vector<double>>& A, std::vector<double>& b) {
    int numRows = A.size();
    int numCols = A[0].size();

    // Augment the coefficient matrix A with the right-hand side vector b
    for (int i = 0; i < numRows; ++i) {
        A[i].push_back(b[i]);
    }

    // Perform forward elimination
    for (int i = 0; i < numRows; ++i) {
        // Find the pivot row
        int pivotRow = i;
        for (int j = i + 1; j < numRows; ++j) {
            if (std::abs(A[j][i]) > std::abs(A[pivotRow][i])) {
                pivotRow = j;
            }
        }

        // Swap rows to pivot
        std::swap(A[i], A[pivotRow]);

        // Scale the pivot row to make the pivot element equal to 1
        double pivot = A[i][i];
        for (int j = i; j <= numCols; ++j) {
            A[i][j] /= pivot;
        }

        // Eliminate the other rows
        for (int j = 0; j < numRows; ++j) {
            if (j != i) {
                double factor = A[j][i];
                for (int k = i; k <= numCols; ++k) {
                    A[j][k] -= factor * A[i][k];
                }
            }
        }
    }

    // Extract the solution from the augmented matrix
    std::vector<double> x(numRows);
    for (int i = 0; i < numRows; ++i) {
        x[i] = A[i][numCols];
    }

    return x;
}