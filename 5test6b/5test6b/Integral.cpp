#include <iostream>
#include <math.h>
#include <iomanip>
#include "Integral.h"

using namespace std;

void Sum(double a, double b, double h, double(*func)(double, double, double), double &S, double t, double s)
{
	double x = a;
	double sum = func(s, t, a) / 2;
	x += h;
	while (x < b)
	{
		sum += func(s, t, x);
		x += h;
	}
	sum +=  func(s, t, b) / 2;
	S = h * sum;
}

void Int(double a, double b, double eps, double(*func)(double, double, double), double t, double s)
{
	int N = 32;
	int counter = 0;
	double h = (b - a) / N;
	double s1 = 0, s2 = 0;

	Sum(a, b, h, func, s1, t, s);

	do
	{
		s2 = s1;
		N *= 2;
		h = (b - a) / N;
		Sum(a, b, h, func, s1, t, s);
		counter++;
	} while (abs(s1 - s2) > eps);
	cout << setw(15) << s << setw(15) << t << setw(15) << s1 << setw(15) << counter << "\n";
}
