#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include "Integral.h"

using namespace std;

double func(double s, double t, double x)
{
	return t * 3 * pow(x, s) / sqrt(1 + pow(x, 3));
}

int main()
{
	double a = 0;
	double b = 1.075;
	double eps = 1e-6;

	cout << setw(15) << "S" << setw(15) << "T" << setw(15) << "Int" << setw(15) << "k_iter\n";


	for (int s = 1; s <= 4; s++)
	{
		for (double t = 0.2; t <= 1.2; t += 0.2)
		{
			Int(a, b, eps, func, t, s);
		}
	}
	
	system("pause");
}