#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int k;
	int h;
	const int d = 10;
	int a;
	const int a1 = 11;
	int all = 0;
	int cur;
	cout << "Vvedite natural'noe chislo k: "; cin >> k;
	for (int j = 1; ; j++)
	{
		int n = 0;
		a = a1 + d * (j - 1);
		h = a;
		while (h > 0)
		{
			h /= 10;
			n++;
		}
		all += n;
		if (all >= k)
		{
			cur = a;
			break;
		}
	}
	while (all > k)
	{
		all--;
		cur /= 10;
	}
	if (cur < 10)
	{
		cout << "Tsifra posledovatel'nosti: " << cur << endl;
	}
	else
	{
		cout << "Tsifra posledovatel'nosti: " << cur % 10 << endl;
	}
	system("pause");
}