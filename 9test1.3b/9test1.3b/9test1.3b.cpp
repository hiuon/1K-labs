#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>

using namespace std;

template <typename T>
void make_no_empty(vector<vector<T>>& mas)
{
	for (int i = 0; i < mas.size(); i++)
	{
		for (int j = 0; j < mas.size(); j++)
		{
			mas[i][j] = 1;
		}
	}
}

template <typename T>
void make_no_empty_ans(vector<vector<T>>& mas)
{
	for (int i = 0; i < mas.size(); i++)
	{
		for (int j = 0; j < mas.size(); j++)
		{
			mas[i][j] = 0;
		}
	}
}

template <typename T>
void out(vector<vector<T>>& mas)
{
	for (int i = 0; i < mas.size(); i++)
	{
		for (int j = 0; j < mas.size(); j++)
		{
			cout << setw(15) << mas[i][j];
		}
		cout << '\n';
	}
}

template <typename T>
void mult_matrix(vector<vector<T>>& mas, vector<vector<T>>& mas2)
{
	vector<vector<double>> temp(mas.size(), vector<double>(mas.size()));
	make_no_empty_ans(temp);
	for (int i = 0; i < mas.size(); i++)
	{
		for (int j = 0; j < mas.size(); j++)
		{
			int p = 0;
			for (int k = 0; k < mas.size(); k++)
			{
				temp[i][j] += mas[i][k] * mas2[k][j];
			}
		}
	}
	mas = temp;
}

template <typename T>
void sum(vector<vector<T>>& mas, vector<vector<T>>& mas1)
{
	for (int i = 0; i < mas.size(); i++)
	{
		for (int j = 0; j < mas.size(); j++)
		{
			mas[i][j] += mas1[i][j];
		}
	}
}

int main()
{
	srand((unsigned)time(0));
	cout << "Vvedtite poryadok matritsy: ";
	int n; cin >> n;
	vector<vector<double>> mas1(n, vector<double>(n));
	vector<vector<double>> mas(n, vector<double>(n));

	make_no_empty_ans(mas);

	cout << "A1: \n";
	make_no_empty(mas1);
	out(mas1);
	sum(mas, mas1);

	cout << "A2: \n";
	mult_matrix(mas1, mas1);
	out(mas1);
	sum(mas, mas1);
	
	cout << "A4: \n";
	mult_matrix(mas1, mas1);
	out(mas1);
	sum(mas, mas1);

	cout << "A8: \n";
	mult_matrix(mas1, mas1);
	out(mas1);
	sum(mas, mas1);

	cout << "A1 + A2 + A4 + A8: \n";
	out(mas);




}