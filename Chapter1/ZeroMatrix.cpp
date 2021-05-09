#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;
static const int M = 5;
static const int N = 6;

//This solution is not the optimized one
//Complexity is O(M+N) as we are using two additional structures to keep track of the zeros in the matrix
//Execution time is O(N*M^2) because we loop twice on the elements
template<typename T, int M, int N>
void addZeros(T(&matrix)[M][N])
{
	bitset<M> zeroRows;
	bitset<N> zeroColumns;

	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (matrix[i][j] == 0)
			{
				zeroRows.set(i,true);
				zeroColumns.set(j, true);
			}
		}
	}

	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (zeroRows[i] == true)
			{
				matrix[i][j] = 0;
			}
			if (zeroColumns[j] == true)
			{
				matrix[i][j] = 0;
			}
		}
	}

}

void printMatrix(int matrix[M][N])
{
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
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
	int matrix[M][N];
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			matrix[i][j] = (2 * i) + j + 1;
		}
	}

	//Adding some zeros
	matrix[1][1] = 0;
	matrix[3][4] = 0;
	matrix[0][5] = 0;

	printMatrix(matrix);
	addZeros(matrix);
	printMatrix(matrix);

}