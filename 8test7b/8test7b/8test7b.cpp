#include <iostream>
#include "8test7b.h"

using namespace std;

int main()
{
	graf<int> g;
	int k;
	cout << "Vvedite chislo elementov grafa: "; cin >> k;
	for (int i = 0; i < k; ++i)
	{
		g.add();
	}
	g._print();
	graf<int> j(g);
	j._print();
	j.find_source();
	j.find_stock();
	j.del_el(3);
}

/*void initGRAF(GRAF*&, int);
void add(GRAF*&, int);
void addPath(GRAF*, int, int);
GRAF* _find(GRAF*, int);
void _print(GRAF*);
void find_source(GRAF*, int);
void find_stock(GRAF*, int);

int main()
{

	GRAF* top = NULL;
	int n, m;
	initGRAF(top, 6);
	addPath(top, 1, 2);
	addPath(top, 1, 3);
	addPath(top, 1, 4);
	addPath(top, 3, 2);
	addPath(top, 4, 2);
	addPath(top, 5, 2);
	addPath(top, 6, 2);
	cout << "Hotite dobavit' element(y/n)?" << endl;
	char l1;
	cin >> l1;
	if (l1 == 'y')
    {
	    add(top, 7);
	    cout << "Skolko iskhodyascikh?" << endl;
	    int o;
	    cin >> o;
        cout << "Vvedite " << endl;
	    for (int i = 0; i < o; i++)
        {
            int u;
            cin >> u;
            addPath(top, 7, u);
        }
        cout<< "Skolko vhodyaschikh?" << endl;
	    o = 0;
	    cin >> o;
	    cout << "Vvedite " << endl;
	    for (int i = 0; i < o; i++)
        {
            int u;
            cin >> u;
            addPath(top, u, 7);
        }
    }
    _print(top);
    cout << "Istochniki: ";
	find_source(top, 7);
	cout << "Stocki: ";
	find_stock(top, 7);
    return 0;
}

void initGRAF(GRAF* &top, int n)
{
	for (int i = 0; i < n; i++)
    {
		add(top, i + 1);
	}
}

void add(GRAF* &top, int key)
{
	GRAF* nv = new GRAF;
	nv->data = key;
	nv->top_sp = NULL;
	nv->next = NULL;
	if (!top)
    {
		top = nv;
	}
	else
    {
		GRAF* p = top;
		GRAF* pv = top;
		while (p && p->data < key)
		{
			pv = p;
			p = p->next;
		}
		nv->next = p;
		pv->next = nv;
	}
}

void addPath(GRAF* top, int x, int y)
{
	GRAF* p = _find(top, x);
	SP* nv = new SP;
	nv->data = y;
	nv->next = NULL;
	if (!p->top_sp)
    {
		p->top_sp = nv;
	}
	else
    {
		SP* pp = p->top_sp;
		SP* pv = pp;
		while (pp && pp->data < y)
        {
			pv = pp;
			pp = pp->next;
		}
		nv->next = pp;
		pv->next = nv;
	}
}

GRAF* _find(GRAF* top, int key)
{
	while (top && top->data != key)
    {
		top = top->next;
	}
	return top;
}

void _print(GRAF* top)
{
	while (top)
    {
		cout << top->data << ": ";
		SP* p = top->top_sp;
		while (p)
        {
			cout << p->data << ' ';
			p = p->next;
		}
		cout << '\n';
		top = top->next;
	}
}

void find_source(GRAF* top, int size)
{
	GRAF* p = top;
	while (p)
    {
		SP* pp = p->top_sp;
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
		}
		p = p->next;
	}
}

void find_stock(GRAF* top, int size)
{
	GRAF* p = top;
	int* check = new int[size];
	for (int i = 0; i < size; ++i)
	{
		*(check + i) = 0;
	}
	while (p)
	{
		SP* pp = p->top_sp;
		while (pp)
		{
			check[pp->data]++;
			pp = pp->next;
		}
		p = p->next;
	}
	for (int i = 0; i < size; ++i)
	{
		if (check[i] == size - 1)
		{
			cout << i << " ";
		}
	}
}
*/