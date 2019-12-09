#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

struct node
{
	double data;
	node* next;
	node* prev;
};

void add(node*& top, node*& end, double key)
{
	node* nv = new node;
	nv->data = key;
	nv->next = 0;
	if (!top)
	{
		nv->prev = NULL;
		top = nv;
		end = nv;
	}
	else
	{
		end->next = nv;
		nv->prev = end;
		end = nv;
		end->next = NULL;
	}
}
void output(node* top)
{
	while (top)
	{
		cout << top->data << ' ';
		top = top->next;
	}
	cout << '\n';
}

double _min(node*& top, node*& end, int n)
{
	double x1, x2;
	double* b = new double[n];
	for (int i = 0; i < n; i++)
	{
		x1 = top->data;
		top = top->next;
		x2 = end->data;
		end = end->prev;
		b[i] = x1 + x2;

	}
	double min = b[0];
	for (int i = 1; i < n; i++)
	{
		min = (b[i] < min) ? b[i] : min;
	}
	return min;
}
int main()
{
	srand((unsigned)(time(0)));
	node* top = NULL;
	node* end = NULL;
	int n;
	cout << " N = "; cin >> n;
	for (int i = 0; i < 2 * n; i++)
	{
		double x = (rand() % 100) / 100.0;
		add(top, end, x);
	}
	output(top);
	double min = _min(top, end, n);
	cout << " min = " << min << '\n';
}