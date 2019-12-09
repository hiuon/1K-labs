#include <iostream>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#include <string.h>

using namespace std;



void comparison(int l, int r, int mid, char a[][30], int i, int j)
{
	char tmp[30][30];
	for (int step = 0; step < r - l + 1; step++)
	{
		if ((j > r) || ((i <= mid) && (strcmp(a[i], a[j]) < 0)))
		{
			strcpy_s(tmp[step], 30, a[i]);
			i++;
		}
		else
		{
			strcpy_s(tmp[step], 30, a[j]);
			j++;
		}
	}
	for (int step = 0; step < r - l + 1; step++)
	{
		strcpy_s(a[l + step], 30, tmp[step]);
	}
}

template <class type1>
void comparison(int l, int r, int mid, type1* arr, int i, int j)
{
	type1 *tmp = new type1[r];
	for (int step = 0; step < r - l + 1; step++)
	{
		if ((j > r) || ((i <= mid) && (arr[i] < arr[j])))
		{
			tmp[step] = arr[i];
			i++;
		}
		else
		{
			tmp[step] = arr[j];
			j++;
		}
	}
	for (int step = 0; step < r - l + 1; step++)
	{
		arr[l + step] = tmp[step];
	}
}

template <class type1> 
 void make_no_empty(type1 *arr, int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (rand() % 201 - 21) / 0.33;
	}
}

 template <class type1>
 void out(type1 *arr, int n)
 {
	 for (int i = 0; i < n; i++)
	 {
		 cout << setw(10) << arr[i];
	 }
 }

 void out(char arr[][30], int n)
 {
	 for (int i = 0; i < n; i++)
	 {
		 cout << setw(10) << arr[i];
	 }
 }

 template <class type1>
 void sort_merge(type1 *arr, int left, int right)
 {
	 if (left == right)
	 {
		 return;
	 }
	 int mid = (left + right) / 2;
	 sort_merge(arr, left, mid); 
	 sort_merge(arr, mid + 1, right);
	 int i = left;
	 int j = mid + 1;
	 comparison(left, right, mid, arr, i, j);
 }


int main()
{
	cout << "Viberyte tip massiva:\n1 --- tselye chisla\n2 --- veschestvennie chisla\n3 --- simvoly\n4 --- zadannie C-stroki\n";
	int choice, N, count = 0; cin >> choice;
	int *arr1;
	double *arr2;
	char *arr3;
	char arr4[30][30] = { "go", "iop", "good", "school", "ndsjnvnsdvk", "jd", "chegc", "wqtyuf", "h" };


	switch (choice)
	{
	case 1:
		cout << "Vvedite razmer massiva: ";
		cin >> N;
		arr1 = new int[N];
		make_no_empty(arr1, N);
		cout << "Nachalniy massiv:      ";
		out(arr1, N);
		sort_merge(arr1, 0, N - 1);
		cout << "\nOtsortirovaniy massiv: ";
		out(arr1, N);
		break;
	case 2:
		cout << "Vvedite razmer massiva: ";
		cin >> N;
		arr2 = new double[N];
		make_no_empty(arr2, N);
		cout << "Nachalniy massiv:      ";
		out(arr2, N);
		sort_merge(arr2, 0, N - 1);
		cout << "\nOtsortirovaniy massiv: ";
		out(arr2, N);
		break;
	case 3:
		cout << "Vvedite razmer massiva: ";
		cin >> N;
		arr3 = new char[N];
		make_no_empty(arr3, N);
		cout << "Nachalniy massiv:      ";
		out(arr3, N);
		sort_merge(arr3, 0, N - 1);
		cout << "\nOtsortirovaniy massiv: ";
		out(arr3, N);
		break;
	case 4:
		cout << "Nachalniy massiv:      ";
		out(arr4, 9);
		sort_merge(arr4, 0, 8);
		cout << "\nOtsortirovaniy massiv: ";
		out(arr4, 9);
		break;
	default:
		break;
	}
	
	cout << '\n';
	system("pause");
}