#pragma once
#include <iostream>
#include <iomanip>

template <typename T> class matrix
{
	static int counter;
	int count;
	int size;
	class vector
	{
	public:
		T* vec;
		int size;

		vector()
		{
			size = 0;
			vec = nullptr;
		}

		vector(int si)
		{
			vec = new T[si];
			size = si;
			for (int i = 0; i < size; ++i)
			{
				*(vec + i) = 0;
			}
		}

		vector(const vector& obj)
		{
			size = obj.size;
			vec = new T[size];
			for (int i = 0; i < size; ++i)
			{
				*(vec + i) = *(obj.vec + i);
			}
		}

		vector resize(int n)
		{
			T* temp = new T[n];
			int c;
			if (n > size)
			{
				c = size;
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
			size = n;
			vec = temp;
			return *this;
		}

		T& operator[](int n)
		{
			try
			{
				if (n >= size || n < 0)
				{
					throw Errors();
				}
				int m = *(vec + 3);
				return *(vec + n);
			}
			catch (Errors)
			{
				std::cout << "Out of range";
				system("pause");
			}
		}

	};
	vector* mas;
public:
	class Errors {};

	matrix()
	{
		counter++;
		count = counter;
		size = 0;
		mas = nullptr;
	}

	matrix(int n1, int n2)
	{
		counter++;
		count = counter;
		mas = new vector[n1];
		size = n1;
		for (int i = 0; i < size; ++i)
		{
			*(mas + i) = matrix<T>::vector(n2);
		}
	}

	matrix(const matrix<T>& obj)
	{
		counter++;
		count = counter;
		mas = new vector[obj.size];
		size = obj.size;
		for (int i = 0; i < size; ++i)
		{
			*(mas + i) = matrix<T>::vector(*(obj.mas + i));
		}
	}
	
	~matrix()
	{
		if (mas)
		{
			for (int i = 0; i < size; ++i)
			{
				delete[]mas[i].vec;
			}
			delete[]mas;
			counter--;
		}
	}

	matrix<T>::vector& operator[](int n)
	{
		try
		{
			if (n >= size || n < 0)
			{
				throw Errors();
			}
			return *(mas + n);
		}
		catch (Errors)
		{
			std::cout << "Out of range";
			system("pause");
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const matrix<T>& obj)
	{
		out << "Matrix " << obj.count << '\n';
		for (int i = 0; i < obj.size; ++i)
		{
			for (int j = 0; j < obj.mas->size; ++j)
			{
				out << std::setw(15) << *((obj.mas + i)->vec + j);
			}
			out << '\n';
		}
		return out;
	}

	friend std::istream& operator>>(std::istream& in, const matrix<T>& obj)
	{
		for (int i = 0; i < obj.size; ++i)
		{
			for (int j = 0; j < obj.mas->size; ++j)
			{
				in >> *((obj.mas + i)->vec + j);
			}
		}
		return in;
	}

	friend matrix<T> operator+(const matrix<T>& obj, const matrix<T>& obj1)
	{
		try
		{
			if (obj.size != obj1.size || obj.mas->size != obj1.mas->size)
			{
				throw Errors();
			}
		}
		catch (Errors)
		{
			std::cout << "Matrixes have dif. sizes";
			std::system("pause");
			return obj;
		}
		int n1 = obj.size;
		int n2 = obj.mas->size;
		matrix<T> mn(n1, n2);
		for (int i = 0; i < n1; ++i)
		{
			for (int j = 0; j < n2; ++j)
			{
				*((mn.mas + i)->vec + j) = *((obj.mas + i)->vec + j) + *((obj1.mas + i)->vec + j);
			}
		}
		return mn;
	}

	matrix<T> operator=(const matrix<T>& obj)
	{
		size = obj.size;
		int n2 = obj.mas->size;
		mas = new vector[size];
		for (int i = 0; i < size; ++i)
		{
			*(mas + i) = matrix<T>::vector(n2);
		}
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < n2; ++j)
			{
				*((mas + i)->vec + j) = *((obj.mas + i)->vec + j);
			}
		}
		return *this;
	}

	friend matrix<T> operator*(const matrix<T>& obj, const matrix<T>& obj1)
	{
		try
		{
			if (obj.mas->size != obj1.size)
			{
				throw Errors();
			}
			matrix temp(obj.size, obj1.mas->size);
			for (int i = 0; i < obj.mas->size; ++i)
			{
				for (int j = 0; j < obj1.size; ++j)
				{
					for (int k = 0; k < obj1.size; ++k)
					{
						*((temp.mas + i)->vec + j) += *((obj.mas + i)->vec + k) * *((obj1.mas + k)->vec + j);
					}
				}
			}
			return temp;

		}
		catch (Errors())
		{
			std::cout << "Matrixes have dif. sizes";
			std::system("pause");
		}
	}

	matrix<T> pow(matrix& obj, int k)
	{
		if (k == 1)
		{
			*this = obj;
			return *this;
		}
		try
		{
			if (obj.size != obj.mas->size)
			{
				throw Errors();
			}
			matrix temp(obj);
			for (int y = 0; y < k - 1; ++y)
			{
				temp = temp * obj;
			}
			*this = temp;
			return *this;
		}
		catch (Errors)
		{
			std::cout << "Matrix has bad size or not odd p";
			std::system("pause");
		}
	}

	matrix<T> resize(int n1, int n2)
	{
		vector* temp = new vector[n1];
		int c;
		if (n1 > size)
		{
			c = size;
			for (int i = 0; i < c; ++i)
			{
				T* temp1 = new T[n2];
				int c1 = mas[i].size;
				if (n2 > mas[i].size)
				{
					
					for (int j = 0; j < c1; ++j)
					{
						*(temp1 + j) = *(mas[i].vec + j);
					}
					for (int j = c1; j < n2; ++j)
					{
						*(temp1 + j) = 0;
					}
				}
				else
				{
					c1 = n2;
					for (int j = 0; j < c1; ++j)
					{
						*(temp1 + j) = *(mas[i].vec + j);
					}
				}
				temp[i].vec = temp1;
				temp[i].size = n2;
			}
			for (int i = c; i < n1; ++i)
			{
				T* temp1 = new T[n2];
				int c1 = mas[i].size;
				for (int j = 0; j < n2; ++j)
				{
					*(temp1 + j) = 0;
				}
				temp[i].vec = temp1;
				temp[i].size = n2;
			}
		}
		else
		{
			c = n1;
			for (int i = 0; i < n1; ++i)
			{
				T* temp1 = new T[n2];
				for (int j = 0; j < n2; ++j)
				{
					*(temp1 + i) = *(mas[i].vec + j);
				}
				temp[i].vec = temp1;
				temp[i].size = n2;
			}
		}
		for (int i = 0; i < size; ++i)
		{
			delete[]mas[i].vec;
		}
		delete[]mas;
		mas = temp;
		size = n1;
		return *this;
	}
};
