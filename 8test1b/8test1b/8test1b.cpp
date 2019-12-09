#include "8test1b_.h"
#include <iostream>
#include <stdlib.h>

int main()
{
	double m0[] = { 1, 2, 2 };
	double m1[] = { 2, 3, 5, 4 };
	pluar m(m0, 3);
	pluar mas(m1, 4);
	std::cout << m << '\n' << mas << '\n';
	pluar n = mas + m;
	n = m;
	std::cout << n << '\n';
	n.add(90);
	std::cout << n << '\n';
	n.remove(3);
	std::cout << n << '\n';
}