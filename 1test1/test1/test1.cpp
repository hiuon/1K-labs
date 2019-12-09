#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
int main(float b)
{

	cin >> b;
	if (b*b==0)
	{
		cout << "error";
		cin >> b;
	}
	else if ((sin(M_PI*b*b) + log10(b*b)) < 0)
	{
		cout << "error";
		cin >> b;
	}
	else
	{
		cout << sin(sin(b) + exp(sin(b) + b * b))*sqrt(sqrt(sin(M_PI*b*b) + log10(b*b)));
		cin >> b;
	}
	
}