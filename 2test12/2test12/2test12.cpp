#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main()
{
	int a, n, h, i;
	double N, N1;
	cout << "Vvedite polojitelnoe vestsestvenoe chislo N "; cin >> N;
	if (N <= 0)
	{
		cout << "Error\n";
		system("pause");
	}
	else
	{
		cout << "\nVvedite kolichestvo pervikh tsifr drobnoy chiasty n "; cin >> n;
		a = (int)N;
		N = N - a;
		if (N < 0.01)
		{
			cout << "\nNeverno\n";
			system("pause");
		}
		else
		{
			h = (int)(N * pow(10, n));
			int c[10];
			for (i = 0; i < 10; i++)
			{
				c[i] = 0;
			}
			while (h)
			{
				c[h % 10]++;
				h /= 10;
			}
			for (i = 0; i < 10; i++)
			{
				if (c[i] > 1)
				{
					cout << "\nNeverno\n";
					system("pause");
					break;
				}
			}
			if (i == 10)
			{
				cout << "\nVerno\n";
				system("pause");
			}
		}
	}
}
