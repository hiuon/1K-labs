#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

int& max(int * arr, int n);

int main()
{
	srand(time(0));
	int N;
	cout << "Vvedite razmer massiva: ";
	cin >> N;
	int *mas = new int[N];
	cout << "Massiv: ";
	for (int i = 0; i < N; i++)
	{
		mas[i] = rand() % 200 - 10;
		cout << setw(4) << mas[i];
	}
	int &x = max(mas, N);// = 1000;
	cout << " \nMaksimalnoe chislo v massive po usloviu: " << x;
	cout << "\n";
	x = 0;
	cout << "Massiv: ";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << mas[i];
	}
	cout << "\n";
	system("pause");
	delete [] mas;
}

int& max(int * arr, int n)
{
	int *counter = new int[n];
	for (int i = 0; i < n; i++)
	{
		counter[i] = 0;
	}
	int max = *(arr);
	int indexMax = 0;
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(arr + i) == *(arr + j))
			{
				counter[i]++;
				check = true;
				max = *(arr + i);
			}
		}
	}
	if (check)
	{
		for (int i = 0; i < n; i++)
		{
			if (counter[i] && max < *(arr + i))
			{
				max = *(arr + i);
				indexMax = i;
			}
		}
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (max < *(arr + i))
			{
				max = *(arr + i);
				indexMax = i;
			}
		}
	}
	delete [] counter;
	return arr[indexMax];
}