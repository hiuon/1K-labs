#include "8test4b.h"
#include <iostream>

using namespace std;

template <typename T>
void del(list<T>& obj, list<T> obj1);

int main()
{
	char mas[] = "asdfgh";
	char mas1[] = "d";
	list<char> m(6, mas);
	list<char> k(2, mas1);
	del(m, k);
	cout << m << '\n';
	m.add('c');
	cout << m;

}