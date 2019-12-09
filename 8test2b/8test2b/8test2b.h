#pragma once
#include <iostream>
#include <string>
class h_num
{
	int rank;
	int* number;
public:
	h_num():rank(1), number(new int[1])
	{
		*(number + 0) = 0;
	}

	h_num(int num)
	{
		rank = 0;
		int c = num;
		while (c)
		{
			c /= 100;
			rank++;
		}
		number = new int[rank];
		for (int i = 0, c = num; i < rank; ++i)
		{
			*(number + i) = c % 100;
			c /= 100;
		}
	}

	h_num(const h_num& obj)
	{
		rank = obj.rank;
		number = new int[rank];
		for (int i = 0; i < obj.rank; ++i)
		{
			*(number + i) = *(obj.number + i);
		}
	}

	~h_num()
	{
		if (number)
		{
			delete[]number;
		}
	}

	friend std::ostream& operator<< (std::ostream& out, const h_num& obj)
	{
		for (int i = obj.rank; i > 0; --i)
		{
			out << *(obj.number + i - 1);
			if (i > 1)
			{
				out << '.';
			}
		}
		return out;
	}

	friend std::istream& operator>> (std::istream& in, h_num& obj)
	{
		std::string s, c = "";
		std::cin >> s;
		int k = 0;
		int h = 0;
		int l = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s.at(i) == '.')
			{
				k++;
				l = 0;
			}
			else
			{
				l++;
				if (l > 2)
				{
					std::cout << "Error input";
					l = 0;
					break;
				}	
				obj.number = new int[k + 1];
				obj.rank = k + 1;
			}
		}
		if (l)
		{
			while (k + 1)
			{
				for (int j = h; j < s.length(); ++j)
				{
					if (s.at(j) == '.')
					{
						break;
					}
					else
					{
						c += s.at(j);
						h++;
					}
				}
				obj.number[k] = std::atoi(c.c_str());
				h++;
				k--;
				c.clear();
			}
		}
		return in;
	}

	h_num operator=(const h_num& obj);
	int operator[](int n);
	friend h_num operator+(const h_num& obj, const h_num& obj1);
	friend h_num operator*(const h_num& obj, const h_num& obj1);
	h_num operator++();
};
