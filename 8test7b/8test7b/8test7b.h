#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct SP
{
	T data;
	SP<T>* next;
};

template <typename T>
struct GRAF
{
	T data;
	SP<T>* top_sp;
	GRAF<T>* next;
};

template <typename T>
class graf
{
	GRAF<T>* top;
	int size;
public:
	graf()
	{
		top = nullptr;
		size = 0;
	}

	graf(int n)
	{
		size = n;
		for (int i = 0; i < n; ++i)
		{
			GRAF<T>* pv = new GRAF<T>;
			pv->data = i + 1;
			pv->top_sp = nullptr;
			pv->next = nullptr;
			if (!top)
			{
				top = pv;
			}
			else
			{
				GRAF<T>* ppv = top;
				while (ppv->next)
				{
					ppv = ppv->next;
				}
				ppv->next = pv;
			}
		}
		for (int j = 1; j <= n; ++j)
		{
			for (int i = 1; i <= n; ++i)
			{
				if (i != j)
				{
					addPath(top, j, i);
				}
			}
		}
	}

	graf(graf<T>& obj)
	{
		size = obj.size;
		GRAF<T>* pv = obj.top;
		GRAF<T>* ppv = new GRAF<T>;
		while (pv)
		{
			GRAF<T>* temp_g = new GRAF<T>;
			temp_g->next = nullptr;
			ppv->data = pv->data;
			ppv->next = temp_g;
			if (pv->top_sp)
			{
				SP<T>* nnv = new SP<T>;
				SP<T>* nv = pv->top_sp;
				ppv->top_sp = nnv;
				while (nv)
				{
					SP<T>* temp_s = new SP<T>;
					temp_s->next = nullptr;
					nnv->next = temp_s;
					nnv->data = nv->data;
					if (nv->next == nullptr)
					{
						delete temp_s;
						nnv->next = nullptr;
					}
					nnv = nnv->next;
					nv = nv->next;
					
				}
			}
			else
			{
				ppv->top_sp = nullptr;
			}

			if (top)
			{
				GRAF<T>* Y = top;
				while (Y->next)
				{
					Y = Y->next;
				}
				Y = ppv;
				if (pv->next == nullptr)
				{
					delete temp_g;
					ppv->next = nullptr;
				}
				ppv = ppv->next;
			}
			else
			{
				if (pv->next == nullptr)
				{
					delete temp_g;
					ppv->next = nullptr;
				}
				top = ppv;
				ppv = ppv->next;
			}
			pv = pv->next;
		}
	}

	~graf()
	{
		GRAF<T>* ppv = top;
		while (ppv)
		{
			SP<T>* pv = ppv->top_sp;
			{
				while (pv)
				{
					pv = pv->next;
					delete ppv->top_sp;
					ppv->top_sp = pv;
				}
			}
			ppv = ppv->next;
			delete top;
			top = ppv;
		}
	}

	void add()
	{
		int jk;
		std::cout << "\nVvedite nomer vershiny: "; cin >> jk;
		std::cout << "\nSkolko iskhodyascikh?" << endl;
		int o;
		cin >> o;
		GRAF<T>* nv = new GRAF<T>;
		nv->data = jk;
		nv->top_sp = nullptr;
		nv->next = nullptr;
		if (!top)
		{
			top = nv;
		}
		else
		{
			GRAF<T>* p = top;
			GRAF<T>* pv = top;
			while (p && p->data < jk)
			{
				pv = p;
				p = p->next;
			}
			nv->next = p;
			pv->next = nv;
		}
		cout << "Vvedite " << endl;
		for (int i = 0; i < o; i++)
		{
			int u;
			cin >> u;
			addPath(top, jk, u);
		}
		/*cout << "\nSkolko vhodyaschikh?" << endl;
		o = 0;
		cin >> o;
		cout << "Vvedite " << endl;
		for (int i = 0; i < o; i++)
		{
			int u;
			cin >> u;
			addPath(top, u, jk);
		}*/
		size++;
	}

	void addPath(GRAF<T>* top, T x, T y)
	{
		GRAF<T>* p = _find(top, x);
		SP<T>* nv = new SP<T>;
		nv->data = y;
		nv->next = nullptr;
		if (!p->top_sp)
		{
			p->top_sp = nv;
		}
		else
		{
			SP<T>* pp = p->top_sp;
			SP<T>* pv = pp;
			bool check = true;
			while (pp)
			{
				if (pp->data == y)
				{
					check = false;
				}
				pp = pp->next;
			}
			pp = p->top_sp;
			if (check)
			{
				while (pp && pp->data < y)
				{
					pv = pp;
					pp = pp->next;
				}
				nv->next = pp;
				pv->next = nv;
			}
		}
	}

	GRAF<T>* _find(GRAF<T>* top, T key)
	{
		while (top && top->data != key)
		{
			top = top->next;
		}
		return top;
	}

	void _print()
	{
		GRAF<T>* p = top;
		while (p)
		{
			cout << p->data << ": ";
			SP<T>* p1 = p->top_sp;
			while (p1)
			{
				cout << p1->data << ' ';
				p1 = p1->next;
			}
			cout << '\n';
			p = p->next;
		}
		cout << "----------------------------------------------------------\n";
	}

	void del_el(T key)
	{
		GRAF<T>* p = top;
		GRAF<T>* ppv = new GRAF<T>;
		while (p)
		{
			if (p->data == key)
			{
				ppv->next = ppv->next->next;
				delete p;
				break;
			}
			ppv = p;
			p = p->next;
		}
		p = top;
		while (p)
		{
			SP<T>* p1 = p->top_sp;
			SP<T>* ppp1 = new SP<T>;
			while (p1)
			{
				if (p1->data == key)
				{
					ppp1->next = ppp1->next->next;
					delete p1;
					break;
				}
				ppp1 = p1;
				p1 = p1->next;
			}
			p = p->next;
		}
		size--;
	}

	void find_source()
	{
		cout << "Sources: \n";
		GRAF<T>* p = top;
		while (p)
		{
			SP<T>* pp = p->top_sp;
			int c = 0;
			while (pp)
			{
				c++;
				pp = pp->next;
			}
			if (c == size - 1)
			{
				cout << p->data << ": ";
				pp = p->top_sp;
				while (pp)
				{
					cout << pp->data << ' ';
					pp = pp->next;
				}
				cout << '\n';
			}
			p = p->next;
		}
		cout << "----------------------------------------------------------\n";
	}

	void find_stock()
	{
		cout << "Stocks: \n";
		GRAF<T>* p = top;
		int* check = new int[size];
		for (int i = 0; i < size; ++i)
		{
			*(check + i) = 0;
		}
		while (p)
		{
			SP<T>* pp = p->top_sp;
			while (pp)
			{
				int k = pp->data;
				check[k - 1]++;
				pp = pp->next;
			}
			p = p->next;
		}
		p = top;
		int y = 0;
		while (p)
		{
			if (check[y] == size - 1)
			{
				cout << p->data << "  ";
			}
			p = p->next;
			y++;
		}
		cout << "\n----------------------------------------------------------\n";
	}
};
