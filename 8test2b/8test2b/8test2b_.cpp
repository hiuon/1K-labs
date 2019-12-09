#include "8test2b.h"
#include <iostream>

using namespace std;

h_num factorial(int n)
{
	h_num k(1);
	h_num m(1);
	for (int i = 0; i < n; ++i)
	{
		k = k * m;
		++m;
	}
	return k;
}

int main()
{
	h_num j, k, m;
	cin >> k >> m;
	j = k * m;
	cout << j;
}