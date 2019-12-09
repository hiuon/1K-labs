#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void matrix(int*, int);
void vyvod(int*, int);

int main()
{
	
	int* arr = NULL; 
	int size, i, j;
	int mas[50][50];
	while (1)
	{
		cout << "Vvedite poryadok matritsy(3<n<50): ";
		cin >> size;
		if (size < 3 || size > 50)
		{
			cout << "Error. Proverte vvedennie dannie\n";
		}
		else
		{
			break;
		}
	}
	arr = (int*)malloc(size * size * sizeof(int));
	matrix(arr, size);
	vyvod(arr, size);
	system("pause");
}
void matrix(int* B, int N)
{
	if (N % 2 == 0)
	{
		int k = N / 2, i = k - 1, j = k + 1, q = 0, x = 1;
		while (x <= N * N)
		{
			for (j--; j >= k - 1 - q && x <= N * N; j--, x++)
			{
				*(B + i * N + j) = x;
			}
			j++;


			for (i++; i <= k + q && x <= N * N; i++, x++)
			{
				*(B + i * N + j) = x;
			}
			i--;

			for (j++; j <= k + 1 + q && x <= N * N; j++, x++)
			{
				*(B + i * N + j) = x;
			}
			j--;

			for (i--; i >= k - 1 - q && x <= N * N; i--, x++)
			{
				*(B + i * N + j) = x;
			}
			j++;
			q++;
		}
	}
	else
	{
		int k = N / 2, i = k, j = k + 1, q = 0, x = 1;
		while (x <= N * N)
		{
			for (j--; j >= k - 1 - q && x <= N * N; j--, x++)
			{
				*(B + i * N + j) = x;
			}
			j++;

			for (i++; i <= k + 1 + q && x <= N * N; i++, x++)
			{
				*(B + i * N + j) = x;
			}
			i--;

			for (j++; j <= k + 1 + q && x <= N * N; j++, x++)
			{
				*(B + i * N + j) = x;
			}
			j--;

			for (i--; i >= k - 1 - q && x <= N * N; i--, x++)
			{
				*(B + i * N + j) = x;
			}
			i++;
			q++;
		}
	}
}

void vyvod(int* B, int N)
{
	for (int i = 0; i < N; i++)
	{
		for ( int j = 0; j < N; j++)
		{
			cout << setw(4) << *(B + N * i + j);
		}
		cout << "\n";
}
 }