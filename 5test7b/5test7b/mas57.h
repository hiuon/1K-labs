#pragma once
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>

using namespace std;

template <class type1> void z1(type1 *arr, type1 *arr1, int n)
{
	for (int i = 0; i < n; i++)
	{
		 arr1[i] = arr[i] = i + 1.0758;
	}
}

template <class type1> void z2(type1 *arr, type1 *arr1, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr1[i] = arr[i] = n - i + 1.8569;
	}
}

template <class type1> void z3(type1 *arr, type1 *arr1, int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		arr1[i] = arr[i] = (rand() % 201 - 71) / 0.33;
	}
}

template <class type1> void sort_bin_vst(type1 *arr, int n, int &k1, int &k2)
{
	type1 x;
	int left;
	int right;
	k1 = 0;
	k2 = 0;

	for (int i = 1; i < n; i++)
	{
		x = arr[i];
		int  left = 0;
		int right = i - 1;

		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (x < arr[mid])
			{
				right = mid - 1;
				k1++;
			}
			else
			{
				left = mid + 1;
				k1++;
			}
		}
		for (int j = i - 1; j >= left; j--)
		{
			arr[j + 1] = arr[j];
			k2++;
		}
		arr[left] = x;
	}
}

template <class type1> void sort_obm(type1 *arr, int n, int &k1, int &k2)
{
	k1 = 0; 
	k2 = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			k1++;
			if (arr[j - 1] > arr[j])
			{
				type1 x = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = x;
				k2++;
			}
		}
	}
}

template <class type1> void out(type1 *arr, int n, int k1, int k2)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << arr[i];
	}
	cout << '\n' << "Chislo sravneniy: " << k1 << '\n' << "Chislo prisvaivaniy: " << k2 << '\n';
}