#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int k, l, m, n;
	cout << "Vvedite polojenie ferzya (k,l)\n k= ";
	cin >> k;
	cout << "\n l= ";
	cin >> l; 
	cout << "Vvedite polojenie slona (m,n)\n m= ";
	cin >> m;
	cout << "\n n= ";
	cin >> n;
	int dx = k - m;
	int dy = l - n;
	if (k == m && l == n)
	{
		cout << "\nProverte vveden. dan.\n Vvedite luboy simvol dlya zaversheniya raboty programy";
		cin >> k;
	}
	else if (k > 8 || k < 0 || l > 8 || l < 0 || m > 8 || m < 0 || n > 8 || n < 0)
	{
		cout << "\nProverte vveden. dan.\n Vvedite luboy simvol dlya zaversheniya raboty programy";
		cin >> k;
	}
	else if (k == m || l == n || abs(dx) == abs(dy))
	{
		cout << "Figury b'ut drug druga\n Vvedite luboy simvol dlya zaversheniya raboty programy";
		cin >> k;
	}
	else
	{
		cout << "Figury ne b'ut drug druga, no est khod pri kotorom oni smogut eto sdelat'\n Vvedite luboy simvol dlya zaversheniya raboty programy";
		cin >> k;
	}
}