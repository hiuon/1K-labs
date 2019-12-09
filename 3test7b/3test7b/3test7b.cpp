#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	cout << "Vvedite poryadok matritsy(1-99): ";
	int n; cin >> n;
	if (n >= 100 || n <= 0)
	{
		cout << "\nError\n";
		system("pause");
	} 
	else
	{
		srand(time(0));
		double A[100];
		double C[100];
		cout << "Matritsa A:\n";
		int counter = 0;
		int h = 0;
		for (int i = 0; i < (n + 1)*n / 2; i++)
		{
			A[i] = i + 1;
			//A[i] = (rand() % 2000 - 70) * 1.0 / (rand() % 1 + 100);
			//A[i] = rand() % 1 + 10;
			//cin >> A[i];
			cout << setw(10) << A[i];
			h++;
			if (h == n - counter)
			{
				cout << "\n";
				h = 0;
				counter++;
				for (int h = 0; h < counter; h++)
				{
					cout << setw(10) << "";
				}
			}
		}
		cout << "\nMatritsa C = A^2: \n";
		float sum;
		int counterC = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				sum = 0;
				for (int k = 0; k < n; k++)
				{
					int k1 = k, j1 = j, i1 = i, k2 = k;
					if (i1 > k1)
					{
						int buf = i1;
						i1 = k1;
						k1 = buf;
					}
					if (k2 > j1)
					{
						int buf = k2;
						k2 = j1;
						j1 = buf;
					}
					sum += A[k1 - i1 + (2 * n - i1 + 1)*i1 / 2] * A[j1 - k2 + (2 * n - k2 + 1)*k2 / 2];
				}
				if (i <= j)
				{
					counterC++;
					C[counterC] = sum;
				}
			}	
		}
		counter = 0;
		h = 0;
		for (int i = 0; i < (n + 1)*n / 2; i++)
		{
			cout << setw(10) << C[i];
			h++;
			if (h == n - counter)
			{
				cout << "\n";
				h = 0;
				counter++;
				for (int h = 0; h < counter; h++)
				{
					cout << setw(10) << "";
				}
			}
		}
		cout << "\n";
		system("pause");
	}
}