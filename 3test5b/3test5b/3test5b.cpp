#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	srand(time(0));
	cout << "Vvedite poryadok matritsy: ";
	int n; cin >> n;
	if (n >= 100)
	{
		cout << "\nError\n";
		system("pause");
	}
	else
	{
		int A[100][100];
		int B[100][100];
		cout << "Matritsa A:\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				A[i][j] = rand() % 201 - 1;
				cout << setw(5) << A[i][j];
			}
			cout << "\n";
		}
		int posi = 0;
		for (int i = 0; i < n; i++)
		{
			int posj = 0;
			
			for (int j = 0; j < n; j++)
			{
				int min = A[i][j];
				for (int i1 = 0; i1 < n; i1++)
				{
					for (int j1 = 0; j1 < n; j1++)
					{
						if (j1 >= i1 + posj - posi)
						{
							if (min > A[i1][j1])
							{
								min = A[i1][j1];
							}
						}
					}
				}
				posj++;
				B[i][j] = min;
			}
			posi++;
		}
		cout << "\nMatritsa B:\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << setw(5) << B[i][j];
			}
			cout << "\n";
		}
		system("pause");
	}
}