#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	cout << "Vvedite kolichestvo elementov posledovatel'nosty: ";
	int n; cin >> n;
	int jmax = 0;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		int N, N1; cin >> N;
		N1 = N;
		if (N == 0)
		{
			j = j + 1;
		}
		if (jmax < j)
		{
			jmax = j;
		}
		if (N != 0)
		{
			j = 0;
		}
	}
	cout << "Kolichestvo elementov v naibolee dlinoy posledovatel'nosty podryad idutsshikh nulei: " << jmax << endl;
	system("pause");
}