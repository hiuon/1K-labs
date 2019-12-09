#include "8test3b2.h"
#include <iostream>
#include <time.h>

using namespace std;

int matrix<float>::counter = 0;

int main()
{
	matrix<float> k(2, 2);
	matrix<float> b(2, 2);
	cin >> k;
	cout << k;
	k.resize(4, 4);
	k = k + b;
	cout << k;
}