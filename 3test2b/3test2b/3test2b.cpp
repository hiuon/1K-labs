#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
int main()
{
		int k;
	cout << "Vvedite razmer matritsy: ";  cin >> k;
	if (k > 10)
	{
		cout << "Error\n";
		system("pause");
	}
	else
	{
		int A[10][10], B[10][10], a[10][10], i, j;
		cout << "\nMatritsa A: \n";
		for (i = 0; i < k; i++)
		{
			for (j = 0; j < k; j++)
			{
				A[i][j] = rand() % 201-70;
				cout << setw(5) << A[i][j];
			}
			cout << "\n";
		}
		for (i = 0; i < k; i++)
		{
			for (j = 0; j < k; j++)
			{
				int max = A[i][j];
				for (int q = 0; q < k; q++)
					for (int n = 0; n < k; n++)
					{
						if (q >= i && n <= j && n >= q && j >= i)
						{
							if (max < A[q][n])
							{
								max = A[q][n];
							}
						}
						if (q <= i && n >= j && n <= q && j < i)
						{
							if (max < A[q][n])
							{
								max = A[q][n];
							}
						}
					}
				B[i][j] = max;
			}
		}
		cout << "Matritsa B: \n";
		for (i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				cout << setw(5) << B[i][j];
			}
			cout << "\n";
		}
		system("pause");
	}
}