#include <iostream>

using namespace std;

int nbYear(int p0, double percent, int aug, int p)
{
	int year = 0;
	while (p0 <= p)
	{
		int per = (int)(p0 * percent);
		p0 += aug;
		p0 += per;
		year++;
	}
	return year;
}

int main()
{
	cout << nbYear(1500, 5, 100, 5000);
}