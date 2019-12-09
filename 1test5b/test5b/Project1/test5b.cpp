#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	float x1, x2, x3, x4, y1, y2, y3, y4, x, y;
	cout << "x1 = "; cin >> x1;
	cout << "x2 = "; cin >> x2;
	cout << "x3 = "; cin >> x3;
	cout << "x4 = "; cin >> x4;
	cout << "y1 = "; cin >> y1;
	cout << "y2 = "; cin >> y2;
	cout << "y3 = "; cin >> y3;
	cout << "y4 = "; cin >> y4;
	if (x1 == x2 || x3 == x4 || y1 == y2 || y3 == y4)
	{
		cout << "Error\n";
		system("pause");
	}
	else
	{
		if (x1 > x2)
		{
			x = x1;
			x1 = x2;
			x2 = x;
			y = y1;
			y1 = y2;
			y2 = y;
		}
		if (y1 > y2)
		{
			x = x1;
			x1 = x2;
			x2 = x;
			y = y1;
			y1 = y2;
			y2 = y;
		}
		if (x3 > x4)
		{
			x = x3;
			x3 = x4;
			x4 = x;
			y = y3;
			y3 = y4;
			y4 = y;
		}
		if (y3 > y4)
		{
			x = x3;
			x3 = x4;
			x4 = x;
			y = y3;
			y3 = y4;
			y4 = y;
		}
		if (x1 >= x4 || x3 >= x2 || y1 >= y4 || y3 >= y2)
		{
			cout << "\npryamougolniki ne perekrivaut drug druga\n";
			system("pause");
		 }
		else
		{
			cout << "\npryamougolniki perekrivaut drug druga\n";
			system("pause");
		}
	}
}