#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
using namespace std;
int main()
{
	srand(time(0));
	int m, n;
	cout << "Vvedite chislo strok matritsy(<50): ";  cin >> m;
	cout << "Vvedite chislo stolbtsov matritsy(<50): ";  cin >> n; cout << "\n";
	if (m > 50 || n > 50)
	{
		cout << "Error";
		system("pause");
	}
	else
	{
		int A[50][50];
		int B[50];
		cout << "\nMatritsa A: \n";
		int i, j;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				A[i][j] = rand() % 201 - 70;
				cout << setw(5) << A[i][j];
			}
			cout << "\n";
		}
		for (i = 0; i < m; i++)
		{
			int max = A[i][0];
			for (j = 0; j < n; j++)
			{
				if (max < A[i][j])
				{
					max = A[i][j];
				}
			}
			B[i] = max;
		}
		cout << "\n\n";
		for (i = 0; i < m; i++)
		{
			cout << setw(5) << B[i];
		}
		cout << "\n\n";
		for (i = 0; i < m; i++)
		{
			for (j = m - 1; j >= i; j--)
			{
				if (B[j - 1] > B[j])
				{
					int masx = B[j - 1];
					B[j - 1] = B[j];
					B[j] = masx;
					for (int k = 0; k < m; k++)
					{
						int masy = A[j - 1][k];
						A[j - 1][k] = A[j][k];
						A[j][k] = masy;
					}

				}
			}
		}
		for (j = 0; j < m; j++)
		{
			cout << setw(5) << B[j];
		}
		cout << "\n\n";
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout << setw(5) << A[i][j];
			}
			cout << "\n";
		}
		system("pause");
	}
}
