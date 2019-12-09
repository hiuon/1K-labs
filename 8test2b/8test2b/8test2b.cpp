#include "8test2b.h"

int h_num:: operator[](int n)
{
	if (n > rank || n < 0)
	{
		std::cout << "Error";
	}
	return *(number + n);
}

h_num h_num:: operator=(const h_num& obj)
{
	rank = obj.rank;
	delete[]number;
	number = new int[rank];
	for (int i = 0; i < rank; i++)
	{
		*(number + i) = *(obj.number + i);
	}
	return *this;
}

h_num operator+(const h_num& obj, const h_num& obj1)
{
	h_num n;
	int m;
	if (obj.rank > obj1.rank)
	{
		m = obj1.rank;
		n.rank = obj.rank;
		n.number = new int[n.rank];
		for (int i = 0; i < m; ++i)
		{
			*(n.number + i) = *(obj.number + i) + *(obj1.number + i);
		}
		for (int i = m; i < n.rank; ++i)
		{
			*(n.number + i) = *(obj.number + i);
		}
	}
	else
	{
		m = obj.rank;
		n.rank = obj1.rank;
		n.number = new int[n.rank];
		for (int i = 0; i < m; ++i)
		{
			*(n.number + i) = *(obj.number + i) + *(obj1.number + i);
		}
		for (int i = m; i < n.rank; ++i)
		{
			*(n.number + i) = *(obj1.number + i);
		}
	}
	for (int i = 0; i < n.rank - 1; ++i)
	{
		if (*(n.number + i) >= 100)
		{
			*(n.number + i + 1) += *(n.number + i) / 100;
			*(n.number + i) = *(n.number + i) % 100;
		}
	}
	if (*(n.number + n.rank - 1) >= 100)
	{
		int* nw = new int[n.rank + 1];
		for (int i = 0; i < n.rank - 1; ++i)
		{
			*(nw + i) = *(n.number + i);
		}
		*(nw + n.rank - 1) = *(n.number + n.rank - 1) % 100;
		*(nw + n.rank) = *(n.number + n.rank - 1) / 100;
		n.rank = n.rank + 1;
		delete[]n.number;
		n.number = nw;
	}
	
	return n;
}

h_num h_num:: operator++()
{
	*(number + 0) = *(number + 0) + 1;
	for (int i = 0; i < rank - 1; ++i)
	{
		if (*(number + i) >= 100)
		{
			*(number + i + 1) += *(number + i) / 100;
			*(number + i) = *(number + i) % 100;
		}
	}
	if (*(number + rank - 1) >= 100)
	{
		int* nw = new int[rank + 1];
		for (int i = 0; i < rank - 1; ++i)
		{
			*(nw + i) = *(number + i);
		}
		*(nw + rank - 1) = *(number + rank - 1) % 100;
		*(nw + rank) = *(number + rank - 1) / 100;
		rank = rank + 1;
		delete[]number;
		number = nw;
	}
	return *this;
}

h_num operator*(const h_num& obj, const h_num& obj1)
{
	h_num n;
	n.rank = obj.rank + obj1.rank;
	n.number = new int[n.rank];
	for (int i = 0; i < n.rank; ++i)
	{
		*(n.number + i) = 0;
	}
	for (int i = 0; i < obj.rank; ++i)
	{
		for (int j = 0; j < obj1.rank; ++j)
		{
			*(n.number + j + i) += *(obj.number + i) * *(obj1.number + j);
		}
	}
	for (int i = 0; i < n.rank - 1; ++i)
	{
		if (*(n.number + i) >= 100)
		{
			*(n.number + i + 1) += *(n.number + i) / 100;
			*(n.number + i) = *(n.number + i) % 100;
		}
	}
	if (*(n.number + n.rank - 1) >= 100)
	{
		int* nw = new int[n.rank + 1];
		for (int i = 0; i < n.rank - 1; ++i)
		{
			*(nw + i) = *(n.number + i);
		}
		*(nw + n.rank - 1) = *(n.number + n.rank - 1) % 100;
		*(nw + n.rank) = *(n.number + n.rank - 1) / 100;
		n.rank = n.rank + 1;
		delete[]n.number;
		n.number = nw;
	}
	int h = 0;
	for (int i = n.rank; i > 0; --i)
	{
		if (!*(n.number + i - 1))
		{
			h++;
		}
		else
		{
			break;
		}
	}
	if (h)
	{
		n.rank = n.rank - h;
		int* nw = new int[n.rank];
		for (int i = 0; i < n.rank; ++i)
		{
			*(nw + i) = *(n.number + i);
		}
		delete[]n.number;
		n.number = nw;
	}
	return n;
}

