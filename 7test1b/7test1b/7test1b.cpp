#include <fstream>
#include <time.h>
#include <iostream>

using namespace std;

void no_empty(fstream &out)
{
	for (int i = 0; i < 120000; i++)
	{
		out << rand() % 10001 << '\n';
	}
}

int* sort(fstream &list, int n, int&l)
{
	int *a = new int[10001];
	int x;

	for (int i = 0; i < 10001; i++)
	{
		a[i] = 0;
	}
	while (list >> x)
	{
		a[x]++;
	}

	l = 0;
	for (int i = 0; i < 10001; i++)
	{
		if (a[i] == 2)
		{
			l++;
		}
	}
	int *b = new int[l];
	int k = 0;
	for (int i = 10001 - 1; i >= 0; i--)
	{
		if (a[i] == 2)
		{
			b[k] = i;
			k++;
		}
	}
	delete[] a;
	return b;
}

void out(int*b, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(0));
	fstream in_and_out("Numbers.txt", ios::out);
	no_empty(in_and_out);
	in_and_out.close();
	in_and_out.open("Numbers.txt", ios::in);
	int l = 0;
	long int n = 120000;
	int *b = sort(in_and_out, n, l);
	out(b, l);
	system("pause");
}