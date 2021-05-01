#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;
static const int dim = 5;

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

//Complexity is O(1) as we are operating on the original array
//Execution time is O(n^2) because the circular loop looks at all the elements in the matrix
template<typename T, int dim>
void rotateMatrix90(T (&matrix)[dim][dim])
{

	for (int i = 0; i < dim/2; i++)
	{
		int first = i;
		int last = dim - i - 1;
		//Roating means doing the following swap
		for (int j = first; j < last; j++)
		{
			int offset = j - first;
			int temp = matrix[first][j];
			//Top row with left column
			matrix[first][j] = matrix[last - offset][first];
			//Left column with bottom row
			matrix[last - offset][first] = matrix[last][last - offset];
			//Bottom row with right column
			matrix[last][last - offset] = matrix[j][last];
			//RIght column with top row
			matrix[j][last] = temp;
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