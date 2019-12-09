#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
using namespace std;
int main()
{
	srand(time(0));
	int A[100];
	int k;
	cout << "Vvedite dlinnu massiva A: "; cin >> k; cout << "\n";
	for (int n = 0; n < k; n++)
	{
		cout << setw(5) << n + 1;
	}
	cout << "\n";
	for (int n = 0; n < k; n++)
	{
		A[n] = rand() % 101 - 30;
		cout << setw(5) << A[n];
	} 
	cout << "\n";
	int a = A[0]; 
	int i = 0; 
	int j = 0; 
	int sum = 0;
	int pos = -1;
	for (int n = 0; n < k; n++)
	{
		sum += A[n];
		if (sum > a)
		{
			a = sum;
			i = pos + 1;
			j = n;
		}
		if (sum < 0)
		{
			sum = 0;
			pos = n;
		}
	}
	cout << "    i = " << i + 1 << " j = " << j + 1 << "\n";
	system("pause");
}