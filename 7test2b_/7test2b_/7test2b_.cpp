#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void make_no_empty(double* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(mas + i*n + j) = 1;
		}
	}
}

void out(double* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(15) << *(mas + i*n + j);
		}
		cout << '\n';
	}
}

void mult_matrix(double* mas, double* mas2, int n)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(mas2 + i*n + j) = 0;
			for (int k = 0; k < n; k++)
			{
				*(mas2 + i*n + j) += *(mas + i*n + k) * *(mas + k*n + j);
			}
		}
	}
}

void sum_and_out(double* mass, double* mas1, double* mas2, double* mas4, double* mas8, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(mass + i*n + j) = *(mas1 + i * n + j) + *(mas2 + i * n + j) + *(mas4 + i * n + j) + *(mas8 + i * n + j);
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
	double* mas1 = new double[n * n];

	cout << "A1: \n";
	make_no_empty(mas1, n);
	out(mas1, n);

	double* mas2 = new double[n*n];
	mult_matrix(mas1, mas2, n);
	cout << "A2: \n";
	out(mas2, n);

	double* mas4 = new double[n*n];
	mult_matrix(mas2, mas4, n);
	cout << "A4: \n";
	out(mas4, n);

	double* mas8 = new double[n*n];
	mult_matrix(mas4, mas8, n);
	cout << "A8: \n";
	out(mas8, n);

	double* mass = new double[n*n];
	sum_and_out(mass, mas1, mas2, mas4, mas8, n);

	delete[]mas1;
	delete[]mas2;
	delete[]mas4;
	delete[]mas8;
	delete[]mass;
	system("pause");
}