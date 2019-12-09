#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>

using namespace std;

double f1(double x)
{
	return (x - 1)*(x - 1) - 5;
}

double f2(double x, double s)
{
	return (x - s)*(x - s) - exp(-x);
}

double func_a(double x, double& a, double& b)
{
	if (f1(x)*f1(a) < 0)
	{
		a = x;
	}
	else if (f1(x)*f1(b) < 0)
	{
		b = x;
	}
	return x;
}

double func_b(double x, double& a, double& b, double s)
{
	if (f2(x, s)*f2(a, s) < 0)
	{
		a = x;
	}
	else if (f2(x, s)*f2(b, x) < 0)
	{
		b = x;
	}
	return x;
}

void methode_hord(double a, double b, double eps, double (*f1)(double))
{
	double result_x = 3;
	int counter = 0;
	while (abs(f1(func_a(result_x, a, b))) > eps)
	{
		result_x = b - (b - a) / (f1(b) - f1(a))*f1(b);
		counter++;
	}
	cout << "Pervoe uravnenie: \n" << "X = " << result_x << '\n' << "F(x) = " << f1(func_a(result_x, a, b)) << '\n' << "k_iter = " << counter << '\n';
	cout << "Vtoroe uravnenie: \n" << setw(15) << "S" << setw(15) << "X" << setw(15) << "F(x)" << setw(15) << "k_inter\n";
}

void methode_hord(double a, double b, double eps, double s, double (*f2)(double, double))
{
	double result_x = 1;
	int counter = 0;
	while (abs(f2(func_b(result_x, a, b, s), s)) > eps)
	{
		result_x = b - (b - a) / (f2(b, s) - f2(a, s))*f2(b, s);
		counter++;
	}
	cout << setw(15) << s << setw(15) << result_x << setw(15) << f2(func_b(result_x, a, b, s), s) << setw(15) << counter << '\n';
}

int main()
{
	double eps = 1e-6;
	double a1 = 2;
	double b1 = 4;
	double a2 = -1.5;
	double b2 = 2;

	methode_hord(a1, b1, eps, f1);
	
	for (double s = 0.7; s <= 1.6; s += 0.3)
	{
		methode_hord(a2, b2, eps, s, f2);
	}

	cout << '\n';
	system("pause");
}