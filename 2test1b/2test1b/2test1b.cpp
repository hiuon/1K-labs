#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int n, n1, k, i, sum, sum1, c, c1, n2, n3;
	i = 0;
	sum = 0;
	sum1 = 0;
	cout << "Vvedite chislo n i kolichestvo tsifr k\n";
	cout << "n= "; 
	cin >> n;
	cout << "\nk= "; 
	cin >> k;
	n1 = n;
	while (n1 != 0.0)
	{
		n1 /= 10;
		i++;
	}
	if (i < k)
	{
		cout << "\nError\n";
		system("pause");
	}
	else
	{
		n1 = n;
		for (c = 0; n1 > 0; c++)
		{
			n1 = n1 / 10;
		}
		n1 = n;
		for (i = 0; i < k; i++)
		{
			n2 = n1 % 10;
			n1 /= 10;
			sum1 = sum1 + n2;
		}
		n1 = n;
		n3 = 0;
		c1 = c;
		for (i = 0; i <= c1; i++)
		{
			 
			n2 = n1 % 10;
			n1 /= 10;
			n3 = n3 + n2 * pow(10, c-1);
			c -= 1;
		}
		for (i = 0; i < k; i++)
		{
			n2 = n3 % 10;
			n3 /= 10;
			sum = sum + n2;
		}
		if (sum == sum1)
		{
			cout << "\nSumma tsifr sovpadaet\n";
			system("pause");
		}
		else
		{
			cout << "\nSumma tsifr  ne sovpadaet\n";
			system("pause");
		}


	}
}