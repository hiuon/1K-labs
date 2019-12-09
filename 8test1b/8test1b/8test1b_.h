#pragma once
#include <iostream>

class pluar
{
public:
	double* mas;
	int size;
	pluar()
	{
		mas = NULL;
		size = 0;
	}

	pluar(double* m, int s)
	{
		bool* check = new bool[s];
		int counter = s;
		for (int i = 0; i < s; ++i)
		{
			for (int j = i + 1; j < s; ++j)
			{
				if (*(m + i) == *(m + j))
				{
					check[i] = false;
					counter--;
					break;
				}
				else
				{
					check[i] = true;
				}
			}
		}
		double* d = new double[s];
		for (int i = 0, j = 0; i < s; i++)
		{
			if (check[i])
			{
				*(d + j) = *(m + i);
				j++;
			}
		}
		delete[] check;
		size = counter;
		mas = d;
	}

	pluar(const pluar &obj)
	{
		mas = new double[obj.size];
		size = obj.size;
		for (int i = 0; i < obj.size; ++i)
		{
			*(mas + i) = *(obj.mas + i);
		}
	}

	pluar supp(const pluar& obj, const pluar& obj1)
	{
		int counter = 0;
		int s = obj.size;
		int s1 = obj1.size;
		bool* check = new bool[s];
		for (int i = 0; i < s; ++i)
		{
			for (int j = 0; j < s1; ++j)
			{
				if (*(obj.mas + i) == *(obj1.mas + j))
				{
					counter++;
					check[i] = true;
					break;
				}
				else
				{
					check[i] = false;
				}
			}
		}
		int size = counter;
		mas = new double[size];

		for (int i = 0, j = 0; i < s; ++i)
		{
			if (check[i])
			{
				*(mas + j) = *(obj.mas + i);
				j++;
			}
		}


		delete[] check;
		return *this;
	}

	pluar add(double* m, int s)
	{
		for (int i = 0; i < s; ++i)
		{
			bool check = true;
			for (int j = 0; j < size; ++j)
			{
				if (*(m + i) == *(mas + j))
				{
					check = false;
					break;
				}
			}

			if (check)
			{
				int k = size;
				size++;
				double* mas1 = new double[size];
				for (int i = 0; i < k; ++i)
				{
					*(mas1 + i) = *(mas + i);
				}
				*(mas1 + size - 1) = *(m + i);
				delete[]mas;
				mas = mas1;
			}
		}
		return *this;
	}

	pluar add(double d)
	{
		bool check = true;
		for (int i = 0; i < size; ++i)
		{
			if (*(mas + i) == d)
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			size++;
			double* mas1 = new double[size];
			for (int i = 0; i < size - 1; ++i)
			{
				*(mas1 + i) = *(mas + i);
			}
			*(mas1 + size - 1) = d;
			delete[]mas;
			mas = mas1;
		}
		return *this;
	}

	pluar remove(double d)
	{
		int k = size - 1;
		double* mas1 = new double[k];
		bool check = false;
		for (int i = 0, j = 0; i < size; ++i)
		{
			if (*(mas + i) == d)
			{
				check = true;
			}
			else
			{
				*(mas1 + j) = *(mas + i);
				j++;
			}
		}
		if (check)
		{
			size = k;
			delete[]mas;
			mas = mas1;
		}
		else
		{
			delete[]mas1;
		}
		return *this;
		
	}

	friend std::ostream& operator<< (std::ostream& out, const pluar& obj)
	{
		for (int i = 0; i < obj.size; i++)
		{
			out << ' ' << *(obj.mas + i);
		}
		return out;
	}

	friend std::istream& operator>> (std::istream& in, const pluar& obj)
	{
		for (int i = 0; i < obj.size; i++)
		{
			in >> *(obj.mas + i);
		}
		return in;
	}

	friend pluar operator+(const pluar& obj, const pluar& obj1)
	{
		pluar n;
		int counter = 0;
		int s = obj.size;
		int s1 = obj1.size;
		bool* check = new bool[s];
		for (int i = 0; i < s; ++i)
		{
			for (int j = 0; j < s1; ++j)
			{
				if (*(obj.mas + i) == *(obj1.mas + j))
				{
					counter++;
					check[i] = false;
					break;
				}
				else
				{
					check[i] = true;
				}
			}
		}
		int size_s = s + s1 - counter;
		double* mas1 = new double[size_s];

		for (int j = 0; j < s1 + s - counter; ++j)
		{
			if (j < s1)
			{
				*(mas1 + j) = *(obj1.mas + j);
			}
			else
			{
				for (int i = 0; i < s; ++i)
				{
					if (check[i])
					{
						*(mas1 + j) = *(obj.mas + i);
						j++;
					}
				}
			}
		}

		n.size = size_s;
		n.mas = mas1;
		delete[] check;
		return n;
	}


	friend pluar operator-(const pluar& obj, const pluar& obj1)
	{
		pluar n;
		int counter = 0;
		int s = obj.size;
		int s1 = obj1.size;
		bool* check = new bool[s];
		for (int i = 0; i < s; ++i)
		{
			for (int j = 0; j < s1; ++j)
			{
				if (*(obj.mas + i) == *(obj1.mas + j))
				{
					counter++;
					check[i] = false;
					break;
				}
				else
				{
					check[i] = true;
				}
			}
		}
		int size_s = s - counter;
		double* mas1 = new double[size_s];

		for (int j = 0, i = 0; j < s; ++j)
		{
			if (check[j])
			{
				*(mas1 + i) = *(obj.mas + j);
				i++;
			}
		}
		n.size = size_s;
		n.mas = mas1;
		delete[] check;
		return n;
	}

	pluar operator=(const pluar& obj)
	{
		mas = new double[obj.size];
		size = obj.size;
		for (int i = 0; i < obj.size; ++i)
		{
			*(mas + i) = *(obj.mas + i);
		}
		return *this;
	}

	~pluar()
	{
		if (!mas)
		{
			delete[] mas;
		}
	}
};

