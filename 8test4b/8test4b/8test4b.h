#pragma once
#include <iostream>
template <typename T>
 struct l
{
	T data;
	l* next;
};
template <typename T>
class list
{
	l<T>* L;
public:
	class ErrorL {};

	list()
	{
		l* nw = new l;
		L = nw;
		L->data = 0;
		L->next = nullptr;
	}

	list(int n, T* info)
	{
		try
		{
			if (n <= 0)
			{
				throw ErrorL();
			}
		}
		catch (list::ErrorL)
		{
			std::cout << "Bad int";
			std::system("pause");
		}
		l<T>* nw = new l<T>;
		L = nw;
		L->data = *(info);
		L->next = nullptr;
		for (int i = 0; i < n - 1; ++i)
		{
			l<T>* ppv = L;
			l<T>* nv = new l<T>;
			nv->next = nullptr;
			nv->data = *(info + i + 1);
			if (L == nullptr)
			{
				L = nv;
			}
			else
			{
				while (ppv->next != nullptr)
				{
					ppv = ppv->next;
				}
				ppv->next = nv;
			}
		}
	}

	list(list<T>& obj)
	{
		l<T>* pv = obj.L;
		l<T>* nv = new l<T>;
		l<T>* nw = nv;
		while (pv)
		{
			nv->data = pv->data;
			pv = pv->next;
			if (pv)
			{
				nv->next = new l<T>;
				nv = nv->next;
			}
			else
			{
				nv->next = nullptr;
			}

		}
		L = nw;
	}

	~list()
	{
		l<T>* nw;
		while (L)
		{
			nw = L->next;
			delete L;
			L = nw;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const list<T>& obj)
	{
		l<T>* nw = obj.L;
		while (nw)
		{
			out << nw->data << ' ';
			nw = nw->next;
		}
		return out;
	}

	friend std::istream& operator>>(std::istream& in, const list<T>& obj)
	{
		l<T>* nw = obj.L;
		while (nw)
		{
			in >> nw->data;
			nw = nw->next;
		}
		return in;
	}

	l<T>*& InitFirst()
	{
		 return L;
	}

	void add(T d)
	{
		l<T>* nv = new l<T>;
		l<T>* ppv = L;
		nv->next = NULL;
		nv->data = d;
		if (!L)
		{
			L = nv;
		}
		else
		{
			while (ppv->next)
			{
				ppv = ppv->next;
			}
			ppv->next = nv;
		}
	}

	void del(T d)
	{
		l<T>* ppv = L;
		l<T>* nw = new l<T>;
		while (ppv)
		{
			if (ppv->data == d)
			{
				L = ppv->next;
				delete ppv;
			}
			else
			{
				while (ppv)
				{
					if (ppv->data == d)
					{
						nw->next = ppv->next;
						delete ppv;
						ppv = nw->next;
						break;
					}
					nw = ppv;
					ppv = ppv->next;
				}
			}
		}
	}

	void del()
	{
		l<T>* nw;
		while (L)
		{
			nw = L->next;
			delete L;
			L = nw;
		}
	}

	l<T>* find(T d)
	{
		l<T>* ppv = L;
		while (ppv)
		{
			if (ppv->data == d)
			{
				return ppv;
			}
			else
			{
				while (ppv)
				{
					if (ppv->data == d)
					{
						return ppv;
					}
					ppv = ppv->next;
				}
			}
		}
	}
};

template <typename T>
void del(list<T>& li, l<T>* s, l<T>* f)
{
	l<T>* ppv = li.InitFirst();
	bool check = false;
	if (li.InitFirst() == s)
	{
		check = true;
	}
	while (ppv)
	{
		if (check)
		{
			while (s != f)
			{
				l<T>* tmp = s->next;
				delete s;
				s = tmp;
			}
			li.InitFirst() = f->next;
			break;
		}
		else if (ppv->next == s)
		{
			l<T>* pv = ppv->next;
			l<T>* tmp = ppv->next;
			ppv->next = f->next;
			while (pv != f)
			{
				pv = pv->next;
				delete tmp;
				tmp = pv->next;
			}

		}
		ppv = ppv->next;
	}
}

template <typename T>
void del(list<T>& obj, list<T> obj1)
{
	l<T>* ppv = obj.InitFirst();
	l<T>* pv = obj1.InitFirst();
	l<T>* start = nullptr;
	l<T>* finish = nullptr;
	bool check = false;
	while (ppv)
	{
		start = ppv;
		while (pv)
		{
			if (pv->data == ppv->data)
			{
				check = true;
				finish = ppv;
				pv = pv->next;
				ppv = ppv->next;
			}
			else
			{
				check = false;
				pv = obj1.InitFirst();
				break;
			}
		}
		if (check)
		{
			del(obj, start, finish);
			pv = obj1.InitFirst();
		}
		else if (start == finish)
		{
			del(obj, start, finish);
			pv = obj1.InitFirst();
		}

		if (ppv)
		{
			ppv = ppv->next;
		}
		else
		{
			break;
		}
	}
}

