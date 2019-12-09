#include <iostream>
#include <iomanip>

using namespace std;

void add(char* A, int* B, char c, int i, int n, char &v)
{
	A[i] = c;
	B[i] = i + 1;
	if (i + 1 == n)
	{
		B[i] = 0;
		v = A[i];
	}
}

void out(char* A, int* B, int n, char &v)
{
	for (int i = 0; B[i] != 0; i++)
	{
		cout << "  " << A[B[i] - 1];
	}
	cout << "  " << v << '\n';
}

void del(int i, int s, char* A, int* B, int& n, char& v)
{
	int k;
	int p = 0;
	if (s == n)
	{
		B[i - 1] = 0;
		v = A[i - 1];
	}
	else
	{
		for (k = i; k < s; k++)
		{
			B[k] = B[s + k - i];
			if (B[s + k - i] == 0)
			{
				v = A[s + k - i];
			}
			p++;
		}
		if (i == 0)
		{
			B[s + k - i - p] = 0;
		}
	}
}

void solution(char* A, char* A1, int* B, int* B1, int &n, int n1, char &v)
{
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		int start = i;
		for (int j = 0; j < n1; j++)
		{
			if (A[start] == A1[j])
			{
				check = true;
				start++;
			}
			else
			{
				check = false;
				i = start;
				break;
			}
		}
		if (check)
		{
			del(i, start, A, B, n, v);
			i = start;
		}
	}
}

int main()
{
	int n;
	cout << "Vvedite chislo simvolov v L: "; cin >> n;
	char* data = new char[n];
	int* ptr = new int[n];
	char v, v1;
	for (int i = 0; i < n; i++)
	{
		char c;
		cout << "#" << i + 1 << ": ";
		cin >> c;
		add(data, ptr, c, i, n, v);
	}
	out(data, ptr, n, v);
	cout << "---------------------------------------\n";

	int n1;
	cout << "Vvedite chislo simvolov v L1: "; cin >> n1;
	char* data1 = new char[n1];
	int* ptr1 = new int[n1];
	for (int i = 0; i < n1; i++)
	{
		char c;
		cout << "#" << i + 1 << ": ";
		cin >> c;
		add(data1, ptr1, c, i, n1, v1);
	}
	out(data1, ptr1, n1, v1);
	cout << "---------------------------------------\n";

	solution(data, data1, ptr, ptr1, n, n1, v);
	out(data, ptr, n, v);
}
