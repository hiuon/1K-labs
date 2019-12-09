#include <iostream> 
#include <stdlib.h>
using namespace std;
int max = 500000;
int main() 
{
	int *arr = new int[max];
	int num;

	cout << "Vvedite chislo N: "; cin >> num; 
	cout << "Chislo edinits v chisle N!: ";
	for (int i = 0; i < max; i++)
	{
		arr[i] = 0;
	}
	arr[0] = 1;
	for (int i = 1; i < num + 1; i++)
	{
		for (int j = 0; j < max; j++)
		{
			arr[j] *= i;
		}
		for (int j = 0; j < max; j++)
		{
			if (arr[j] >= 10)
			{
				arr[j + 1] += arr[j] / 10;
				arr[j] = arr[j] % 10;
			}
		}
	}
	int n1 = 0;
	for (int i = 0; i < max; i++)
	{
		if (arr[i] == 1)
		{
			n1++;
		}
	}
	cout << n1;
	cout << "\n";
	system("pause");
}