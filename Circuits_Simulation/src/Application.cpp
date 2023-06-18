#include <iostream>
#include "include/Circuit.h"
#include "LinearAlgebra/include/algebra.h"

int main()
{
    // Create the circuit
    Circuit circuit;

    Vector2D mat(3, 3);
    mat.matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 10},
    };
    std::vector<double> b = { 3, 3, 4 };

    std::vector<double> res = mat.solveEquations(b);

    std::cout << "A: \n";
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            std::cout << mat.get(i, j) << ' ';
        std::cout << '\n';
    }

    std::cout << "b: \n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << b[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "res: \n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';


	return 0;
}
