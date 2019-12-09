#include "vector.h"
vector vector::size(int si)
{
	s = si;
	vec = new int[s];
	return *this;
}

int vector::size()
{
	return s;
}

vector vector::random()
{
	for (int i = 0; i < s; ++i)
	{
		*(vec + i) = rand() % 800 - 500;
	}
	return *this;
}

int& vector::operator[](int n)
{
	if (n < 0 || n >= s)
	{
		std::cout << "Error. Out of range";
		std::system("pause");
		return n;
	}
	else
	{
		return *(vec + n);
	}
}

vector vector::operator()(int n)
{
	int* temp = new int[n];
	int c;
	if (n > s)
	{
		c = s;
		for (int i = 0; i < c; ++i)
		{
			*(temp + i) = *(vec + i);
		}
		for (int i = c; i < n; ++i)
		{
			*(temp + i) = 0;
		}

	}
	else
	{
		c = n;
		for (int i = 0; i < c; ++i)
		{
			*(temp + i) = *(vec + i);
		}
	}
	delete[]vec;
	s = n;
	vec = temp;
	return *this;
}
	