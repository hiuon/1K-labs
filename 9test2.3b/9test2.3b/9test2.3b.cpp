#include <iostream>
#include <vector>
#include <list>
#include <time.h>

using namespace std;

double _min(vector<double> k)
{
	double min = k.front() + k.back();
	for (int i = 0; i < k.size() / 2; ++i)
	{
		if (min > k.at(i) + k.at(k.size() - 1 - i))
		{
			min = k.at(i) + k.at(k.size() - 1 - i);
		}
	}
	return min;
}

double _min(list<double> k)
{
	double min = k.front() + k.back();
	list<double>::iterator s = k.begin();
	list<double>::reverse_iterator f = k.rbegin();
	for (int i = 0; i < k.size()/2; ++i)
	{
		if (min > *s + *f)
		{
			min = *s + *f;
		}
		s++;
		f++;
	}
	return min;
}

int main()
{
	srand((unsigned)(time(0)));
	int n;
	vector<double> k1;
	cout << " N = "; cin >> n; 
	for (int i = 0; i < 2 * n; i++)
	{
		double x = (rand() % 100) / 100.0;
		k1.push_back(x);
		cout << x << "  ";
	}
	double min = _min(k1);
	cout << '\n' << min << '\n';

	list<double> k2;
	cout << " N = "; cin >> n;
	for (int i = 0; i < 2 * n; i++)
	{
		double x = (rand() % 100) / 100.0;
		k2.push_back(x);
		cout << x << "  ";
	}
	min = _min(k2);
	cout << '\n' << min << '\n';
}