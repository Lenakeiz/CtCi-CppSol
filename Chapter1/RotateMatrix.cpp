#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;
static const int dim = 4;

void swapValues(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void swapValues(int(&a) [dim], int (&b) [dim])
{
	for (size_t i = 0; i < dim; i++)
	{
		swapValues(a[i], b[i]);
	}
}

template<typename T, int dim>
void rotateMatrix90(T (&matrix)[dim][dim])
{

	for (int i = 0; i < dim/2; i++)
	{
		//Roating means doing the following swap
		for (int j = 0; j < dim - i - 1; j++)
		{
			int temp = matrix[i][j];
			//Top row with left column
			matrix[i][j] = matrix[dim-j-1][i];
			//Left column with bottom row
			matrix[dim - j - 1][i] = matrix[dim - i - 1][dim - j - 1];
			//Bottom row with right column
			matrix[dim - i - 1][dim - j - 1] = matrix[j][dim - i - 1];
			//RIght column with top row
			matrix[j][dim - i - 1] = temp;
		}
	}
}

void printMatrix(int matrix[dim][dim])
{
	for (size_t i = 0; i < dim; i++)
	{
		for (size_t j = 0; j < dim; j++)
		{
			cout << matrix[i][j];
			if (matrix[i][j] > 9)
			{
				cout << " ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}	
	cout << endl;
}

int main()
{
	int matrix[dim][dim];
	for (size_t i = 0; i < dim; i++)
	{
		for (size_t j = 0; j < dim; j++)
		{
			matrix[i][j] = (2*i) + j + 1;
		}
	}

	printMatrix(matrix);
	rotateMatrix90(matrix);
	printMatrix(matrix);

}