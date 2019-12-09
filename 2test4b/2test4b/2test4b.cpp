#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main()
{
	double eps = 1e-6;
	double sum = 0.0;
	double x; cin >> x;
	double n = 1000;
	if (x < 0.0 || x > 1)
	{
		cout << "Error\n";
	}
	else
	{
		for (int k = 1; abs(n) >= eps; k++)
		{
			int fact = 1;
			for (int i = 1; i <= (2 * k + 1); i++)
			{
				fact = fact * i;
			}
			for (int i = 1; i <= (2 * k + 1); i++)
			{
				x *= x;
			}
			if ((k + 1) % 2 == 0)
			{
				n =  x / (fact);
			}
			else
			{
				n = ((-1)*x) / (fact);
			}
			sum = sum + n;
		}
		cout << sum << endl;
	}
	system("pause");
	
}
