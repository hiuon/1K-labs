#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "mas57.h"

using namespace std;

int main()
{
	int N;
	cout << "Vvedite razmer massiva: ";
	cin >> N;
	double * arr;
	double * arr1;
	arr = new double [N];
	arr1 = new double[N];
	int k1 = 0;
	int k2 = 0;

	cout << "Vozrast: ";
	z1(arr, arr1, N);
	for (int i = 0; i < N; i++)
	{
		cout << setw(10) << arr[i];
	}
	sort_bin_vst(arr, N, k1, k2);
	cout << "\n||||Binarnye vstavki: ";
	out(arr, N, k1, k2);

	sort_obm(arr1, N, k1, k2);
	cout << "\n||||Obmen: ";
	out(arr1, N, k1, k2);

	cout << "\n\nUbivanie: ";
	z2(arr, arr1, N);
	for (int i = 0; i < N; i++)
	{
		cout << setw(10) << arr[i];
	}
	sort_bin_vst(arr, N, k1, k2);
	cout << "\n||||Binarnye vstavki: ";
	out(arr, N, k1, k2);

	sort_obm(arr1, N, k1, k2);
	cout << "\n||||Obmen: ";
	out(arr1, N, k1, k2);

	cout << "\n\nSluchaino: ";
	z3(arr, arr1, N);
	for (int i = 0; i < N; i++)
	{
		cout << setw(10) << arr[i];
	}
	sort_bin_vst(arr, N, k1, k2);
	cout << "\n||||Binarnye vstavki: ";
	out(arr, N, k1, k2);

	sort_obm(arr1, N, k1, k2);
	cout << "\n||||Obmen: ";
	out(arr1, N, k1, k2);



	system("pause");
}