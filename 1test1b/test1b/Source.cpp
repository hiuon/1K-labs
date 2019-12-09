#include <iostream>
#include <float.h>
#include <math.h>
using namespace std;
int main(int s, int t, float x)
{
	cout << "VVedite s ";
	cin >> s;
	cout << "\n Vvedite t ";
	cin >> t;
	cout << "\n Vvedite x ";
	cin >> x;
	if (x < 0)
	{
		cout << "Error";
	}
	if (pow(x, t) <= 0)
	{
		cout << "Error";
	}
	else if (s == 0)
	{
		cout << "Error";
	}
	else if (abs((log10(pow(x, t)) + cos(pow(x, 1.0 / s))*cos(pow(x, 1.0 / s))) < FLT_EPSILON*2))
	{
		cout << "Error";
	}
	else
	{
		cout << x * x / (log10(pow(x, t)) + cos(pow(x, 1.0 / s))*cos(pow(x, 1.0 / s)));
		cin >> x;
	}
}