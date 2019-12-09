#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	double dx = 0.1;
	double x0 = -0.6;
	double xn = 0.8;
	double eps = 1e-6;
	double x = x0;
	int i = 0;
	int m, n, h;
	h = 1;
	m = 2;
	n = 3;
	double sum;
	double xx=1;
	sum = 0;
	double y, y1;
	for (x0 = -0.6; x0 <= xn; x0 += dx)
	{
		y = (1 / (pow(1 + x, 3))) - 1;
		cout << setw(15) << x << setw(15) << y << setw(15);
		x += dx;
		while (abs(xx) > eps)
		{
			if (m % 2 == 0)
			{
				xx = m * n / 2;
				for (i = 0; i < h; i++)	
				{
					xx = -xx*x0;
				}
				sum += xx;
				h += 1;
				m += 1;
				n += 1;
			}
			else
			{
				xx = m * n / 2;
				for (i = 0; i < h; i++)
				{
					xx = xx * x0;
				}
				sum += xx;
				h += 1;
				m += 1;
				n += 1;
			}
		}
		xx = 1;
		cout << setw(15) << sum << setw(15) << h << endl;
		h = 1;
		m = 2;
		n = 3;
		sum = 0;
	}
	system("pause");
}