#include "8test5b.h"
#include <iostream>
#include <time.h>

using namespace std;

template <typename T>
T _min(dlist<T> list, int n)
{
	double x1, x2, min;
	x1 = list.start(0);
	x2 = list.finish(0);
	min = x1 + x2;
	for (int i = 1; i < n; i++)
	{
		x1 = list.start(i);
		x2 = list.finish(i);
		if (x1 + x2 < min)
		{
			min = x1 + x2;
		}
	}
	return min;
}

int main()
{
	srand((unsigned)(time(0)));
	int n;
	cout << " N = "; cin >> n;
	dlist<double> list;
	for (int i = 0; i < 2 * n; i++)
	{
		double x = (rand() % 100) / 100.0;
		list.add(x);
	}
	cout << list << '\n';
	double min = _min(list, n);
	cout << " min = " << min << '\n';
}