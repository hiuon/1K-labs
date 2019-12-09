#pragma once
#include <iostream>

template <typename T>
struct node
{
	T data;
	node* next;
	node* prev;
};

template <typename T>
class dlist
{
	node<T>* top;
	node<T>* end;
public:
	class LErrors {};

	dlist()
	{
		top = end = nullptr;
	}

	dlist(int n)
	{
		top = nullptr;
		end = nullptr;
		try
		{
			if (n <= 0)
			{
				throw LErrors();
			}
			for (int i = 0; i < n; ++i)
			{
				node<T>* nv = new node<T>;
				nv->data = 0;
				nv->next = nullptr;
				if (!top)
				{
					nv->prev = nullptr;
					top = nv;
					end = nv;
				}
				else
				{
					end->next = nv;
					nv->prev = end;
					end = nv;
					end->next = nullptr;
				}
			}
		}
		catch (LErrors)
		{
			std::cout << "Bad size";
			std::system("pause");
		}
	}

	dlist(int n, T* d)
	{
		top = nullptr;
		end = nullptr;
		try
		{
			if (n <= 0)
			{
				throw LErrors();
			}
			for (int i = 0; i < n; ++i)
			{
				node<T>* nv = new node<T>;
				nv->data = *(d + i);
				nv->next = nullptr;
				if (!top)
				{
					nv->prev = nullptr;
					top = nv;
					end = nv;
				}
				else
				{
					end->next = nv;
					nv->prev = end;
					end = nv;
					end->next = nullptr;
				}
			}
		}
		catch (LErrors)
		{
			std::cout << "Bad size";
			std::system("pause");
		}
	}

	dlist(dlist<T>& obj)
	{
		node<T>* ppv = obj.top;
		top = nullptr;
		end = nullptr;
		while (ppv)
		{ 
			node<T>* nv = new node<T>;
			nv->data = ppv->data;
			nv->next = nullptr;
			if (!top)
			{
				nv->prev = nullptr;
				top = nv;
				end = nv;
			}
			else
			{
				end->next = nv;
				nv->prev = end;
				end = nv;
				end->next = nullptr;
			}
			ppv = ppv->next;
		}
	}

	~dlist()
	{
		node<T>* nw;
		while (top)
		{
			nw = top->next;
			delete top;
			top = nw;
		}
	}

	node<T>*& TInitFirst()
	{
		return top;
	}

	node<T>*& EInitFirst()
	{
		return end;
	}

	node<T>* find(T d)
	{
		node<T>* ppv = top;
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
		return nullptr;
	}

	void add(T d)
	{
		node<T>* nv = new node<T>;
		nv->data = d;
		nv->next = nullptr;
		if (!top)
		{
			nv->prev = nullptr;
			top = nv;
			end = nv;
		}
		else
		{
			end->next = nv;
			nv->prev = end;
			end = nv;
			end->next = nullptr;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const dlist<T>& obj)
	{
		node<T>* nw = obj.top;
		while (nw)
		{
			out << nw->data << ' ';
			nw = nw->next;
		}
		return out;
	}

	friend std::istream& operator>>(std::istream& in, const dlist<T>& obj)
	{
		node<T>* nw = obj.top;
		while (nw)
		{
			in >> nw->data;
			nw = nw->next;
		}
		return in;
	}

	void del(T key)
	{
		while (find(key))
		{
			node<T>* pv, * ppv;
			ppv = find(key);
			pv = ppv->prev;

			if (ppv)
			{
				if (top->data == key)
				{
					pv = top;
					top = top->next;
					if (top)
					{
						top->prev = nullptr;
					}
					else
					{
						end = nullptr;
					}
				}
				else
				{
					pv->next = ppv->next;
					if (pv->next)
					{
						pv->prev = nullptr;
						pv->next->prev = pv;
					}
					else
					{
						end = ppv;
					}
				}
				delete ppv;
			}
		}
	}

	void del()
	{
		node<T>* nw;
		while (top)
		{
			nw = top->next;
			delete top;
			top = nw;
		}
	}

	T start(int n)
	{
		node<T>* nw = top;
		for (int i = 0; i < n; ++i)
		{
			nw = nw->next;
		}
		return nw->data;
	}

	T finish(int n)
	{
		node<T>* nw = end;
		for (int i = 0; i < n; ++i)
		{
			nw = nw->prev;
		}
		return nw->data;
	}
};
