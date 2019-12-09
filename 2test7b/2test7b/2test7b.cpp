#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	float sum = 10;
	float sum1 = 0;
	cout << "Vvedite n: "; cin >> n;
	int n1 = n;
	for (float x = 1; x <= 2; x += 0.25)
	{
		int koef = 1;
		float sqw = x * x;
		int k = 0;
		while (n1 > 0)
		{
			sum += koef * sqw;
			koef += 2;
			sqw *= x * x;
			n1 -= 1;
			k += 3;
			
		}
		n1 = n;
		int k1 = 0;
		float sum1 = 2 * n1 - 1;
		for (n1; n1 > 0; n1--)
		{ 
			sum1 = sum1 * x*x + (2*n1 - 3);
			k1 = k1 + 3;
		}
		sum1 = sum1 + 11;
		n1 = n;
		if (n == 0)
		{
			cout << setw(15) << x << setw(15) << sum << setw(15) << 2 * n << setw(15) << k + 1 << setw(15) << sum1 << setw(15) << 0 << setw(15) << k1 + 1 << endl;
		}
		else
		{
			cout << setw(15) << x << setw(15) << sum << setw(15) << 2 * n << setw(15) << k + 1 << setw(15) << sum1 << setw(15) << 2 * n - 1 << setw(15) << k1 + 1 << endl;
		}
		sum = 10;
	}
	system("pause"); 
}