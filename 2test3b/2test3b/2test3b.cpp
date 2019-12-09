#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	for (int i = 100; i < 1000; i++)
	{
		int s = 2;
		for (s; s <= i; s++)
		{
			if (i % s != 0)
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if (i == s)
		{
			 
			int n1 = s % 10;
			s /= 10;
			int n2 = s % 10;
			s /= 10;
			int n3 = s % 10;
			s = 2;
			for (s; s < 1000; s++)
			{
				if ((n1 * 100 + n2 * 10 + n3) % s != 0 && 
					(n1 * 100 + n3 * 10 + n2) % s != 0 && 
					(n2 * 100 + n1 * 10 + n3) % s != 0 && 
					(n2 * 100 + n3 * 10 + n1) % s != 0 && 
					(n3 * 100 + n2 * 10 + n1) % s != 0 && 
					(n3 * 100 + n1 * 10 + n2) % s != 0)
				{
					continue;
				}
				else
				{
					break;
				}

			}
			if (s == n3 * 100 + n2 * 10 + n1)
			{
				int k1 = n3 * 100 + n2 * 10 + n1;
				int k2 = n3 * 100 + n1 * 10 + n2;
				int k3 = n1 * 100 + n2 * 10 + n3;
				int k4 = n1 * 100 + n3 * 10 + n2;
				int k5 = n2 * 100 + n1 * 10 + n3;
				int k6 = n2 * 100 + n3 * 10 + n1;
				if (k1 == k2 || k1 == k3 || k1 == k4 || k1 == k5 || k1 == k6)
				{
					cout << k1 << endl;
				}
				if (k2 == k3 || k2 == k4 || k2 == k5 || k2 == k6)
				{
					cout << k2 << endl;
				}
				if (k3 == k4 || k3 == k5 || k3 == k6)
				{
					cout << k3 << endl;
				}
				if (k4 == k5 || k4 == k6)
				{
					cout << k4 << endl;
				}
				if (k5 == k6)
				{
					cout << k5 << endl;
				}
			}
			

		}
		s = 2;
			
	}
	system("pause");
}