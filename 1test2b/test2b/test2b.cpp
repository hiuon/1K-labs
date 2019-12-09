#include <iostream>
#include <math.h>
using namespace std;
int main(float x, float y, float R)
{
	cout << "Vvedite coordinaty tochki (x,y) i znachenie radiusa R. \n x= ";
	cin >> x;
	cout << "\n y= ";
	cin >> y;
	cout << "\n R= ";
	cin >> R;
	if (R < 0)
	{
		cout << "R - polojitelnoe chislo. Proverte vvedenye dannye";
		cin >> x;
	}
	else if (y >= -x + (-2 * R) && y <= 0 && x <= 0)
	{
		cout << "Tochka prinadlejit zadannoy ploskosty";
		cin >> x;
	}
	else if (sqrt(pow(x, 2) + pow(y, 2)) >= R && x >= 0 && y >= 0 && x <= 2 * R && y <= 2 * R)
	{
		cout << "Tochka prinadlejit zadannoy ploskosty";
		cin >> x;
	}
	else
	{
		cout << "Tochka ne prinadlejit zadannoy ploskosty";
		cin >> x;
	}
}