#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
using namespace std;
int main()
{
	srand(time(0));
	int stroki, stolbtsi;
	cout << "Vvedite chislo strok matritsy(<50): ";  cin >> stroki;
	cout << "Vvedite chislo stolbtsov matritsy(<50): ";  cin >> stolbtsi; cout << "\n";
	if (stroki > 50 || stolbtsi > 50)
	{
		cout << "Error";
		system("pause");
	}
	else
	{
		int A[50][50];
		int B[50];
		for (int i = 0; i < stroki; i++)
		{
			for (int j = 0; j < stolbtsi; j++)
			{
				*(*(A + i) + j) = rand() % 201 - 70;
				cout << setw(5) << *(*(A + i) + j);
			}
			cout << "\n";
		}
		for (int i = 0; i < stroki; i++)
		{
			int max = *(*(A + i) + 0);
			for (int j = 0; j < stolbtsi; j++)
			{
				if (*(*(A + i) + j) > max)
				{
					max = *(*(A + i) + j);
				 }
			}
			*(B + i) = max;
		}
		cout << "\n";
		for (int j = 0; j < stroki; j++)
		{
			cout << setw(5) << *(B + j);
		}
		cout << "\n";
		int swap = 0;
		int k = 0;
		while (k < stroki)
		{
			if (k + 1 != stroki && *(B + k) > *(B + k + 1))
			{
				int min = *(B + k);
				*(B + k) = *(B + k + 1);
				*(B + k + 1) = min;
				swap = 1;
				for (int j = 0; j < stolbtsi; j++)
				{
					int mas = *(*(A + k) + j);
					*(*(A + k) + j) = *(*(A + k + 1) + j);
					*(*(A + k + 1) + j) = mas;
				}
			}
			k++;
			if (swap == 1 && k == stroki)
			{
				swap = 0;
				k = 0;
			}
		}
		for (int j = 0; j < stroki; j++)
		{
			cout << setw(5) << *(B + j);
		}
		cout << "\n";
		cout << "\n";
		for (int i = 0; i < stroki; i++)
		{
			for (int j = 0; j < stolbtsi; j++)
			{
				cout << setw(5) << *(*(A + i) + j);
			}
			cout << "\n";
		}
		system("pause");
	}
}
