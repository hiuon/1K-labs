#pragma once
#include <iostream>
class vector
{
	int s;
	int* vec;
public:
	vector():s(0), vec(NULL){}

	vector(int* mas, int si)
	{
		s = si;
		vec = new int[s];
		for (int i = 0; i < s; ++i)
		{
			*(vec + i) = *(mas + i);
		}
	}

	vector(int si)
	{
		vec = new int[si];
		s = si;
		for (int i = 0; i < s; ++i)
		{
			*(vec + i) = 0;
		}
	}

	vector(const vector& obj)
	{
		vec = new int[obj.s];
		s = obj.s;
		for (int i = 0; i < s; ++i)
		{
			*(vec + i) = *(obj.vec + i);
		}
	}

	~vector()
	{
		if (vec)
		{
			delete[]vec;
		}
	}

	vector size(int si);

	int size();

	vector random();

	friend std::ostream& operator<< (std::ostream& out, const vector& obj)
	{
		out << '(';
		for (int i = 0; i < obj.s; i++)
		{
			out << ' ' << *(obj.vec + i);
		}
		out << " )";
		return out;
	}

	friend std::istream& operator>> (std::istream& in, const vector& obj)
	{
		for (int i = 0; i < obj.s; i++)
		{
			in >> *(obj.vec + i);
		}
		return in;
	}

	int& operator[](int n);

	vector operator()(int n);
};
