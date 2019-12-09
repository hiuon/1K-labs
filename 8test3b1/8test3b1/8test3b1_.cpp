#include "vector.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned)time(0));
	int mas[] = { 1, 2, 3, 4, 5 };
	vector k(mas, 5);
	cout << k;
	k(6);
	cout << k;
	k[0] = 90;
	cout << k;
}