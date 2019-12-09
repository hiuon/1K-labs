#include <iomanip>  
#include <math.h>  
#include <iostream>   
#include <stdlib.h>
using namespace std;
int main()
{
	const int N = 1000;
	bool a[N] = { 0 };
	unsigned int n, i, j;
	for (i = 2; i < N; i++)
	{
			a[i] = 1;
	}
	n = sqrt(double(N));
	for (i = 2; i <= n; i++)
	{
		if (a[i] == true)
		{
			for (j = i * 2; j < N; j += i)
			{
				a[j] = false;
			}
		}
	}
	for (i = 100; i < N; i++)
	{
		if (a[i] == true)
		{
			int k1 = i % 10;
			int k2 = (i / 10) % 10;
			int k3 = (i / 100) % 10;
			if (a[k1 * 100 + k2 * 10 + k3] == true &&
				a[k1 * 100 + k3 * 10 + k2] == true &&
				a[k2 * 100 + k1 * 10 + k3] == true &&
				a[k2 * 100 + k3 * 10 + k1] == true &&
				a[k3 * 100 + k2 * 10 + k1] == true &&
				a[k3 * 100 + k1 * 10 + k2] == true)
			{
				cout << i << ' ';
			}
		}
	}
	cout << endl;
	system("pause");
}
