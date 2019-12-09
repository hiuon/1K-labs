#include "8test6b.h"
#include <iostream>

using namespace std;

int main()
{
	int mas[] = { 4, 2, 5, 4, 15, 3, 2, 6, 4, 3 };
	tree<int> d(mas, sizeof(mas)/(sizeof(int)));
	TREE<int>* ppv = search_el(d, 2);
	d.out();
	cout << "'''''''''''''''''\n";
	del_all_list(d);
	cout << "'''''''''''''''''\n";
	d.out();
}