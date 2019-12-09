#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void make_no_empty(double** mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(mas + i) + j) = rand() % 100;
			*(*(mas + i) + j) = *(*(mas + i) + j) / 100;
		}
	}
}

void out(double** mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(15) << *(*(mas + i) + j);
		}
		cout << '\n';
	}
}

void mult_matrix(double** mas, double** mas2, int n)
{
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(mas2 + i) + j) = 0;
			for (int k = 0; k < n; k++)
			{
				*(*(mas2 + i) + j) += *(*(mas + i) + k) * *(*(mas + k) + j);
			}
		}
	}
}

void sum_and_out(double** mass, double** mas1, double** mas2, double** mas4, double** mas8, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(mass + i) + j) = *(*(mas1 + i) + j) + *(*(mas2 + i) + j) + *(*(mas4 + i) + j) + *(*(mas8 + i) + j);
		}
	}
	cout << "A1 + A2 + A4 + A8:\n";
	out(mass, n);
}

int main()
{
	srand((unsigned)time(0));
	cout << "Vvedtite poryadok matritsy: ";
	int n; cin >> n;
	double** mas1 = new double*[n];
	for (int i = 0; i < n; i++)
	{
		mas1[i] = new double[n];
	}

	cout << "A1: \n";
	make_no_empty(mas1, n);
	out(mas1, n);
	
	double** mas2 = new double*[n];
	for (int i = 0; i < n; i++)
	{
		mas2[i] = new double[n];
	}
	mult_matrix(mas1, mas2, n);
	cout << "A2: \n";
	out(mas2, n);

	double** mas4 = new double*[n];
	for (int i = 0; i < n; i++)
	{
		mas4[i] = new double[n];
	}
	mult_matrix(mas2, mas4, n);
	cout << "A4: \n";
	out(mas4, n);

	double** mas8 = new double*[n];
	for (int i = 0; i < n; i++)
	{
		mas8[i] = new double[n];
	}
	mult_matrix(mas4, mas8, n);
	cout << "A8: \n";
	out(mas8, n);

	double** mass = new double*[n];
	for (int i = 0; i < n; i++)
	{
		mass[i] = new double[n];
	}
	sum_and_out(mass, mas1, mas2, mas4, mas8, n);

	for (int i = 0; i < n; i++)
	{
		delete[]mas1[i];
	}
	delete[]mas1;

	for (int i = 0; i < n; i++)
	{
		delete[]mas2[i];
	}
	delete[]mas2;

	for (int i = 0; i < n; i++)
	{
		delete[]mas4[i];
	}
	delete[]mas4;

	for (int i = 0; i < n; i++)
	{
		delete[]mas8[i];
	}
	delete[]mas8;

	for (int i = 0; i < n; i++)
	{
		delete[]mass[i];
	}
	delete[]mass;
	system("pause");
}