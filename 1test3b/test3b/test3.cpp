#include <iostream>

#include <stdlib.h>
//x1>x2>x3<x4
using namespace std;
int main()
{
	int l;
	cout << "Vyberite sposob resheniya. 1 - cherez if, drugoy simvol - cherez ?\n"; cin >> l;
	if (l == 1)
	{
		float x4, x3, x2, x1;
		float m;
		cout << "Vvedite x1 ";
		cin >> x1;
		cout << "Vvedite x2 ";
		cin >> x2;
		cout << "Vvedite x3 ";
		cin >> x3;
		cout << "Vvedite x4 \n";
		cin >> x4;
		if (x2 > x1)
		{
			m = x1;
			x1 = x2;
			x2 = m;
		}
		if (x2 < x3)
		{
			m = x2;
			x2 = x3;
			x3 = m;
		}
		if (x2 > x1)
		{
			m = x1;
			x1 = x2;
			x2 = m;
		}
		if (x3 > x4)
		{
			m = x3;
			x3 = x4;
			x4 = m;
		}
		if (x1 == x2 || x2 == x3 || x3 == x4)
		{
			cout << "Error";
			system("pause");
		}
		else
		{
			cout << x1 << ">" << x2 << ">" << x3 << "<" << x4 << "\n";
			system("pause");
		}
	}
	else
	{
		float x4, x3, x2, x1;
		float m;
		cout << "Vvedite x1 ";
		cin >> x1;
		cout << "Vvedite x2 ";
		cin >> x2;
		cout << "Vvedite x3 ";
		cin >> x3;
		cout << "Vvedite x4 ";
		cin >> x4;
		cout << "\n";
		(x2 > x1) ? (m = x1, x1 = x2, x2 = m) : x2 = x2;
		(x2 < x3) ? (m = x2, x2 = x3, x3 = m) : x3 = x3;
		(x2 > x1) ? (m = x1, x1 = x2, x2 = m) : x1 = x1;
		(x3 > x4) ? (m = x3, x3 = x4, x4 = m) : x1 = x1;
		if (x1 == x2 || x2 == x3 || x3 == x4)
		{
			cout << "Error";
			system("pause");
		}
		else
		{
			cout << x1 << ">" << x2 << ">" << x3 << "<" << x4 << "\n";
			system("pause");
		}
	}
}